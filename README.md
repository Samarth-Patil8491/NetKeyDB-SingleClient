# NetKeyDB-SingleClient
NetKeyDB-SingleClient is a lightweight in-memory key-value database server written in C++ using TCP sockets. It supports basic commands like SET, GET, DEL, and EXIT while handling one client at a time. This project demonstrates socket programming, command parsing, and the core working principles of a simple database server.

**NetKeyDB-SingleClient**

NetKeyDB-SingleClient is a lightweight in-memory key–value database server developed in C++ using TCP socket programming. It is a beginner-friendly project designed to demonstrate how basic database servers (like Redis) work internally, focusing on networking, command parsing, and data storage concepts.

This version supports only one client connection at a time, making it ideal for understanding the fundamentals before moving to multi-client and advanced system design.

**Project Goal**

The main objective of this project is to build a simple database server from scratch that:

Accepts commands over a network connection

Stores data in memory

Processes database operations in real time

Demonstrates how client–server architecture works

**Technologies Used**

C++ (Core programming)

WinSock API (TCP socket communication)

STL Unordered Map (In-memory data storage)

StringStream (Command parsing)

**How It Works**

The server starts and listens on port 8080.

A client connects using Telnet/Ncat.

The server receives text commands.

Commands are parsed and executed.

Data is stored in an in-memory key–value store.

A response is sent back to the client.

The database exists only while the server is running (no file storage).

**Supported Commands**
Command	Description
SET key value	Stores a value for a key
GET key	Retrieves the value of a key
DEL key	Deletes a key from the database
EXIT	Disconnects the client and stops the server
**Features**

Real-time key–value storage

TCP socket server

Command-line based client interaction

Error handling for invalid commands

Simple and readable architecture

**How to Run**

**Compile:**

g++ server.cpp -o server -lws2_32  ##Copy this and paste in any code editor terminal


**Run server:**

server.exe   ##Copy this and paste in any code editor terminal


**Connect using another terminal:**

ncat localhost 8080 ##Open power shell and type thus command and wait for the ncar client to connect and get started for pls see the above supported command section  


**Learning Outcomes**

This project helps understand:

Socket programming fundamentals

Client–server communication

In-memory database design

Command interpreters

Basics of backend system development

**Future Improvements**

Multi-client support (threads)

Authentication system

Data persistence (save to file)

More commands (LIST, UPDATE, etc.)
