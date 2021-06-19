#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>

namespace mtm
{

    template <class T>
    class SortedList;

    /*=======================================================================*/
    /*============================ class Node ===============================*/
    /*=======================================================================*/

    template <class T>
    class Node
    {
        T data;
        Node<T> *next;
        Node<T> *previous;

    public:
        /**
         * @brief delete the default constructor
         * @param 
         */
        Node() = delete;
        /**
         * @brief constructor with data parameter
         * @param data_new
         */
        Node(const T data_new);
        /**
         * @brief copy constructor
         * @param node
         */
        Node(const Node<T> &node) = default;
        /**
         * @brief default destructor
         * @param 
         */
        ~Node() = default;
        /**
         * @brief operator= for Node
         * @param node
         * @return Node<T>&
         */
        Node<T> &operator=(const Node<T> &node) = default;
        friend class SortedList<T>;
    };

    template <class T>
    Node<T>::Node(const T data_new) : data(data_new), next(nullptr), previous(nullptr) {}

    /*=======================================================================*/
    /*========================= class SortedList ============================*/
    /*=======================================================================*/

    template <class T>
    class SortedList
    {
        Node<T> *head;
        int size;

    public:
        class const_iterator;

        /**
         * @brief SortedList constructor
         */
        SortedList();
        /**
         * @brief SortedList copy constructor
         * @param list
         */
        SortedList(const SortedList<T> &list);
        /**
         * @brief SortedList destructor
         */
        ~SortedList();
        /**
         * @brief SortedList operator=
         * @param list
         * @return SortedList<T>
         */
        SortedList<T> &operator=(const SortedList<T> &list);

        /**
         * @brief insert new element to the list
         * @param element
         * @return true if success , false if doesn't
         */
        bool insert(const T element);
        /**
         * @brief remove element from the list
         * @param it
         * @return true if success , false if doesn't
         */
        bool remove(const SortedList<T>::const_iterator &it);
        /**
         * @brief get the length of the list
         * @return int length
         */
        int length();
        /**
         * @brief get the first iterator of the list
         * @return const_iterator
         */
        const_iterator begin() const;
        /**
         * @brief get the last iterator of the list
         * @return const_iterator
         */
        const_iterator end() const;

        /**
         * @brief filter the list with the predict func and return the filtered list
         * @param func
         * @return SortedList<T> after the filter
         */
        template <typename predict>
        SortedList<T> filter(predict func) const;
        /**
         * @brief returns a new list after changes of the elements that made by the func function  
         * @param func
         * @return SortedList<T> after the apply
         */
        template <typename function>
        SortedList<T> apply(function func) const;
    };

    template <class T>
    SortedList<T>::SortedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    template <class T>
    SortedList<T>::SortedList(const SortedList<T> &list) : head(nullptr), size(0)
    {
        Node<T> *temp = list.head;
        while (temp != nullptr)
        {
            this->insert(temp->data);
            temp = temp->next;
        }
        this->size = list.size;
    }

    template <class T>
    SortedList<T>::~SortedList()
    {
        Node<T> *temp = this->head;
        while (temp != nullptr)
        {
            Node<T> *to_delete = temp;
            temp = temp->next;
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
        Node<T> *temp = this->head;
        while (temp != nullptr)
        {
            Node<T> *to_delete = temp;
            temp = temp->next;
            delete to_delete;
        }
        temp = list.head;
        head = nullptr;
        size = 0;
        while (temp != nullptr)
        {
            this->insert(temp->data);
            temp = temp->next;
        }
        size = list.size;
        return *this;
    }

    template <class T>
    bool SortedList<T>::insert(const T element)
    {
        Node<T> *new_node = new Node<T>(element);
        Node<T> *last_node = nullptr;
        for (Node<T> *it = this->head; it != nullptr; it = it->next)
        {
            if (element < it->data)
            {
                new_node->next = it;
                new_node->previous = it->previous;
                if (it->previous != nullptr)
                {
                    it->previous->next = new_node;
                }
                it->previous = new_node;
                this->size++;
                if (it == this->head)
                {
                    this->head = new_node;
                }
                return true;
            }
            last_node = it;
        }
        new_node->next = nullptr;
        new_node->previous = last_node;
        this->size++;
        if (last_node == nullptr)
        {
            this->head = new_node;
        }
        else
        {
            last_node->next = new_node;
        }
        return true;
    }

    template <class T>
    bool SortedList<T>::remove(const SortedList<T>::const_iterator &it)
    {
        if (it.node == nullptr)
        {
            throw std::out_of_range("End of List");
        }
        for (Node<T> *node = this->head; node != nullptr; node = node->next)
        {
            if ((node->previous == it.node->previous) &&
                (node->next == it.node->next))
            {
                if (node->previous != nullptr)
                {
                    node->previous->next = node->next;
                }
                else
                {
                    this->head = node->next;
                }
                if (node->next != nullptr)
                {
                    node->next->previous = node->previous;
                }
                delete node;
                this->size--;
                return true;
            }
        }
        return false;
    }

    template <class T>
    int SortedList<T>::length()
    {
        return this->size;
    }

    template <class T>
    template <typename predict>
    SortedList<T> SortedList<T>::filter(predict func) const
    {
        SortedList<T> new_list;
        for (Node<T> *node = this->head; node != nullptr; node = node->next)
        {
            if (func(node->data))
            {
                new_list.insert(node->data);
            }
        }
        return new_list;
    }

    template <class T>
    template <typename function>
    SortedList<T> SortedList<T>::apply(function func) const
    {
        SortedList<T> new_list;
        for (Node<T> *node = this->head; node != nullptr; node = node->next)
        {
            new_list.insert(func(node->data));
        }
        return new_list;
    }

    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const
    {
        return const_iterator(this->head);
    }

    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::end() const
    {
        Node<T> *node;
        for (node = this->head; node != nullptr; node = node->next)
        {
        }
        return const_iterator(node);
    }

    /*=======================================================================*/
    /*======================= class const_iterator ==========================*/
    /*=======================================================================*/

    template <class T>
    class SortedList<T>::const_iterator
    {
        Node<T> *node;
        /**
         * @brief const_iterator constructor that get Node<T>*
         * @param node_new
         */
        const_iterator(Node<T> *node_new) : node(node_new){};

    public:
        /**
         * @brief The default constructor is deleted
         * @param 
         */
        const_iterator() = delete;
        /**
         * @brief const_iterator copy constructor
         * @param iterator_new
         */
        const_iterator(const const_iterator &iterator_new) = default;
        /**
         * @brief default destructor
         * @param 
         */
        ~const_iterator() = default;
        /**
         * @brief const_iterator operator=
         * @param iterator_new
         * @return const_iterator&
         */
        const_iterator &operator=(const const_iterator &iterator_new) = default;
        /**
         * @brief const_iterator pre-fix operator ++
         * @return const_iterator& with the ++ change
         */
        const_iterator &operator++();
        /**
         * @brief const_iterator post-fix operator ++
         * @param dummy int parameter
         * @return const_iterator& without the ++ change
         */
        const_iterator operator++(int);
        /**
         * @brief boolean operator== for const_iterator
         * @param iterator_new
         * @return true if identical , false if doesn't
         */
        bool operator==(const const_iterator iterator_new) const;
        /**
         * @brief operator* for const_iterator
         * @return the T data of the iterator 
         */
        const T &operator*() const;
        friend class SortedList<T>;
    };

    template <class T>
    typename SortedList<T>::const_iterator &SortedList<T>::const_iterator::operator++()
    {
        if (this->node == nullptr)
        {
            throw std::out_of_range("End of List");
        }
        this->node = this->node->next;
        return *this;
    }

    template <class T>
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++(int)
    {
        SortedList<T>::const_iterator temp = *this;
        if (this->node == nullptr)
        {
            throw std::out_of_range("End of List");
        }
        this->node = this->node->next;
        return temp;
    }

    template <class T>
    bool SortedList<T>::const_iterator::operator==(
        const SortedList<T>::const_iterator iterator_new) const
    {
        if ((this->node == nullptr && iterator_new.node != nullptr) ||
            ((this->node != nullptr && iterator_new.node == nullptr)))
        {
            return false;
        }
        if (this->node == nullptr && iterator_new.node == nullptr)
        {
            return true;
        }
        if ((this->node->next == iterator_new.node->next) &&
            (this->node->previous == iterator_new.node->previous))
        {
            return true;
        }
        return false;
    }

    template <class T>
    const T &SortedList<T>::const_iterator::operator*() const
    {
        if (this == nullptr || this->node == nullptr)
        {
            throw std::out_of_range("Out of range");
        }
        return this->node->data;
    }
}

#endif