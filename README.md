````
# TODO App

A lightweight, interactive **command-line TODO application written in C++**. The application allows users to create, view, complete, uncomplete, and delete tasks directly from the terminal.

This project is designed as a practical C++ application demonstrating fundamental programming concepts such as structures, functions, arrays, references, loops, conditional statements, input validation, and console-based user interaction.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Application Preview](#application-preview)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Compilation](#compilation)
- [Running the Application](#running-the-application)
- [Usage](#usage)
- [Task Data Model](#task-data-model)
- [Data Storage](#data-storage)
- [Input Validation](#input-validation)
- [Current Limitations](#current-limitations)
- [Future Improvements](#future-improvements)
- [Learning Objectives](#learning-objectives)
- [Code Organization](#code-organization)
- [Example Workflow](#example-workflow)
- [Contributing](#contributing)
- [Roadmap](#roadmap)
- [License](#license)
- [Author](#author)
- [Acknowledgements](#acknowledgements)

---

## Overview

**TODO App** is a simple terminal-based task management application written in C++.

The application provides a menu-driven interface that allows users to manage a list of tasks without requiring any external libraries or frameworks.

Each task contains:

- A completion status
- A title
- A description

The application also keeps track of:

- The total number of tasks
- The total number of completed tasks

The current version stores tasks in memory using a fixed-size array.

---

## Features

- Add multiple tasks at once
- Add a title to each task
- Add a description to each task
- Mark tasks as completed
- Unmark completed tasks
- View all tasks
- View the total number of tasks
- View the number of completed tasks
- Delete tasks
- Basic invalid-input handling
- Interactive command-line interface
- No external dependencies

---

## Application Preview

When the application starts, the following menu is displayed:

```text
===============
    TODO APP
===============
1. Add task
2. View tasks
3. Mark/Unmark tasks
4. Delete Task
5. Exit
Input:
````

 The user can select an operation by entering the corresponding number.

---

 ## Project Structure

```
assassin-cloud-todo/
└── to-do/
    ├── function.cpp
    ├── function.h
    └── main.cpp
```

 ### File Description

 | File | Description |
| --- | --- |
| `main.cpp` | Contains the main program loop, menu handling, and task completion logic. |
| `function.h` | Contains the `tasks` structure and function declarations. |
| `function.cpp` | Contains the implementations of the application's functions. |

---

 ## How It Works

 The application starts by initializing the task counters:

```
int numberoftask {};
int size {};
int numberoftaskscompleted {};
```

 The program then continuously displays the main menu until the user chooses the exit option.

 The available operations are:

```
1 → Add task
2 → View tasks
3 → Mark/Unmark tasks
4 → Delete task
5 → Exit
```

 The application uses separate functions for different operations.

 For example:

```
void welcome();
int takeinputfromuser();
void cinfail();
void goback();
void addtask(int& size, int& numberoftask);
void viewtask(int numberoftask, int numberoftaskscompleted);
void deletetask(int& numberoftask, int& numberoftaskscompleted);
```

 This keeps the implementation separated into smaller and easier-to-understand components.

---

 ## Requirements

 To compile and run this project, you need a C++ compiler.

 ### Supported Compilers

 The project can be compiled using:

 - GCC
- Clang
- Microsoft Visual C++ (MSVC)
- MinGW

 ### Standard Libraries Used

 The project currently uses standard C++ libraries:

```
#include <iostream>
#include <string>
```

 No external libraries or packages are required.

---

 ## Getting Started

 ### Clone the Repository

 If the project is hosted on GitHub, clone it using:

```
git clone <repository-url>
```

 Then move into the project directory:

```
cd assassin-cloud-todo
```

 Navigate to the source directory:

```
cd to-do
```

 You should see:

```
function.cpp
function.h
main.cpp
```

---

 ## Compilation

 ### Using GCC

 From inside the `to-do` directory, run:

```
g++ main.cpp function.cpp -o todo
```

 For C++11:

```
g++ -std=c++11 main.cpp function.cpp -o todo
```

 For C++17:

```
g++ -std=c++17 main.cpp function.cpp -o todo
```

 If compilation is successful, an executable named `todo` will be created.

---

 ## Running the Application

 ### Linux / macOS

```
./todo
```

 ### Windows

 If compiled using MinGW:

```
todo.exe
```

 or:

```
.\todo.exe
```

---

 # Usage

 ## 1\. Add a Task

 Select option:

```
1
```

 The application asks how many tasks you want to add:

```
How many tasks do you want to add:
```

 For each task, you will be asked to enter:

```
Enter Title:
Enter description:
```

 Example:

```
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
```

 Every newly created task starts with the status:

```
Incomplete
```

---

 ## 2\. View Tasks

 Select option:

```
2
```

 The application displays all currently stored tasks.

 Example:

```
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
```

 The displayed information includes:

 - Task number
- Completion status
- Title
- Description
- Total number of tasks
- Number of completed tasks

---

 ## 3\. Mark or Unmark a Task

 Select option:

```
3
```

 The application asks:

```
Which task to mark/unmark:
```

 Enter the task number.

 For example:

```
1
```

 If the task is incomplete, it becomes completed:

```
Successfully marked as completed
```

 The task status changes from:

```
Incomplete
```

 to:

```
Completed
```

 If the task is already completed, selecting it again changes it back to:

```
Incomplete
```

 The completed-task counter is updated automatically.

---

 ## 4\. Delete a Task

 Select option:

```
4
```

 The application asks:

```
Which task do you wanna delete:
```

 Enter the task number.

 For example:

```
2
```

 If the task exists, the application displays:

```
Successfully deleted!
```

 After deletion, the remaining tasks are shifted to fill the empty position.

 For example:

```
Before deletion:

Task 1
Task 2
Task 3
Task 4
```

 If Task 2 is deleted:

```
After deletion:

Task 1
Task 3
Task 4
```

 If the deleted task was completed, the completed-task counter is also decreased.

---

 ## 5\. Exit

 Select:

```
5
```

 The application exits the main loop and terminates.

---

 ## Task Data Model

 Tasks are represented using a C++ structure defined in `function.h`:

```
struct tasks{
    std::string taskcompleted;
    std::string title;
    std::string description;
};
```

 Each task contains three pieces of information.

 ### Completion Status

 The application currently uses two status values:

```
Completed
Incomplete
```

 ### Title

 Stores the name or short title of the task.

 Example:

```
Learn C++
```

 ### Description

 Stores additional information about the task.

 Example:

```
Practice functions, arrays, and structures.
```

---

 ## Task Storage

 The application currently uses a global array:

```
tasks add[1000];
```

 Tasks are stored using zero-based array indexing.

 For example:

 | User Task Number | Array Index |
| --- | --- |
| Task 1 | 0 |
| Task 2 | 1 |
| Task 3 | 2 |
| Task 4 | 3 |

When a user enters a task number, the application decreases it by one to convert the user-facing task number into an array index.

---

 ## Data Storage

 Currently, all tasks are stored only in memory.

 This means tasks are available while the application is running, but they are not permanently saved.

 The current lifecycle is:

```
Start Application
       ↓
Add Tasks
       ↓
Tasks Stored in Memory
       ↓
Manage Tasks
       ↓
Exit Application
       ↓
Tasks Are Lost
```

 If the program is started again, the task list begins empty.

---

 ## Input Validation

 The application contains basic input validation.

 If invalid numeric input causes `std::cin` to enter a failed state, the program calls:

```
cinfail();
```

 The function performs:

```
cin.clear();
cin.ignore(1000, '\n');
```

 This clears the error state and removes invalid characters from the input buffer.

 The application also validates task numbers before accessing a task.

 Invalid task selections result in messages such as:

```
Invalid task
```

 or:

```
Invalid input
```

---

 ## Current Limitations

 The current version is intentionally simple and has several limitations.

 ### Fixed-Size Array

 Tasks are stored in:

```
tasks add[1000];
```

 Therefore, the actual array has space for 1,000 tasks.

 ### No Persistent Storage

 Tasks are lost when the application exits because they are not saved to a file or database.

 ### No Task Editing

 The application currently does not provide an option to edit an existing task's:

 - Title
- Description

 ### No Search

 There is currently no functionality to search for tasks.

 ### No Filtering

 Users cannot currently filter tasks by:

 - Completed status
- Incomplete status

 ### No Priority

 Tasks do not currently have priority levels.

 ### No Due Dates

 Tasks do not currently support deadlines or due dates.

 ### Basic Input Validation

 Input handling can be improved to handle more edge cases, including unexpected input during task creation.

 ### Global State

 The task array is currently declared globally:

```
tasks add[1000];
```

 A future version could encapsulate task management inside a class.

 ### Capacity Check Mismatch

 The current implementation declares an array of 1,000 tasks:

```
tasks add[1000];
```

 However, `addtask()` contains validation that allows values up to 10,000.

 This should be corrected in a future version so that the validation limit matches the actual storage capacity.

---

 ## Future Improvements

 ### Persistent Storage

 Implement file storage so tasks remain available after restarting the application.

 Possible approaches include:

 - Text files
- CSV files
- JSON files
- SQLite
- Other databases

 Possible workflow:

```
Application Start
       ↓
Load Tasks From File
       ↓
Manage Tasks
       ↓
Save Tasks
       ↓
Application Exit
```

 ### Replace Array With `std::vector`

 The fixed-size array:

```
tasks add[1000];
```

 could be replaced with:

```
std::vector<tasks>
```

 This would provide dynamic storage and make task management more flexible.

 ### Edit Tasks

 Add an option allowing users to modify:

 - Task title
- Task description
- Completion status

 ### Task Priorities

 Introduce priority levels:

```
Low
Medium
High
```

 ### Due Dates

 Allow users to specify task deadlines.

 Example:

```
Title: Complete C++ Project
Due Date: 2026-10-15
Priority: High
```

 ### Search Functionality

 Allow users to search for tasks using:

 - Title
- Description
- Status

 ### Task Filtering

 Add options such as:

```
Show all tasks
Show completed tasks
Show incomplete tasks
```

 ### Sorting

 Allow tasks to be sorted by:

 - Title
- Priority
- Due date
- Completion status

 ### Confirmation Prompts

 Add confirmation before destructive operations.

 Example:

```
Are you sure you want to delete this task? (y/n)
```

 ### Improved User Interface

 The command-line interface could be improved with:

 - Colors
- Better formatting
- Clearer menus
- Improved error messages
- Screen clearing
- Better navigation

 ### Object-Oriented Design

 The application could eventually be redesigned using classes such as:

```
class Task
{
    // Task information
};
```

 and:

```
class TodoManager
{
    // Task management functionality
};
```

 This would provide better encapsulation and make the application easier to maintain and extend.

---

 ## Learning Objectives

 This project demonstrates several fundamental C++ concepts.

 ### Functions

 The application separates functionality into individual functions:

```
void welcome();
int takeinputfromuser();
void cinfail();
void goback();

void addtask(int& size, int& numberoftask);

void viewtask(
    int numberoftask,
    int numberoftaskscompleted
);

void deletetask(
    int& numberoftask,
    int& numberoftaskscompleted
);
```

 ### Structures

 The `tasks` structure groups related task information:

```
struct tasks{
    std::string taskcompleted;
    std::string title;
    std::string description;
};
```

 ### Arrays

 Multiple tasks are stored in an array:

```
tasks add[1000];
```

 ### References

 References are used when functions need to modify variables from the caller:

```
void addtask(int& size, int& numberoftask);
```

 ### Loops

 The main application uses a loop to repeatedly display the menu until the user chooses to exit.

 ### Conditional Statements

 The application uses `if`, `else if`, and `else` statements to process menu choices and validate input.

 ### Strings

 The project uses `std::string` to store:

 - Task status
- Task title
- Task description

 ### Input and Output

 The application uses `std::cin` and `std::cout` for terminal interaction.

---

 ## Code Organization

 The project separates declarations, implementations, and program execution.

```
                  ┌──────────────────┐
                  │     main.cpp     │
                  │                  │
                  │  Main Program    │
                  │  Menu Handling   │
                  │  Task Logic      │
                  └────────┬─────────┘
                           │
                           ▼
                  ┌──────────────────┐
                  │   function.h     │
                  │                  │
                  │  Structures      │
                  │  Declarations    │
                  └────────┬─────────┘
                           │
                           ▼
                  ┌──────────────────┐
                  │   function.cpp   │
                  │                  │
                  │  Implementations │
                  │  Task Functions  │
                  └──────────────────┘
```

 This structure keeps the application organized and makes individual components easier to understand.

---

 ## Example Workflow

 A typical session might look like this:

```
Start Application
       ↓
Select "Add task"
       ↓
Create tasks
       ↓
Select "View tasks"
       ↓
Review tasks
       ↓
Select "Mark/Unmark tasks"
       ↓
Complete a task
       ↓
Select "Delete Task"
       ↓
Remove an unwanted task
       ↓
Select "Exit"
```

---

 ## Example Session

```
===============
    TODO APP
===============
1. Add task
2. View tasks
3. Mark/Unmark tasks
4. Delete Task
5. Exit
Input:
1

How many tasks do you want to add:
2

Enter Title:
Learn C++

Enter description:
Study functions and structures

Enter Title:
Build TODO App

Enter description:
Create a command-line task manager

Tasks successfully added

Input anything to go back:
back
```

 Viewing the tasks:

```
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
Create a command-line task manager

Number of Tasks: 2
Number of Tasks completed: 0
```

 After completing Task 1:

```
Which task to mark/unmark:
1

Successfully marked as completed
```

 The completed-task count becomes:

```
Number of Tasks: 2
Number of Tasks completed: 1
```

---

 ## Contributing

 Contributions are welcome.

 To contribute:

 1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Test the application.
5. Commit your changes.
6. Push the branch.
7. Open a pull request.

 Example:

```
git checkout -b feature/task-editing
```

 After making your changes:

```
git add .
git commit -m "Add task editing functionality"
git push origin feature/task-editing
```

 Then create a pull request on GitHub.

 ### Contribution Guidelines

 When contributing to the project:

 - Keep the code readable.
- Use descriptive variable and function names.
- Avoid unnecessary duplication.
- Validate user input.
- Keep related functionality organized.
- Test changes before submitting a pull request.
- Follow the existing project structure where practical.

---

 ## Roadmap

 - [x] Add tasks
- [x] View tasks
- [x] Mark tasks as completed
- [x] Unmark completed tasks
- [x] Delete tasks
- [x] Track completed task count
- [x] Basic input validation
- [ ] Edit tasks
- [ ] Persistent file storage
- [ ] Replace fixed array with `std::vector`
- [ ] Search tasks
- [ ] Filter tasks
- [ ] Task priorities
- [ ] Due dates
- [ ] Improved input validation
- [ ] Confirmation before deletion
- [ ] Improved terminal UI
- [ ] Object-oriented redesign
- [ ] Database support

---

 ## License

 No license has currently been specified for this project.

 If you intend to distribute this project as open-source software, consider adding an appropriate license, such as the MIT License.

 A license file can be added to the repository as:

```
LICENSE
```

---

 ## Author

 **Assassin Cloud**

 A C++ command-line TODO application created as a practical project for learning and applying fundamental C++ programming concepts.

---

 ## Acknowledgements

 This project uses standard C++ functionality and does not require external libraries or frameworks.

 The application was built using standard components such as:

 - C++
- `<iostream>`
- `<string>`

---

 ## Final Notes

 The TODO App provides a simple foundation for learning C++ through a practical project.

 The current implementation focuses on the core operations required for a basic task manager:

```
Create
  ↓
View
  ↓
Complete / Uncomplete
  ↓
Delete
```

 The project can be progressively expanded with persistent storage, dynamic data structures, task editing, priorities, deadlines, searching, filtering, and object-oriented architecture.

```

```
