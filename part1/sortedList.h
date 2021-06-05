#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include "Node.h"

typedef int T;

template <class T>
class SortedList 
{
    class Node* head;
    int size;

    public :
    SortedList();
    SortedList(const SortedList& list);
    ~SortedList();
    SortedList &operator=(const SortedList& list) = default;

    void insert(const Node new_node); //maybe bool or exception
    void remove(Node deleted_node); //maybe bool or exception, need iterator
    int length();
    //SortedList filter()
};

template <class T>
SortedList<T>::SortedList()
{
    *(this->head) = Node<T>::Node();
    this->size = 0;
}

template <class T>
SortedList<T>::SortedList(const SortedList& list)
{
    *(this->head) = Node<T>::Node((*list.head));
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