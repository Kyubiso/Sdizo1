

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include "stack.h"
#include "Table.h"
#include "MaxHeap.h"
#include "List.h"

using namespace std;

using namespace std;

int opt;

int main() {
    mainMenu: // Etykieta do komendy goto
    cout <<
         "===MENU GŁÓWNE===" << endl <<
         "[1] Tabela" << endl <<
         "[2] Lista" << endl <<
         "[3] Kopiec" << endl <<
         "[]" << endl <<
         "[]" << endl <<
         "[6] Test" << endl <<
         "=================" << endl << "<";

    cin >> opt;

    switch (opt) {
        case 1:
            Table();
            break;
        case 2:
            List();
            break;
        case 3:
            MaxHeap();
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




