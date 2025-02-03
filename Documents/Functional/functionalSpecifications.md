# Functional Specifications

## Table Of Contents

<details>
<summary>Click to expand</summary>

- [Project Overview](#project-overview)
  - [Project Definition](#project-definition)
  - [Objectives](#objectives)
  - [Project Scopes](#project-scopes)
  - [Deliverables](#deliverables)
- [Stakeholders](#stakeholders)
  - [Project Roles](#project-roles)
  - [Other Stakeholders](#other-stakeholders)
- [Functional Requirements](#functional-requirements)
- [Dataset Requirements](#dataset-requirements)
  - [Dataset Structure](#dataset-structure)
  - [Usage In The Program](#usage-in-the-program)
- [UI Snapshots](#ui-snapshots)
  - [Main Menu](#main-menu)
  - [Find My Way](#find-my-way)
  - [Loading Screens](#loading-screens)
- [Personas](#personas)
- [Use Cases](#use-cases)
- [Non-Functional Requirements](#non-functional-requirements)
- [Available Resources](#available-resources)
  - [Learning Resources](#learning-resources)
- [Error Handling](#error-handling)
- [Future Improvements](#future-improvements)
  - [Call For Tender Compliant](#call-for-tender-compliant)
  - [Beyond Call For Tender](#beyond-call-for-tender)
- [Glossary](#glossary)

</details>

## Project Overview

### Project Definition

This project aims to create a software tool that calculates the fastest route between two landmarks in the United States. It will handle a large dataset and provide results through a user-friendly REST API supporting common data formats.

#### Objectives

- Develop a software solution to calculate the quickest path between two landmarks in the United States.
- Show functionality via a REST API supporting both JSON and XML response formats.
- Ensure the solution is optimized for a large-scale dataset (24 million nodes) and meets performance goals.

#### Project Scopes

| In Scope                                                                       |
| ------------------------------------------------------------------------------ |
| Implementing shortest-path calculation using efficient algorithms (e.g., A\*). |
| Creating a REST API with endpoints to look for the shortest paths.             |
| Processing input data from a required CSV file containing landmarks.           |
| Dataset validation to ensure graph integrity and connectivity.                 |

| Out of Scope                                                   |
| -------------------------------------------------------------- |
| Real-time updates to the dataset during API operation.         |
| User interface or front-end application for end-users.         |
| Advanced visualization tools or external database integration. |

#### Deliverables

| Name                      | Type                                | Deadline           |
| ------------------------- | ----------------------------------- | ------------------ |
| Functional Specifications | Documentation                       | February 7th 2025  |
| Technical Specification   | Documentation                       | February 7th 2025  |
| Management Documents      | Documentation                       | February 7th 2025  |
| C++ Source Code           | Fully commented code                | February 7th 2025  |
| REST API Implementation   | API supporting JSON/XML             | February 7th 2025  |
| Dataset Validation Tool   | Standalone utility                  | February 7th 2025  |
| Test Suite                | Detailed tests and testing strategy | February 7th 2025  |
| Oral Presentation         | Presentation                        | February 14th 2025 |

---

### Stakeholders

#### Project Roles

| Picture                                                                     | Full name          | Role              | Description                                                                                                                           | Links                                                                                                                |
| --------------------------------------------------------------------------- | ------------------ | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| <img src="https://avatars.githubusercontent.com/u/146000775?v=4" width=150> | Evan UHRING        | Project Manager   | Monitors the project's timeline and goals. Main coordinator between stakeholders and the team.                                        | [LinkedIn](https://www.linkedin.com/in/evan-uhring-72911b293/) [GitHub](https://github.com/Evan-UHRING)              |
| <img src="https://avatars.githubusercontent.com/u/146005062?v=4" width=150> | Manech LAGUENS     | Program Manager   | Makes sure the project meets expectation. Is responsible for writing the Functional Specifications                                    | [LinkedIn](https://www.linkedin.com/in/manech-laguens-020127293/) [GitHub](https://github.com/Manech-Laguens)        |
| <img src="https://avatars.githubusercontent.com/u/145991192?v=4" width=150> | Enzo GUILLOUCHE    | Technical Leader  | Makes the technical decision in the project. Translates the Functional Specification into Technical Specifications. Does code review. | [LinkedIn](https://www.linkedin.com/in/enzoguillouche/) [GitHub](https://github.com/EnzoGuillouche)                  |
| <img src="https://avatars.githubusercontent.com/u/169643790?v=4" width=150> | Pavlo PRENDI       | Software Engineer | Writes and tests code to implement project features. Participates in documentation and technical design discussions.                  | [LinkedIn](https://www.linkedin.com/in/pavlo-prendi-674777309/) [GitHub](https://github.com/PavloPrendi)             |
| <img src="https://avatars.githubusercontent.com/u/159240038?v=4" width=150> | Mariem ZAIANE      | Software Engineer | Writes and tests code to implement project features. Participates in documentation and technical design discussions.                  | [LinkedIn](https://www.linkedin.com/in/mariem-zaiane-2b2165225/) [GitHub](https://github.com/Mariem-Zaiane)          |
| <img src="https://avatars.githubusercontent.com/u/145995586?v=4" width=150> | Maxime THIZEAU     | Quality Assurance | Tests the product to identify and document bugs and issues. Creates test plans and verifies that fixes are implemented correctly.     | [LinkedIn](https://www.linkedin.com/in/maxime-thizeau-0b311a293/) [GitHub](https://github.com/MaximeTAlgosup)        |
| <img src="https://avatars.githubusercontent.com/u/71769656?v=4" width=150>  | Aurélien FERNANDEZ | Technical Writer  | Creates the user manual. Ensures all materials are clear and easy to understand for end users.                                        | [LinkedIn](https://www.linkedin.com/in/aurélien-fernandez-4971201b8/) [GitHub](https://github.com/aurelienfernandez) |

#### Other Stakeholders

| Name           | Role                        | Links                                  |
| -------------- | --------------------------- | -------------------------------------- |
| Franck JEANNIN | Client (ALGOSUP's director) | [Website](https://algosup.com/en.html) |

## Functional Requirements

**Shortest Path Calculation**

- Input: IDs of source and destination landmarks.
- Output:
  - Total travel time as an integer.
  - Ordered list of landmarks in the computed path.

**REST API**

- **Endpoint:** `GET /path`
- **Parameters:**
  - `source_id`: Starting landmark ID.
  - `destination_id`: Destination landmark ID.
- **Response Formats:**
  - JSON:
    ```JSON
    {
      "path": ["101", "303"],
      "time": 35
    }
    ```
  - XML:
    ```XML
    <response>
      <path>
        <landmark>101</landmark>
        <landmark>303</landmark>
      </path>
      <time>35</time>
    </response>
    ```

**Dataset Validation**

- Ensure the graph forms a Directed Acyclic Graph (DAG).
- Verify that the graph is fully connected (all nodes are reachable).

**Performances**

- Query responses must be generated in less than 1 second.
- Approximation of the result must not exceed 10% deviation from the shortest possible duration.

**User Data**

- The program should not require user data.

## Dataset Requirements

The program relies on the USA-roads.csv file to work. This file contains the links between landmarks and must be located in the src directory, or else it wont be detected.

### Dataset Structure

The dataset must follow this format:

```
StartPoint,EndPoint,Distance
1,2,5062
3,4,1035
6,5,359
7,8,5822
10,9,7211
11,12,6217
14,13,20
15,16,3481
17,18,3782
19,16,40717
```

- Start Point (ID): Identifies the starting landmark.
- End Point (ID): Identifies the destination landmark.
- Distance: Represents the “span” between the two landmarks in an abstract unit.

### Usage In The Program

- The dataset is used to create a directed graph, with nodes representing landmarks and edges representing connections between them.
- The Distance column is used by the shortest-path algorithm (A\*) to compute the quickest routes.

## UI Snapshots

### Main Menu

The main menu serves as the starting point for all user interactions. From here, users can:

- Calculate the quickest path between two landmarks.
- View the project contributors in the credits section.
- Exit the program and return to the console.

![image](https://github.com/user-attachments/assets/a19a7b4d-3885-4a48-ae41-45bd8b2fcc5e)

### Find My Way

This section allows users to input their desired departure and destination points to calculate the shortest path. Users must select values between 1 and 23,947,347.

- Step 1: Enter the departure number.
- Step 2: Enter the destination number.

Once both inputs are validated, the system processes the request to calculate the shortest path.

![image](https://github.com/user-attachments/assets/92539dc3-24ef-43b0-abda-81707ca8b876)

![image](https://github.com/user-attachments/assets/0c15e08e-09a7-41ba-9262-d8e7b5d9fcac)

### Loading Screens

After submitting the departure and destination numbers, the system calculates the shortest path and provides real-time feedback to the user with a simple loading screen.

Key details displayed during this process include:

- Confirmation of selected departure and destination points.
- Final results, including:
  - Total travel time.
  - Time taken for the calculation.
  - Confirmation that the data has been converted to JSON or XML formats and saved.

![image](https://github.com/user-attachments/assets/c2d45795-efab-4309-932e-3e2ede19e622)

## Personas

<img width="949" alt="personaPAGNAN" src="https://github.com/user-attachments/assets/cab0e867-d391-4787-896e-5db29e84e1f3" />

<img width="949" alt="personaLEE" src="https://github.com/user-attachments/assets/0e37228a-7aa7-42cb-8d2b-cac49e2c3667" />

<img width="949" alt="personaBroussard" src="https://github.com/user-attachments/assets/62c989bc-c874-4e3d-a6a9-3e9534bbeae9" />

## Use Cases

| Use case ID | Name                    | Description                                                                   | Pre-conditions                                       | Flow of events                                                                                                          | Exit criteria                                                             | Note                                |
| ----------- | ----------------------- | ----------------------------------------------------------------------------- | ---------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- | ----------------------------------- |
| 1           | PathQuick Menu          | The user wants to enter the PathQuick menu.                                   | Having the latest version downloaded and unzipped.   | - mac: execute start.sh<br>- windows: execute start.cmd                                                                 | You've entered the menu and can select an option.                         |                                     |
| 2           | Calculate Shortest Path | Input numbers to see the travel time between them.                            | Being on the menu.                                   | Type 1, then choose a departure and a destination number. Validate with 1 if your choice is correct to have the result. | Have access to the travel time, and calculation time.                     |                                     |
| 3           | Credits                 | The user wants to view the credits for the application.                       | The program is running, and the user is on the menu. | 1. User selects option 2 from the menu.<br>2. The system shows the contributors and tools used.                         | The user views the credits and can return to the main menu by pressing 0. |                                     |
| 4           | Exit to Console         | The user wants to leave the menu and return to the console.                   | The program is running, and the user is in the menu. | 1. User selects option 0 from the menu.<br>2. The system terminates and returns control to the console.                 | The program closes, and the terminal is ready for new commands.           | Ensure all processes are terminated |
| 5           | Validated Bin Output    | The user wants to check if JSON and XML files were created in the bin folder. | The program is running, and the user is in the menu. | The user goes into the Bin folder and checks if the files are here.                                                     | The user knows whether the JSON and XML files were successfully created.  |

## Non-Functional Requirements

**User Experience**

- The program should include a user interface, in which users can navigate and use features included in the latest release.
- The interface should be minimal and usable through a computer's terminal.
- The interface should be understandable enough so that the user does not need external help while using the program.

**User Interaction**

- The server should not take longer than a minute to set up itself.
- Between each human and machine interaction there should be a visual indicator that shows the program is still running, the user should not wait for more than 5 seconds to see a visual response.

**Portability**

- The program should work on MacOS, Windows and Linux.

## Available Resources

- **Total Hours:** 264 hours available to complete the project (from January 6 to February 7).
- **Team Members:** One computer per team member, as well as another one that will be used as a server.
- **Mentorship:** Support from [Georgios TSATIRIS](https://www.linkedin.com/in/georgios-tsatiris/), our computer science teacher.

---

### Learning Resources

To have a better understanding of C++, data structures, algorithms, and REST API development, the following resources were given to the students:

#### Videos

- [C++ Full Course - Beginner to Advanced](https://youtu.be/1v_4dL8l8pQ?si=CV35wdEOx1KCl-E3)  
  A comprehensive guide to learning C++ from scratch.
- [Introduction to Data Structures](https://youtu.be/wN0x9eZLix4?si=rBOmrNonypEmn5Kx)  
  A beginner-friendly overview of data structures.
- [Data Structures and Algorithms in C++](https://youtu.be/8hly31xKli0?si=xUAj3fC6d9h0oKAm)  
  Focused on practical implementations in C++.

#### Articles

- [An Open Guide to Data Structures and Algorithms](https://open.umn.edu/opentextbooks/textbooks/an-open-guide-to-data-structures-and-algorithms)  
  A free textbook for learning and reference.
- [REST API Introduction - GeeksforGeeks](https://www.geeksforgeeks.org/rest-api-introduction/)  
  Explains the basics of REST API and its use cases.
- [Building RESTful APIs with C++](https://medium.com/@AlexanderObregon/building-restful-apis-with-c-4c8ac63fe8a7)  
  Step-by-step guide to implementing REST APIs in C++.




## Error Handling

| Error Type           | Scenario                                                    | Message                                                  |
|----------------------|-------------------------------------------------------------|----------------------------------------------------------------|
| **Server Issues**    | The server fails to compile on Windows.                     | "Cannot compile."                                              |
|                      | The server fails to compile on MacOS.                       | "Cannot compile."                                              |
|                      | The server is not running when the user makes a request.   | "Server not connected. Wait until it is connected."            |
|                      | The server shuts down unexpectedly.                         | "The server shuts down."                                       |
|                      | The server disconnects while processing input.             | "Error: The server was disconnected while processing input."   |
| **Input Errors**     | The user provides a blank input.                            | "Source or destination cannot be empty."                      |
|                      | The user enters a number larger than 23,947,347.           | "Source or destination cannot be over 23,947,347."            |
|                      | The user enters a character instead of a number.           | "Invalid input! Expected a number from the list."             |
|                      | The user enters a string instead of a number.              | "Invalid input! Expected a number from the list."             |
|                      | The user enters a floating-point number.                   | "Source and destination need to be integers."                 |
|                      | The user enters a negative number.                         | "Source or destination cannot be under 1."                    |
|                      | The user enters zero as an input.                          | "Source or destination cannot be under 1."                    |
| **Algorithm Issues** | The algorithm does not return the shortest path.           | "No errors written, the algorithm isn't going in further steps." |
|                      | The program does not proceed to the next step as expected. | "Not going to the next step but no errors shown."             |
|                      | The response time exceeds the expected limit.              | "1 to 23,947,347 in 3 sec."                                   |
| **Output Format**    | The user requests an unsupported file format.              | "File format not recognized."                                  |
|                      | The XML and JSON files contain different data.             | "Mismatch in JSON and XML output."                            |
|                      | No external files are created for JSON/XML output.        | "The path is found but no external files were created."       |
| **Validation Tool**  | The CSV file contains duplicate entries.                    | "The program found two duplicates."                           |
|                      | The CSV file contains loops.                               | "The program returned a loop."                              |
|                      | The dataset is not fully connected.                        | "The program returned an error."                              |
|                      | The file format is incorrect.                              | "Invalid file format. Expected CSV."                         |




## Future Improvements

### Call For Tender Compliant

- Delivering results with full precision and zero error in path calculation.
- Reduce the memory usage.
- Introduce caching mechanisms for frequently requested routes.

### Beyond Call For Tender

- Implement a graphical interface accessible via a web browser for ease of use.
- Allow users to calculate shortest paths for different travel modes (bus, train, car, bicycle, walking).
- Enable users to define multiple waypoints between the start and destination.
- Allow users to choose different CSV datasets to adapt route calculations to different regions or transportation networks.



## Glossary

| Term Used                    | Definition                                                                                             |
| ---------------------------- | ------------------------------------------------------------------------------------------------------ |
| PathQuick                    | The name of the tool designed to calculate the shortest path between two landmarks.                    |
| JSON                         | Lightweight data-interchange format used to represent structured data in a readable format.            |
| XML                          | Markup language used to encode documents in a format that is both human-readable and machine-readable. |
| Dataset                      | Collection of data points, here representing landmarks and their connections.                          |
| DAG (Directed Acyclic Graph) | Graph with directed edges where no cycles are present, used for shortest-path calculations.            |
| REST API                     | Architectural style for designing networked applications that use standard HTTP methods.               |
| Landmark                     | Node or point in the dataset representing a location within the transportation network.                |
| A\*                          | Graph traversal and pathfinding algorithm that is widely used for shortest-path calculations.          |
| Bin Folder                   | Folder where the output files (e.g., JSON/XML results) are stored by the program.                      |

