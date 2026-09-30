TODO App

A lightweight, interactive command-line TODO application written in C++. The application provides a simple way to create, view, complete, uncomplete, and delete tasks directly from the terminal.

The project is designed as a beginner-friendly C++ application demonstrating fundamental concepts such as structures, functions, arrays, references, loops, conditional statements, input validation, and basic console interaction.

Table of Contents

Overview

Features

Application Preview

Project Structure

How It Works

Getting Started

Compilation

Usage

Task Management

Data Model

Input Validation

Current Limitations

Future Improvements

Learning Objectives

Contributing

License

Overview

The TODO App is a terminal-based task management program developed in C++. It provides a menu-driven interface through which users can manage a list of tasks.

Each task contains:

A completion status

A title

A description

The application keeps track of both the total number of tasks and the number of completed tasks.

The project currently uses an in-memory array to store tasks, meaning all tasks exist only while the program is running.

Features
Task Creation

Users can add multiple tasks at once. Every task contains:

Title

Description

Completion status

Newly created tasks are automatically assigned the status:

Incomplete

Task Viewing

Users can view all currently stored tasks. Each task displays its:

Task number

Completion status

Title

Description

The application also displays:

Total number of tasks

Total number of completed tasks

Complete / Uncomplete Tasks

Users can select a task by its number and toggle its completion status.

For example:

Incomplete → Completed
Completed → Incomplete


The completed-task counter is automatically updated when the status changes.

Task Deletion

Users can delete a task by entering its task number.

After deletion, the remaining tasks are shifted so that the task list remains continuous.

Input Handling

The application includes basic handling for invalid menu input and provides feedback when an invalid task number is entered.

Application Preview

When the application starts, users are presented with the following menu:

===============
    TODO APP
===============
1. Add task
2. View tasks
3. Mark/Unmark tasks
4. Delete Task
5. Exit
Input:

Project Structure
assassin-cloud-todo/
└── to-do/
    ├── function.cpp
    ├── function.h
    └── main.cpp

main.cpp

Contains the application's main execution loop.

Responsibilities include:

Displaying the main menu

Reading user choices

Processing menu options

Managing task completion state

Maintaining task counters

Exiting the application

function.h

Contains the declarations shared between the source files.

It defines the tasks structure:

struct tasks{
    std::string taskcompleted;
    std::string title;
    std::string description;
};


It also contains declarations for the application's functions.

function.cpp

Contains the implementations of the application's functionality.

Implemented functions include:

welcome()

takeinputfromuser()

cinfail()

goback()

addtask()

viewtask()

deletetask()

How It Works

The program starts by initializing the task counters:

int numberoftask {};
int size {};
int numberoftaskscompleted {};


It then enters an infinite menu loop.

The user selects one of the available operations:

1 → Add task
2 → View tasks
3 → Mark/Unmark task
4 → Delete task
5 → Exit


The program continues running until the user selects option 5.

Getting Started
Prerequisites

To build and run this project, you need a C++ compiler.

Supported compilers include:

GCC

Clang

Microsoft Visual C++ (MSVC)

MinGW

The project uses standard C++ libraries such as:

<iostream>
<string>


No external dependencies are required.

Compilation

Navigate to the to-do directory:

cd assassin-cloud-todo/to-do


Compile the application using GCC:

g++ main.cpp function.cpp -o todo


Run the application:

Linux / macOS
./todo

Windows
todo.exe


Or compile directly as:

g++ main.cpp function.cpp -o todo.exe

Usage

After launching the application, select an option from the menu.

Add a Task

Select:

1


The application asks:

How many tasks do you want to add:


After specifying the number of tasks, provide a title and description for each task.

Example:

How many tasks do you want to add:
2

Enter Title:
Learn C++

Enter description:
Study functions and structures

Enter Title:
Build TODO App

Enter description:
Implement task management features

Tasks successfully added

View Tasks

Select:

2


Example output:

Task 1
Incomplete
Title:
Learn C++
description:
Study functions and structures

Task 2
Incomplete
Title:
Build TODO App
description:
Implement task management features

Number of Tasks: 2
Number of Tasks completed: 0

Mark a Task as Completed

Select:

3


The application asks for the task number:

Which task to mark/unmark:


For example:

Which task to mark/unmark:
1

Successfully marked as completed


The selected task will now have:

Completed

Unmark a Completed Task

The same menu option can be used to change a completed task back to incomplete.

Completed → Incomplete


Example:

Which task to mark/unmark:
1

Successfully marked as Incompleted

Delete a Task

Select:

4


Then enter the task number:

Which task do you wanna delete:
2


If the task exists, it will be removed:

Successfully deleted!


The remaining tasks are shifted to fill the deleted task's position.

Exit

Select:

5


The application exits the main loop and terminates.

Task Management

Each task is represented by the following structure:

struct tasks{
    std::string taskcompleted;
    std::string title;
    std::string description;
};

Task Status

The application currently uses two status values:

Incomplete
Completed

Task Numbering

Tasks are displayed using one-based numbering:

Task 1
Task 2
Task 3


Internally, however, the array uses zero-based indexing:

Task 1 → index 0
Task 2 → index 1
Task 3 → index 2


The program converts the user's task number into the corresponding array index before accessing the task.

Data Storage

Tasks are currently stored in a global array:

tasks add[1000];


This means the application's task data is stored in memory while the program is running.

Important

Tasks are not persistent.

When the application is closed, all tasks are lost.

For example:

Program starts
      ↓
Tasks are added
      ↓
Tasks exist in memory
      ↓
Program exits
      ↓
Tasks are lost


A future version could implement file-based or database storage to preserve tasks between sessions.

Input Validation

The application includes basic validation for several types of invalid input.

For example, invalid menu input is handled using:

if(cin.fail()){
    cinfail();
}


The cinfail() function resets the input stream and removes invalid input from the buffer.

Task-related operations also check whether the requested task number is within the currently available range.

Current Limitations

The current implementation is intentionally simple and has several areas that could be improved.

Fixed-Size Storage

Tasks are stored in:

tasks add[1000];


This means the actual storage capacity is limited to 1,000 elements.

No Persistent Storage

Tasks are not saved to disk, so all data is lost after the program terminates.

Basic Input Validation

The current input validation primarily handles invalid numeric input and basic task-number validation. More comprehensive validation could be added for empty titles, descriptions, and other unexpected input.

String-Based Completion Status

Task completion is represented using strings:

"Completed"
"Incomplete"


An enum, bool, or dedicated status type could provide stronger type safety.

Global Task Array

The task array is currently global:

tasks add[1000];


A class or dedicated task manager could provide better encapsulation and organization.

No Task Editing

The current application allows users to create, view, complete/uncomplete, and delete tasks, but does not provide an option to edit an existing task's title or description.

No Search or Filtering

Users cannot currently search for a specific task or filter tasks by completion status.

Future Improvements

Several improvements could be introduced in future versions.

Storage

Save tasks to a text file

Load tasks when the application starts

Add JSON-based storage

Introduce a database such as SQLite

Better Data Structures

Replace the fixed-size array with:

std::vector<tasks>


This would make task storage more flexible and easier to manage.

Task Editing

Add functionality to:

Edit task titles

Edit descriptions

Change task status

Task Priority

Introduce priorities such as:

Low
Medium
High

Due Dates

Allow users to assign deadlines to tasks.

Example:

Title: Complete C++ Project
Due Date: 2026-10-15

Search

Allow users to search tasks by:

Title

Description

Status

Filtering

Provide options such as:

Show all tasks
Show completed tasks
Show incomplete tasks

Sorting

Tasks could be sorted by:

Title

Priority

Due date

Completion status

Improved User Interface

The terminal interface could be enhanced with:

Colors

Better formatting

Clear screen functionality

Confirmation prompts

Improved error messages

Object-Oriented Design

The project could eventually be redesigned around classes such as:

class Task
class TodoManager


This would provide better separation of responsibilities and make the project easier to extend.

Learning Objectives

This project demonstrates several fundamental C++ programming concepts.

Functions

The application separates functionality into multiple functions:

void welcome();
int takeinputfromuser();
void addtask(int& size, int& numberoftask);
void viewtask(int numberoftask, int numberoftaskscompleted);
void deletetask(int& numberoftask, int& numberoftaskscompleted);

Structures

The tasks structure groups related task information together:

struct tasks{
    std::string taskcompleted;
    std::string title;
    std::string description;
};

Arrays

The application stores multiple tasks using an array:

tasks add[1000];

References

References are used to modify counters directly inside functions:

void addtask(int& size, int& numberoftask);

Loops

The main application uses a loop to continuously display the menu until the user chooses to exit.

Conditional Statements

if, else if, and else statements are used to process user selections and validate input.

Standard Library

The project uses standard C++ functionality including:

<iostream>
<string>

Code Organization

The project follows a simple separation between declarations, implementations, and program execution.

                 ┌──────────────┐
                 │   main.cpp   │
                 │              │
                 │ Main Loop    │
                 │ Menu Logic   │
                 └──────┬───────┘
                        │
                        ▼
                 ┌──────────────┐
                 │ function.h   │
                 │              │
                 │ Structures   │
                 │ Declarations │
                 └──────┬───────┘
                        │
                        ▼
                 ┌──────────────┐
                 │ function.cpp │
                 │              │
                 │ Functions    │
                 │ Implementation│
                 └──────────────┘


This organization keeps the program logic separated from function declarations and implementations.

Error Handling

The application provides basic error messages for invalid operations.

Examples include:

Invalid Input!


and:

Invalid task


This prevents some invalid user input from causing the application to immediately terminate.

Contributing

Contributions and improvements are welcome.

A typical contribution workflow is:

Fork the repository.

Create a new branch.

Make your changes.

Test the application.

Commit your changes.

Push the branch.

Open a pull request.

When contributing, try to keep the code readable and maintain the existing project structure unless a larger architectural improvement is being proposed.

Development Guidelines

When modifying the project:

Use clear and descriptive function names.

Keep functions focused on a single responsibility.

Validate user input where appropriate.

Avoid unnecessary global state in future improvements.

Prefer standard C++ containers and types where appropriate.

Keep the code easy to read and maintain.

Test all task operations after making changes.

Roadmap

Potential development roadmap:

[x] Add tasks
[x] View tasks
[x] Mark tasks as completed
[x] Unmark completed tasks
[x] Delete tasks
[x] Track completed task count
[ ] Edit tasks
[ ] Persistent file storage
[ ] Search tasks
[ ] Filter tasks
[ ] Task priorities
[ ] Due dates
[ ] Improved input validation
[ ] Replace fixed array with std::vector
[ ] Object-oriented redesign
[ ] Database support

License

No license has currently been specified for this project.

If this project is intended to be publicly distributed or open source, a license such as the MIT License can be added in a future revision.

Author

Assassin Cloud TODO

A C++ command-line TODO application created as a practical project for learning and applying fundamental C++ programming concepts.

Acknowledgements

This project was developed using standard C++ functionality and does not require any external libraries or frameworks.

Final Notes

The TODO App is intentionally kept simple so that its underlying C++ concepts remain easy to understand. It provides a foundation that can be progressively expanded into a more complete task-management application.

The current implementation focuses on core task operations, while future versions can introduce persistent storage, improved data structures, object-oriented design, advanced task properties, and a richer command-line interface.
