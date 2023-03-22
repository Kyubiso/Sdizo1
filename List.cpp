//
// Created by kuba on 20/03/23.
//

#include "List.h"
#include "iostream"

using namespace std;

void List::addFirst() {
    Node *newElement = new Node();
    cout << "Podaj liczbe ktora wprowadzasz";
    cin >> newElement->data;
    newElement->prev = nullptr;
    newElement->next = head;

    if (head != nullptr) {
        head->prev = newElement; //Head w tym momencie jest 2. wiec wskazuje poprzedni na nowy element
    } else tail = newElement;

    head = newElement;
}

void List::addLast() {
    Node *newElement = new Node();
    cout << "Podaj liczbe ktora wprowadzasz";
    cin >> newElement->data;
    if (tail != nullptr) {
        tail->next = newElement;
    } else head = newElement;

    tail = newElement;
}

void List::addInside() {
    cout << "W ktorym miejscu wprowadzic nowy element?";
    size_t index;
    cin >> index;
    Node *nextElement = getNode(index);
    if (!nextElement) {
        cout << "Index nie wystepuje w liscie";
        return;
    }
    Node *newElement = new Node();
    cout << "Podaj liczbe ktora wprowadzasz";
    cin >> newElement->data;

    if (nextElement->prev) {                    //Jesli wskazuje na cos wczesniej
        nextElement->prev->next = newElement;   // Wskaźnim poprzedniego elementu na następny elemnt
    } else head = nextElement;                  // Ma wskazywać na nowy element
    nextElement->prev = newElement;
}
void List::removeFirst() {
    Node* temp = head;
    if (temp==nullptr) {
        return;
    }
    if (temp == tail) { //Jeśli początek jest koncem to i koniec i początek ustawiamy na nullpointer
        delete head;
        head= nullptr;
        tail= nullptr;
    }
    temp->next->prev= nullptr;
    head=head->next;
    delete temp;
}

void List::removeLast() {
    if (!head) return;
    if (head == tail) { // początek równy końcowi
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    Node* temp = tail;
    temp->prev->next = nullptr;
    tail=tail->prev;
    delete temp;
}

void List::removeInside() {
    size_t index;
    cout << "Z którego miejsca chcesz usunąć element";
    cin>>index;
    Node *temp = getNode(index);
    if (temp) {
        deleteNode(temp);
    }
}
List::Node *List::getNode(int index) {
    Node *temp = head; //Ustawiamy znacznik na początku
    for (int i = 0; i < index; i++) {
        temp = temp->next; //Przesuwanie sie w dol po liscie tyle razy zeby ustawic sie na index
        if (temp = nullptr) {
            cout << "Indexu nie ma na liście";
            return nullptr;
        }
    }
    return temp;
}

List::Node *List::getNodeWithVal(int num) {
    Node *temp = head; // Ustawienie wskaźnika na poczĄTEK LISTY
    while (temp) {
        if (temp->data == num) {
            return temp;
        }
        temp = temp->next;
    }
    cout << "W liście nie ma takiej wartości";
    return nullptr;
}

void List::deleteNode(Node* node) {
    if (node->next) { //Sprawdzenie czy usuwany node jest ostatni
        node->next->prev=node->prev;
    }
    else tail=node->prev;
    if (node->prev) {
        node->prev->next=node->next;
    } else head=node->next;

    delete node;

}


bool List::contains(int num) { //Sprawdzanie czy lista zawiera dany element
    Node *temp = head;
    while (temp) {
        if (temp->data == num) { //Jeśli ten element się pojawi, zwracamy true
            return true;
        }
        temp = temp->next;  //Przechodzenie po tablicy
    }
    return false;
}

    void List::clear(){
        while (head) {
            removeLast();
        }
    }


