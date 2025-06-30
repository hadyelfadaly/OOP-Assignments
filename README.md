# Flight Management System (Assignment 1)

A comprehensive C++ flight reservation system that allows users to book seats, manage passengers, and handle flight operations with an interactive seating plan.


## Features

### User Features
- **Flight Details**: View complete flight information including seating plan
- **Passenger Search**: Search for passengers by name
- **Seat Availability**: Check and book available seats with visual seating plan
- **Interactive Booking**: Real-time seat selection with availability checking

### Admin Features
- **Passenger Management**: Add multiple passengers to flights
- **Passenger Removal**: Remove specific passengers from flights
- **Departure Time**: Set and update flight departure times
- **Flight Monitoring**: View updated flight details after modifications

### Technical Features
- **Dynamic Memory Management**: Efficient allocation and deallocation
- **Operator Overloading**: Custom operators for intuitive operations
- **Visual Seating Plan**: ASCII-based seat layout (A = Available, R = Reserved)
- **Data Persistence**: In-memory passenger and seat tracking

## System Architecture

### Class Structure
```
Flight
├── Private Members
│   ├── flightNum, seatCapacity, numOfBooked
│   ├── flightDest, departureTime
│   ├── passengersName[], seatingPlan[][]
│   ├── passengers[], seatNum (map)
│   └── Helper functions
└── Public Interface
    ├── Search functions
    ├── Passenger management
    ├── Display functions
    └── Overloaded operators

Passenger
├── Private Members
│   ├── name, ID
│   └── static passengerCount
└── Public Interface
    ├── Constructors
    ├── Getters
    └── Overloaded operators
```

## Technical Implementation

### Key Components

**Dynamic Memory Management**
- Dynamic arrays for passengers and seating plan
- Proper cleanup in destructors
- Memory-safe operations

**Seating Algorithm**
- 2D boolean array for seat tracking
- Row/column mapping system
- Visual representation generation

**Operator Overloading**
- `++`: Increase flight capacity
- `+=`: Add single passenger
- `--`: Remove last passenger
- `-=`: Remove multiple passengers
- `<<`: Display flight information

**Search Functionality**
- Name-based passenger search
- Seat availability checking
- Linear search implementation

## File Structure

```
project/
├── main.cpp          # Main program entry point
├── Flight.h          # Flight class declaration
├── Flight.cpp        # Flight class implementation
├── Passenger.h       # Passenger class declaration
└── Passenger.cpp     # Passenger class implementation
```

**Note**: This system is designed as a console application for demonstration purposes. It showcases object-oriented programming concepts, dynamic memory management, and interactive user interfaces in C++.

# Doctor Management System (Assignment 2)

A comprehensive C++ application for managing medical professionals, featuring polymorphic doctor types (Surgeons and Specialists) with specialized fee calculation and surgery scheduling capabilities.

##  Features

### Core Functionality
- **Multi-Doctor Management**: Handle multiple doctors with different specializations
- **Polymorphic Design**: Abstract base class with specialized implementations
- **Dynamic Fee Calculation**: Different billing methods for surgeons vs specialists
- **Surgery Scheduling**: Complete surgery management for surgeons
- **File Output**: Automatic report generation to `doctors.txt`

### Doctor Types
- **Surgeons**: 
  - Hourly rate billing system
  - Surgery schedule management
  - Patient appointment tracking
- **Specialists**: 
  - Quarter-hour rate billing system
  - Specialization tracking
  - Consultation-focused workflow

### Technical Features
- **Object-Oriented Design**: Inheritance, polymorphism, and encapsulation
- **Dynamic Memory Management**: Safe allocation and deallocation
- **Pure Virtual Functions**: Abstract interface enforcement
- **File I/O Operations**: Persistent data storage
- **Const Correctness**: Immutable getter methods

## 🏗️ System Architecture

### Class Hierarchy
```
Doctor (Abstract Base Class)
├── Protected Members
│   ├── id, name, duration, rate
│   └── Virtual methods
├── Pure Virtual Functions
│   ├── setSurgery()
│   └── printSurgeries()
└── Derived Classes
    ├── Surgeon
    │   ├── Surgery scheduling
    │   ├── Hourly billing (rate per 60 min)
    │   └── Patient management
    └── Specialist
        ├── Specialization tracking
        ├── Quarter-hour billing (rate per 15 min)
        └── Consultation management

surgerySchedule (Supporting Class)
├── Patient name tracking
├── Surgery date management
└── Getter/Setter methods
```

### Design Patterns
- **Template Method Pattern**: Base fee calculation with specialized implementations
- **Polymorphism**: Runtime type determination for doctor operations
- **Aggregation**: Surgeon contains surgerySchedule objects
- **Encapsulation**: Private data with controlled access

## Installation & Setup

1. **Clone the repository**
2. **Compile the project**
3. **Run the application**

## File Structure

```
project/
├── main.cpp              # Main program entry point
├── Doctor.h              # Abstract base class declaration
├── Doctor.cpp            # Base class implementation
├── Surgeon.h             # Surgeon class declaration
├── Surgeon.cpp           # Surgeon class implementation
├── Specialist.h          # Specialist class declaration
├── Specialist.cpp        # Specialist class implementation
├── surgerySchedule.h     # Surgery scheduling class declaration
├── surgerySchedule.cpp   # Surgery scheduling implementation
└── doctors.txt           # Generated output file
```

## Technical Implementation

### Key Design Decisions

**Abstract Base Class**
```cpp
class Doctor {
protected:
    string id, name;
    int duration;
    double rate;
public:
    virtual double calculateTotalFee() const;
    virtual string PrettyPrint() const;
    virtual void setSurgery(int index, const surgerySchedule& surgery) = 0;
    virtual void printSurgeries(ostream &strm) const = 0;
};
```

**Polymorphic Fee Calculation**
- Surgeons: Hourly rate system for complex procedures
- Specialists: Quarter-hour rate for consultations

**Memory Management**
- Dynamic array allocation for surgeries
- Proper cleanup in destructors
- Copy constructor for deep copying

**File I/O Integration**
- Unified output stream handling
- Both console and file output support
- Structured data formatting

## Learning Objectives

This project demonstrates:
- **Object-Oriented Programming**: Inheritance, polymorphism, encapsulation
- **Abstract Classes**: Pure virtual functions and interface design
- **Dynamic Memory Management**: Pointers, arrays, and proper cleanup
- **File I/O Operations**: Reading from and writing to files
- **Design Patterns**: Template method and factory patterns
- **Professional Code Structure**: Header/implementation separation

**Note**: This system demonstrates advanced C++ concepts including polymorphism, abstract classes, and dynamic memory management. It serves as an excellent example of object-oriented design principles in healthcare management software.