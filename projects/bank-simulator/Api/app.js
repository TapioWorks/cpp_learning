var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const basicAuth = require('express-basic-auth');

var indexRouter = require('./routes/index');

var actionsRouter = require('./routes/actions');
var loginRouter = require('./routes/login');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var customerRouter = require('./routes/customer');


var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use(basicAuth({users: { 'admin': '1234' }}))

app.use('/', indexRouter);
app.use('/actions', actionsRouter);
app.use('/account', accountRouter);
app.use('/login', loginRouter);
app.use('/card', cardRouter);
app.use('/customer', customerRouter);



module.exports = app;