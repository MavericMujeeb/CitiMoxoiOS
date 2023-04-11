//
//  SearchViewController.swift
//  in_view
//
//  Created by Balaji Babu Modugumudi on 17/10/22.
//

import UIKit

class MoxoViewController : UIViewController{
    
    var mepClient: MEPClient!
    
    var accessToken: String = ""
    
    var loginEmailId: String = ""
    
    override func viewDidLoad() {
        mepClient = MEPClient.sharedInstance()
        mepClient.setup(withDomain: "citiusdev04.moxo.com", linkConfig: nil)
        
        super.viewDidLoad()
        self.navigationController?.navigationBar.isHidden = true
        self.view.backgroundColor = .white
        
        MEPClient.sharedInstance().delegate?.client?(mepClient, didTapClose: {
            print("Close clicked")
        })
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if accessToken.isEmpty {
            self.callAccessTokenAPI()
        } else {
            self.buildMoxoUI()
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        mepClient.hideMEPWindow()
    }
    
    func callAccessTokenAPI() {
        CircleLoader.sharedInstance.show()
       
        let parameters = "{" +
        "\"client_id\":\"OGYwM2RlMjU\"," +
        "\"client_secret\":\"MTVhMzc1MWU\"," +
        "\"org_id\":\"P07wuoEJ4K6BElaAJd6qwkC\"," +
        "\"email\":\"\(self.loginEmailId)\"" +
        "}"
        print("Params ", parameters)
        let fullUrl: String = "https://citiusdev04.moxo.com/v1/core/oauth/token"
        
        guard let url = try? URL(string: fullUrl) else {
            return
        }
        
        var request = URLRequest(url: url)
        request.httpMethod = "POST" //set http method as POST
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        
        request.httpBody = parameters.data(using: .utf8)!
        
        let task = URLSession.shared.dataTask(with: request){
            data, urlResponse, error in
            if let response = urlResponse as? HTTPURLResponse {
                if let data = data {
                    do {
                        let jsonResult = try JSONSerialization.jsonObject(with: data, options: .allowFragments) as? [String:Any]
                        if response.statusCode == 200 {
                            self.accessToken  = jsonResult?["access_token"] as! String
                            print(self.accessToken)
                            self.mepClient.linkUser(withAccessToken: self.accessToken) { error in
                                print("MEPClient handler->")
                                print(error)
                                self.buildMoxoUI()
                            }
                        } else {
                            DispatchQueue.main.async {
                                let message = jsonResult?["message"] as! String
                                let code = jsonResult?["code"] as! String
                                let alert = UIAlertController(title: code, message: message, preferredStyle: .alert)
                                alert.addAction(UIAlertAction(title: "OK", style: .default, handler: { action in
                                    CircleLoader.sharedInstance.hide()
//                                    let dashBoardVC = DashboardViewController.init(nibName: nil, bundle: nil)
//                                    self.navigationController?.pushViewController(dashBoardVC, animated: true)
                                    switch action.style{
                                    case .default:
                                        self.dismiss(animated: true)
                                    case .cancel:
                                        self.dismiss(animated: true)
                                        
                                    case .destructive:
                                        self.dismiss(animated: true)
                                        
                                    @unknown default:
                                        self.dismiss(animated: true)
                                    }
                                }))
                                self.present(alert, animated: true, completion: nil)
                                return
                            }
                        }
                    } catch {
                        //print("Server Error")
                        //print("Error Code: \(error._code)")
                        //print("Error Messsage: \(error.localizedDescription)")
                        //if let str = String(data: data, encoding: String.Encoding.utf8){
                        //print("Print Server data:- " + str)
                        //}
                    }
                }
            }
        }
        task.resume()
    }
    
    func buildMoxoUI(){
        CircleLoader.sharedInstance.hide()
        DispatchQueue.main.async {
            self.mepClient.showMEPWindow()
        }
    }
}
