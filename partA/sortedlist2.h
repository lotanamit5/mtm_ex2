#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include "Node.h"

class SortedList
{
    node *head;
    int length;

public:
    SortedList() : length(0)
    {
        head = new node();
    }
    ~SortedList() = default;
    SortedList(const SortedList &);
    SortedList &operator=(const SortedList &);

    void remove();
    int length();

    class const_iterator;
    const_iterator begin() const;
    const_iterator end() const;
};

class SortedList::const_iterator
{
    const SortedList *sorted_list;
    int index;
    friend class SortedList;

public:
    const_iterator() = delete;
    const_iterator(const const_iterator &) = default;
    const_iterator &operator=(const const_iterator &) = default;
    ~const_iterator();

    const int &operator*() const;
    const_iterator &operator++();
    const_iterator operator++(int);
    bool operator==(const const_iterator &it) const;
    bool operator!=(const const_iterator &it) const;
};

// template <class T>
// struct node
// {
//     node<T> *next;
//     node<T> *previous;
//     T data;
// };

// template <class T>
// class SortedList
// {
// public:
//     node *head;
//     SortedList<T>();
//     ~SortedList<T>();
//     SortedList<T>(const SortedList &);
//     SortedList &operator=(const SortedList &);
//     void insert(T elem); //mabye pointer
//     // void remove(Iterator elem);
//     int length();
//     //predict
//     //apply
//     class const_iterator;
//     const_iterator begin() const;
//     const_iterator end() const;
// };

// template <class T>
// class SortedList<T>::const_iterator
// {
//     const SortedList<T> *sortedlist;
//     int index;
//     friend class SortedList<T>;
//     //constructor?

// public:
//     const T &operator*() const;
//     const_iterator &operator++();
//     const_iterator operator++(int);

//     bool operator==(const const_iterator &it) const;
//     bool operator!=(const const_iterator &it) const;

//     const_iterator() = delete;
//     const_iterator(const const_iterator &) = default;
//     const_iterator &operator=(const const_iterator &) = default;
//     ~const_iterator();
// };

#endif