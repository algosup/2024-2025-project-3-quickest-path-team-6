# PathQuick - Test Plan

This project was requested by [ALGOSUP](https://algosup.com), a French computer science school.

This project aims to create a quick pathfinding<sup><a href="#1">[1]</a></sup> server according to a CSV<sup><a href="#1">[2]</a></sup> file of USA-roads.

<details>
<summary>Table of Contents</summary>

- [Introduction](#introduction)
  - [Overview](#overview)
- [Testing Strategy](#testing-strategy)
  <!-- - [Quality Assurance Team](#quality-assurance-team) -->
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

The team was asked to create a pathfinder based on a .csv file about the USA roads. To implement it, a localhost server<sup><a href="#1">[3]</a></sup> should be created as well as all the algorithm<sup><a href="#1">[4]</a></sup> behind it. \
It should return the time needed to complete the journey and a list of all the landmarks it passes by. \
Moreover, a validation tool should be created to verify the .csv file formatting (LANDMARK_A__ID, LANDMARK_B_ID, TIME).

## Testing Strategy

The testing strategy would be sorted into two different categories. The first one would be dedicated to code testing while the second one would be based on document testing.

**Code Testing Strategy**

Regarding the Code Testing Strategy, we decided to test the different versions of the code as early as possible.

This project requires a program running on diverse operating systems. However, the development team uses only Windows computers. Therefore, each time they have a working prototype on their own branches<sup><a href="#1">[5]</a></sup>, they would merge<sup><a href="#1">[6]</a></sup> them into the dev branch for the entire team to test it on their machine.

This would be considered as the first test.

However, other tests would be done at periodic times. Hopefully, the more frequently possible. In the worst case, these tests would be done once a week.

Our testing strategy will mainly use the [agile testing](#agile-testing)<sup><a href="#1">[7]</a></sup> strategy, to ensure no bugs<sup><a href="#1">[8]</a></sup> come in between two different versions of our piece of software. However, this would not be the only method used. Some [unit tests](#unit-testing)<sup><a href="#1">[9]</a></sup> would be written to test a specific part of the code and would be run automatically during a pull request<sup><a href="#1">[10]</a></sup> on the dev branch, thanks to [GitHub Actions](#github-actions)<sup><a href="#1">[11]</a></sup>. Finally, the QA team will also use some [smoke testing](#smoke-testing)<sup><a href="#1">[12]</a></sup>, [system testing](#system-testing)<sup><a href="#1">[13]</a></sup> and [compatibility testing](#compatibility-testing)<sup><a href="#1">[14]</a></sup>. This would ensure the product would provide the critical functionalities and is compatible with every operating system.

**Documentation Testing Strategy**

The document testing would be done following the template previously done on the GitHub issue<sup><a href="#1">[15]</a></sup>, a GitHub<sup><a href="#1">[16]</a></sup> feature. You can find a markdown version of this quoted template in the [GitHub Issues Report part](#github-issues-report).

These different reviews<sup><a href="#1">[17]</a></sup> would be done for each document's final version, once they are pushed on their own branch (document for the functionalSpecification.md, technicalSpecification.md, userManual.md, and testPlan.md | management for the different management artifacts).

These reviews must be done before the document deliverables which is on the 7th of February of 2025.

<!-- ### Quality Assurance Team

The quality assurance team is only composed of myself. However, there are other quality assurances in other teams. We could, therefore, create a quality assurance team between us. To improve our global test quality and to brainstorm test cases among us.

It would lead the quality assurance team to improve their document and the global experience of the team. It would also be a plus for the development team, they would have more feedback on their product and could correct any issues detected more efficiently.

Finally, you can find our line of thoughts and different documents created between us in this particular folder: "[QualityAssuranceTeamArtifacts]()". -->
<!-- Unused for now -->

### Testing Scope

Testing will focus on our REST API and on the validation tool the development team will provide.

#### In Scope

- REST API:
  - Handle all possible methods
  - Check for input possibilities
  - Check the output
  - Check the file format as output
- Algorithm:
  - Check if the output is the one predicted for a specific input
  - Check if the output is within a range of 10% with the shortest path
- Validation Tool:
  - Check the format of the file provided as input
- Documentation:
  - Spelling accuracy
  - Typographical errors
  - Naming conventions
  - Coherency
  - Links
  - Tables

#### Out Of Scope

- Font details;
- Graphical design;
- Full application development;
- Post-deployment maintenance;

### Testing Types

#### Agile Testing

The first testing type is the agile one. It would allow the team to avoid creating bugs between two different versions of the product. It would be used on the REST API, the validation tool, and on the algorithm.

#### Unit Testing

Unit testing will be used to ensure small functions are given a good output and not a non-intended one. Therefore, it would ensure every little part of the code would run as intended. \
It would be used on every code, especially on the validation tool.

#### Smoke Testing

Smoke testing is really useful when testing small critical aspects and/or features of a project. We would use it mainly on the algorithm and REST API by following test cases<sup><a href="#1">[18]</a></sup>.

#### System Testing

Next, we would use system Testing as a black box, providing it an input and checking if the output is the one intended or not. It would be used on the REST API and the validation tool.

#### Compatibility Testing

Finally, the product will be tested on different operating systems to be sure it is compatible. \
All of the products would pass this test.

## Test Cases

The table underneath would be used as a template for all the different test cases designed during this project. There would also be one test case for every single test we will proceed on our product.

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

All the test cases will be stored in the markdown file testCases.md that is accessible [there](/Documents/TestPlan/testCases.md). They will also be visible in a [google spreadsheet](https://docs.google.com/spreadsheets/d/1w3GkvyACPfrN6t2wp6ESf5VsZAYqkQ7p-10jfRc_C9k/edit?usp=sharing).

Moreover, all the test results would be accessible on the second sheet of the same Google spreadsheet. They would be presented this way:

| Category name   | Input                                     |
| --------------- | ----------------------------------------- |
| ID              | The test case ID                          |
| Name            | Name of the test case                     |
| Description     | A short description of the test case      |
| Result state    | Did the test pass?                        |
| Expected result | The expected result                       |  
| Actual result   | The description of the result if it fails |

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

For this project, GitHub Actions have been made to handle the basic Unit tests at each pull request on the dev branch. This would ensure the functioning of the code and the automation would save a non-negligible amount of time.

These Actions can be find on our GitHub repository, following [this link](https://github.com/algosup/2024-2025-project-3-quickest-path-team-6/actions).

## GitHub Issues Report

### Document Review

To provide a better track on document reviews, a template was created on the GitHub issue, allowing everyone to check their own document review to change and improve their documents accordingly.

The Document template was created with the following parts:

**Background Information**

This part is here to inform how to read properly the issue and to have a better comprehension of the correction provided.

This part contains two subparts, Display, and Conventions.

The Display part is only here to provide a visual representation of the format used inside the issue. \
The Conventions part lists all the formatting used within the review.

**Improvement(s)**

Improvement(s) is the main part of the report. It is composed of five subparts which are:

- Naming convention:
  - There will be displayed the errors found regarding the naming conventions defined in [this file](../Technical/conventions.md).

- Spelling errors:
  - This one is quite explicit. It will showcase the different spelling errors from the reviewed document.

- Links misbehavior:
  - If a link isn't redirecting to the proper page, it would be indicated there.

- Tables malfunction:
  - This section will mainly be used if a table isn't displayed properly.

- Coherency issues:
  - This section will list the wordy or incomprehensible sentences.

**Other Suggestion(s)**

Finally, this section will list suggestions to improve the document. It could be from adding a part to center a table.

---

Here is a picture of the template:

<img width="901" alt="Document review" src="https://github.com/user-attachments/assets/ababddc0-8d18-4076-952b-befcb2cedeb4" />

The template is also reachable on our GitHub repository or by following this [link](https://github.com/algosup/2024-2025-project-3-quickest-path-team-6/blob/main/.github/ISSUE_TEMPLATE/document-review.md).

### Dev Review

A development template has also been created in order to keep track of the code and to ensure a readable and well-functioning algorithm. \
This template is designed in the same way as the document review template. In other words, there are three main parts, which are:
- Background Information;
- Improvement(s);
- Other Suggestion(s).

The only difference with the previously stated template is in the Improvement(s)' content. It would be composed of:

- Coding convention:
  - It would identify all the errors regarding the coding conventions determined on the conventions.md file that you could find following [this link](../Technical/conventions.md).

- Spelling errors:
  - This section would be the same as the one in the document review template, it would mainly consist of listing any spelling errors found inside the code.

- Outputs errors:
  - During the review, tests will be done. Therefore, if the output of these tests isn't the one expected, they will be written in this section.

---

The development review template is shown below:

<img width="914" alt="Dev review" src="https://github.com/user-attachments/assets/1c058aa2-e55a-4b8f-bedd-c0fa3e606986" />

Like the previous template, it is reachable on our GitHub repository or by following [this link](https://github.com/algosup/2024-2025-project-3-quickest-path-team-6/blob/main/.github/ISSUE_TEMPLATE/dev-review.md).

### Labels

Finally, to complete these issues, labels were created to have a better understanding of the issues at first sight. \
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
| <img src="https://github.com/user-attachments/assets/9251106f-df7b-4ef7-8fed-68496e4a4748" alt="technical_label" height="50">     | Test plan or test cases related            |
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

All the defined durations for each task only are expected. Therefore, if a task takes more time than needed, overtime hours could be done to complete these tasks before their deadlines.

### Tasks Schedule

This part would display the supposed schedule for the quality assurance part of the project. However, the team decided to proceed with an agile method. Therefore, these dates are meant to change over time. Moreover, the expanded duration of the tasks is explained by this method.

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

The testing part of a project is really important. It is there to ensure the good behavior of the product, but also to have constant documentation to not be looked down on.

We would thank all the members of the team who worked on this project.

Finally, we would then thank [ALGOSUP](https://algosup.com) for this project and this opportunity to develop our skills once again.

## Sources

- [GitHub](https://github.com/)
- [Informatica](https://www.informatica.com)
- [Cambridge Dictionary](https://dictionary.cambridge.org)
- [TechTarget](https://www.techtarget.com)
- [Wikipedia](https://en.wikipedia.org/wiki/Main_Page)
- [GeeksforGeeks](https://www.geeksforgeeks.org)
- [Linguee](https://www.linguee.com)

## Glossary

| Term                                      | Definition                                                                                                                                                                                                                                   | Source                                                                                                                                                                                        |
| ----------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <a id="1">[7]</a>: Agile Testing          | It is a software development practice that promotes frequent, automated testing of new code as it is completed and stipulates that defects should be fixed as soon as they are found.                                                        | [Informatica](https://www.informatica.com/services-and-training/glossary-of-terms/agile-testing-definition.html#:~:text=Agile%20testing%20is%20a%20software,soon%20as%20they%20are%20found.)  |
| <a id="1">[4]</a>: Algorithm              | It is a set of mathematical instructions that must be followed in a fixed order, and that, especially if given to a computer, will help to calculate an answer to a mathematical problem.                                                    | [Cambridge](https://dictionary.cambridge.org/fr/dictionnaire/anglais/algorithm)                                                                                                               |
| <a id="1">[8]</a>: Bugs                   | They are mistakes or problems in a computer program.                                                                                                                                                                                         | [Cambridge](https://dictionary.cambridge.org/fr/dictionnaire/anglais/bug)                                                                                                                     |
| <a id="1">[14]</a>: Compatibility Testing | It is an assessment used to ensure a software application is properly working across different browsers, databases, operating systems (OS), mobile devices, networks and hardware.                                                           | [TechTarget](https://www.techtarget.com/whatis/definition/compatibility-test#:~:text=A%20compatibility%20test%20is%20an,mobile%20devices%2C%20networks%20and%20hardware.)                     |
| <a id="1">[2]</a>: CSV                    | It is a text file format that uses commas to separate values, and newlines to separate records.                                                                                                                                              | [Wikipedia](https://en.wikipedia.org/wiki/Comma-separated_values)                                                                                                                             |
| <a id="1">[16]</a>: GitHub                | It is a cloud-based platform where you can store, share, and work together with others to write code.                                                                                                                                        | [GitHub Docs](https://docs.github.com/en/get-started/start-your-journey/about-github-and-git)                                                                                                 |
| <a id="1">[11]</a>: GitHub Actions        | It is a continuous integration and continuous delivery (CI/CD) platform that allows you to automate your build, test, and deployment pipeline.                                                                                               | [GitHub Docs](https://docs.github.com/en/actions/about-github-actions/understanding-github-actions)                                                                                           |
| <a id="1">[5]</a>: GitHub Branch          | They allow you to develop features, fix bugs, or safely experiment with new ideas in a contained area of your repository.                                                                                                                    | [GitHub Docs](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-branches)                                     |
| <a id="1">[15]</a>: GitHub Issues         | They are a way to track and manage the work needed to improve your projects.                                                                                                                                                                 | [GeeksforGeeks](https://www.geeksforgeeks.org/issues-in-github/)                                                                                                                              |
| <a id="1">[6]</a>: GitHub Merge           | It is a GitHub feature that allows people to fuse two branches into one.                                                                                                                                                                       | [GitHub Docs](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/incorporating-changes-from-a-pull-request/merging-a-pull-request)                                     |
| <a id="1">[10]</a>: GitHub Pull-request    | It is a proposal to merge a set of changes from one branch into another.                                                                                                                                                                     | [GitHub Docs](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)                                |
| <a id="1">[3]</a>: Local Host Server      | It is a hostname that refers to the current computer used to access it.                                                                                                                                                                      | [Wikipedia](https://en.wikipedia.org/wiki/Localhost)                                                                                                                                          |
| <a id="1">[1]</a>: Path Finder            | It showed the others the way through the woods. In our context, to find the shortest way between two landmarks.                                                                                                                              | [Linguee](https://www.linguee.fr/anglais-francais/traduction/pathfinder.html#:~:text=éclaireur%20m,chemin%20à%20travers%20les%20bois.)                                                        |
| <a id="1">[17]</a>: Review                | To check quality.                                                                                                                                                                                                                            | /                                                                                                                                                                                             |
| <a id="1">[12]</a>: Smoke Testing         | It is a software testing method that is used to determine if a new software build is ready for the next testing phase. This testing method determines if the most crucial functions of a program work but does not delve into finer details. | [TechTarget](https://www.techtarget.com/searchsoftwarequality/definition/smoke-testing#:~:text=Smoke%20testing%2C%20also%20called%20build,not%20delve%20into%20finer%20details.)              |
| <a id="1">[13]</a>: System Testing        | It is the process in which a quality assurance (QA) team evaluates how the various components of an application interact together in the full, integrated system or application.                                                             | [TechTarget](https://www.techtarget.com/searchsoftwarequality/definition/system-testing#:~:text=System%20testing%2C%20also%20referred%20to,full%2C%20integrated%20system%20or%20application.) |
| <a id="1">[18]</a>: Test Cases            | They define what must be done to test a system, including the steps executed in the system, the input data values entered into the system and the test results expected throughout test case execution.                                      | [TechTarget](https://www.techtarget.com/searchsoftwarequality/definition/test-case#:~:text=Test%20cases%20define%20what%20must,expected%20throughout%20test%20case%20execution.)              |
| <a id="1">[9]</a>: Unit Tests             | It is a form of software testing by which isolated source code is tested to validate expected behavior.                                                                                                                                      | [Wikipedia](https://en.wikipedia.org/wiki/Unit_testing)                                                                                                                                       |
