//
// Created by kuba on 19/03/23.
//
#include "iostream"
#include "stack.h"

int stackopt;
struct node {
    int data;   // element stosu (zawartość)
    node *next; //wskaźnik na kolejny element
};
node *top; // wskaźnik na górę stosu
stack::stack() {
    top = NULL; // jest stos ale nic w nim nie ma
    stackMenu:
    displayMenu();
    cout << "<";
    cin >> stackopt;
    switch (stackopt) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            //DODAJ CASE 4
        default:
            goto stackMenu; //Dodaj destruktor

    }
}


void stack::push() {
    node *temp;
    temp = new node;
    cout << "Wprowadź element który dodajesz do stosu (int)";
    cin >> temp->data; // -> odniesienie to zmiennej data w strukturze node
    temp->next = top; // To co wcześniej było szczytem teraz jest elementem następnym w stosie ( o jeden niższym )
    top = temp;     //Przypisanie adresu temp do adresu góry stosu, bo pchnięty element jest na górze czyli wskazuje sam na siebie?
}

void stack::pop() {
    if (top != NULL) { // Jeśli wskaźnik an coś wskazuje
        node *temp = top;//wskaźnikk temp ustawia się na adres góry stosu
        top = top->next; //wskaźnik top ustawia się na elemencie niższym
        cout << temp->data << "Usunięto";
        delete temp; // zwalnianie miejsca temp czyli usuwamy to co na górze stosu było
    } else cout << "Stos jest pusty";
}

void stack::display() {
    node *temp = top; // wskaxnik tymczasowy na szczyt stosu
    while (temp != NULL) {// Dopoki są elementy do wskazywania
        cout << temp->data << " ";
        temp = temp->next; //Ustawienie na kolejny lement do wyswietlenia
    }
}

void stack::displayMenu() {
    cout <<
         "===============MENU STOSU=================" << endl <<
         "[1] Dodaj element do stosu" << endl <<
         "[2] Usuń element ze stosu " << endl <<
         "[3] Wyświetl stos " << endl <<
         "[4] Wyświetl wierzchołek stosu " << endl <<
         "[5] Usuń cały stos " << endl <<
         "==========================================";
}

stack::~stack() {
    while (top != NULL) {
        node *temp = top; // ustawienie adresu temp tam gdzie aktualny szczyt
        top = top->next; //Top o jedno niżej
        delete temp; //zwolnienie miejsca gdzie wskazuje temp

    }
}