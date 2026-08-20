const db = require('../database');


const saltRounds=10;
const customer={
  get: function(callback) {
    return db.query('select * from customer', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from customer where CustomerID=?', [id], callback);
  },
  add: function(customer, callback) {
     
      return db.query('insert into customer (Name, Address, Phonenumber) values(?,?,?)',
       [customer.Name,customer.Address,customer.Phonenumber],callback);
    
  },
  delete: function(id, callback) {
    return db.query('delete from customer where CustomerID=?', [id], callback);
  },
  update: function(id, customer, callback) {
     
      return db.query('update customer set Name=?, Address=?, Phonenumber=? where CustomerID=?',
      [customer.Name,customer.Address,customer.Phonenumber,id],callback);
    
  }

}
          
module.exports = customer;