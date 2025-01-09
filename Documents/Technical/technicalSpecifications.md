# Technical Specifications - PathQuick

<details>
<summary>Click to expand</summary>

- [Technical Specifications - PathQuick](#technical-specifications---pathquick)
  - [Project Summary](#project-summary)
    - [Technical Requirements](#technical-requirements)
      - [Core Requirements](#core-requirements)
      - [Performance Goals](#performance-goals)
      - [Data Integrity Verification](#data-integrity-verification)
    - [Expected Deliverables](#expected-deliverables)
  - [File tree and documents](#file-tree-and-documents)
  - [Hardware](#hardware)
  - [Main Program](#main-program)
    - [File Structure](#file-structure)
    - [C++ libraries](#c-libraries)
    - [C++ conventions](#c-conventions)
      - [Classes](#classes)
    - [REST API](#rest-api)
  - [Glossary](#glossary)

</details>

## Project Summary

**PathQuick** is a high-performance software solution designed to calculate the quickest path between two landmarks in the United States. It leverages a robust C++ implementation to ensure optimal performance, exposes its functionality through a REST API, and supports flexible response formats. The system is tailored to handle large-scale datasets efficiently, adhering to strict performance and accuracy requirements.

### Technical Requirements

#### Core Requirements

**Programming Language**: The software must be implemented in C++ to achieve optimal performance.

**REST API Specification**: The solution will provide a REST API running on an HTTP server (localhost) with the following features:

- **Input**: Accepts IDs of the source and destination landmarks.

- **Output**: Returns the travel time and an ordered list of landmarks in the path.

- **Response Formats**: Supports both XML and JSON for response payloads.

**Data Source**: The system will process a file (USA-roads.csv) containing approximately 24 million nodes. Each line represents a bidirectional connection between two landmarks with a specified travel time. The format is as follows:

```csv
Landmark_A_ID,Landmark_B_ID,Time
```

Connections are bidirectional, implying if a connection exists from A to B, it also exists from B to A.

#### Performance Goals

**Response Time**: API queries must complete within 1 second on a typical laptop.

**Approximation Heuristics**: Solutions may use heuristics to achieve speed, with the returned path being no more than 10% longer in duration than the shortest possible path.

#### Data Integrity Verification

To ensure dataset reliability, the following checks must be performed:

- **Graph Validation**: Verify the file forms a Directed Acyclic Graph (DAG) free of loops.

- **Connectivity Check**: Ensure the graph is fully connected, allowing navigation between any two landmarks.

These checks are infrequent, allowing the use of a simpler and potentially less efficient algorithm. A language other than C++ may be used for this purpose.

### Expected Deliverables

**C++ Source Code**: Well-documented code with comments, limited to STL and libraries necessary for the Web server.

**Time and Space Complexity**: Provide Big O notation for the main algorithms.

**REST API Implementation**: Support for both XML and JSON response formats, demonstrating flexibility.

**Test Suite**: Comprehensive tests to validate correctness, performance, and compliance with the 10% approximation rule.

**Data Validation Tool**: A utility for verifying the integrity of the provided CSV file.

## File tree and documents

As written in the [naming conventions](./conventions.md), folders are written in PascalCase and files are written in camelCase.

```md
2023-2024-project-2-serious-game-team-6
├─── Documents
│   ├─── Functional
│   │   ├─── (other files...)
│   │   └─── functionalSpecifications.md
│   ├─── Management
│   │   ├─── (other files...)
│   │   └─── projectCharter.md
│   ├─── Manuals
│   │   ├─── (other files...)
│   │   └─── userManual.md
│   ├─── TestPlan
│   │   ├─── (other files...)
│   │   └─── testPlan.md
│   └─── Technical
│       ├─── (other files...)
│       └─── technicalSpecifications.md
├─── Src
├─── .gitignore
└─── README.md
```

## Hardware

These are all the hardware we'll use to develop the project:

- [**Apple MacBook Air - M3 10-core GPU**](https://www.apple.com/fr/shop/buy-mac/macbook-air/13-pouces-m3)
  - 13.6 inch (2560 x 1664)
  - RAM: 16.0 GB
  - macOS Ventura 13.0
  - Apple M3 Chip
  - Qwerty keyboard

- [**Lenovo Thinkbook 14**](https://pcsupport.lenovo.com/us/en/products/laptops-and-netbooks/thinkbook-series/thinkbook-14-iil/20sl)
  - Windows 11 Pro
  - 14-inch (1920 x 1080)
  - Processor: Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor

- [**ThinkPad E14 Gen 5**](https://www.lenovo.com/fr/fr/p/laptops/thinkpad/thinkpade/thinkpad-e14-gen-5-(14-inch-intel)/len101t0064)
  - Windows 11 Pro
  - 14-inch (1920 x 1080)
  - Processor: 13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor

## Main Program

The naming conventions are available [here](./conventions.md).

### File Structure

```md
Src
├─── main.cpp
├─── Api
│   ├─── Algorithm 
│   │   └─── (every necessary files to find the quickest path)
│   ├─── api.cpp
│   ├─── Bin 
│   │   └─── server
│   └─── JsonXml 
│       └─── (every necessary files to parse JSON & XML)
├─── Bin
│   └─── quickPath
└─── Headers
    ├─── Input
    │   └─── (every necessary files to get user input)
    └─── Display
        └─── (every necessary files to print data onto the console)
```

### C++ libraries

Some libraries will be needed to perform the project.

### C++ conventions

#### Classes

Classes must be declared in a dedicated header file, named with their class name.

Defining classes, Software Engineers must **encapsulate** data. Every variable of a class will be declared as *private*, and some methods will be declared as *public*. The public methods of a class can manipulate private data.
This prevents clients from directly accessing those information.

Creating an object of a class, a **constructor** must be called. It is named with its class name, and allocate data as soon as the object is created.

---

**Connections** will be the main point of the program. Every connection has a list of *identifiers* and a *time representation*.
Those data are provided in the .csv file and will be needed to be extracted.

./connection.hpp

```c++
class Connection {
    // protected data 
    private: 
    std::list<int> ids;
    int time;

    // accessible data
    public:
    /* constructor of the class
        Parameters: 
        - id1 (constant integer)
        - id2 (constant integer)
        - time (constant integer)
    */
    Connection(const int id1, const int id2, const int time) {
        this->ids.push_back(id1);
        this->ids.push_back(id2);
        this->time = time;
    }

    // other public methods...
}
```

### REST API

The REST API is another huge part of the project, where the .csv file data will be extracted.

The program will be able to **send requests** to this API.

For example: 
The program would need the connection between *landmark 3* and *landmark 9*. It will send a request with arguments (*landmark 3 and landmark 9 ids*) and the API will provide data, such as the time of the specific connection.

## Glossary

| Term | Link |
| -- | -- |
| **Encapsulation** is a mechanism that brings data and methods together within a structure by hiding the object's implementation, i.e. preventing access to the data by any means other than the proposed services. | [Wikipedia](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)) |
| **Constructor** is a special type of function called to create an object. It prepares the new object for use, often accepting arguments that the constructor uses to set required member variables. | [Wikipedia](https://en.wikipedia.org/wiki/Constructor_(object-oriented_programming)) |
| **REST (Representational State Transfer)** is a software architectural style that was created to guide the design and development of the architecture for the World Wide Web. | [Wikipedia](https://en.wikipedia.org/wiki/REST) |
| An **Application Programming Interface (API)** is a connection between computers or between computer programs. It is a type of software interface, offering a service to other pieces of software. | [Wikipedia](https://en.wikipedia.org/wiki/API) |
