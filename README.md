# User Authentication Service

User authentication service is a C++ program that manage authenticate user login with username and password

## Feature

* Use Hash tables to store username and password
* Support debug mode with commands listed below
* Developed with TDD (Test-Driven Development)

## Installation

1. cd into app/ folder

```bash
cd app
```

2. build the program

```bash
clang++ -std=c++20 -o main *.cpp
```

3. run the executable

```bash
./main
```

## Usage

### User Interface

**Create** *username* *password*: create username/password combination  
**LOGIN** *username* *password*: validate username/password combination  
**REMOVE** *username*: remove user with given username  
**CLEAR**: Remove all username/password combination  
**QUIT**: quit the program  

### Debug Command

**DEBUG ON**: turns on debug mode  
**DEBUG OFF**: turns off debug mode  
**LOGIN COUNT**: show the number of current username/password combination  
**BUCKET COUNT**: show the number of buckets in the hash table at present  
**LOAD FACTOR**: show the number of load factor of the hash table at present  
**MAX BUCKET SIZE**: shows the length of the largest bucket in the hash table  
