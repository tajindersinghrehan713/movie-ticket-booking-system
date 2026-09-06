# 🎬 Movie Ticket Booking System

A modular, Object-Oriented C++ system designed to simulate movie ticket reservations, seat allocations, dynamic pricing, and payment processing[cite: 1].

---

## 📌 Project Architecture & Modules

The codebase is designed using modular object-oriented principles, separating distinct responsibilities across multiple components[cite: 1]:

| Module | Responsibility |
| :--- | :--- |
| `01_Movie.cpp`[cite: 1] | Defines movie entities, titles, genres, and metadata[cite: 1]. |
| `02_Seat.cpp`[cite: 1] | Base representation of cinema hall seating[cite: 1]. |
| `03_Screen.cpp`[cite: 1] | Screen layout and capacity configuration[cite: 1]. |
| `04_Cinema.cpp`[cite: 1] | Cinema hall management and multiplex infrastructure[cite: 1]. |
| `05_Show.cpp`[cite: 1] | Show schedules, movie associations, and time slots[cite: 1]. |
| `06_ShowSeat.cpp`[cite: 1] | Dynamic seat states for individual show schedules (available, reserved, booked)[cite: 1]. |
| `07_Customer.cpp`[cite: 1] | User and customer information management[cite: 1]. |
| `08_Booking.cpp`[cite: 1] | Reservation logic, order creation, and status tracking[cite: 1]. |
| `09_Payment.cpp`[cite: 1] | Core payment contract and transaction handling[cite: 1]. |
| `10_PaymentTypes.cpp`[cite: 1] | Payment strategy implementations (UPI, Cards, Cash)[cite: 1]. |
| `11_PriceCalculator.cpp`[cite: 1] | Dynamic billing, seat pricing, and tax calculation[cite: 1]. |
| `12_TicketPrinter.cpp`[cite: 1] | Console-based ticket formatting and receipt printing[cite: 1]. |
| `13_BookingService.cpp`[cite: 1] | Orchestration layer connecting UI/input with business logic[cite: 1]. |
| `14_Snack.cpp`[cite: 1] | Concession stand items and add-on ordering[cite: 1]. |
| `main.cpp`[cite: 1] | Entry point driving interactive execution and menu flows[cite: 1]. |

---

## 📐 Design & Analysis Artifacts

The system is accompanied by design and requirement analysis models[cite: 1]:
* **Class Diagram**: UML structure detailing classes, attributes, methods, and relationships[cite: 1].
* **Sequence Diagram**: Interaction flow between customer, booking service, payment gateway, and show manager[cite: 1].
* **SOLID Mapping**: Breakdown detailing Single Responsibility, Open-Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion adherence[cite: 1].
* **Noun-Verb Analysis**: Domain requirement breakdown mapping entities to nouns and operations to verbs[cite: 1].

---

## 🚀 Getting Started

### Prerequisites
* A standard C++ compiler (`g++`, `clang++`, or MSVC) supporting C++11 or above.

### Compilation
Compile all modular source files into a single binary[cite: 1]:

```bash
g++ *.cpp -o movie_ticket_app
