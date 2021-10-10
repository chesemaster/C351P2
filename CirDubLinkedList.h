//
// Created by cmps351 on 9/28/21.
//

#ifndef PA2_C00424036_CIRDUBLINKEDLIST_H
#define PA2_C00424036_CIRDUBLINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node<T> *before;
    Node<T> *next;
};
template <typename T>
class CirDubLinkedList {

public:
    void insert(T item);
    T removeLargest();
    T removeSmallest();
    T remove(T item);
    void removeAt(int i);
    void resetList();
    bool contains(T item) const;
    T get(int i) const;
    [[nodiscard]] bool isEmpty() const;
    int GetLength() const;
    void copyFrom(const CirDubLinkedList &list2);
    void printList() const;
    CirDubLinkedList();
    CirDubLinkedList(const CirDubLinkedList &list2);
    ~CirDubLinkedList();


private:
    Node<T>* head;
    int length;
};

#endif //PA2_C00424036_CIRDUBLINKEDLIST_H
