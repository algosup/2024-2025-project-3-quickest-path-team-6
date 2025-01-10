# Management Artifacts - PathQuick

This document is used to centralize all the management artifacts as listed below:

- [Management Artifacts](#management-artifacts---pathquick)
    - [RACI Matrix](#raci-matrix)
    - [Risks \& Mitigations](#risks--mitigations)
    - [Key Performance Indicators](#key-performance-indicators)
    - [Weekly Reports](#weekly-reports)


## RACI Matrix

| Name                     | Project Manager | Program Manager | Technical Leader | Software engineer | Quality assurance | Technical Writer | Client |
| ------------------------ | --------------- | --------------- | ---------------- | ----------------- | ----------------- | ---------------- | ------ |
| Call for Tender          | I               | I               | I                | I                 | I                 | I                | R      |
| Project charter          | R               | A               | C                | C                 | C                 | C                | I      |
| Schedule creation        | R               | C               | C                | C                 | C                 | C                | /      |
| Functional specification | A               | R               | C                | /                 | C                 | /                | C      |
| Technical specification  | A               | C               | R/A              | I                 | C                 | /                | C      |
| Coding process           | A               | I               | R                | R/A               | C                 | /                | /      |
| Testing planification    | A               | /               | C                | C                 | R/A               | I                | /      |
| Usage instructions       | A               | C               | C                | C                 | I                 | R/A              | I      |

Legend:

| Letter | Full name   | Description                                     |
| ------ | ----------- | ----------------------------------------------- |
| R      | Responsible | Executes the task or activity                   |
| A      | Accountant  | Ultimately answerable for the task's completion |
| C      | Consulted   | Provides input and/or advice on the task        |
| I      | Informed    | Kept updated on progress and decisions          |
| /      | /           | No interaction with this role for this task     |

## Risks & Mitigations

| Risk | Consequence | Impact | Mitigation |
| --- | --- | --- | --- |
| A team member is absent | The progression of the project is slowed | High | Split the work evenly so if someone cannot work, other team members can work on it without problem |
| Faulty data in the USA-roads.csv file | The input dataset may have errors or inconsistencies | High | Develop a robust data validation tool to check for graph integrity before processing. |
| Memory inefficiency or suboptimal data structures. | The solution may not handle the scale of 24 million nodes efficiently. | High | Use memory-efficient data structure an streamline data parsing to load only necessary parts of the graph |

## Key Performance Indicators

To follow the progress of the project, multiple KPIs have been defined. They can be viewed through our [KPIs spread sheet](https://docs.google.com/spreadsheets/d/1eKVS6e0FwKcXLgHNbZsB1XYESFJWPV4A9yk-6R81024/edit?usp=sharing).

Our KPIs have been separated into different categories as followed:

- ### Documents
    - Project charter
    - Functional specifications
    - Technical specifications
    - Test plan
    - User manual

- ### Development
    - Program to verify the CSV file provided
    - The algorithm for the quickest path

## Weekly Reports

Each week will be resumed in weekly documents listed [here](WeeklyReports), or by following a precise week using the following links:

- [Week 1](WeeklyReports/weeklyReport1.md)
- [Week 2](WeeklyReports/weeklyReport2.md)
- [Week 3](WeeklyReports/weeklyReport3.md)
- [Week 4](WeeklyReports/weeklyReport4.md)
- [Week 5](WeeklyReports/weeklyReport5.md)
- [Week 6](WeeklyReports/weeklyReport6.md)