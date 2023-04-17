#include "MaxHeap.h"
#include "Table.h"

//
// Created by kuba on 22/03/23.
//
MaxHeap::MaxHeap() {displayMenu();}

MaxHeap::~MaxHeap() {}

void MaxHeap::clear() {}

void MaxHeap::add(int num) {
    data.addLast(num);
    fixUp(data.getSize() - 1);
}

void MaxHeap::deleteAt(size_t index) {
    if (index >= data.getSize()) {
        cout << "Indeks poza kopcem" << endl;
    }
}// 0 domyś;nie root
void MaxHeap::display() {
    if (data.getSize() == 0) {
        cout << "Brak kopca";
        return;
    }
    display(0,"",false);
}

void MaxHeap::display(size_t index, string odstep, bool prawy) {
    cout << odstep;
    if (index < data.getSize()) cout << odstep;
    if (prawy) {
        cout << "R:  ";
        odstep += "    ";
    } else {
        cout << "L:   ";
        odstep="|   ";
    }
    cout<<data[index]<<endl;
    display(getLeft(index),odstep,false);
    display(getRight(index), odstep, true);
}

bool MaxHeap::contains(int num) {
    return data.contains(num);
}

void MaxHeap::deleteValue(int num) {
    size_t index = getIndexOf(num);
    if (index != -1) {
        data.swap(index,data.getSize()-1);
        data.deleteLast();
        fixDown(index);
    }
}


size_t MaxHeap::getParent(size_t index) {
    return (index-1)/2;
}

size_t MaxHeap::getLeft(size_t index) {
    return index*2+1;
}

size_t MaxHeap::getRight(size_t index) {
    return index*2+2;
}

size_t MaxHeap::getIndexOf(int num) {
    for (size_t i = 0; i < data.getSize(); i++) {
        if (data[i] == num) {
            return i;
        }
    }
    return -1;
}

void MaxHeap::fixUp(size_t pos) {
    while (pos != 0) {
        if (data[pos] > data[getParent(pos)]) {
            data.swap(pos, getParent(pos));
        }
        pos = getParent(pos);
    }
}

void MaxHeap::fixDown(size_t pos) {
    size_t size = data.getSize();
    size_t largest = pos;
    if (getLeft(pos) < size && data[getLeft(pos)] > data[largest])
        largest = getLeft(pos);

    if (getRight(pos) < size && data[getRight(pos)] > data[largest])
        largest = getRight(pos);

    if (largest == pos) return;
    else {
        data.swap(largest, pos);
        fixDown(largest);
    }
}

void MaxHeap::displayMenu() {
    int number;
    menu:
    cout<<
    "=============Kopiec============="<<endl<<
    "[1]Dodaj element"<<endl<<
    "[2]Usuń element"<<endl<<
    "[3]Wyświetl Kopiec"<<endl<<
    "[4]Usuń element o danym indeksie"<<endl<<
    "[5]Wyjdź"<<endl;

    int opt;
    cout<<"<";
    cin>>opt;

    switch (opt) {
        case 1:
            cout<<"Wprowadź liczbe: ";
            cin>>number;
            add(number);
            goto menu;
        case 2:
            cout << "Który element usunąć? ";
            cin>>number;
            deleteValue(number);
            goto menu;
        case 3:
            display();
            goto menu;
        case 4:
            cout << "Podaj indeks: ";
            cin>>number;
            deleteAt(number);
            goto menu;
        case 5:
            break;

    }
}

#include "MaxHeap.h"
