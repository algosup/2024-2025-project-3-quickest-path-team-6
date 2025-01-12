# Functional specifications

## Project Roles
| Picture | Full name       | Role               | Links                                                             |
| ----- | --------------- | ------------------------ | ----------------------------------------------------------------- |
| <img src="https://avatars.githubusercontent.com/u/146000775?v=4" width=150> | Evan UHRING | Project manager | [LinkedIn](https://www.linkedin.com/in/evan-uhring-72911b293/) [GitHub](https://github.com/Evan-UHRING) |
| <img src="https://avatars.githubusercontent.com/u/146005062?v=4" width=150> | Manech LAGUENS | Program manager | [LinkedIn](https://www.linkedin.com/in/manech-laguens-020127293/) [GitHub](https://github.com/Manech-Laguens)  |
| <img src="https://avatars.githubusercontent.com/u/145991192?v=4" width=150> | Enzo GUILLOUCHE | Tech lead| [LinkedIn](https://www.linkedin.com/in/enzoguillouche/) [GitHub](https://github.com/EnzoGuillouche) |
| <img src="https://avatars.githubusercontent.com/u/169643790?v=4" width=150> | Pavlo PRENDI | Software engineer | [LinkedIn](https://www.linkedin.com/in/pavlo-prendi-674777309/) [GitHub](https://github.com/PavloPrendi) |
| <img src="https://avatars.githubusercontent.com/u/159240038?v=4" width=150> | Mariem ZAIANE | Software engineer | [LinkedIn](https://www.linkedin.com/in/mariem-zaiane-2b2165225/) [GitHub](https://github.com/Mariem-Zaiane) |
| <img src="https://avatars.githubusercontent.com/u/145995586?v=4" width=150> | Maxime THIZEAU | Quality assurance | [LinkedIn](https://www.linkedin.com/in/maxime-thizeau-0b311a293/) [GitHub](https://github.com/MaximeTAlgosup) |
| <img src="https://avatars.githubusercontent.com/u/71769656?v=4" width=150> | Aurélien FERNANDEZ | Tech writer | [LinkedIn](https://www.linkedin.com/in/aurélien-fernandez-4971201b8/) [GitHub](https://github.com/aurelienfernandez) |
## Glossary
|therm used | Definition|
|--------|---------|
| ddd | dddd
## Functional Requirements 

## Project Overview

### **Project Definition**

#### **Objectives**
- Develop a high-performance software solution to calculate the quickest path between two landmarks in the United States.
- Expose functionality via a REST API supporting both JSON and XML response formats.
- Ensure the solution is optimized for a large-scale dataset (24 million nodes) and meets performance goals.

#### **Scope**
| **In Scope**                                                                 | **Out of Scope**                                                                 |
| ---------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| Implementing shortest-path calculation using efficient algorithms (e.g., A*). | Real-time updates to the dataset during API operation.                           |
| Creating a REST API with endpoints to look for the shortest paths.                  | User interface or front-end application for end-users.                          |
| Dataset validation to ensure graph integrity and connectivity.               | Advanced visualization tools or external database integration.                  |

#### **Deliverables**
| **Name**                       | **Type**               | **Deadline**           |
| ------------------------------ | ---------------------- | ---------------------- |
| Functional Specifications Document | Documentation         | February 7th 2025         |
| Technical Specification Document | Documentation | February 7th 2025 |
|Management Documents | Documentation | February 7th 2025 |
| C++ Source Code                | Fully commented code   | February 7th 2025         |
| REST API Implementation        | API supporting JSON/XML| February 7th 2025         |
| Dataset Validation Tool        | Standalone utility     | February 7th 2025         |
| Test Suite                     | Comprehensive tests and test plan  | February 7th 2025         |
| Oral Presentation | Presentation | February 14th 2025 |

---

## **Functional Requirements**

### **Core Functional Requirements**
1. **Shortest Path Calculation**
   - Input: IDs of source and destination landmarks.
   - Output:
     - Total travel time as an integer.
     - Ordered list of landmarks in the computed path.

2. **REST API**
   - **Endpoint:** `GET /path`
   - **Parameters:**
     - `source_id`: Starting landmark ID.
     - `destination_id`: Destination landmark ID.
   - **Response Formats:**
     - JSON:
       ```json
       {
         "time": 35,
         "path": ["101", "205", "303"]
       }
       ```
     - XML:
       ```xml
       <response>
         <time>35</time>
         <path>
           <landmark>101</landmark>
           <landmark>205</landmark>
           <landmark>303</landmark>
         </path>
       </response>
       ```

3. **Dataset Validation**
   - Ensure the graph forms a Directed Acyclic Graph (DAG).
   - Verify that the graph is fully connected (all nodes are reachable).

4. **Performances**
   - Query responses must be generated in less than **1 second**.
   - Approximation of the result shouldn't exceed **10% deviation** from the shortest possible duration.

---

