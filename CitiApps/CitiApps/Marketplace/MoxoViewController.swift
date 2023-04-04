//
//  SearchViewController.swift
//  in_view
//
//  Created by Balaji Babu Modugumudi on 17/10/22.
//

import UIKit

class MoxoViewController : UIViewController{
    
    var mepClient: MEPClient!
    
    override func viewDidLoad() {
        mepClient = MEPClient.sharedInstance()
        mepClient.setup(withDomain: "citiusdev04.moxo.com", linkConfig: nil)
        mepClient.linkUser(withAccessToken: "Z3IzM2dyZvUrBI3uZ3LPsjIZPhY-GT9DNhM2QC0dUDYpHTBHCAUhUmdyZ3EzQF4tERNTJyA9DycUOFAEEQQlCzcUDj0gKxA_VSALPw0n_wS1bbLCeMhYRIhXNS_0hA") { error in
            print("MEPClient handler->")
            print(error)
            self.buildMoxoUI()
        }
        super.viewDidLoad()
        self.navigationController?.navigationBar.isHidden = true
        self.view.backgroundColor = .white
        
        MEPClient.sharedInstance().delegate?.client?(mepClient, didTapClose: { 
            print("Close clicked")
        })
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        self.buildMoxoUI()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        mepClient.hideMEPWindow()
    }
    
    func buildMoxoUI(){
        mepClient.showMEPWindow()
    }
}
