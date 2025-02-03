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
  - [File Tree And Documents](#file-tree-and-documents)
  - [Hardware](#hardware)
  - [Main Program](#main-program)
    - [File Structure](#file-structure)
    - [C++ Libraries](#c-libraries)
      - [Standard Libraries](#standard-libraries)
      - [Specific Libraries](#specific-libraries)
    - [C++ Conventions](#c-conventions)
      - [Classes](#classes)
    - [Rest Api](#rest-api)
    - [Algorithm](#algorithm)
      - [Input Processing](#input-processing)
      - [Core Algorithm](#core-algorithm)
      - [Output Generation](#output-generation)
      - [Advanced Features](#advanced-features)
      - [Big-O Complexity](#big-o-complexity)
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

**Response Time**: API queries must be completed within 1 second on a typical laptop.

**Approximation Heuristics**: Solutions may use heuristics to achieve speed, with the returned path being no more than 10% longer in duration than the shortest possible path.

#### Data Integrity Verification

To ensure dataset reliability, the following checks must be performed:

- **Graph Validation**: Verify the file forms a Directed Acyclic Graph (DAG) free of loops.

- **Connectivity Check**: Ensure the graph is fully connected, allowing navigation between any two landmarks.

These checks are infrequent, allowing the use of a simpler and potentially less efficient algorithm. A language other than C++ may be used for this purpose.

### Expected Deliverables

**C++ Source Code**: Well-documented code with comments, limited to STL and libraries necessary for the Web server.

**Time And Space Complexity**: Provide Big O notation for the main algorithms.

**REST API Implementation**: Support for both XML and JSON response formats, demonstrating flexibility.

**Test Suite**: Comprehensive tests to validate correctness, performance, and compliance with the 10% approximation rule.

**Data Validation Tool**: A utility for verifying the integrity of the provided CSV file.

## File Tree And Documents

As written in the [naming conventions](./conventions.md), folders are written in PascalCase, and files are written in camelCase.

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
├─── Client
│   ├─── Bin
│   │   ├─── pathQuick (client's binary file)
│   │   ├─── pathQuick.exe (client's executable file)
│   │   ├─── pathQuick.json (JSON file to store outputs)
│   │   ├─── pathQuick.xml (XML file to store outputs)
│   ├─── Display
│   │   └─── display.hpp (prints data onto the console)
│   ├─── Input
│   │   └─── userInput.hpp (gets user inputs)
│   ├─── Includes
│   │   └─── includes.hpp (gets user inputs)
│   ├─── main.cpp (main program)
│   └─── request.hpp (sending request program)
│   ├─── startClient.cmd (main program's build file for Windows)
│   └─── startClient.sh (main program's build file for macOS)
├─── Libraries
│   ├─── Nlohmann (JSON library)
│   └─── Tinyxml2 (XML library)
├─── Server 
│   ├─── Algorithm
│   │   ├─── algorithm.hpp (processes the pathfinding)
│   │   └─── loadData.hpp (loads and organizes .csv file's data)
│   ├─── Api
│   │   ├─── api.cpp (elaborates the API's functionalities)
│   │   ├─── api.hpp (sets the API functionalities)
│   │   └─── server.cpp (server's main program)
│   ├─── Bin
│   │   ├─── server (server's binary file)
│   │   └─── server.exe (server's executable file)
│   ├─── DataValidation
│   │   └─── validateCsv.cpp (validation tool's program)
│   └─── Formatting 
│   │   ├─── conversionJson.hpp (converts data into appropriate format)
│   │   └─── conversionXml.hpp (converts data into appropriate format)
│   ├─── startServer.cmd (server's build file for Windows)
│   ├─── startServer.sh (server's build file for macOS)
│   ├─── startValidation.cmd (validation tool's build file for Windows)
│   └─── startValidation.sh (validation tool's build file for macOS)
├─── pathQuickLauncher.cmd (server's build file for Windows)
├─── pathQuickLauncher.sh (server's build file for macOS)
└─── USA-roads.csv (.csv file where the data is)
```

### C++ Libraries

Some libraries will be needed to perform the project.

#### Standard Libraries

A huge amount of these **STL libraries** need the namespace `std`.
A namespace is called like this:

```c++
using namespace std;
```

1. **`<iostream>`**: Part of the input/output library, enabling console input and output operations.

- `std::cout`, prints strings and variables to the console.
- `std::endl`, inserts a newline character and flushes the output buffer.
- `std::cin`, retrieves user input from the console and stores it into variables.

2. **`<string>`**: This library provides the string class, which allows the handling of dynamic text sequences.

- `std::string`, as a flexible container for storing and manipulating sequences of characters.
  
Useful for text processing, string concatenation, and manipulation.

3. **`<vector>`**: Provides the vector container, a dynamic array-like structure that allows the efficient resizing of elements.

- `std::vector<T>`: A sequence container that encapsulates dynamic arrays. The `T` stands for the data type, which needs to be specified.

Supports dynamic resizing, random access, and fast insertions and deletions at the end.
Often used for handling lists of items when the size may change during execution.

4. **`<sstream>`**: Provides string stream functionality for reading and writing strings as streams.

- `std::stringstream`: A stream class to operate on strings, enabling the parsing and formatting of data from and to strings.

Useful for data conversion (e.g., string to integer) and for constructing formatted strings from variables.

5. **`<fstream>`**: Enables file stream operations for reading from and writing to files.

- `std::ifstream`: Input file stream, used for reading from files.
- `std::ofstream`: Output file stream, used for writing to files.
- `std::fstream`: A combination of both input and output file stream.

These classes provide functionality for file handling in a platform-independent manner.

6. **`<queue>`**: Provides the queue container, which implements a FIFO (First In, First Out) data structure.

- `std::queue<T>`: A container adapter that provides a queue interface.

Commonly used in situations where you need to process elements in the order they were added, such as reconstructing the path the algorithm formed.

7. **`<unordered_map>`**: Implements a hash table-based associative container for storing key-value pairs.

- `std::unordered_map<Key, T>`: A container that stores pairs of keys and values, allowing fast access by key.

Offers average constant-time complexity for searching, inserting, and deleting elements.
Useful when you need efficient lookups and don't care about the order of elements.

8. **`<limits>`**: Provides information about the properties of arithmetic types (such as the maximum and minimum values).

- **`std::numeric_limits<T>`**: Template class to access the limits of different types (e.g., maximum or minimum values for int, double).

Commonly used for checking type boundaries and handling edge cases in computations.

9. **`<chrono>`**: Provides utilities for working with time and durations.

- `std::chrono::duration`: Represents time intervals (e.g., seconds, milliseconds).
- `std::chrono::high_resolution_clock`: A clock with the highest available precision for measuring time intervals.

Useful for performance measurements and time calculations.

#### Specific Libraries

1. **`<nlohmann>`** is a C++ library used to handle JSON writing/reading. We'll use it to write the list of landmarks of the path in JSON format including `#include <nlohmann/json.hpp>`.

With this library, we will be able to use:

```c++
// Convert path to JSON
nlohmann::json jsonData = path;
```

It will actually convert the path data into JSON data, allowing us to write easily into JSON format.

2. **`<tinyxml2>`** is a C++ library used to handle XML writing/reading. We'll use it to write the list of landmarks of the path in XML format including `#include <tinyxml2.h>`.

With this library, we will be able to use:

```c++
// Create an XML document
tinyxml2::XMLDocument xmlDoc;
```

It will actually create an XML document, allowing us to write easily into it in XML format.

**Installation**

For some reason, those libraries create some OS-related issues. For ease of use, we moved the libraries into the project directory.

Even though, here are the steps to install properly the libraries:

*macOS*:

```bash
brew install nlohmann-json
brew install tinyxml2
```

*Windows*:

1. **Install MSYS2** (A Package Manager for Windows) *MSYS2* is a great way to install libraries and packages on Windows, similar to how Homebrew works on macOS.

- [Download and install MSYS2](https://www.msys2.org/).
- After installing MSYS2, open the MSYS2 terminal and update the system:

```sh
pacman -Syu  # Updates the MSYS2 system
pacman -Su   # Ensures everything is up-to-date
```

2. **Install the libraries** with MSYS2: MSYS2 provides a package for `nlohmann-json` and `tinyxml2` via the mingw-w64-x86_64 repository.

- Run this command in the MSYS2 terminal to install `nlohmann-json`:

```sh
pacman -S mingw-w64-x86_64-nlohmann-json
```

- Run this command in the MSYS2 terminal to install `tinyxml2`:

```sh
pacman -S mingw-w64-x86_64-tinyxml2
```

This will install both `nlohmann-json` and `tinyxml2` headers in your MSYS2 environment. It also ensures the libraries and headers are available for compilation.

### C++ Conventions

#### Classes

Classes must be declared in a dedicated header file, named with their class name.

Defining classes, Software Engineers must **encapsulate** data. Every variable of a class will be declared as *private*, and some methods will be declared as *public*. The public methods of a class can manipulate private data.
This prevents clients from directly accessing that information.

In creating an object of a class, a **constructor** must be called. It is named with its class name, and allocates data as soon as the object is created.

---

**Connections** will be the main point of the program. Every connection has a list of *identifiers* and a *time representation*.
Those data are provided in the .csv file and will need to be extracted.

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

### Rest Api

The REST API serves as a critical program for the software, enabling efficient extraction and interaction with data stored in the .csv file. The API operates on a **localhost server**, restricting access to the host machine for enhanced security and development simplicity.

**Base URL**:

The API's base URL is: `http://localhost:8080`

**Route Calculation Endpoint**:

- URL Format: `/route`
- Description: Calculates the quickest path between two landmarks based on their IDs.
- Request Method: `GET`
- Parameters:
  - `source` (*Required*): Landmark ID of the starting point.
  - `destination` (*Required*): Landmark ID of the endpoint.
  - `format` (*Required*): Specifies the response format. Accepts XML or JSON.
- Example Request:
  `curl "http://localhost:8080/route?source=1&destination=2&format=json"`

**Response Structure**:

As responses will be available in both JSON and XML formats, the response structure should fit the format.

JSON:

<img src="https://github.com/user-attachments/assets/bf960afa-61c8-459a-9d84-950a810e9e9c" width=250>

XML:

<img src="https://github.com/user-attachments/assets/02773b24-5621-4d9e-88de-63333a37304a" width=250>

**Error Handling**:

- *Invalid Parameters*: Returns a `400` Bad Request.
- *Resource Not Found*: Returns a `404` Not Found.
- *Server Error*: Returns a `500` Internal Server Error.

Here's how the server interacts with the other components:

<img src="https://github.com/user-attachments/assets/d1c40d6f-4710-4eae-9dae-d5ed9d7a95d1" width=500>

### Algorithm

To determine which path is the quickest, we'll need to create an algorithm.
Here's a detailed look at how it would operate:

#### Input Processing

**Data Validation**:

The algorithm can validate the input data from the `USA-roads.csv` file.
It checks for missing or malformed entries, ensures the graph is bidirectional, and verifies connectivity between landmarks.

#### Core Algorithm

To perform the algorithm, we would need to create a weighted graph.

**Graph Construction**:

A weighted graph is constructed, where:

Several global nodes are determined as the graphs' edges.
These nodes are connected to every single node, and connections are stored in a list.

The edges are handled as a structure:

```c++
struct Edge {
    int to; // the landmark it is connected to
    double time; // the travel time between both landmarks
};
```

The global nodes are determined through a simple calculation process:

- The first node is chosen randomly.

<img width="250" src="https://github.com/user-attachments/assets/c0f3425d-dd8b-4286-8fb1-b99d9c021f8c" />

- Then, the second node is the furthest away from the first one.

<img width="250" src="https://github.com/user-attachments/assets/175ade78-d762-4078-85e2-b4dea4d713ef" />

- And the following ones are the furthest away from the other ones.

<img width="250" src="https://github.com/user-attachments/assets/aeae0d9d-5393-449e-9d25-c34d709c1615" />

- Finally, we connect these global nodes to all the other ones.

<img width="250" src="https://github.com/user-attachments/assets/b738ec30-4239-4cae-8c9d-d3dca83a298f" />

- Since all nodes are connected to several global nodes, we can estimate the distance between two nodes in the graph by calculating the difference between their respective distances to a global node.

<img width="250" src="https://github.com/user-attachments/assets/7fa6c9a1-3445-4c37-bb91-d3b86ce8ca9d" />

- And with this estimation, we can perform the primary algorithm.

<img width="250" src="https://github.com/user-attachments/assets/89ddd532-cfd3-4cc3-836d-2fae10995d2e" />

**Shortest Path Calculation**:

PathQuick employs **Dijkstra's Algorithm** for precise and efficient route calculation.
When speed is critical for large datasets, a **Bidirectional Dijkstra** approach is utilized, reducing the computational time by simultaneously searching from the start and end points.

**Heuristic Optimization**:

For near-instant results, the A* (A-star) algorithm is leveraged with heuristic functions based on geographical distance.
This ensures routes are within 10% of the optimal shortest path while significantly reducing processing time.

#### Output Generation

**Route Formatting**:

Once the optimal path is determined, it is formatted as an ordered list of landmarks.
The list is converted into both XML and JSON data, in dedicated files.

To handle writing into the appropriate file formats, we would need the `nlohmann-json` and `tinyxml2` libraries. 
Refer to the [libraries part](#specific-libraries) for more information.

**Performance Metrics**:

Along with the route, PathQuick provides:

- *Travel Time*: The estimated time for the journey.
- *Landmark Highlights*: A summary of key locations along the path (in the JSON and XML files).

#### Advanced Features

**Scalability**:

The algorithm handles datasets with millions of nodes and edges, maintaining performance through efficient data structures.

**Error Handling**:

Robust mechanisms ensure graceful handling of invalid or incomplete queries, providing meaningful error messages or fallback routes.

#### Big-O Complexity

**Graph Construction**: *O(N²)*

**Pathfinding**:
- **O((V + E) log V)** (Dijkstra)
- **O((V + E)¹/² log V)** (Bidirectional Dijkstra)

For large graphs, **Bidirectional Dijkstra or A\*** will dominate, making the overall worst-case complexity:

**O((V + E)¹/² log V) + O(N²)**

If **E = O(V²)**, then the worst-case complexity simplifies to:

**O(V log V) + O(N²)**

Since **N ≈ V** (landmarks = nodes), the final complexity is approximately:

**O(N²) (graph construction) + O(N log N) (pathfinding)**

Overall, the dominant term is **O(N²)**, making this the worst-case complexity.

## Glossary

| Term | Link |
| -- | -- |
| **Standard Template Library** (STL) is a software library that provides a set of common classes for C++, such as containers and associative arrays. | [Wikipedia](https://en.wikipedia.org/wiki/Standard_Template_Library) |
| **Encapsulation** is a mechanism that brings data and methods together within a structure by hiding the object's implementation, i.e. preventing access to the data by any means other than the proposed services. | [Wikipedia](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)) |
| **Constructor** is a special type of function called to create an object. It prepares the new object for use, often accepting arguments that the constructor uses to set required member variables. | [Wikipedia](https://en.wikipedia.org/wiki/Constructor_(object-oriented_programming)) |
| **REST (Representational State Transfer)** is a software architectural style that was created to guide the design and development of the architecture for the World Wide Web. | [Wikipedia](https://en.wikipedia.org/wiki/REST) |
| An **Application Programming Interface (API)** is a connection between computers or between computer programs. It is a type of software interface, that offers a service to other pieces of software. | [Wikipedia](https://en.wikipedia.org/wiki/API) |
| **Dijkstra's Algorithm**  is an algorithm for finding the shortest paths between nodes in a weighted graph, which may represent, for example, a road network. | [Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) |
| **Big O notation** is a mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity. | [Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation) |
| A **weighted graph** is a graph where each edge has a numerical value called a weight. | [Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation) |
| A weighted graph in this context is made up of **nodes** (representing the points) which are connected by **edges** (representing the lines). | [Wikipedia](https://en.wikipedia.org/wiki/Graph_theory) |
