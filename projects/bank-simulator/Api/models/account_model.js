const db = require('../database');


const saltRounds=10;
const account={
  get: function(callback) {
    return db.query('select * from account', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from account where Accountnumber=?', [id], callback);
  },
  add: function(account, callback) {
     
      return db.query('insert into account (Accountbalance) values(?)',
       [account.Accountbalance],callback);
    
  },
  delete: function(id, callback) {
    return db.query('delete from account where Accountnumber=?', [id], callback);
  },
  update: function(id, account, callback) {
     
      return db.query('update account set Accountbalance=? where Accountnumber=?',
      [account.Accountbalance,id],callback);
    
  }

}
          
module.exports = account;