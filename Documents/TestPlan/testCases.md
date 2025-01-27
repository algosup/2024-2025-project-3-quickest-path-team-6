# PathQuick - Test Cases

## Overview

This document will gather all the test cases written by the quality assurance. They would be sorted into four different categories which are:
- REST API
- Algorithm
- Menu
- Validation Tool

You can also find all these test cases on a Google Spreadsheet at [this link](https://docs.google.com/spreadsheets/d/1w3GkvyACPfrN6t2wp6ESf5VsZAYqkQ7p-10jfRc_C9k/edit?usp=sharing).

## Priority

The following test cases would be assigned a priority from high to medium following the underneath table:

|Number|Priority|
|------|--------|
|1     |High    |
|2     |Medium  |
|3     |Low     |

## Test Cases: REST API

### REST API: Compilation And Running On Windows

| Test Case ID              | 1                                                                          |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: Compilation And Running On Windows                                           |
| Test Case Description     | Verify if the `startServer.cmd` is working properly.                        |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                           |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `.\startServer.cmd`. |
| Test Case Expected Result | The server should run and be initialized.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                                                                    |
| Test Case Priority        | High 1                                                                     |
| Test Case Assigned To     | Maxime Thizeau                                                             |

### REST API: Compilation And Running On macOS

| Test Case ID              | 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: Compilation And Running On MacOS                                 |
| Test Case Description     | Verify if the `startServer.sh` is working properly.                         |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                           |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `./startServer.sh`. |
| Test Case Expected Result | The server should run and be initialized.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                                                                    |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                             |

### REST API: Shut Down

| Test Case ID              | 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: Shut Down                                 |
| Test Case Description     | Verify if the server could be shut down by a key and not by closing the tab.                         |
| Test Case Pre-conditions  | The server should be running.                           |
| Test Case Steps           | 1. Open your terminal with the server. <br> 2. Click on `space`. |
| Test Case Expected Result | The server should shut down.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                                                                    |
| Test Case Priority        | Low 3 |
| Test Case Assigned To     | Maxime Thizeau                                                             |

### REST API: GET Method

#### Input: Blank Space

| Test Case ID              | 3 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: Blank Space                                   |
| Test Case Description     | Verify an error is sent when a wrong Input is inserted.                    |
| Test Case Pre-conditions  | The Server should be online.                                               |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=&destination=2&format=json"`|
| Test Case Expected Result | Should return an error.                                                    |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                        |

#### Input: Number Over 30 000 000

| Test Case ID              | 3 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: Number Over 30 000 000                        |
| Test Case Description     | Verify an error is returned if the number exceeds the number of nodes.        |
| Test Case Pre-conditions  | The server should be online.                                               |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=300000000&destination=2&format=json"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                             |

#### Input: Char

| Test Case ID              | 3 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is put as input.                 |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=a&destination=2&format=json"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                       |

#### Input: String

| Test Case ID              | 3 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is put as input.                                              |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=aaaa&destination=2&format=json"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Float

| Test Case ID              | 3 - 5                                                                        |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float is put as input.                  |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=1.2&destination=2&format=json"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                        |

#### Input: Signed Number

| Test Case ID              | 3 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is put as input.                                               |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=-1&destination=2&format=json"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                           |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                   |

#### Input: 0

| Test Case ID              | 3 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Input: 0                                                      |
| Test Case Description     | Verify an error is returned when 0 is out as input.                                               |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=0&destination=2&format=json"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                          |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                        |

#### Good Inputs

| Test Case ID              | 3 - 8                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Good Inputs                                                      |
| Test Case Description     | Verify the answer is returned properly with the right data.                                               |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=1&destination=2&format=json"` |
| Test Case Expected Result | Should return the path and travel time from node 1 to 2.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                          |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                        |

#### Output: XML?

| Test Case ID              | 4 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Output: XML?                                                      |
| Test Case Description     | Verify the output file is XML.                                               |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=1&destination=2&format=xml"` <br> 3. Go to the bin folder.                |
| Test Case Expected Result | An XML file should have been created with the data.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Output: JSON?

| Test Case ID              | 4 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Output: JSON?                                                      |
| Test Case Description     | Verify the output file is JSON.                                               |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=1&destination=2&format=json"` <br> 3. Go to the bin folder.                  |
| Test Case Expected Result | A JSON file should have been created with the data.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Non-handled File Format

| Test Case ID              | 4 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Non-handled File Format                                                      |
| Test Case Description     | Verify an error is returned when a file format other than XML and JSON is asked for.                                               |
| Test Case Pre-conditions  | The server should be online.                                                  |
| Test Case Steps           | 1. Open another terminal <br> 2. Enter: `curl "http://localhost:8080/route?source=1&destination=2&format=jpg"` |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Output: Are XML And JSON Files Similar?

| Test Case ID              | 4 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | REST API: GET Method: Output: Are XML And JSON Files Similar?                                                      |
| Test Case Description     | Verify the content of both files and compare them to see if the path and time travel are the same.                                               |
| Test Case Pre-conditions  | The server should be online. You should have an XML and a JSON file for the same request.                                                  |
| Test Case Steps           | 1. Go to the Bin folder. <br> 2. Open both files. <br> 3. Compare path and travel time.                  |
| Test Case Expected Result | The files contain the same data.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                         |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

## Test Cases: Algorithm

### Algorithm: Compilation And Running On Windows

| Test Case ID              | 8                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Algorithm: Compilation And Running On Windows                               |
| Test Case Description     | Verify the `startClient.cmd` is running properly.                                 |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `.\startClient.cmd`.                  |
| Test Case Expected Result | The algorithm should run.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                          |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Algorithm: Compilation And Running On macOS

| Test Case ID              | 9                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Algorithm: Compilation And Running On MacOS                                                      |
| Test Case Description     | Verify the `startClient.sh` is running properly.                                               |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `./startClient.sh`.                  |
| Test Case Expected Result | The algorithm should run.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                           |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                        |

### Running Time

| Test Case ID              | 10                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Algorithm: Running Time                                                      |
| Test Case Description     | Verify that the algorithm finds the shortest path in less than a second.                                               |
| Test Case Pre-conditions  | Having the algorithm running properly. Having the server running.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to Find my way. <br> 3. Provide a source and a destination.                  |
| Test Case Expected Result | The path should be returned in less than a second.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Accuracy

| Test Case ID              | 11                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Algorithm: Accuracy                                                      |
| Test Case Description     | Verify the travel time is in a range of 10% above the quickest path.        |
| Test Case Pre-conditions  | Having the algorithm running properly. Having the server running.                                                 |
| Test Case Steps           | 1. Open the terminal. <br> 2. Go to Find my way. <br> 3. Provide a source and a destination.             |
| Test Case Expected Result | The time travel should be between the quickest path and 10% above it.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

## Test Cases: Menu

### Menu: First Page

#### Input: Blank Space

| Test Case ID              | 12 - 1                                                                        |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: Blank Space                                       |
| Test Case Description     | Verify an error is returned when a blank space is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter a blank space.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Low  3 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Number Over 30 000 000

| Test Case ID              | 12 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: Number Over 30 000 000                                                      |
| Test Case Description     | Verify an error is returned when a big number is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter 30 000 000.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Char

| Test Case ID              | 12 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                |
| Test Case Steps           | 1. Enter a.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: String

| Test Case ID              | 12 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                |
| Test Case Steps           | 1. Enter aaa.                    |
| Test Case Expected Result | An error should be returned.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Float

| Test Case ID              | 12 - 5                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float number is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter 1.2.                  |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Signed Number

| Test Case ID              | 12 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter -1                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: 0

| Test Case ID              | 12 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: 0                                                      |
| Test Case Description     | Verify the program shuts down when a 0 is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter 0.                  |
| Test Case Expected Result | The program should shut down.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: 1

| Test Case ID              | 12 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: 1                                                      |
| Test Case Description     | Verify the "find my way" page appears when a 1 is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter 1.                  |
| Test Case Expected Result | The program should change page to the "find my way" one.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: 2

| Test Case ID              | 12 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: First Page: Input: 2                                                      |
| Test Case Description     | Verify the "Credits" page appears when a 2 is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. The server should be running.                                                 |
| Test Case Steps           | 1. Enter 2.                  |
| Test Case Expected Result | The program should shut down.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Menu: Find My Way

#### Departure: Input: Blank Space

| Test Case ID              | 13 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: Blank Space                                       |
| Test Case Description     | Verify an error is returned when a blank space is given as input.                                               |
| Test Case Pre-conditions  | The Menu and the server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter a blank space.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Low  3 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: Number Over 30 000 000

| Test Case ID              | 13 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: Number Over 30 000 000                                                      |
| Test Case Description     | Verify an error is returned when a big number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                  |
| Test Case Steps           | 1. Enter 30 000 000.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: Char

| Test Case ID              | 13 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter a.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: String

| Test Case ID              | 13 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter aaa.                    |
| Test Case Expected Result | An error should be returned.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: Float

| Test Case ID              | 13 - 5                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter 1.2.                  |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: Signed Number

| Test Case ID              | 13 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Page: Departure: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter -1.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: 0

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: 0                                                      |
| Test Case Description     | Verify the program sends an error when a 0 is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter 0.                  |
| Test Case Expected Result | The program should send an error back.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Departure: Input: Good Input

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Departure: Input: Good Input                                                      |
| Test Case Description     | Verify the program ask you for a destination when the input is valid.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page.                                                 |
| Test Case Steps           | 1. Enter a number between 1 and 23947347.                  |
| Test Case Expected Result | The program should validate the answer and ask for a destination.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau   |

#### Destination: Input: Blank Space

| Test Case ID              | 13 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: Blank Space                                       |
| Test Case Description     | Verify an error is returned when a blank space is given as input.                                               |
| Test Case Pre-conditions  | The Menu and the server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter a blank space.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Low  3 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: Number Over 30 000 000

| Test Case ID              | 13 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: Number Over 30 000 000                                                      |
| Test Case Description     | Verify an error is returned when a big number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                 |
| Test Case Steps           | 1. Enter 30 000 000.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: Char

| Test Case ID              | 13 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter a.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: String

| Test Case ID              | 13 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter aaa.                    |
| Test Case Expected Result | An error should be returned.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: Float

| Test Case ID              | 13 - 5                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter 1.2.                  |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: Signed Number

| Test Case ID              | 13 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Page: Destination: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter -1.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: 0

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: 0                                                      |
| Test Case Description     | Verify the program sends an error when a 0 is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter 0.                  |
| Test Case Expected Result | The program should send an error back.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Destination: Input: Good Input

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Destination: Input: Good Input                                                      |
| Test Case Description     | Verify the program validate a good input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure should have been given.                                                |
| Test Case Steps           | 1. Enter a number between 1 and 23947347.                  |
| Test Case Expected Result | The program should show a new menu.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau   |

#### Input: Blank Space

| Test Case ID              | 13 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Input: Blank Space                                       |
| Test Case Description     | Verify an error is returned when a blank space is given as input.                                               |
| Test Case Pre-conditions  | The Menu and the server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter a blank space.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Low  3 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Number Over 30 000 000

| Test Case ID              | 13 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Input: Number Over 30 000 000                                                      |
| Test Case Description     | Verify an error is returned when a big number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                 |
| Test Case Steps           | 1. Enter 30 000 000.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Char

| Test Case ID              | 13 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter a.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: String

| Test Case ID              | 13 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter aaa.                    |
| Test Case Expected Result | An error should be returned.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Float

| Test Case ID              | 13 - 5                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter 1.2.                  |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Signed Number

| Test Case ID              | 13 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Page: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter -1.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: 0

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Input: 0                                                      |
| Test Case Description     | Verify the program shuts down when a 0 is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter 0.                  |
| Test Case Expected Result | The program shuts down.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: 1

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: 1                                                      |
| Test Case Description     | Verify the program run and find the shortest path.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter 1.                  |
| Test Case Expected Result | The program should run.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau   |

#### Input: 2 - XML

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: 2                                                      |
| Test Case Description     | Verify the program change the input from XML to JSON.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter 2.                  |
| Test Case Expected Result | The program change the type format to JSON.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau   |

#### Input: 2 - JSON

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: 2                                                      |
| Test Case Description     | Verify the program change the input from JSON to XML.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter 2.                  |
| Test Case Expected Result | The program change the type format to XML.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau   |

#### Input: 3

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: 3                                                      |
| Test Case Description     | Verify the program ask you for a departur again when the input is 3.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. A departure and a destination should have been given.                                                |
| Test Case Steps           | 1. Enter 3.                  |
| Test Case Expected Result | The program should ask you for a new departure.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau   |

#### Quit: Input: Blank Space

| Test Case ID              | 13 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Quit: Input: Blank Space                                       |
| Test Case Description     | Verify an error is returned when a blank space is given as input.                                               |
| Test Case Pre-conditions  | The Menu and the server should be running. You should be on the Find My Way page. The path should have been found.                                                |
| Test Case Steps           | 1. Enter a blank space.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Low  3 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Quit: Input: Number Over 30 000 000

| Test Case ID              | 13 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Quit: Input: Number Over 30 000 000                                                      |
| Test Case Description     | Verify an error is returned when a big number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. The path should have been found.                                                 |
| Test Case Steps           | 1. Enter 30 000 000.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Quit: Input: Char

| Test Case ID              | 13 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Quit: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. The path should have been found.                                                |
| Test Case Steps           | 1. Enter a.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Quit: Input: String

| Test Case ID              | 13 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Quit: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. The path should have been found.                                                |
| Test Case Steps           | 1. Enter aaa.                    |
| Test Case Expected Result | An error should be returned.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Quit: Input: Float

| Test Case ID              | 13 - 5                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Quit: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. The path should have been found.                                                |
| Test Case Steps           | 1. Enter 1.2.                  |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Quit: Input: Signed Number

| Test Case ID              | 13 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Page: Quit: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. The path should have been found.                                               |
| Test Case Steps           | 1. Enter -1.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Quit: Input: 0

| Test Case ID              | 13 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Find My Way: Quit: Input: 0                                                      |
| Test Case Description     | Verify the program shows the main page when a 0 is given as input.                                               |
| Test Case Pre-conditions  | The Menu and server should be running. You should be on the Find My Way page. The path should have been found.                                                |
| Test Case Steps           | 1. Enter 0.                  |
| Test Case Expected Result | The program should show the main page.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Menu: Credits

#### Input: Blank Space

| Test Case ID              | 14 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: Blank Space                                       |
| Test Case Description     | Verify an error is returned when a blank space is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                 |
| Test Case Steps           | 1. Enter a blank space.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Low  3 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Number Over 30 000 000

| Test Case ID              | 14 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: Number Over 30 000 000                                                      |
| Test Case Description     | Verify an error is returned when a big number is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                  |
| Test Case Steps           | 1. Enter 30 000 000.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Char

| Test Case ID              | 14 - 3                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: Char                                                      |
| Test Case Description     | Verify an error is returned when a character is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                 |
| Test Case Steps           | 1. Enter a.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: String

| Test Case ID              | 14 - 4                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: String                                                      |
| Test Case Description     | Verify an error is returned when a string is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                 |
| Test Case Steps           | 1. Enter aaa.                    |
| Test Case Expected Result | An error should be returned.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2|
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Float

| Test Case ID              | 14 - 5                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: Float                                                      |
| Test Case Description     | Verify an error is returned when a float number is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                 |
| Test Case Steps           | 1. Enter 1.2.                  |
| Test Case Expected Result | Should return an error.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: Signed Number

| Test Case ID              | 14 - 6                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: Signed Number                                                      |
| Test Case Description     | Verify an error is returned when a signed number is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                 |
| Test Case Steps           | 1. Enter -1.                  |
| Test Case Expected Result | An error should be returned.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

#### Input: 0

| Test Case ID              | 14 - 7                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Menu: Credits: Input: 0                                                      |
| Test Case Description     | Verify the program shuts down when a 0 is given as input.                                               |
| Test Case Pre-conditions  | The Menu should be running. You should be on the Credits page.                                                 |
| Test Case Steps           | 1. Enter 0.                  |
| Test Case Expected Result | The program should send you back to the main page.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

## Test Cases: Validation Tool

### Validation Tool: Compilation And Running On Windows

| Test Case ID              | 15                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Validation Tool: Compilation And Running On Windows                                                      |
| Test Case Description     | Verify the `startValidator.cmd` is running properly.                                              |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `.\startValidator.cmd`.                  |
| Test Case Expected Result | The validator should run without any errors.                               |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Validation Tool: Compilation And Running On macOS

| Test Case ID              | 16                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Validation Tool: Compilation And Running On MacOS                                                      |
| Test Case Description     | Verify the `startValidator.sh` is running properly.                                                |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `./startValidator.sh`.                 |
| Test Case Expected Result | The validator should run without any errors.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Format Conformity - 1

| Test Case ID              | 17 - 1                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Validation Tool: Format Conformity - 1                                                    |
| Test Case Description     | Verify if the file contains a table with three columns, 1 for landmark A, another for landmark B, and the last one for travel time.                                               |
| Test Case Pre-conditions  | Having a CSV file, and a running validator.                                                  |
| Test Case Steps           | 1. Put the CSV file on the same level as the validator. <br> 2. Run the validator.                  |
| Test Case Expected Result | Return an error.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### Format Conformity - 2

| Test Case ID              | 17 - 2                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Validation Tool: Format Conformity - 2                                                    |
| Test Case Description     | Verify if the file contains a table with three columns, 1 for landmark A, another for landmark B, and the last one for travel time.                                               |
| Test Case Pre-conditions  | Having a CSV file, and a running validator.                                                  |
| Test Case Steps           | 1. Put the CSV file on the same level as the validator. <br> 2. Run the validator.                  |
| Test Case Expected Result | Run without any errors.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                             |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### File Conformity

| Test Case ID              | 18                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Validation Tool: File Conformity                                                      |
| Test Case Description     | Verify if the file is a CSV file.                                               |
| Test Case Pre-conditions  | Having a CSV file.                                                  |
| Test Case Steps           | 1. Put the CSV file on the same level as the validator. <br> 2. Run the validator.                  |
| Test Case Expected Result | Run without any errors.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                        |

### Nodes Connection

| Test Case ID              | 19                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Validation Tool: Nodes Connection                                                      |
| Test Case Description     | Verify that every Node is accessible.                                               |
| Test Case Pre-conditions  | Having the validator running and a CSV file.                                                  |
| Test Case Steps           | 1. Put the CSV file on the same level as the validator. <br> 2. Run the validator.                   |
| Test Case Expected Result | Run without any errors.                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | Medium 2 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

## Test Cases: PathQuick

### PathQuick: Compilation And Running On Windows

| Test Case ID              | 15                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | PathQuick: Compilation And Running On Windows                                                      |
| Test Case Description     | Verify the `pathQuickLauncher.cmd` is running properly.                                              |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `.\pathQuickLauncher.cmd`.                  |
| Test Case Expected Result | Two terminals should appear, one for the server and another for the menu.                               |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                              |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |

### PathQuick: Compilation And Running On macOS

| Test Case ID              | 16                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | PathQuick: Compilation And Running On MacOS                                                      |
| Test Case Description     | Verify the `pathQuickLauncher.sh` is running properly.                                                |
| Test Case Pre-conditions  | Having the GitHub repository on your own machine.                                                  |
| Test Case Steps           | 1. Open your terminal. <br> 2. Go to the src folder. <br> 3. Enter this cmd line: `./pathQuickLauncher.sh`.                 |
| Test Case Expected Result | Two terminals should appear, one for the server and another for the menu.                                 |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | To Test                            |
| Test Case Priority        | High 1 |
| Test Case Assigned To     | Maxime Thizeau                                                         |