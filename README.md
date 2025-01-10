# 2024-2025-project-3-quickest-path-team-6

This project implements a REST API server in C++ to calculate the quickest path between two landmarks in the United States. The server supports both JSON and XML responses and uses platform-specific socket programming for multi-platform compatibility (Windows and POSIX systems).

## Features

- HTTP GET endpoint for calculating the quickest path.
    
- Supports JSON and XML response formats.
    
- Multi-threaded to handle multiple client connections simultaneously.
    
- Multi-platform support (Windows, Linux, macOS) using conditional compilation.
    
- Modular code structure with clear separation of concerns.
    

## Requirements

- **Operating System**: Windows (Winsock2) or Linux/macOS (POSIX sockets).
    
- **Compiler**: Microsoft Visual Studio (MSVC), GCC, or Clang.
    
- **Dependencies**:
    
    - Winsock2 library (`Ws2_32.lib`) for Windows.
        
    - POSIX socket libraries for Linux/macOS.
        

## Setup and Compilation

### Compilation

1. Clone the repository:
    
    ```
    git clone <repository-url>
    cd <repository-folder>
    ```
    
2. Open the project in your IDE or compiler:
    
    - **For Windows (MSVC)**:
        
        - Ensure `Ws2_32.lib` is linked in the project settings.
            
    - **For Linux/macOS**:
        
        - Ensure POSIX socket libraries are available (default for most systems).
            
3. Build the project.
    

### Running the Server

1. Run the compiled binary.
    
2. The server listens on `localhost:8080` by default. You can change the port by modifying the `PORT` variable in `api.cpp`.
    

### Example Requests

- Use tools like `curl`, Postman, or a browser to send requests to the server.
    

#### Example Request

**GET** `http://localhost:8080/quickest-path?source=LandmarkA&dest=LandmarkB`

Headers:

- `Accept: application/json` for JSON response.
    
- `Accept: application/xml` for XML response.
    

#### Example Response (JSON)

```
{
  "travel_time": 15,
  "path": ["LandmarkA", "LandmarkB", "LandmarkC"]
}
```

#### Example Response (XML)

```
<response>
  <travel_time>15</travel_time>
  <path>
    <landmark>LandmarkA</landmark>
    <landmark>LandmarkB</landmark>
    <landmark>LandmarkC</landmark>
  </path>
</response>
```

## Notes

- Replace the placeholder backend logic in `algorithm.cpp` with an actual pathfinding algorithm.
    
- The code uses conditional compilation to support multi-platform compatibility.
    
- Ensure proper environment setup for your operating system.
    

## Future Enhancements

- Refine error handling for unsupported HTTP methods and invalid requests.
    
- Optimize performance for handling large datasets.
    

## Troubleshooting

- If the server fails to start, ensure port `8080` is available or change the port in the code.
    
- Verify all required libraries are correctly linked.