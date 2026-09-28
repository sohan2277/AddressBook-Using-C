<div align="center">

# 📒 ADDRESS BOOK MANAGEMENT SYSTEM

### A Console-Based Contact Management Application in C

<p>
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C">
  <img src="https://img.shields.io/badge/Compiler-GCC-orange?style=for-the-badge&logo=gnu" alt="GCC">
  <img src="https://img.shields.io/badge/Platform-Linux-lightgrey?style=for-the-badge&logo=linux" alt="Linux">
</p>

<p>
  <b>📇 Create • 🔍 Search • ✏️ Edit • 🗑️ Delete • 📋 Manage Contacts</b>
</p>

</div>

---

## 📌 About the Project

**Address Book Management System** is a console-based application developed in **C** for managing contact information through a simple and interactive menu-driven interface.

The application allows users to **create, search, edit, delete, and display contacts**, while also providing input validation for names, phone numbers, and email addresses.

Contact data is stored using **file handling**, allowing the information to be loaded when the application starts and saved when the application exits.

---

<div align="center">

### ✨ Simple • Efficient • Modular • Beginner Friendly ✨

</div>

---

## 🚀 Features

* ➕ Create a new contact
* 🔍 Search contacts by:

  * Name
  * Phone number
  * Email
* ✏️ Edit existing contact details
* 🗑️ Delete contacts with confirmation
* 📋 Display all available contacts
* 💾 Save contacts to a file
* 📂 Load contacts automatically when the program starts
* ✅ Name validation
* ✅ Phone number validation
* ✅ Duplicate phone number detection
* ✅ Email validation
* 📊 Supports up to **100 contacts**

---

## 🛠️ Technologies Used

* **C Programming Language**
* GCC Compiler
* Structures
* Functions
* Pointers
* Arrays
* Strings
* File Handling
* Input Validation

---

## 📂 Project Structure

```text
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
└── README.md
```

### File Description

| File        | Description                                                                        |
| ----------- | ---------------------------------------------------------------------------------- |
| `main.c`    | Contains the main menu and program execution flow                                  |
| `contact.c` | Implements contact creation, searching, editing, deletion, listing, and validation |
| `contact.h` | Defines `Contact`, `AddressBook`, and function declarations                        |
| `file.c`    | Handles saving and loading contacts                                                |
| `file.h`    | Contains file-handling function declarations                                       |
| `README.md` | Project documentation                                                              |

> **Note:** `contacts.txt` is used by the application to store contact data and is generated/used during program execution.

---

## ⚙️ Compilation

Make sure GCC is installed on your system.

Compile all C source files using:

```bash
gcc main.c contact.c file.c -o addressbook
```

Run the program:

```bash
./addressbook
```

### Linux

```bash
gcc main.c contact.c file.c -o addressbook
./addressbook
```

---

## 🖥️ Main Menu

When the application starts, the following menu is displayed:

```text
+======================================================================+
|                   ADDRESS BOOK MANAGEMENT SYSTEM                     |
|                                 BY                                   |
|                             S O H A N                                |
+======================================================================+
|           [1] Create contact                                         |
|           [2] Search contact                                         |
|           [3] Edit contact                                           |
|           [4] Delete contact                                         |
|           [5] List all contacts                                      |
|           [6] Exit                                                   |
+----------------------------------------------------------------------+
```

---

## 📌 Operations

### 1. Create Contact

Creates a new contact by taking:

* Name
* Phone number
* Email address

The project validates the entered information before adding the contact to the address book.

A maximum of **100 contacts** can be stored.

### 2. Search Contact

Contacts can be searched using:

```text
1. NAME
2. NUMBER
3. EMAIL
```

Searching by name can return matching contacts, while phone number and email searches identify the corresponding contact.

### 3. Edit Contact

An existing contact can be modified by selecting which field to update:

```text
1. NAME
2. NUMBER
3. EMAIL
```

The same validation rules are applied when entering updated information.

### 4. Delete Contact

The user selects a contact and receives a confirmation prompt before deletion.

When a contact is deleted, the remaining contacts are shifted to maintain the address book structure.

### 5. List All Contacts

Displays all contacts in a formatted table:

```text
NO         NAME                      PHONE           EMAIL
----------------------------------------------------------------
1          alice                     9458799546      alice@gmail.com
2          Bob                       1234567890      bobnew@gmail.com
...
```

The project formats the output into columns for easier readability.

### 6. Exit

Before exiting, the program saves the current contacts to `contacts.txt`.

---

## ✅ Input Validation

### Name Validation

The name can contain alphabetic characters and spaces. Invalid characters are rejected.

### Phone Number Validation

The phone number:

* Must contain exactly **10 digits**
* Must contain only numeric characters
* Must not already exist in another contact

### Email Validation

The email validation checks for:

* `@`
* `.`
* Text before `@`
* Valid text between `@` and `.`
* Text after `.`
* No spaces
* Lowercase characters

---

## 💾 File Handling

The project uses `contacts.txt` to store contact information.

Each contact is stored in the following format:

```text
Name,Phone,Email
```

Example:

```text
Sohan,9765306823,sohan@gmail.com
```

The program writes all contacts to the file when saving and reads them back when loading.

---

## 🔄 Program Flow

```text
             ┌─────────────────┐
             │  Start Program  │
             └────────┬────────┘
                      │
                      ▼
             ┌─────────────────┐
             │ Load Contacts   │
             │ from contacts.txt│
             └────────┬────────┘
                      │
                      ▼
             ┌─────────────────┐
             │   Display Menu  │
             └────────┬────────┘
                      │
          ┌───────────┼───────────┐
          │           │           │
          ▼           ▼           ▼
       Create      Search       Edit
          │           │           │
          └───────────┼───────────┘
                      │
          ┌───────────┴───────────┐
          │                       │
          ▼                       ▼
       Delete                   List
          │                       │
          └───────────┬───────────┘
                      │
                      ▼
                ┌───────────┐
                │   Exit?   │
                └─────┬─────┘
                      │
                     Yes
                      │
                      ▼
             ┌─────────────────┐
             │ Save Contacts   │
             │ to contacts.txt │
             └────────┬────────┘
                      │
                      ▼
                   Exit
```

---

## 🧠 C Concepts Demonstrated

This project demonstrates practical usage of:

* `struct`
* Arrays of structures
* Pointers
* Functions
* Header files
* Function declarations
* String manipulation
* File handling
* `fopen()`, `fclose()`
* `fprintf()`, `fscanf()`
* `strcmp()`, `strcpy()`, `strlen()`
* Character validation using `ctype.h`
* Menu-driven programming
* Input validation
* Modular programming

---

## 📈 Possible Future Improvements

Some possible enhancements for future versions:

* Sort contacts alphabetically
* Add partial/substring search
* Add multiple phone numbers per contact
* Add contact groups/categories
* Improve email validation
* Add a graphical user interface
* Add password protection
* Export contacts to CSV
* Add a database such as SQLite
* Improve input handling and error recovery

---

## 🎯 Learning Objective

The main objective of this project is to build a practical application using fundamental and intermediate **C programming concepts**, particularly **structures, functions, pointers, strings, file handling, and modular programming**.

---

## 👨‍💻 Author

<div align="center">

### **Sohan**

⭐ If you found this project useful, consider giving the repository a star!

</div>

---

<div align="center">

**📒 Address Book Management System • Built with C**

</div>
