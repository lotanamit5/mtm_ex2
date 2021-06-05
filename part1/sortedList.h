#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include "Node.h"

typedef int T;

template <class T>
class SortedList 
{
    class Node<T>* head;
    int size;

    public :
    SortedList();
    SortedList(const SortedList& list);
    ~SortedList();
    SortedList &operator=(const SortedList& list) = default;

    void insert(const Node<T>* new_node); //maybe bool or exception
    void remove(Node<T>* deleted_node); //maybe bool or exception, need iterator
    int length();
    //SortedList filter()
};

template <class T>
SortedList<T>::SortedList()
{
    this->head = NULL;
    this->size = 0;
}

template <class T>
SortedList<T>::SortedList(const SortedList& list)
{
    Node<T>* temp = list->head;
    while(!temp)
    {
        this->insert(temp);
        temp = temp->next;
    }
    this->size = list.size;
}

template <class T>
SortedList<T>::~SortedList()
{
    class Node* temp;
    while(!this->head)
    {
        temp = this->head;
        *(this->head) = Node<T>::getNext()
        delete temp;
    }
}

#endif