//
// Created by kuba on 19/03/23.
//

#ifndef SDIZO_STACK_H
#define SDIZO_STACK_H

#include "string"

using namespace std;

class stack {
    // empty, size, top , push, pop
public:
    void loadFromFile();

    void loadFromFile(string filename);

    stack();

    stack(int size);

    ~stack();

    void push();

    void display();

    void pop();

    void displayMenu();
};


#endif //SDIZO_STACK_H
