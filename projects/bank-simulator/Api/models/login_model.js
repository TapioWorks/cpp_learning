const db = require('../database');

const login={
  checkCardPIN: function(Cardnumber, callback) {
      return db.query('SELECT CardPIN FROM card WHERE Cardnumber = ?',[Cardnumber], callback); 
    }
};
          
module.exports = login;