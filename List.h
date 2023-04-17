//
// Created by kuba on 20/03/23.
//

#ifndef SDIZO_LIST_H
#define SDIZO_LIST_H


class List {
private:
    struct Node {
        Node *prev;
        Node *next;
        int data;
    };

    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void addFirst();

    void addLast();

    void addInside();

    void removeFirst();

    void removeLast();

    void removeInside();

    bool contains(int num);

    void deleteValue();

    List();

    ~List();

    Node *getNode(int index);

    Node *getNodeWithVal(int num);

    void deleteNode(Node *node);

    void clear();

    void displayMenu();
};


#endif //SDIZO_LIST_H
