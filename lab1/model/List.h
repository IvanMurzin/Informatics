#pragma once


#include "Item.h"
#include <iostream>

template<class T>
class List {
    class Node {
    private:
        T data;
        Node *next = nullptr;
        Node *previous = nullptr;
    public:

        explicit Node(T &&data) : data(std::move(data)) {}

        explicit Node(const T &data) : data(data) {}

        explicit Node() = default;

        T &getData() {
            return data;
        }

        Node *getNext() const {
            return next;
        }

        Node *getPrevious() const {
            return previous;
        }

        void setNext(Node *node) {
            next = node;
        }

        void setPrevious(Node *node) {
            previous = node;
        }

        Node &operator=(Node &&other) {
            this->data = std::move(other.data);
            this->previous = other.previous;
            this->next = other.next;
            other.previous = nullptr;
            other.next = nullptr;
        }
    };


private:
    Node *start;
    Node *last;

public:
    class Iterator {
    private:
        Node *node;
        List<T> *src;
    public:
        Iterator(List<T> *src, Node *node) : node(node), src(src) {}

        void add(T &&data) {
            if (node == nullptr) return src->add(std::move(data));
            Node *newNode = new Node(std::move(data));
            newNode->setNext(node);
            newNode->setPrevious(node->getPrevious());
            if (node->getPrevious() == nullptr) {
                src->start = newNode;
            } else {
                node->getPrevious()->setNext(newNode);
            }
            node->setPrevious(newNode);
        }

        void add(const T &data) {
            if (node == nullptr) return src->add(data);
            Node *newNode = new Node(data);
            newNode->setNext(node);
            newNode->setPrevious(node->getPrevious());
            if (node->getPrevious() == nullptr) {
                src->start = newNode;
            } else {
                node->getPrevious()->setNext(newNode);
            }
            node->setPrevious(newNode);
        }

        T &operator*() {
            return node->getData();
        }

        Iterator operator++() {
            node = node->getNext();
            return *this;
        };

        bool operator==(const Iterator &right) {
            return node == right.node;
        }

        bool operator!=(const Iterator &right) {
            return node != right.node;
        }
    };

    explicit List() : start(nullptr), last(nullptr) {}

    List(List &&other) {
        this->start = other.start;
        this->last = other.last;
        other.start = nullptr;
        other.last = nullptr;
    }

    List(List &other) {
        this->start = other.start;
        this->last = other.last;
    }

    List &operator=(List &&other) {
        Node *itr = start;
        while (itr != nullptr) {
            Node *trash = itr;
            itr = itr->getNext();
            delete trash;
        }
        this->start = other.start;
        this->last = other.last;
        other.start = nullptr;
        other.last = nullptr;
        return *this;
    }

    List &operator=(List &other) {
        this->start = other.start;
        this->last = other.last;
        return *this;
    }

    void add(T &&data) {
        Node *newNode = new Node(std::move(data));
        if (start == nullptr) {
            start = newNode;
            last = start;
            return;
        }
        last->setNext(newNode);
        newNode->setPrevious(last);
        last = last->getNext();
    }

    void add(const T &data) {
        Node *newNode = new Node(data);
        if (start == nullptr) {
            start = newNode;
            last = start;
            return;
        }
        last->setNext(newNode);
        newNode->setPrevious(last);
        last = last->getNext();
    }

    ~List() {
        Node *itr = start;
        while (itr != nullptr) {
            Node *trash = itr;
            itr = itr->getNext();
            delete trash;
        }
    }


    Iterator begin() const {
        return Iterator(const_cast<List<T> *>(this), start);
    }

    Iterator end() const {
        return Iterator(const_cast<List<T> *>(this), nullptr);
    }

};