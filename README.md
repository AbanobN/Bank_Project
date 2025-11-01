# Bank ATM CLI (C++17)

A modern command-line ATM simulation written in **C++17**, showcasing *state machine architecture*, *RAII memory safety*, and *unit testing*.

## 🧠 Overview
This project simulates ATM operations (authentication, withdrawal, deposit, balance, transfer) using clean software architecture patterns.

## ⚙️ Tech Stack
- C++17 (STL, Smart Pointers, Exceptions)
- CMake
- Clang-Tidy / Sanitizers

## 🧩 Architecture
- **State Machine**: controls app flow (Idle → Auth → Menu → Transaction)
- **Repository Pattern**: for file-based account storage
- **Services Layer**: business rules for transactions
- **Tests**: cover account logic and auth edge cases


