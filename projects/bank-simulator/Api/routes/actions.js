const { response } = require('express');
const express = require('express');
const router = express.Router();
const actions = require('../models/actions_model');

router.get('/:id?&:arr?',
function(request, response){
  if (request.params.id,request.params.arr){
    actions.getById(request.params.id,request.params.arr, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    actions.get(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});
router.post('/', 
function(request, response) {
  actions.add(request.body, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body); 
    }
  });
});

router.delete('/:id', 
function(request, response) {
  actions.delete(request.params.id, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(count);
    }
  });
});


router.put('/:id', 
function(request, response) {
  actions.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post('/money_pano',
function(request, response) {
    actions.money_pano(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }else {
            response.json(dbResult.affectedRows);
        }
    })
});

router.post('/money_otto',
function(request, response) {
    actions.money_otto(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }else {
            response.json(dbResult.affectedRows);
        }
    })
});
router.get('/:id/5',
function(request, response) {
  
    actions.getById5(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    })
});
module.exports = router;
