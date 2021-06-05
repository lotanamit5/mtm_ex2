#ifndef NODE_H
#define NODE_H
#include <iostream>

template <class T>
class Node
{
    public :
    T data;
    class Node<T>* next;
    class Node<T>* previous;

    Node(const T data_new);
    Node(const Node<T>& node) = default;
    ~Node() = default;
    Node<T> &operator=(const Node<T>& node) = default;
};

template <class T>
Node<T>::Node(const T data_new) : data(data_new), next(NULL), previous(NULL) {}

#endif