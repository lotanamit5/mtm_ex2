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
SortedList<T>::SortedList(const SortedList<T> &list)
{
    Node<T> *temp = list.head;
    while (!temp)
    {
        this->insert(temp);
        temp = temp->getNext();
    }
    this->size = list.size;
}

template <class T>
SortedList<T>::~SortedList()
{
    Node<T> *temp = this->head;
    while (!temp)
    {
        Node<T> *to_delete = temp;
        temp = temp->getNext();
        delete to_delete;
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

/*=============================================================================================================*/
/*======================================== class const_iterator ===============================================*/
/*=============================================================================================================*/

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
    const_iterator(const const_iterator &iterator_new) = default;
    ~const_iterator() = default;
    const_iterator &operator=(const const_iterator &iterator_new) = default;
    const_iterator &operator++()
    {
        if (this->iterator->getNext() == nullptr)
        {
            throw std::out_of_range;
        }
        this->iterator = this->iterator->getNext();
        return *this;
    }
    bool operator==(const const_iterator iterator_new) const;
    const Node<T> &operator*() const;
};

/*template <class T>
SortedList<T>::const_iterator &SortedList<T>::const_iterator::operator++()
{
    if(this->iterator->getNext()==nullptr)
    {
        throw std::out_of_range;
    }
    this->iterator = this->iterator->getNext();
    return *this;
}*/

template <class T>
bool SortedList<T>::const_iterator::operator==(const SortedList<T>::const_iterator iterator_new) const
{
    if (this->iterator->getNext() != iterator_new.iterator->getNext())
    {
        return false;
    }
    return true;
}

template <class T>
const Node<T>& SortedList<T>::const_iterator::operator*() const
{
    return *(this->iterator);
}

#endif