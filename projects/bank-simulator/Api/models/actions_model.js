const db = require('../database');


const saltRounds=10;
const actions={
  get: function(callback) {
    return db.query('select * from actions', callback);
  },
  getById: function(id,arr, callback) {
    const arrToInt=parseInt(arr);
    return db.query('select * from actions where Accountnumber=? order by date desc limit ?,10', [id,arrToInt], callback);
  },
  getById5: function(id, callback) {
    return db.query('select * from actions where Accountnumber=? order by date desc limit 5', [id], callback);
  },
  add: function(actions, callback) {
     
      return db.query('insert into actions (amount, date, actiontype,Accountnumber) values(?,?,?,?)',
       [actions.amount,actions.date,actions.actiontype,actions.Accountnumber],callback);
    
  },
  delete: function(id, callback) {
    return db.query('delete from actions where actionID=?', [id], callback);
  },
  update: function(id, actions, callback) {
     
      return db.query('update actions set amount=?, date=?, actiontype=?, Accountnumber=? where actionID=?',
      [actions.amount,actions.date,actions.actiontype,actions.Accountnumber,id],callback);
    
  },
  money_pano: function(procedure_params,callback) {
      return db.query(
          'call money_pano (?,?)',
          [procedure_params.Accountnumber, procedure_params.amount],
          callback
      );
  },
  money_otto: function(procedure_params,callback) {
    return db.query(
        'call money_otto (?,?)',
        [procedure_params.Accountnumber, procedure_params.amount],
        callback
    );
}

}
          
module.exports = actions;