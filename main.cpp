

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include "stack.h"
#include "Table.h"

using namespace std;

using namespace std;

int opt;

void createTable() {
    Table table = *new Table();
}

void createStack() {
    stack stos = *new stack();
};


int main() {
    mainMenu: // Etykieta do komendy goto
    cout <<
         "===MENU GŁÓWNE===" << endl <<
         "[1] Tabela" << endl <<
         "[2] Stos" << endl <<
         "[]" << endl <<
         "[]" << endl <<
         "[]" << endl <<
         "[6] Test" << endl <<
         "=================" << endl << "<";

    cin >> opt;

    switch (opt) {
        case 1:
            createTable();
            break;
        case 2:
            createStack();
            break;
        case 6:
            struct timespec ts;
            struct timespec te;
            clock_gettime(CLOCK_REALTIME, &ts);
            usleep(100);
            clock_gettime(CLOCK_REALTIME, &te);
            cout << te.tv_nsec - ts.tv_nsec << endl;
            break;
        default:
            cout << "Nie ma takiej liczby" << endl;
            goto mainMenu;

    }

}




