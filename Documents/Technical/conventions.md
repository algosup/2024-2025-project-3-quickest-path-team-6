# Conventions

This file outlines the conventions of the project, including the *writing and code* ones.

## Writing conventions

**All documentations** have to be written in **proper English**.

- **All the folders** have to be named in **PascalCase**.

❌
```md
./folder
./some_Folders
```

✅
```md
./Folder
./SomeFolders
```

- **All the files** have to be named in **camelCase**.

❌
```md
./File
./Another-file
```

✅
```md
./file
./anotherFile
```

- **All the parts' title** have to be named in **PascalCase**, with spaces.

❌
```md
## part
## the-Other-Part
```

✅
```md
## Part
## The Other Part
```

### Commits conventions

- **All the commits** have to be named regarding what changes have been done.

❌
```md
Updated functionalSpecifications.md
done check algo
```

✅
```md
Added requirements part
Implemented the checking algorithm
```

- **All the commits** have to contain a proper description regarding what changes have been done.

❌
```md
the algo is done
```

✅
```md
The requirements part has been added to the functional specifications. The glossary has been updated too.

The checking algorithm has been implemented into the code base. It returns the expected time to the main program.
```

## Code conventions

- **All the classes** have to be named in **PascalCase**.

❌
```c++
class the_class;
class anotherClass;
```

✅
```c++
class MainClass;
class AnotherClass;
```

- **All the functions** have to be named in **camelCase**.

❌
```c++
int MAIN(){}
int Function(){}
```

✅
```c++
int main(){}
int anotherFunction(){}
```

- **All the variables** have to be named in **snake_case**.

❌
```c++
int VAr;
std::string Second_VAR = "Hello";
```

✅
```c++
int var = 1;
std::string second_var = "Hello";
```

- Although, the **constants** have to be written in **UPPER_SNAKE_CASE**.

❌
```c++
const int constant = 1;
std::string Second_Constant = "Hello";
```

✅
```c++
const int CONSTANT = 1;
std::string SECOND_CONSTANT = "Hello";
```

- **Some comments** have to be written within the code base, outlining what a class or a function should do. **All the comments** have to be written to serve specific purposes. Software Engineers have to avoid writing useless comments.

❌
```c++
// initializing an integer
int var = 1;
```

```c++
// this function returns if a number is even or not
bool isEven(int number){
    return number % 2; // returns if the number is even or not
}
```

✅
```c++
int var = 1;
```

```c++
/* 
    This function returns a boolean if a number is even or not.
    Parameters: 
        - number (integer)
*/
bool isEven(int number){
    return number % 2;
}
```
