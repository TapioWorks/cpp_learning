# Bank Simulator

A university team project implementing a simulated banking system.

The system consists of a Qt/C++ desktop application, a Node.js/Express
backend providing REST-style API endpoints, and a MySQL database.

## Architecture

```text
┌─────────────────────────┐
│      Qt / C++ Client    │
│                         │
│  Banking UI             │
│  PIN authentication     │
│  Account operations     │
│  Transaction history    │
└────────────┬────────────┘
             │
             │ HTTP / REST
             ▼
┌─────────────────────────┐
│    Node.js / Express    │
│                         │
│  Customer API           │
│  Account API            │
│  Card API               │
│  Login API              │
│  Banking actions        │
└────────────┬────────────┘
             │
             │ SQL
             ▼
┌─────────────────────────┐
│         MySQL           │
│                         │
│  Customers              │
│  Accounts               │
│  Cards                  │
│  Transactions            │
└─────────────────────────┘
