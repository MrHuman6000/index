//
// Created by Admin on 06.07.2026.
//


#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("../learn.cpp");
    if (!file.is_open()) {
        std::cerr << "Error: File doesn't exit!" << std::endl;
        return 1;
    }

    std::string line;
    int line_count = 0;
    int function_count = 0;

    while (std::getline(file, line)) {
        line_count++;
        if (line.find("void ") != std::string::npos) {
            function_count++;
        }
    }
    std::cout << "Lines in the file " << line_count << std::endl;
    std::cout << "Function declarations found " << function_count << std::endl;

    file.close();
    return 0;

}