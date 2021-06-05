#ifndef NODE_H
#define NODE_H
#include <iostream>

template <class T>
class Node
{
    public :
    T data;
    class Node* next;
    class Node* previous;

    Node(T data_new, Node* next_new);
    Node(const Node& node);
    ~Node();
    Node &operator=(const Node& node) = default;
};

template <class T>
Node<T>::Node(T data_new, Node* next_new)
{
    this->data = data_new;
    this->next = NULL;
    this->previous = NULL;
}

#endif