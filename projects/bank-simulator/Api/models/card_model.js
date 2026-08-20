const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const card={
  get: function(callback) {
    return db.query('select * from card', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from card where Cardnumber=?', [id], callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.CardPIN, saltRounds, function(err, hash) {
      return db.query('insert into card (CardPIN, CustomerID, Accountnumber) values(?,?,?)',
      [hash, card.CustomerID, card.Accountnumber], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where Cardnumber=?', [id], callback);
  },
  update: function(id, card, callback) {
    bcrypt.hash(card.CardPIN, saltRounds, function(err, hash) {
      return db.query('update card set CardPIN=?, CustomerID=?, Accountnumber=? where Cardnumber=?',
      [hash, card.CustomerID, card.Accountnumber, id], callback);
    });
    },
    cardlock: function(id, callback) {
      return db.query('call cardlock(?)', [id], callback);
    },
  }


          
module.exports = card;