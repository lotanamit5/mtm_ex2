#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include "Node.h"

typedef int T;

template <class T>
class SortedList
{
    class Node<T> *head;
    int size;

public:
    class const_iterator;

    const_iterator begin() const;
    const_iterator end() const;

    SortedList();
    SortedList(const SortedList &list);
    ~SortedList();
    SortedList &operator=(const SortedList<T> &list);

    void insert(const Node<T> *new_node); //maybe bool or exception
    void remove(Node<T> *deleted_node);   //maybe bool or exception, need iterator
    int length();
    //SortedList filter()
    //SortedList apply()
};

template <class T>
SortedList<T>::SortedList()
{
    this->head = NULL;
    this->size = 0;
}

template <class T>
SortedList<T>::SortedList(const SortedList &list)
{
    Node<T> *temp = list->head;
    while (!temp)
    {
        this->insert(temp);
        temp = temp->next;
    }
    this->size = list->size;
}

template <class T>
SortedList<T>::~SortedList()
{
    class Node *temp;
    while (!this->head)
    {
        temp = this->head;
        *(this->head) = this->head delete temp;
    }
}

template <class T>
SortedList<T> &SortedList<T>::operator=(const SortedList<T> &list)
{
    if (this == &list)
    {
        return *this;
    }
    delete head;
    Node<T> *temp = list->head;
    while (!temp)
    {
        this->insert(temp);
        temp = temp->next;
    }
    this->size = list->size;
    return *this;
}

template <class T>
int SortedList<T>::length()
{
    return this->size;
}

template <class T>
class SortedList<T>::const_iterator
{
    class Node<T> *iterator;

    const_iterator(Node<T> *node)
    {
        iterator = Node<T>::Node(*node);
    }

public:
    const_iterator() = delete;
    const_iterator(const const_iterator &iterator_new)
    {
        iterator = Node<T>::Node(*(iterator_new->iterator));
    }
    ~const_iterator()
    {
        delete iterator;
    }
    const_iterator &operator=(const const_iterator &iterator_new)
    {
        if (this == &iterator_new)
        {
            return *this;
        }
        delete iterator;
        iterator = Node<T>::Node(*(iterator_new->iterator));
        return *this;
    }
    const_iterator operator++(const_iterator iterator_new)
    {
        if (iterator_new == NULL || iterator_new->next == NULL)
        {
            throw std::out_of_range;
        }
        this->iterator = this->iterator->next;
        return iterator_new;
    }
    bool operator==(const const_iterator iterator_new) const
    {
        if (iterator->data != iterator_new->iterator->data ||
            iterator->next != iterator_new->iterator->next ||
            iterator->previous != iterator_new->iterator->previous)
        {
            return false;
        }
        return true;
    }
    const Node<T> &operator*() const
    {
        return iterator; //not done
    }
};

#endif