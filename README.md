# Food Delivery Management System

A minimal C++17 implementation of an online food‑delivery platform. The project demonstrates how to model customers, drivers, restaurants, menu items and orders using an object‑oriented design.

## ✨ Features
- **CRUD operations** for customers, drivers, restaurants and menu items
- **Order workflow** with automatic driver assignment
- **Static lookup utilities** to locate any entity by ID
- **Vector‑based storage** of entities for straightforward iteration and testing

## 📁 Project Layout
```text
.
├── Client.cpp / Client.h          # Customer entity
├── Driver.cpp / Driver.h          # Driver entity
├── Restaurant.cpp / Restaurant.h  # Restaurant and its menu
├── Item.cpp / Item.h              # Menu item definition
├── Order.cpp / Order.h            # Order contents and behaviour
├── Orderstatus.h                  # OrderStatus enum
├── FoodDelivery.cpp / FoodDelivery.h # Core management logic
└── main.cpp                       # Assertion-based example usage
```

## 🚚 Order Lifecycle
| Status        | Description        |
|---------------|--------------------|
| `ORDERED`     | Order created      |
| `PREPARING`   | Restaurant cooking |
| `SENT`        | Driver delivering  |
| `DELIVERED`   | Delivery complete  |

## ⚙️ Build
Ensure a compiler with C++17 support is installed (g++, clang++, or MSVC).

```bash
# Linux / macOS
g++ -std=c++17 main.cpp Client.cpp Driver.cpp FoodDelivery.cpp \
    Item.cpp Order.cpp Restaurant.cpp -o food_delivery

# Windows (MinGW)
g++ -std=c++17 main.cpp Client.cpp Driver.cpp FoodDelivery.cpp \
    Item.cpp Order.cpp Restaurant.cpp -o food_delivery.exe
```

Run the resulting binary (`./food_delivery` or `food_delivery.exe`).

> **Case sensitivity:** The project was originally created on a case‑insensitive platform. On Linux or macOS make sure each `#include` matches the exact file name.

## 🧪 Example Tests
`main.cpp` uses `assert` statements to demonstrate:
- Adding and removing customers, drivers and restaurants
- Creating orders, updating status and assigning drivers

Run the compiled program to execute these checks.

## 🔄 GitLab CI
```yaml
stages: [build]

build:
  stage: build
  image: gcc:latest
  script:
    - g++ -std=c++17 main.cpp Client.cpp Driver.cpp FoodDelivery.cpp \
          Item.cpp Order.cpp Restaurant.cpp -o food_delivery
    - ./food_delivery
```

## 📜 License
No license specified. All rights reserved — contact the author before redistribution or derivative work.
