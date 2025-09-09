// Complete Guide to C++ Programming Foundations
// Exercise 08_06
// Queues and Stacks, by Eduardo Corpeño

#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::queue<std::string> eventQueue;  // FIFO container for game events
    std::stack<std::string> undoStack;   // LIFO container for undo operations

    // Adding events to the queue
    eventQueue.push("Move Forward");
    eventQueue.push("Collect Coin");
    eventQueue.push("Attack Enemy");

    // Processing events in FIFO order
    while (!eventQueue.empty()) {
        std::string currentEvent = eventQueue.front();
        std::cout << "Performing event: " << currentEvent << std::endl;
        eventQueue.pop();
        undoStack.push(currentEvent);
    }

    // Processing events in LIFO order
    while (!undoStack.empty()) {
        std::string currentEvent = undoStack.top();
        std::cout << "Performing event: " << currentEvent << std::endl;
        undoStack.pop();
    }

    std::cout << std::endl << std::endl;
    return 0;
}
