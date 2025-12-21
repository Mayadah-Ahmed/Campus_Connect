# Campus Connect – Phase 3 Partial Implementation

## Project Overview
Campus Connect is a student community platform designed to help university students connect, share posts, and interact within their academic community.

This repository contains a **partial backend implementation** for **Phase 3** of the project, focusing on system design, object-oriented principles, and core functionalities.

---

## Implemented Features
- User Registration
- User Login (Authentication)
- Create Text Posts
- View All Posts

---

## Architecture
The system follows the **MVC (Model–View–Controller)** architecture:

- **Model**: Represents core entities such as User and Post.
- **Service**: Contains business logic (authentication, post management).
- **Controller**: Handles user interaction through a console-based interface.
- **Repository**: Abstracts data storage using interfaces (in-memory implementation).

---

## SOLID Principles
- **Single Responsibility Principle (SRP)**: Each class has a single responsibility.
- **Dependency Inversion Principle (DIP)**: Services depend on repository interfaces rather than concrete implementations.
- **Open/Closed Principle (OCP)**: New repository implementations can be added without modifying existing services.

---

## Technology Stack
- Language: C++
- Build System: CMake
- Architecture: MVC
- Programming Paradigm: Object-Oriented Programming (OOP)

---

## How to Build and Run
```bash
mkdir build
cd build
cmake ..
cmake --build .
./CampusConnect
