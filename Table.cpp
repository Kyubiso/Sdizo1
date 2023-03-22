//
// Created by kuba on 19/03/23.
//

#include <fstream>
#include <iostream>
#include "Table.h"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

Table::Table() {
    displayMenu();
}

void Table::enlarge(bool isFirst) {
    size_t newSize = arrsize+1;
    int *newArray = new int[newSize];
    copy(data, data + arrsize, newArray+isFirst); // Jesli dodajemy na początku to
    delete[]data; //Enlarge robi: wolne miejsce na starcie + reszta przepisana
    data=newArray;
}

void Table::reduce(bool isFirst) {
    if(arrsize==0) return;
    size_t newSize = arrsize-1;
    int* newArray = new int[newSize];
    copy(data+isFirst, data + newSize+ isFirst, newArray);
    delete[]data;
    data=newArray;
}

void Table::moveLeft(int index) {
    size_t newSize = arrsize-1;
    int* newArray = new int[newSize];
    copy(data, data + index, newArray); // elementy nie zmienialne
    copy(data+index+1,data+arrsize, newArray+index); //elementy na prawo
    arrsize = newSize;
    delete[]data;
    data=newArray;
}

void Table::moveRight(int index) {
    size_t newSize = arrsize+1;
    int *newArray = new int[newSize];
    copy(data,data+index,newArray);
    copy(data + index, data + arrsize, newArray+index+1); // zrobi sie jedno wolne miejsce w tablicy
    arrsize=newSize;
    delete[]data;
    data=newArray;
}

void Table::addFirst(int num) {
    enlarge(true);
    data[0]=num;
}
void Table::addLast(int num) {
    enlarge(false);
    data[arrsize-1]=num;
}
void Table::addAt(int num, int index) {
    if (index < 0 || index > arrsize) {
        cout<<"Index poza tabela";
        return;
    }
    moveRight(index);
    data[index]=num;

}

void Table::deleteFist() {
    reduce(true);
}
void Table::deleteLast() {
    reduce(false);
}
void Table::deleteAt(int index) {
    if (index >= arrsize) {
        cout << "Indeks poza tabelą"<<endl;
        return;
    }
    moveLeft(index);
}
bool Table::contains(int num) {
    for (int i = 0; i < arrsize; i++) {
        if (data[i] == num) {
            cout<<"Element znajduje się w indexie: "<<num<<endl;
            return true;
        }
    }
    cout << "Nie znaleziono";
    return false;
}
void Table::display() {
    if (arrsize == 0) {
        cout<<"Brak tabeli"<<endl;
    }
    for (int i = 0; i < arrsize; i++) {
        cout<<i<<". "<<data[i]<<endl;
    }
}

void Table::clear() {
    fill(data, data + arrsize, 0);
    arrsize=0;
    delete[]data;
    data= nullptr;
}

size_t Table::getSize(){
    return arrsize;
};

void Table::swap(size_t firstIndex, size_t secondIndex) {
    int temp = data[firstIndex];
    data[firstIndex]=data[secondIndex];
    data[secondIndex]=temp;
}


int Table::operator[](const size_t index) {
    if (index >= arrsize) {
        throw out_of_range("Indeks poza tabela");
    }
    return data[index];
}
int Table::operator[](const size_t index) const {
    if (index>=arrsize) throw out_of_range("Indeks poza tabela");
    return data[index];
}


void Table::generateTable(int size) {
    tab = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        tab[i] = 1 + (::rand() % 100);
    }
    cout << "Wylosowana tabela: " << endl;
    for (int i = 0; i < size; i++) {
        cout << tab[i] << endl;
    }
}

void Table::generateTable() {
    int size;
    cout << "Podaj rozmiar: ";
    cin >> size;
    generateTable(size);
};


int Table::loadFromFile(string filename) {
    string *plik = static_cast<string *>(::malloc(sizeof(string))); // Miejsce w pamieci do przetrzymywania stringa
    int size = 1;                                                         //Zmieniajacy sie rozmiar tablicy
    fstream stream(filename);                                       // Strumien do odczytywania
    tab = (int *) malloc(sizeof(int));                            //Zadeklarowanie miejsca na tablice
    while (getline(stream, *plik)) {
        ::realloc(tab, size * sizeof(int));                //Powiekszenie rozmiaru tablicy
        cout << *plik;                                         // Wyswietlenie bierzącego elementu
        *tab++ = stoi(*plik);                                 // Przypisanie do tablicy stringa przerobionego na inta
        size++;                                                  // zwiekszenie rozmiaru
    }
    stream.close();
    ::free(plik);
    cout << *tab;
}

int Table::loadFromFile() {
    string filename;
    cout << "Podaj nazwe pliku";
    cin >> filename;
    loadFromFile(filename);

}


Table::~Table() {
    free(data);
    data= nullptr;
    arrsize=0;
} //czyszczenie tabelki

void Table::displayMenu() {
    menu:
    cout <<
         "========MENU TABELI===========" << endl <<
         "[1] Wygeneruj Tabelę" << endl <<
         "[2] Wczytaj Tabelę z pliku" << endl <<
         "[3] Usuń element z Tabeli" << endl <<
         "[4] Usuń Tabelę" << endl <<
         "==============================" << endl << ">";
    int opt;
    cin >> opt;
    switch (opt) {
        case 1:
            generateTable();
            break;
        case 2:
            loadFromFile();
        default:
            cout << "Nie ma takiej opcji" << endl;
            goto menu;
    }
}