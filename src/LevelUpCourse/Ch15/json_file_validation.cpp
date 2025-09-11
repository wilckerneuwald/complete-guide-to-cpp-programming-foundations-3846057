/*
    Write an application that reads a json file and check if it is valid or not.
    Base your verdict on balance of brackets, braces and quotes.
    Keep it simple:
    - Only count double quotes (""), not single quotes('').
    - Assume simple content with no escape chars inside strings.
    - Ignore everything between quotes.
*/

#include <fstream>
#include <iostream>
#include <stack>
#include <string>

int main() {
    int count_line = 0;
    std::string line;
    std::stack<char> stack;
    std::ifstream file("example.json");

    while (std::getline(file, line)) {
        count_line++;
        for (char c : line) {
            switch (c) {
                case '{':
                    stack.push(c);
                    break;
                case '}':
                    if (stack.size() > 0 && stack.top() == '{') {
                        stack.pop();
                    } else {
                        std::cout << "Invalid json! Unexpected closed bracket on line: "
                                  << count_line << std::endl;
                        return 0;
                    }
                    break;
                case '[':
                    stack.push(c);
                    break;
                case ']':
                    if (stack.size() > 0 && stack.top() == '[') {
                        stack.pop();
                    } else {
                        std::cout << "Invalid json! Unexpected closed brace on line: " << count_line
                                  << std::endl;
                        return 0;
                    }
                    break;
                case '"':
                    if (stack.size() > 0 && stack.top() == '"') {
                        stack.pop();
                    } else if (stack.top() == '{' || stack.top() == '[') {
                        stack.push(c);
                    } else {
                        std::cout << "Invalid json! Open quote on line: " << count_line
                                  << std::endl;
                        return 0;
                    }
                    break;
            }
        }
    }

    file.close();

    if (!stack.size())
        std::cout << "Valid json!" << std::endl;
    else
        std::cout << "Invalid json! Not closed items: " << stack.size() << std::endl;

    return 0;
}