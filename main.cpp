/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vekrakis
 *
 * Created on 25 Ιανουαρίου 2017, 1:39 μμ
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    node *next;
};

class list {
public:
    list();
    void add(int k, int x);
    int searchMF(int x);

private:
    node *head;
};

list::list() {
    head = NULL;
}

void list::add(int k, int x) {
    node *p = head;

    if (head == NULL) {
        head = new node;
        head->data = x;
        head->next = NULL;
    }
    else {
        int i;
        node *q = NULL;

        if (k == 1) {
            q = new node;
            head = q;
            q->data = x;
            q->next = p;
        } else {
            //FOR(i, 1 TO k - 2)
            for (int i=1; i<(k - 2); i++)
                p = p->next;

            q = new node;
            q->next = p->next;
            p->next = q;
            q->data = x;
        }
    }
}

int list::searchMF(int x) {
    int x_position = 1;
    node *p = head, *previous = head;

    while ((p != NULL) && (p->data != x)) {
        previous = p;
        p = p->next;
        x_position = x_position + 1;
    }

    if (previous->next == NULL)
        return (0);
    else if (x_position == 1)
        return (1);
    else {
        previous = p->next;
        p->next = head;
        head = p;
        return (x_position);
    }
}

int main(int argc, char** argv) {

    return 0;
}

