#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    T data;
    Node<T> *next;
    Node<T> *previous;

    public:
    Node(const T data_new);
    Node(const Node<T> &node) = default;
    ~Node() = default;
    Node<T> &operator=(const Node<T> &node) = default;
    T getData() const;
    Node<T> *getNext() const;
    Node<T> *getPrevious() const;
};

template <class T>
Node<T>::Node(const T data_new) : data(data_new), next(NULL), previous(NULL) {}

template <class T>
T Node<T>::getData() const
{
    return this->data;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
    return this->next;
}

template <class T>
Node<T> *Node<T>::getPrevious() const
{
    return this->previous;
}

#endif