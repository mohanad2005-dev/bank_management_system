# 🏦 Bank Management System

A **console-based Bank Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts.

The system provides functionality for managing **clients, users, currencies, transactions, transfers, and login records**, with a **permission-based access control system**.

---

## 🔐 Password Protection

The system includes a simple password protection mechanism for user passwords.

Before a user's password is stored in the users file, **3 is added to each digit of the password**. The modified value is then stored in the file instead of the original password.

This prevents user passwords from being stored directly in their original form and demonstrates a basic approach to password protection using C++.

> ⚠️ **Note:** This is a simple educational encryption/obfuscation technique and is not intended to replace secure password hashing methods used in real-world banking systems.

---

## 📌 About the Project

This project simulates a basic banking management system through a **console interface**.

The system includes:

- 👤 Client Management
- 👥 User Management
- 💰 Banking Transactions
- 🔄 Money Transfers
- 💱 Currency Management
- 🔐 Login & Authentication
- 🔑 Permission-Based Access Control
- 📋 Login & Transfer Registers
- 🔐 Password Protection
- 💾 File-Based Data Storage

The project is designed to practice and demonstrate **C++ Object-Oriented Programming**, file handling, inheritance, encapsulation, and bitwise permissions.

---

## 🔐 Login System

The program starts with a **Login Screen** where the user enters their username and password.

### Login Features

- 🔑 Username & password authentication
- 🔢 Maximum of **3 login attempts**
- 🚫 Access denied after failed attempts
- 👤 Current user tracking
- 📋 Login activity recording
- 🔐 Permission-based access control
- 🔐 Password protection before storing user data

After successful authentication, the user is taken to the **Main Menu**.

---

## 🔑 User Permissions

The system uses **bitwise permissions** to control access to different parts of the application.

| Permission | Value | Description |
|:--:|:--:|:--|
| 👁️ Show Clients | `1` | View clients |
| ➕ Add Client | `2` | Add a new client |
| 🗑️ Delete Client | `4` | Delete a client |
| ✏️ Update Client | `8` | Update client information |
| 🔎 Find Client | `16` | Search for a client |
| 💰 Transactions | `32` | Access banking transactions |
| 👥 Manage Users | `64` | Manage system users |
| 💱 Currencies | `128` | Manage currencies |
| 📋 Login Registers | `256` | View login records |
| 👑 Full Access | `-1` | Access all system features |

### 🛡️ Access Control

Before accessing a protected operation, the system checks the current user's permissions.

If the required permission is not available, the system displays:

```text
Access Denied
```

This allows different users to have different levels of access within the system.

---

## 👥 User Management

Authorized users can manage the users of the banking system.

### Available Operations

- 📋 Show Users List
- ➕ Add New User
- 🗑️ Delete User
- ✏️ Update User
- 🔎 Find User

### User Information

Each user contains:

- First Name
- Last Name
- Email
- Phone
- Username
- Password
- Permissions

User data is stored in a text file, with the password stored in its protected form.

---

## 👤 Client Management

The system provides complete client management functionality.

### Available Operations

- 📋 Show Clients List
- ➕ Add New Client
- 🗑️ Delete Client
- ✏️ Update Client
- 🔎 Find Client

### Client Information

Each client contains:

- First Name
- Last Name
- Email
- Phone
- Account Number
- PIN Code
- Balance

Client data is stored in a text file.

---

## 💰 Banking Transactions

The system provides a dedicated **Transactions** section.

| Operation | Description |
|:--:|:--|
| 💵 Deposit | Add money to a client's balance |
| 💸 Withdraw | Withdraw money from a client's balance |
| 💰 Total Balances | Display total client balances |
| 🔄 Transfer | Transfer money between clients |
| 📋 Transfer Registers | View transfer records |

The system automatically updates client balances after transactions.

---

## 🔄 Money Transfer

The transfer system allows users to transfer money between two bank clients.

### Transfer Information

Each transfer records:

- 📅 Date & Time
- 👤 Source Account
- 👤 Destination Account
- 💰 Transfer Amount
- 💵 Source Balance
- 💵 Destination Balance
- 👨‍💻 Current User

Transfer records are stored for later viewing.

---

## 💱 Currency Management

The system includes a dedicated currency management section.

### Available Operations

- 📋 Currencies List
- 🔎 Find Currency
- ✏️ Update Currency
- 🧮 Currency Calculator

### 🧮 Currency Calculator

The Currency Calculator allows users to convert an amount from one currency to another.

The user enters:

- 💱 Source Currency
- 💱 Target Currency
- 💰 Amount

The system then calculates the converted amount using the exchange rates stored in the system.

---

## 📋 Login Registers

The system records successful login operations.

Each login record contains information such as:

- 📅 Date & Time
- 👤 Username
- 🔐 Password
- 🔑 Permissions

Authorized users can view the login register from the system menu.

---

## ✨ Features

### 🔐 Authentication & Security

- Username and password authentication
- 3 login attempts
- Permission-based access control
- Full access permission
- Access denied for unauthorized operations
- Simple password protection before storing passwords

### 👤 Client Management

- Add clients
- Update clients
- Delete clients
- Find clients
- Display clients
- View total balances

### 👥 User Management

- Add users
- Update users
- Delete users
- Find users
- Display users
- Manage user permissions
- Protected password storage

### 💰 Banking

- Deposit
- Withdraw
- Transfer
- Total balances
- Transfer registers
- Transaction management

### 💱 Currency

- Currency management
- Find currencies
- Update currencies
- Currency calculator

### 📋 Records

- Login registers
- Transfer registers
- File-based data storage

### 🛠️ Other

- Input validation
- Multiple console screens
- Structured project organization
- Object-Oriented Programming

---

## 🛠️ Technologies Used

- **C++**
- **Object-Oriented Programming (OOP)**
- **Visual Studio**
- **Standard C++ Library**
- **Classes & Objects**
- **Inheritance**
- **Encapsulation**
- **File Handling**
- **Vectors**
- **Enums**
- **Structures**
- **Bitwise Operations**
- **Input Validation**

---

## 📂 Project Structure

```text
BankProject/
│
├── 📁 Classes/
│   ├── clsBankClients.h
│   ├── clsBankCurrencies.h
│   ├── clsBankUsers.h
│   ├── clsDate.h
│   ├── clsHeader.h
│   ├── clsInputValidate.h
│   ├── clsLoginRegister.h
│   ├── clsPerson.h
│   ├── clsString.h
│   ├── clsTransferRegisters.h
│   └── clsUtil.h
│
├── 📁 Data/
│   ├── ClientsFile.txt
│   ├── CurrenciesFile.txt
│   ├── LoginRegisterFile.txt
│   ├── TransfersRegisterFile.txt
│   └── UsersFile.txt
│
├── 📁 Includes/
│   └── Global.h
│
├── 📁 Screens/
│   ├── clsAddNewClientScreen.h
│   ├── clsAddNewUserScreen.h
│   ├── clsBankClients.h
│   ├── clsBankCurrencies.h
│   ├── clsBankUsers.h
│   ├── clsCurrenciesCalculatorScreen.h
│   ├── clsCurrenciesScreen.h
│   ├── clsDeleteClientScreen.h
│   ├── clsDeleteUserScreen.h
│   ├── clsDepositScreen.h
│   ├── clsFindClientScreen.h
│   ├── clsFindCurrencyScreen.h
│   ├── clsFindUserScreen.h
│   ├── clsLoginScreen.h
│   ├── clsMainScreen.h
│   ├── clsManageUsersScreen.h
│   ├── clsShowClientsListScreen.h
│   ├── clsShowCurrenciesListScreen.h
│   ├── clsShowLoginRegisterScreen.h
│   ├── clsShowTotalBalancesScreen.h
│   ├── clsShowTransferRegistersScreen.h
│   ├── clsShowUsersListScreen.h
│   ├── clsTransactionsScreen.h
│   ├── clsTransferScreen.h
│   ├── clsUpdateClientScreen.h
│   ├── clsUpdateCurrencyScreen.h
│   ├── clsUpdateUserScreen.h
│   └── clsWithdrawScreen.h
│
├── 📁 Source/
│   └── BankProject.cpp
│
├── 📄 BankProject.sln
├── 📄 BankProject.vcxproj
├── 📄 BankProject.vcxproj.filters
└── 📄 .gitignore
```

---

## 🚀 How to Run

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/mohanad2005-dev/bank_management_project.git
```

### 2️⃣ Open the Project

Open:

```text
BankProject.sln
```

using **Visual Studio**.

### 3️⃣ Build the Project

Build the solution using:

```text
Build → Build Solution
```

### 4️⃣ Run the Program

Run the project using:

```text
Debug → Start Without Debugging
```

---

## 🔄 Program Flow

```text
┌─────────────────────┐
│    Login Screen     │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│ Authenticate User   │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│    Main Menu        │
└──────────┬──────────┘
           │
     ┌─────┼─────┬─────────────┐
     ▼     ▼     ▼             ▼
  Clients Users Transactions Currencies
     │     │       │             │
     ▼     ▼       ▼             ▼
  Manage Manage  Banking       Manage
  Clients Users Operations    Currencies
```

---

## 🎯 Project Goals

This project was developed to practice and improve practical **C++ programming skills**, especially:

- Object-Oriented Programming
- Working with classes and inheritance
- Encapsulation
- File handling
- User authentication
- Password protection
- Permission systems
- Bitwise operations
- Data validation
- Building a larger multi-file C++ project

---

## 👨‍💻 Author

**Mohanad Abu-Najie**

⭐ If you find this project useful, feel free to explore the code and give it a star!
