//NetKey Data Base(DB)
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <winsock2.h>
#include <algorithm>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    unordered_map<string, string> database;
    

    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&address, sizeof(address));
    listen(server_fd, 5);

    cout << "Server started on port 8080 pls try to connect.......\n";

    SOCKET client_socket = accept(server_fd, nullptr, nullptr);
    cout << "Client connected!\n";

    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));

        int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0) break;

        buffer[bytes] = '\0';
        string line(buffer);

        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());

        if (line.empty()) continue;

        stringstream ss(line);
        string command, key, value, extra;
        ss >> command;

        string response;

        if (command == "SET" || command == "set") {
            ss >> key >> value >> extra;
            if (key.empty() || value.empty() || !extra.empty())
                response = "Error: Usage -> SET key value\n";
            else {
                database[key] = value;
                response = "OK\n";
            }
        }
        else if (command == "GET" || command == "get") {
            ss >> key >> extra;
            if (database.find(key) != database.end())
                response = database[key] + "\n";
            else
                response = "NULL\n";
        }
        else if (command == "DEL" || command == "del") {
            ss >> key >> extra;
            if (database.erase(key))
                response = "1\n";
            else
                response = "0\n";
        }
        else if (command == "EXIT" || command == "exit") {
            response = "Server shutting down...\n";
            send(client_socket, response.c_str(), response.size(), 0);
            break;  // Exit loop and shut server
        }
        else {
            response = "Unknown command\n";
        }

        send(client_socket, response.c_str(), response.size(), 0);
    }

    cout << "Server stopped.\n";

    closesocket(client_socket);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}

