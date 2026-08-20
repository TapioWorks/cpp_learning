const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', 
  function(request, response) {
    if(request.body.Cardnumber && request.body.CardPIN){
      const Cardnumber = request.body.Cardnumber;
      const CardPIN = request.body.CardPIN;
        login.checkCardPIN(Cardnumber, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(CardPIN,dbResult[0].CardPIN, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  response.send(true);
                }
                else {
                    console.log("wrong CardPIN");
                    response.send(false);
                }			
                  response.end();
              }
              );
            }
            else{
              console.log("Card does not exist");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("Cardnumber or CardPIN missing");
      response.send(false);
    }
  }
);

module.exports=router;