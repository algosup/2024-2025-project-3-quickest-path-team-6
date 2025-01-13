# PathQuick - Test Plan

This project was requested by [ALGOSUP](https://algosup.com), a French computer science school.

The aim of this project is to create a quick pathfinding server according to a CSV file of USA-roads.

<details>
<summary>Table of Contents</summary>

- [Introduction](#introduction)
  - [Overview](#overview)
- [Testing Strategy](#testing-strategy)
  - [Quality Assurance Team](#quality-assurance-team)
  - [Testing Scope](#testing-scope)
    - [In Scope](#in-scope)
    - [Out Of Scope](#out-of-scope)
  - [Testing Types](#testing-types)
    - [Agile Testing](#agile-testing)
    - [Unit Testing](#unit-testing)
    - [Smoke Testing](#smoke-testing)
    - [System Testing](#system-testing)
    - [Compatibility Testing](#compatibility-testing)
- [Test Cases](#test-cases)
- [Testing Tools](#testing-tools)
  - [Hardware](#hardware)
  - [Software](#software)
- [Test Criteria](#test-criteria)
  - [Suspension Criteria](#suspension-criteria)
  - [Entry Criteria](#entry-criteria)
  - [Exit Criteria](#exit-criteria)
- [GitHub Actions](#github-actions)
- [GitHub Issues Report](#github-issues-report)
  - [Document Review](#document-review)
  - [Dev Review](#dev-review)
  - [Labels](#labels)
- [Testing Schedule And Estimation](#testing-schedule-and-estimation)
  - [Tasks Time Estimation](#tasks-time-estimation)
  - [Tasks Schedule](#tasks-schedule)
- [Test Deliverables](#test-deliverables)
- [Conclusion And Acknowledgments](#conclusion-and-acknowledgments)
- [Sources](#sources)
- [Glossary](#glossary)
    
</details>

## Introduction

### Overview

The team was asked to create a path finder according to a .csv file about the USA-roads. To implement it, a localhost server should be created as well as all the algorithm behind it.
It should return the time needed to complete the journey and a list of all the different landmarks it passes by.
Moreover, a validation tool should be created aside to verify the .csv file formating (LANDMARK_A__ID, LANDMARK_B_ID, TIME).

## Testing Strategy

The testing strategy would be sorted in two different categories. The first one would be dedicated to the code testing while the second one would be based on document testing.

**Code Testing Strategy**

Regarding the Code Testing Strategy, we decided to test the different versions of the code as early as possible.

This project requires a programm running on diverse operating system. However, the development team is only using Windows computer. Therefore, each time they have a working prototype on their own branches, they would merge them into the dev branch for the entire team to test it on their machine.

This would be considered as the first test.

However, other test would be done at periodic time. Hopefully, the more frequently possible. In the worst case, these tests would be done once a week.

Our testing strategy will mainly use the [agile testing](#agile-testing) strategy, to ensure no bugs come in between two different versions of our piece of software. However, this would not be the only method used. Some [unit tests](#unit-testing) would be written to test specific part of the code and would be run automatically during a pull request on the dev branch, thanks to [GitHub Actions](#github-actions). Finally, the QA team will also use some [smoke testing](#smoke-testing), [system testing](#system-testing) and [compatibility testing](#compatibility-testing). This would ensure the product would provide the critical functionalities and is compatible on every operating system.

**Documentation Testing Strategy**

The document testing would be done following the template previously done on the GitHub issue, a GitHub feature. You can fine a markdown version of this quoted template in the [GitHub Issues Report part](#github-issues-report).

These different reviews would be done for each document's final version, once they are pushed on their own branch (document for the functionalSpecification.md, technicalSpecification.md, userManual.md, and testPlan.md | management for the different management artifacts).

These reviews must be done before the document deliverables which is on the 7th february of 2025.

### Quality Assurance Team

The quality assurance team is only composed of myself. However, there are other quality assurances in other teams. We could, therefore, create a quality assurance team between us. To improve our global test quality and to brainstorm test cases among us.

It would lead quality assurances to improve their document and the global experience of the team. It would also be a plus for the development team, they would have more feedback on their product and could correct any issues detected more efficiently.

Finally, you could find our line of thoughts and different documents creating between us on this particular folder: "[QualityAssuranceTeamArtifacts]()".
<!-- Unused for now -->

### Testing Scope

Testing will focus on our REST api and on the validation tool the development team will provide.

#### In Scope

- REST API:
  - Handle all possible method;
  - Check for inputs possibilities;
  - Check the output;
  - Check the file format as output.
- Algorithm:
  - Check if the output is the one predict for a specific input;
  - Check if the output is within a range of 10% with the shortest path;
- Validation Tool:
  - Check the format of the file provided as input;
- Documentation:
  - Spelling accuracy;
  - Typographical errors;
  - Naming conventions;
  - Coherency;
  - Links;
  - Tables;

#### Out Of Scope

- Font details;
- Graphical design;
- Full application development;
- Post-deployment maintenance;

### Testing Types

#### Agile Testing

The first testing type is the agile one. It would allow the team to avoid creating bugs inbetween two different versions of the product. It would be used on the REST API, the validation tool and on the algorithm.

#### Unit Testing

Unit testing will be used to ensure small functions are given the good output and not a non-intended one. Therefore, it would ensure every little part of the code would run as intended.
It would be used on every code, especially on the validation tool.

#### Smoke Testing

The smoke testing is really useful when testing small critical aspects and/or features of a project. We would use it mainly on the algorithm and rest API by following test cases.

#### System Testing

Next, we would use system Testing as a black box, providing it an input and checking if the output is the one intended or not. It would be use on the REST API and the validation tool.

#### Compatibility Testing

Finally, the product will be test on different operating system to be sure it is compatible.
All of the product would pass this test.

## Test Cases

The table underneath would be used as a template for all the different test cases designed during this project. Their would also be one test case for every single test we will proceed on our product.

Here is the template of a test case:

| Test Case ID              | ID                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Name of the test case                                                      |
| Test Case Description     | Description of the test case                                               |
| Test Case Pre-conditions  | Requirements for the test                                                  |
| Test Case Steps           | Steps to go from the current state to the expected result                  |
| Test Case Expected Result | Result expected after following the steps                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | Status of the test (To Test, Testing, Tested)                              |
| Test Case Priority        | Defines if a test is important or not. Using numbers: Low  3 / Medium 2 / High 1 |
| Test Case Assigned To     | Name of the tester                                                         |

All the test cases will be stored in the markdown file test_cases.md that is accessible [there](/documents/QA/test_cases.md). They will also be visible in a [google spreadsheet]().

Moreover, all the test's results would be accessible on the second sheet of the same Google spreadsheet under this form:

<!-- To redefine -->
| Category name      | Input                                     |
| ------------------ | ----------------------------------------- |
| ID                 | The test case ID                          |
| Name               | Name of the test case                     |
| Description        | A short description of the test case      |
| Date               | When the test was done                    |
| Result state       | Did the test pass?                        |
| Result description | The description of the result if it fails |

## Testing Tools

### Hardware

All the tests will be done on different tools:

- [Apple MacBook Air - M3 10-core GPU](https://www.apple.com/fr/shop/buy-mac/macbook-air/13-pouces-m3)
  - 13.6 inch (2560 x 1664)
  - RAM: 16.0 GB
  - macOS Sequoia 15.0
  - Apple M3 Chip
  - Qwerty keyboard

- [Lenovo Thinkbook 14](https://pcsupport.lenovo.com/us/en/products/laptops-and-netbooks/thinkbook-series/thinkbook-14-iil/20sl)
  - Windows 11 Pro
  - 14-inch (1920 x 1080)
  - Processor: Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor
  
- [ThinkPad E14 Gen 5](https://www.lenovo.com/fr/fr/p/laptops/thinkpad/thinkpade/thinkpad-e14-gen-5-(14-inch-intel)/len101t0064)
  - Windows 11 Pro
  - 14-inch (1920 x 1080)
  - Processor: 13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor

### Software

- [Visual Studio Code](https://code.visualstudio.com/) for the development of the product.
- [Git](https://git-scm.com/) for the version control and to track the defects.
- [G++](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) for the compilation of the final product on [Windows](https://code.visualstudio.com/docs/cpp/config-mingw), [macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac).
- [Postman](https://www.postman.com) to test the API produced by the development team.

## Test Criteria

### Suspension Criteria

If a test reaches the suspension criteria, we will halt the subsequent testing. The development and quality assurance teams will then collaborate to address and resolve the issue before proceeding. This approach ensures that problems are handled individually, preventing the inclusion of unresolved issues in the program and avoiding the creation of additional problems.

### Entry Criteria

The entry criteria are the prerequisites that must be met to ensure the test can be conducted in the best possible conditions. These include:
- Confirming that testing is done on a valid version of the code;
- Ensuring the necessary unit tests are available;
- Verifying that the testing environment is correctly configured.

### Exit Criteria

The exit criteria define the requirements for concluding the testing phase. These include:
- Achieving a success rate of at least 80%;
- Ensuring there are no critical or high-severity defects during testing;
- Reporting all issues of medium or low severity.

## GitHub Actions

For this project, GitHub Actions have been made to handle the basic Unit tests at each pull request on the dev branch. This would ensure the functionning of the code and the automation would save a non negligable amount of time.

These Actions can be fin on our GitHub repository, following [this link](https://github.com/algosup/2024-2025-project-3-quickest-path-team-6/actions).

## GitHub Issues Report

### Document Review

To provide a better track on document reviews, a template was created on the GitHub issue, allowing everyone to check their own document review to change and improve their documents accordingly.

The Document template was created with the following parts:

**Background Information**

This part is here to inform how to read properly the issue and to have a better comprehension of the correction provided.

This part contains two subparts, Display, and Conventions.

The Display part is only here to provide a visual representation of the format used inside the issue.
The Conventions part list all the formating used within the review.

**Improvement(s)**

Improvement(s) is the main part of the report. It is composed of five subparts which are:

- Naming convention:
  - Here will be displayed the errors found regarding the naming conventions defined in [this file](../Technical/conventions.md).

- Spelling errors:
  - This one is quite explicit. It will showcase the different spelling errors from the reviewed document.

- Links misbehavior:
  - If a link isn't redirecting to the proper page, it would be indicated there.

- Tables malfunction:
  - This section will mainly be used if a table isn't displayed properly.

- Coherency issues:
  - This section will list the wordy or incomprehensible sentences.

**Other Suggestion(s)**

Finally, this section would list suggestions to improve the document. It could be from adding a part to center a table.

---

Here is a picture of the template:

<img width="901" alt="Screenshot 2025-01-08 at 16 59 15" src="https://github.com/user-attachments/assets/ababddc0-8d18-4076-952b-befcb2cedeb4" />

The template is also reachable on our GitHub repository or following this [link](https://github.com/algosup/2024-2025-project-3-quickest-path-team-6/blob/main/.github/ISSUE_TEMPLATE/document-review.md).

### Dev Review

A development template has also been created in order to keep track of the code and to assure a readable and well-functioning algorithm.
This template is designed in the same way as the document review template. In other words, there is three main parts, which are:
- Background Information;
- Improvement(s);
- Other Suggestion(s).

The only differences with the previously stated template is on the Improvement(s)' content. It would be composed of:

- Coding convention:
  - It would identify all the errors regarding the coding conventions determined on the conventions.md file that you could find following [this link](../Technical/conventions.md).

- Spelling errors:
  - This section would be the same as the one in the document review template, it would mainly consist on listing any spelling errors found inside the code.

- Outputs errors:
  - During the reviez, tests will be done. Therefore, if the output of these tests aren't the one expected, they would be written in this section.

---

The development review template is shown below:

<!-- Put the screenshot -->

Like the previous template, it is reachable on our GitHub repository or following [this link](https://github.com/algosup/2024-2025-project-3-quickest-path-team-6/blob/main/.github/ISSUE_TEMPLATE/dev-review.md).

### Labels

Finally, to complete these issues, labels were created to have a better understanding of the issues at first sight.
It would also help the team to know who is assigned to a dedicated issue.

| Label                                                                                                                             | Description                                |
| :-------------------------------------------------------------------------------------------------------------------------------: | ------------------------------------------ |
| <img src="https://github.com/user-attachments/assets/076c8b37-8337-47a0-a475-1d78c9f09491" alt="bug_label" height="50">           | Something isn't working                    |
| <img src="https://github.com/user-attachments/assets/e44bec86-07eb-480b-a5af-e1d4be2c1bb3" alt="critical_label" height="50">      | Critical priority level                    |
| <img src="https://github.com/user-attachments/assets/d5e148c4-e12e-4599-a38d-ebbac902e6fb" alt="dev_label" height="50">           | Development related                        |
| <img src="https://github.com/user-attachments/assets/eb5f9039-d191-4494-beb4-fafc1491be44" alt="documentation_label" height="50"> | Improvements or additions to documentation |
| <img src="https://github.com/user-attachments/assets/6030359e-26f9-4a88-8a75-a454a97533a0" alt="enhancement_label" height="50">   | New feature or request                     |
| <img src="https://github.com/user-attachments/assets/42274989-5d59-42a1-a6e6-1d5942965b7d" alt="functional_label" height="50">    | Functional specifications related          |
| <img src="https://github.com/user-attachments/assets/a8952957-0026-4de1-b5c6-6e2441a5c02b" alt="help_wanted_label" height="50">   | Extra attention is needed                  |
| <img src="https://github.com/user-attachments/assets/0b18c354-a65b-4812-80c2-bc8aea056ced" alt="high_label" height="50">          | High priority level                        |
| <img src="https://github.com/user-attachments/assets/f3033bf8-6d49-4bbf-bec4-663eb7fe8bbc" alt="low_label" height="50">           | Low priority level                         |
| <img src="https://github.com/user-attachments/assets/c4ccab0d-6871-4d43-991d-6af59c623f5d" alt="management_label" height="50">    | Management related                         |
| <img src="https://github.com/user-attachments/assets/317e223d-ece9-4349-9e00-af5cdc5d6579" alt="medium_label" height="50">        | Medium priority level                      |
| <img src="https://github.com/user-attachments/assets/ce610b9f-a366-487c-822b-9a30d08fa6d0" alt="technical_label" height="50">     | Technical specifications related           |
| <img src="https://github.com/user-attachments/assets/072bda87-7fdd-4e48-862a-8693376edc7d" alt="user_manual_label" height="50">   | User manual related                        |
| <img src="https://github.com/user-attachments/assets/13206089-ea16-48f8-a160-385eec349c42" alt="wontfix_label" height="50">       | This will not be worked on                 |

## Testing Schedule And Estimation

### Tasks Time Estimation

| Task                             | Duration |
| -------------------------------- | -------- |
| Functional specifications review | 3 hours  |
| Technical specifications review  | 5 hours  |
| Test plan writing                | 15 hours |
| Test plan review                 | 3 hours  |
| Test case writing                | 20 hours |
| Test case applying               | 30 hours |
| User manual review               | 3 hours  |
| Management review                | 6 hours  |
| Bug reports                      | 3 hours  |
| Bug data report creation         | 3 hours  |
| Bug data report fulfilment       | 5 hours  |

All the defined duration for each tasks only are expectation. Therefore, if a task take more time than needed, overtime hours could be done to complete these tasks before their deadlines.

### Tasks Schedule

This part would display the supposed schedule for the quality assurance part of the project. However, the team decided to proceed with an agile method. Therefore, these dates are meant to change over the time. Moreover, the expanded duration of the tasks are explained by this method.

| Task                            | Start date | End date |
| ------------------------------- | ---------- | -------- |
| GitHub initialization           | 01/06/25   | 01/06/25 |
| Test plan writing               | 01/06/25   | 01/24/25 |
| Test cases creation             | 01/13/25   | 01/31/25 |
| code testing                    | 01/14/25   | 02/07/25 |
| Functional specification review | 01/14/25   | 02/07/25 |
| Technical specification review  | 01/14/25   | 02/07/25 |
| User manual review              | 01/14/25   | 02/07/25 |
| Management review               | 01/14/25   | 02/14/25 |
| Test case execution             | 01/24/25   | 02/07/25 |
| Bug reports                     | 01/14/25   | 02/07/25 |
| Bug data report                 | 01/14/25   | 02/07/25 |

## Test Deliverables

All the test deliverables should be delivered at the very least on the 7th of February.

- **Test plan:** It will define how the tests should be done and the strategy chosen.
- **Test cases:** It will contain all the tests that will be done to see if the product is functional.
- **Bug reports:** Each will contain a report about a bug found during the test sessions.
- **Bug data report:** It will allow us to see all of the reports in one place.

## Conclusion And Acknowledgments

The testing part of a project is really important. It is there to assure the well behaving of the product, but also to have constant documentation to not be looked down.

We would thank all the members of the team who worked on this project.

Finally, we would then thank [ALGOSUP](https://algosup.com) for this project and this opportunity to develop our skills once again.

## Sources

- [GitHub](https://github.com/)

## Glossary

|Term|Definition|Source|
|----|----------|------|
|Agile testing|||
|Algorithm|||
|Bugs|||
|Compatibility testing|||
|CSV|||
|GitHub|||
|GitHub actions|||
|GitHub branch|||
|GitHub issues|||
|GitHub merge|||
|GitHub pull-request|||
|Local host server|||
|Path finder|||
|Review|||
|Smoke testing|||
|System testing|||
|Test cases|||
|Unit tests|||
