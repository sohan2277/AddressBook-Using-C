<div align="center">

# 📒 Address Book Management System

### A Console-Based Contact Management Application in C

<p>
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/GCC-Compiler-orange?style=for-the-badge&logo=gnu" alt="GCC">
  <img src="https://img.shields.io/badge/Linux-Platform-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux">
  <img src="https://img.shields.io/badge/File%20Handling-00897B?style=for-the-badge" alt="File Handling">
  <img src="https://img.shields.io/badge/Structures-455A64?style=for-the-badge" alt="Structures">
</p>

<p>
  <b>📇 Create • 🔍 Search • ✏️ Edit • 🗑️ Delete • 📋 Manage Contacts</b>
</p>

</div>

---

## 📑 Table of Contents

1. [Overview](#1-overview)
2. [Key Features](#2-key-features)
3. [Tech Stack](#3-tech-stack)
4. [Project Structure](#4-project-structure)
5. [Compilation & Execution](#5-compilation--execution)
6. [Application Menu](#6-application-menu)
7. [Contact Operations](#7-contact-operations)
8. [Input Validation](#8-input-validation)
9. [File Handling](#9-file-handling)
10. [Program Flow](#10-program-flow)
11. [C Concepts Demonstrated](#11-c-concepts-demonstrated)
12. [Possible Improvements](#12-possible-improvements)
13. [Author](#13-author)

---

# 1. Overview

**Address Book Management System** is a console-based application developed in **C** for managing contact information through a menu-driven interface.

The application provides functionality to **create, search, edit, delete, and display contacts**, with validation for names, phone numbers, and email addresses.

Contact information is stored using **file handling**, allowing existing contacts to be loaded when the program starts and saved when the application exits.

---

# 2. Key Features

| Feature | Description |
|---|---|
| ➕ Create Contact | Add a new contact with name, phone number and email |
| 🔍 Search Contact | Search by name, phone number or email |
| ✏️ Edit Contact | Modify existing contact information |
| 🗑️ Delete Contact | Remove contacts with confirmation |
| 📋 List Contacts | Display all stored contacts in a formatted table |
| 💾 File Storage | Save and load contacts using `contacts.txt` |
| ✅ Input Validation | Validate names, phone numbers and email addresses |
| 🔎 Duplicate Detection | Prevent duplicate phone numbers |
| 📊 Contact Capacity | Supports up to 100 contacts |
| 🧩 Modular Design | Contact and file operations separated into modules |

---

# 3. Tech Stack

| Technology / Concept | Purpose |
|---|---|
| **C** | Core application development |
| **GCC** | Compilation |
| **Linux / Unix** | Development and execution environment |
| **Structures** | Represent contacts and address-book data |
| **Arrays** | Store multiple contacts |
| **Pointers** | Data manipulation and function operations |
| **Strings** | Contact information processing |
| **File Handling** | Persistent contact storage |
| **Input Validation** | Validate user-entered information |
| **Modular Programming** | Separate contact and file-management logic |

---

# 4. Project Structure

```text
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.txt
└── README.md
```

### File Responsibilities

| File | Responsibility |
|---|---|
| `main.c` | Main program flow and menu handling |
| `contact.c` | Contact creation, search, editing, deletion, listing and validation |
| `contact.h` | Contact/address-book structures and function declarations |
| `file.c` | Saving and loading contact information |
| `file.h` | File-handling function declarations |
| `contacts.txt` | Persistent contact data |
| `README.md` | Project documentation |

> `contacts.txt` is generated/used by the application during execution.

---

# 5. Compilation & Execution

Make sure GCC is installed on your system.

## Compile

```bash
gcc main.c contact.c file.c -o addressbook
```

## Run

```bash
./addressbook
```

### Linux

```bash
gcc main.c contact.c file.c -o addressbook
./addressbook
```

---

# 6. Application Menu

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

# 7. Contact Operations

## 7.1 Create Contact

Creates a new contact using:

- Name
- Phone number
- Email address

The entered information is validated before the contact is added.

The application supports a maximum of **100 contacts**.

---

## 7.2 Search Contact

Contacts can be searched using:

```text
1. NAME
2. NUMBER
3. EMAIL
```

| Search Method | Behaviour |
|---|---|
| **Name** | Finds matching contact names |
| **Phone Number** | Identifies the corresponding contact |
| **Email** | Identifies the corresponding contact |

---

## 7.3 Edit Contact

Existing contact information can be modified by selecting the required field:

```text
1. NAME
2. NUMBER
3. EMAIL
```

The same validation rules are applied when updated information is entered.

---

## 7.4 Delete Contact

The user selects the contact to delete and receives a confirmation prompt.

After deletion, the remaining contacts are shifted to maintain the address-book structure.

---

## 7.5 List All Contacts

All stored contacts are displayed in a formatted table:

```text
NO         NAME                      PHONE           EMAIL
----------------------------------------------------------------
1          alice                     9458799546      alice@gmail.com
2          Bob                       1234567890      bobnew@gmail.com
...
```

The formatted output makes the stored contact information easier to read.

---

## 7.6 Exit

Before exiting, the application saves the current contacts to:

```text
contacts.txt
```

The saved information can then be loaded during the next program execution.

---

# 8. Input Validation

The application validates user input before storing or updating contact information.

## Name Validation

Names can contain:

- Alphabetic characters
- Spaces

Invalid characters are rejected.

## Phone Number Validation

The phone number:

- Must contain exactly **10 digits**
- Must contain only numeric characters
- Must not already exist in another contact

## Email Validation

The email validation checks for:

- `@`
- `.`
- Text before `@`
- Valid text between `@` and `.`
- Text after `.`
- No spaces
- Lowercase characters

---

# 9. File Handling

The application uses:

```text
contacts.txt
```

to maintain contact information between program executions.

Each contact is stored in the following format:

```text
Name,Phone,Email
```

Example:

```text
Sohan,9765306823,sohan@gmail.com
```

### File Operations

| Operation | Purpose |
|---|---|
| **Load** | Read existing contacts when the program starts |
| **Save** | Write current contacts when the program exits |

The project uses standard C file-handling functions such as:

```c
fopen()
fclose()
fprintf()
fscanf()
```

---

# 10. Program Flow

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
          ┌────────────┼────────────┐
          │            │            │
          ▼            ▼            ▼
       Create        Search        Edit
          │            │            │
          └────────────┼────────────┘
                       │
          ┌────────────┴────────────┐
          │                         │
          ▼                         ▼
       Delete                      List
          │                         │
          └────────────┬────────────┘
                       │
                       ▼
                ┌─────────────┐
                │    Exit?    │
                └──────┬──────┘
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

# 11. C Concepts Demonstrated

This project provides practical implementation of:

- `struct`
- Arrays of structures
- Pointers
- Functions
- Header files
- Function declarations
- String manipulation
- File handling
- `fopen()` and `fclose()`
- `fprintf()` and `fscanf()`
- `strcmp()`
- `strcpy()`
- `strlen()`
- Character validation using `ctype.h`
- Menu-driven programming
- Input validation
- Modular programming

---

# 12. Possible Improvements

Future versions could include:

- Alphabetical contact sorting
- Partial / substring search
- Multiple phone numbers per contact
- Contact groups or categories
- Improved email validation
- Graphical user interface
- Password protection
- CSV export
- SQLite database support
- Improved input handling and error recovery

---

# 13. Author

<div align="center">

### **Sohan K**

**Embedded Systems & IoT Developer**

<p>
  <a href="https://github.com/sohan2277">
    <img src="https://img.shields.io/badge/GitHub-sohan2277-181717?style=for-the-badge&logo=github" alt="GitHub"/>
  </a>
  <a href="https://www.linkedin.com/in/sohan2277/">
    <img src="https://img.shields.io/badge/LinkedIn-Sohan%20K-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/>
  </a>
</p>

</div>

---

<p align="center">
  <b>📒 C • Data Structures • File Handling • Modular Programming</b>
</p>
