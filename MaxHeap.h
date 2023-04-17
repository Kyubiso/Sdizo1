//
// Created by kuba on 22/03/23.
//

#ifndef SDIZO1_MAXHEAP_H
#define SDIZO1_MAXHEAP_H

#include "Table.h"

class MaxHeap {
private:
    Table data;
public:
    MaxHeap();
    ~MaxHeap();
    void clear();
    void add(int num);
    void deleteAt(size_t index=0); // 0 domyś;nie root
    void display();
    bool contains(int num);
    void deleteValue(int num);
    void displayMenu();
private:
    size_t getParent(size_t index);
    void display(size_t index, string odstep, bool prawy);
    size_t getLeft(size_t index);
    size_t getRight(size_t index);
    size_t getIndexOf(int num);
    void fixUp(size_t pos);
    void fixDown(size_t pos);

};


#endif //SDIZO1_MAXHEAP_H
