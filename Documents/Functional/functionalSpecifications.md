# Functional Specifications

## Project Overview

### Project Definition

Our task is to create a tool that delivers precise results with the challenges of processing large datasets and ensuring smooth API integration. Its purpose is to provide a reliable solution tailored to transportation analysis and optimization needs.

#### Objectives

- Develop a software solution to calculate the quickest path between two landmarks in the United States.
- Show functionality via a REST API supporting both JSON and XML response formats.
- Ensure the solution is optimized for a large-scale dataset (24 million nodes) and meets performance goals.

#### Project Scopes

| In Scope                                                                       |
| ------------------------------------------------------------------------------ |
| Implementing shortest-path calculation using efficient algorithms (e.g., A\*). |
| Creating a REST API with endpoints to look for the shortest paths.             |
| Dataset validation to ensure graph integrity and connectivity.                 |

| Out of Scope                                                   |
| -------------------------------------------------------------- |
| Real-time updates to the dataset during API operation.         |
| User interface or front-end application for end-users.         |
| Advanced visualization tools or external database integration. |

#### Deliverables

| Name                      | Type                              | Deadline           |
| ------------------------- | --------------------------------- | ------------------ |
| Functional Specifications | Documentation                     | February 7th 2025  |
| Technical Specification   | Documentation                     | February 7th 2025  |
| Management Documents      | Documentation                     | February 7th 2025  |
| C++ Source Code           | Fully commented code              | February 7th 2025  |
| REST API Implementation   | API supporting JSON/XML           | February 7th 2025  |
| Dataset Validation Tool   | Standalone utility                | February 7th 2025  |
| Test Suite                | Detailed tests and testing strategy| February 7th 2025  |
| Oral Presentation         | Presentation                      | February 14th 2025 |

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
    ```json
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
  - Confirmation that the data has been converted to both JSON and XML formats and saved.

![image](https://github.com/user-attachments/assets/c2d45795-efab-4309-932e-3e2ede19e622)



## Personas

<img width="978" alt="persona1" src="https://github.com/user-attachments/assets/a93bfaa6-399f-43f6-ba20-425a093c1ee9" />

<img width="978" alt="persona2" src="https://github.com/user-attachments/assets/a8c051a2-f38d-4e5e-8116-9f7fa23913e3" />

<img width="978" alt="persona3" src="https://github.com/user-attachments/assets/fd50f3e2-fed6-4801-a3e6-01543b346e5b" />



## Non-Functional Requirements

**User Experience**

- The program should include a user interface, in which users can navigate and use features included in the latest release.
- The interface should be minimal and usable through a computer's terminal.
- The interface should be understandable enough so that the user does not need external help while using the program.

**User Interaction**

- The server should not take longer than a minute to set up itself.
- Between each human and machine interaction there should be a visual indicator that shows the program is still running, the user should not wait for more than 5 seconds to see a visual response.

**Portability**

- The program should work on MacOS and on Windows.

## Available Resources

- **Total Hours:** 264 hours available to complete the project (from January 6 to February 7).
- **Team Members:** One computer per team member, as well as another one that will be used as a server.
- **Mentorship:** Support from [Georgios Tsatiris](https://www.linkedin.com/in/georgios-tsatiris/), our computer science teacher.

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

<!-- MUST ADD:
Futur improvements
Complete glossary
 -->


## Use Cases

| Use case number | Name                    | Description                                                                   | Pre-conditions                                       | Flow of events                                                                                                          | Exit criteria                                                             | Note                                |
| --------------- | ----------------------- | ----------------------------------------------------------------------------- | ---------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- | ----------------------------------- |
| 1               | PathQuick Menu          | The user wants to enter the PathQuick menu.                                   | Having the latest version downloaded and unzipped.   | - mac: execute start.sh<br>- windows: execute start.cmd                                                                 | You've entered the menu and can select an option.                         |                                     |
| 2               | Calculate Shortest Path | Input numbers to see the travel time between them.                            | Being on the menu.                                   | Type 1, then choose a departure and a destination number. Validate with 1 if your choice is correct to have the result. | Have access to the travel time, and calculation time.                     |                                     |
| 3               | Credits                 | The user wants to view the credits for the application.                       | The program is running, and the user is on the menu. | 1. User selects option 2 from the menu.<br>2. The system shows the contributors and tools used.                         | The user views the credits and can return to the main menu by pressing 0. |                                     |
| 4               | Exit to Console         | The user wants to leave the menu and return to the console.                   | The program is running, and the user is in the menu. | 1. User selects option 0 from the menu.<br>2. The system terminates and returns control to the console.                 | The program closes, and the terminal is ready for new commands.           | Ensure all processes are terminated |
| 5               | Validated Bin Output     | The user wants to check if JSON and XML files were created in the bin folder. | The program is running, and the user is in the menu. | The user goes into the Bin folder and checks if the files are here.                                                        | The user knows whether the JSON and XML files were successfully created.  |                                     |






## Glossary

| Term Used                    | Definition                                                                                                  |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------- |
| PathQuick                    | The name of the tool designed to calculate the shortest path between two landmarks.                         |
| JSON                         | A lightweight data-interchange format used to represent structured data in a readable format.               |
| XML                          | A markup language used for encoding documents in a format that is both human-readable and machine-readable. |
| Dataset                      | A collection of data points, here representing landmarks and their connections.                             |
| DAG (Directed Acyclic Graph) | A graph with directed edges where no cycles are present, used for shortest-path calculations.               |
| REST API                     | An architectural style for designing networked applications that use standard HTTP methods.                |
| Landmark                     | A node or point in the dataset representing a location within the transportation network.                   |
| A*                          | A graph traversal and pathfinding algorithm that is widely used for shortest-path calculations.             |
| Bin Folder | Folder where the output files (e.g., JSON/XML results) are stored by the program.
