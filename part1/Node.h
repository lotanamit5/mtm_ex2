#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public :
    T data;
    class Node* next;
    class Node* previous;

    Node(T data_new, Node<T>* next_new, Node<T>* previous_new);
    Node(const Node<T>& node) = default;
    ~Node() = default;
    Node &operator=(const Node<T>& node) = default;
};

template <class T>
Node<T>::Node(T data_new, Node* next_new, Node* previous_new) 
{
    this->data = data_new;
    this->next = next_new;
    this->previous = previous_new;
}

#endif