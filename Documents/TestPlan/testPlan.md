# PathQuick - Test Plan

This project was requested by [ALGOSUP](https://algosup.com), a French computer science school.

The aim of this project is to create a quick pathfinding server according to a CSV file of USA-roads.

<details>
<summary>Table of Contents</summary>

<!-- TODO -->
    
</details>

## Introduction

### Overview

The team was asked to create a path finder according to a .csv file about the USA-roads. To implement it, a localhost server should be created as well as all the algorithm behind it.
It should return the time needed to complete the journey and a list of all the different landmarks it passes by.
Moreover, a validation tool should be created aside to verify the .csv file formating (LANDMARK_A__ID, LANDMARK_B_ID, TIME).

## Testing Strategy

The testing strategy would be sorted in two different categories. The first one would be dedicated to the code testing while the second one would be based on document testing.

**Code Testing Strategy**

Regarding the Code Testing Strategy, we decided to test the diffrent version of the code as early as possible.

This project requires a programm running on diverse open source system. However, the development team is only using Windows computer. Therefore, each time they have a working prototype on their own branches, they would merge them into the dev branch for the entire team to test it on their machine.

This would be considered as the first test.

However, other test would be done at periodic time. Hopefully, the more frequently possible. In the worst option, these tests would be made once in a week.

<!-- Our testing strategy will be based on three different testing types. At first, we will use [smoke testing](#smoke-testing) to see basic functionalities. Then we will use some [unit tests](#unit-testing) to see in more detail if the code runs as expected. We will also use some [agile testing](#agile-testing) to test the code before each push on GitHub. -->

**Documentation Testing Strategy**

The document testing would be done following the template previously done on the GitHub issue, a GitHub feature. You can fine a markdown version of this quoted template in the [GitHub Issues Report part](#github-issues-report).

These different reviews would be done for each document's final version, once they are pushed on their own branch (document for the functionalSpecification.md, technicalSpecification.md, userManual.md, and testPlan.md | management for the different management artifacts).

These reviews must be done before the document deliverables which is on the 7th february of 2025.

### Quality Assurance team

The quality assurance team is only composed of myself. However, there are other quality assurances in other team. We could, therefore, create a quality assurance team between us. To improve our global test quality and to brainstorm test cases among us.

It would lead quality assurances to improve their document and the global experience of the team. It would also be a plus for the development team, they would have more feedback on their product and could correct any issues detected more efficiently.

Finally, you could find our line of thoughts and different documents creating between us on this particular folder: "[QualityAssuranceTeamArtifacts]()".
<!-- Unused for now -->

### Testing Scope

<!-- Testing will focus on assembly instruction and the assembler. -->

#### In Scope

<!-- - Assembly instruction:
  - All the instructions defined in the [Functional Specification](/documents/functional/functional_specification.md) should function as intended.
- Assembler:
  - Absence of significant bug;
  - Should run properly;
  - Should assemble the files;
- Emulator:
  - Absence of significant bug;
  - Should run properly;
  - Should interpret ASM files;
- Documentation:
  - Spelling accuracy;
  - Typographical errors;
  - Naming conventions; -->

#### Out Of Scope

<!-- - Font details;
- Interrupt instruction; -->

### Testing Type

<!-- #### Smoke testing -->

<!-- The quality assurance would use a smoke testing strategy for the assembler, like this he would be sure that it would work as intended by doing some easy tests each time he would run the code. -->

<!-- #### Unit testing -->

<!-- The quality assurance will also use Unit tests for all the particular instructions in the assembly language created by the team. It will also be used to ensure that some functions in the assembler work as intended. -->

<!-- #### Agile testing -->

<!-- Finally, the quality assurance will use an agile testing strategy. This means that he should be reactive each time a version is pushed on the repository and test them. -->

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

All the test cases will be stored in the markdown file test_cases.md that is accessible [ther](/documents/QA/test_cases.md). They will also be visible in a [google spreadsheet]().

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

<!-- When a test is done, if a suspension criteria is reached, we stop the following test, and the development team, as well as the quality assurance team, will work together until the issue is fixed. This method will allow us to take issues one by one and not create a program with existing issues inside. It would avoid generating more issues. -->

### Entry Criteria

<!-- The entry criteria are the criteria needed for the well-being of the test and to ensure to proceed in the best environment possible. \
The three main criteria are:
- Be sure to proceed with the tests on a valid version of the code;
- Be sure to have the unit tests required;
- Be sure that the environment is correctly set for the tests; -->

### Exit Criteria

<!-- The exit criteria should specify the requirements to complete before the end of the testing phase. \
These criteria are:
- We need to have at least an 80% success rate;
- We need to have no critical or high-severity defects during the tests;
- All the little and medium severity issues should be reported; -->

## GitHub Issues Report

**Document Review**

<!-- To provide a better bug report, I chose to create a bug report template that we can apply to GitHub issues. It allows the people who found a bug to report it quickly and effectively with the main information needed. \
Here is a picture of the template:

![Bug report high](/documents/QA/pictures/bug_report_high.png)
![Bug report low](/documents/QA/pictures/bug_report_low.png) -->

**Dev Review**

<!-- TODO -->

**Labels**

<!-- I also provide labels to my team, permitting us to have a better comprehension of the bug, just with the title and the labels. There are 15 of them: -->

<!-- |Label|Description|
|:-----:|-----------|
|![Bug Label](/documents/QA/pictures/bug_label.png)|Something isn't working|
|![Critical Label](/documents/QA/pictures/critical_label.png)|Critical Priority|
|![Dev Label](/documents/QA/pictures/dev_label.png)|Use for Dev|
|![Documentation Label](/documents/QA/pictures/documentation_label.png)|Improvements or additions to documentation|
|![Duplicate Label](/documents/QA/pictures/duplicate_label.png)|This issue or pull request already exists|
|![Enhancement Label](/documents/QA/pictures/enhancement_label.png)|New feature or request|
|![Good first issue Label](/documents/QA/pictures/good_first_issue_label.png)|Good for newcomers|
|![Help wanted Label](/documents/QA/pictures/help_wanted_label.png)|Extra attention is needed|
|![High Label](/documents/QA/pictures/high_label.png)|High Priority|
|![Invalid Label](/documents/QA/pictures/invalid_label.png)|This doesn't seem right|
|![Low Label](/documents/QA/pictures/low_label.png)|Low Priority|
|![medium Label](/documents/QA/pictures/medium_label.png)|Medium Priority|
|![Question Label](/documents/QA/pictures/question_label.png)|Further information is requested|
|![Test case Label](/documents/QA/pictures/test_case_label.png)|Use for test case|
|![Wontfix Label](/documents/QA/pictures/wontfix_label.png)|This will not be worked on| -->

## Testing Schedule And Estimation

### Tasks Time Estimation

<!-- |Task|Duration|
|----|--------|
|Requirement specification documentation review|5 hours|
|Test plan writing|20 hours|
|Test cases creation|10 hours|
|Assembly testing|15 hours|
|Quality assurance meeting|4 hours|
|Test case execution|20 hours|
|GitHub initialization|2 hours|
|Bug reports|12 hours|
|Bug data report|6 hours| -->

<!-- All the durations defined here are only estimations! It could take more or less time according to the advancement of the tasks, the extra hours outside the school, or even if the test cases don't occur any errors or issues. -->

### Tasks Schedule

<!-- |Task|Start date|End date|
|----|----------|--------|
|GitHub initialization|01/22/24|01/22/24|
|Test plan writing|01/22/24|02/16/24|
|Test cases creation|01/22/24|02/16/24|
|Assembly testing|01/22/24|01/30/24|
|Functional specification review|01/29/24|01/30/24|
|Quality assurance meeting|01/29/24|01/29/24|
|Functional specification review|02/08/24|02/09/24|
|Test case execution|01/30/24|02/23/24|
|Bug reports|01/30/24|02/23/24|
|Bug data report|01/30/24|02/23/24| -->

## Test Deliverables

<!-- - **Test plan:** It will define how the tests should be done and the strategy chosen.
- **Test cases:** It will contain all the tests that will be done to see if the product is functional.
- **Bug reports:** Each will contain a report about a bug found during the test sessions.
- **Bug data report:** It will allow us to see all of the reports in one place. -->

## Conclusion And Acknowledgments

<!-- The testing part of a project is one of the most important ones. If the quality isn't assured, then the product would not work as intended, this is why this part is such an important one.

We would thank all the members of the team who worked on this project.
We would thank the other quality assurances that we work with, our product would have been less good without their help.

We would also thank our teacher [Caroline CORDIER](https://www.linkedin.com/in/caroline-cordier-dpo/), who taught us the fundamentals of a good test plan and the quality assurance role.

We would also thank the previous project quality assurance, who helped us by giving us hints.

Finally, we would then thank [ALGOSUP](https://algosup.com) for this project and this opportunity to develop our skills once again. -->

## Sources

<!-- - [Cambridge Dictionary](https://dictionary.cambridge.org/)
- [GitHub](https://github.com/)
- [Informatica](https://www.informatica.com/eng.html)
- [TechTarget](https://www.techtarget.com/)
- [Wikipedia](https://en.wikipedia.org/wiki/Main_Page) -->

## Glossary

<!-- |Term|Definition|Source|
|----|----------|------|
|Agile testing|A software development practice that promotes frequent, automated testing of new code as it is completed and stipulates that defects should be fixed as soon as they are found.|[Informatica](https://www.informatica.com/in/services-and-training/glossary-of-terms/agile-testing-definition.html#:~:text=Agile%20testing%20is%20a%20software,soon%20as%20they%20are%20found.)|
|Assembler|A program that changes computer instructions into machine code (= a set of numbers that gives instructions to a computer).|[Cambridge Dictionary](https://dictionary.cambridge.org/fr/dictionnaire/anglais/assembler)|
|Assembly language|In computer programming, assembly language is any low-level programming language with a very strong correspondence between the instructions in the language and the architecture's machine code instructions.|[Wikipedia](https://en.wikipedia.org/wiki/Assembly_language)|
|Compiler|In computing, a compiler is a computer program that translates computer code written in one programming language (the source language) into another language (the target language).|[Wikipedia](https://en.wikipedia.org/wiki/Compiler)|
|C language|C is a general-purpose computer programming language. C is commonly used on computer architectures that range from the largest supercomputers to the smallest microcontrollers and embedded systems.|[Wikipedia](https://en.wikipedia.org/wiki/C_(programming_language))|
|Git|A distributed version control system that tracks changes in any set of computer files, usually used for coordinating work among programmers who are collaboratively developing source code during software development.|[Wikipedia](https://en.wikipedia.org/wiki/Git)|
|GitHub|GitHub, Inc. is an AI-powered developer platform that allows developers to create, store, manage, and share their code.|[Wikipedia](https://en.wikipedia.org/wiki/GitHub)|
|GitHub Issues|GitHub Issues are items you can create in a repository to plan, discuss, and track work. Issues are simple to create and flexible to suit a variety of scenarios. You can use issues to track work, give or receive feedback, collaborate on ideas or tasks, and efficiently communicate with others.|[GitHub](https://docs.github.com/en/issues/tracking-your-work-with-issues/about-issues)|
|GNU Compiler Collection (GCC)|The GNU Compiler Collection (GCC) is an optimizing compiler produced by the GNU Project supporting various programming languages, hardware architectures, and operating systems.|[Wikipedia](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)|
|Interpreter|In computer science, an interpreter is a computer program that directly executes instructions written in a programming or scripting language, without requiring them previously to have been compiled into a machine language program.|[Wikipedia](https://en.wikipedia.org/wiki/Interpreter_(computing))|
|Linux|Linux is a family of open-source Unix-like operating systems based on the Linux kernel, an operating system kernel first released on September 17, 1991, by Linus Torvalds.|[Wikipedia](https://en.wikipedia.org/wiki/Linux)|
|MacOS|MacOS, originally Mac OS X, previously shortened as OS X, is an operating system developed and marketed by Apple Inc.|[Wikipedia](https://en.wikipedia.org/wiki/MacOS)|
|Test case|In software engineering, a test case is a specification of the inputs, execution conditions, testing procedure, and expected results that define a single test to be executed to achieve a particular software testing objective, such as to exercise a particular program path or to verify compliance with a specific requirement.|[Wikipedia](https://en.wikipedia.org/wiki/Test_case)|
|Smoke testing|A software testing method that is used to determine if a new software build is ready for the next testing phase. This testing method determines if the most crucial functions of a program work but does not delve into finer details.|[TechTarget](https://www.techtarget.com/searchsoftwarequality/definition/smoke-testing#:~:text=Smoke%20testing%2C%20also%20called%20build,not%20delve%20into%20finer%20details.)|
|Unit testing|A software testing method by which individual units of source code—sets of one or more computer program modules together with associated control data, usage procedures, and operating procedures—are tested to determine whether they are fit for use.|[Wikipedia](https://en.wikipedia.org/wiki/Unit_testing)|
|Visual Studio Code|Visual Studio Code, also commonly referred to as VS Code, is a source-code editor developed by Microsoft for Windows, Linux, and macOS. Features include support for debugging, syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git.|[Wikipedia](https://en.wikipedia.org/wiki/Visual_Studio_Code)|
|Windows|Microsoft Windows is a group of several proprietary graphical operating system families developed and marketed by Microsoft. Each family caters to a certain sector of the computing industry.|[Wikipedia](https://en.wikipedia.org/wiki/Microsoft_Windows)| -->