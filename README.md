# 🍽️ Restaurant Management System

A comprehensive C++ application for managing restaurant operations, featuring role-based access control, order management, and real-time table tracking. This project demonstrates advanced object-oriented programming principles and system design patterns.

## 🚀 Key Features

### 🔐 Role-Based Authentication
- **Admin Panel**: Full system oversight with access to all table orders
- **Server Access**: Table-specific order management and customer service
- Secure credential verification system

### 📋 Order Management
- **Dynamic Order Creation**: Add products with real-time pricing
- **Order Modification**: Remove items with automatic total recalculation
- **Order Tracking**: View detailed order summaries for each table
- **Financial Tracking**: Automatic total calculation and management

### 🏢 Multi-Table Support
- **Scalable Table System**: Support for unlimited restaurant tables
- **Table State Management**: Independent order tracking per table
- **Real-time Updates**: Instant order status updates across the system

## 🛠️ Technical Architecture

### Object-Oriented Design Patterns
- **Encapsulation**: Private data members with controlled access through public methods
- **Composition**: Restaurant class composed of Mesa, Mesero, and Admin objects
- **Polymorphism**: Role-based access control through inheritance patterns

### Core Classes
```cpp
├── Restaurante     # Main system controller
├── Admin          # Administrator role with full system access
├── Mesero         # Server role with table management capabilities
├── Mesa           # Table management and order tracking
└── Producto       # Product data structure
```

### Memory Management
- **RAII Principles**: Resource Acquisition Is Initialization
- **STL Containers**: Efficient use of `std::vector`, `std::map`, and `std::string`
- **No Memory Leaks**: Proper object lifecycle management

## 🔧 Technical Skills Demonstrated

### C++ Core Concepts
- ✅ **Object-Oriented Programming**: Classes, inheritance, encapsulation
- ✅ **STL Containers**: Dynamic arrays, associative containers, iterators
- ✅ **Memory Management**: Stack allocation, RAII principles
- ✅ **Exception Safety**: Bounds checking and error handling
- ✅ **Modern C++**: Use of auto keyword, range-based loops, const correctness

### Software Engineering Practices
- ✅ **Modular Design**: Separation of concerns across multiple files
- ✅ **Header Guards**: Prevention of multiple inclusions
- ✅ **Clean Code**: Meaningful variable names and function signatures
- ✅ **Documentation**: Clear code structure and comments

## 🏗️ System Architecture

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│     Admin       │    │     Mesero      │    │   Restaurante   │
│                 │    │                 │    │                 │
│ - Credentials   │    │ - Credentials   │    │ - Mesas Map     │
│ - View All      │────┤ - Table Access  │────┤ - Meseros List  │
│   Orders        │    │ - Order Mgmt    │    │ - Admin Object  │
└─────────────────┘    └─────────────────┘    └─────────────────┘
         │                       │                       │
         └───────────────────────┼───────────────────────┘
                                 │
                    ┌─────────────────┐    ┌─────────────────┐
                    │      Mesa       │    │    Producto     │
                    │                 │    │                 │
                    │ - Order Vector  │────┤ - Name & Price  │
                    │ - Total Calc    │    │ - Getters       │
                    │ - Order Mgmt    │    │                 │
                    └─────────────────┘    └─────────────────┘
```

## 🚦 Getting Started

### Prerequisites
- C++11 compatible compiler (GCC, Clang, MSVC)
- Standard Template Library (STL)

### Compilation
```bash
# Using g++
g++ -std=c++11 -Wall -Wextra -o restaurant *.cpp

# Using clang++
clang++ -std=c++11 -Wall -Wextra -o restaurant *.cpp

# Using Visual Studio (Windows)
cl /std:c++11 *.cpp /Fe:restaurant.exe
```

### Running the Application
```bash
./restaurant
```

## 💡 Usage Examples

### Admin Login
```
Username: admin
Password: adminpassword
```
**Capabilities:**
- View all table orders
- System-wide oversight
- Financial reporting

### Server Login
```
Username: Paco
Password: paco123
```
**Capabilities:**
- Add products to orders
- Remove items from orders
- Print order summaries
- Manage specific tables

## 🎯 Business Logic Features

### Order Processing Workflow
1. **Authentication**: Role-based login system
2. **Table Selection**: Choose specific table for order management
3. **Product Management**: Add/remove items with real-time pricing
4. **Order Tracking**: View complete order details and totals
5. **Session Management**: Secure logout functionality

### Data Integrity
- **Automatic Recalculation**: Order totals update automatically
- **Bounds Checking**: Safe array access and modification
- **State Consistency**: Synchronized data across all operations

## 📊 Performance Characteristics

- **Time Complexity**: O(1) table access, O(n) order operations
- **Space Complexity**: O(m*n) where m = tables, n = average orders per table
- **Scalability**: Designed for small to medium restaurant operations
