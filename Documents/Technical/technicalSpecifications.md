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

</details>

## Project Summary

**PathQuick** is a high-performance software solution designed to calculate the quickest path between two landmarks in the United States. It leverages a robust C++ implementation to ensure optimal performance, exposes its functionality through a REST API, and supports flexible response formats. The system is tailored to handle large-scale datasets efficiently, adhering to strict performance and accuracy requirements.

## Technical Requirements

### Core Requirements

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

### Performance Goals

**Response Time**: API queries must complete within 1 second on a typical laptop.

**Approximation Heuristics**: Solutions may use heuristics to achieve speed, with the returned path being no more than 10% longer in duration than the shortest possible path.

### Data Integrity Verification

To ensure dataset reliability, the following checks must be performed:

- **Graph Validation**: Verify the file forms a Directed Acyclic Graph (DAG) free of loops.

- **Connectivity Check**: Ensure the graph is fully connected, allowing navigation between any two landmarks.

These checks are infrequent, allowing the use of a simpler and potentially less efficient algorithm. A language other than C++ may be used for this purpose.

## Expected Deliverables

**C++ Source Code**: Well-documented code with comments, limited to STL and libraries necessary for the Web server.

**Time and Space Complexity**: Provide Big O notation for the main algorithms.

**REST API Implementation**: Support for both XML and JSON response formats, demonstrating flexibility.

**Test Suite**: Comprehensive tests to validate correctness, performance, and compliance with the 10% approximation rule.

**Data Validation Tool**: A utility for verifying the integrity of the provided CSV file.
