Student Management System (C Program)

A simple and efficient Student Management System written in C with role-based access control.
This project allows Admin, Staff, User, and Guest to manage and view student records based on their permissions.

| Role      | Add | View | Search | Update | Delete |
| --------- | --- | ---- | ------ | ------ | ------ |
| **Admin** | ✔️  | ✔️   | ✔️     | ✔️     | ✔️     |
| **Staff** | ❌   | ✔️   | ✔️     | ✔️     | ❌      |
| **User**  | ❌   | ✔️   | ✔️     | ❌      | ❌      |
| **Guest** | ❌   | ✔️   | ❌      | ❌      | ❌      |

Features:

Role-based login system

Add new students

Display all student records

Search for a student by ID

Update student details

Delete student records

Pre-loaded sample student data

Clean, menu-driven interface

Technologies Used:

C Programming Language

Structs

Arrays

Functions

String Comparison

Menu-driven logic
Project Structure:

├── student_management_system.c

└── README.md

How to Run the Program:

compile -- gcc student_management_system.c -o sms

Run -- ./sms

Default Login Credentials :

| Username | Password | Role  |
| -------- | -------- | ----- |
| admin    | admin123 | ADMIN |
| staff    | staff123 | STAFF |
| guest    | guest123 | GUEST |
| user     | user123  | USER  |

Sample Student Records (Pre-Loaded) :

| ID   | Name    | Marks |
| ---- | ------- | ----- |
| 1002 | SHRAVAN | 560   |
| 1003 | Rayalu  | 580   |
| 1004 | Pks     | 585   |
| 1005 | Mahesh  | 589   |
| 1006 | Suresh  | 499   |

Author :

Developed by: Jithin