//
// Created by kuba on 19/03/23.
//

#ifndef SDIZO_TABLE_H
#define SDIZO_TABLE_H

#include <string>
#include "iostream"

using namespace std;


class Table {
    int *tab;
    int tabSize;
private:
    void enlarge(bool isFirst=false);
    void reduce(bool isFirst=false);
    void moveRight(int index);
    void moveLeft(int index);

    size_t arrsize;
    int* data;


public:
    int operator[](const size_t index);
    int operator[](const size_t index) const;

    Table();

    ~Table();

    int loadFromFile(string filename);

    int loadFromFile();

    int saveToFile(string filename);
    void displayMenu();
    void generateTable(int size);
    void generateTable();
    void deleteValue(int num);
    void addFirst(int num);
    void addLast(int num);
    void addAt(int num, int index);
    void deleteFist();
    void deleteLast();
    void deleteAt(int index);
    bool contains(int num);
    void display();
    void clear();
    size_t getSize();
    void swap(size_t firstIndex, size_t secondIndex);


};


#endif //SDIZO_TABLE_H
