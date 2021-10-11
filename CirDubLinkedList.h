//
// Created by cmps351 on 9/28/21.
//

#ifndef PA2_C00424036_CIRDUBLINKEDLIST_H
#define PA2_C00424036_CIRDUBLINKEDLIST_H
#include <iostream>


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


/*
 * Function to add an item to the list in its appropriate spot
 * Precondition:
 *      item is of matching type to the class instance
 * Postcondition:
 *      The provided item has been inserted into the list at its appropriate spot based on
 *      increasing sort. i.e. the smallest element is first
 */
template <typename T>
void CirDubLinkedList<T>::insert(T item){
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
    if (this->length == 0){
        newNode->next = nullptr;
        newNode->before = nullptr;
        this->head = newNode;
    }
    if (this->length == 1){
        if (item < this->head->data){
            Node<T>* copyHead = this->head;
            delete [] this->head;
            newNode->before = copyHead;
            newNode->next = copyHead;
            this->head = newNode;
        }
        else{
            this->head->next = newNode;
            this->head->before = newNode;
            newNode->next = this->head;
            newNode->before = this->head;
        }
    }
    else if (this->length > 1){
        Node<T> *nodeToAdd = new Node<T>;
        nodeToAdd->data = item;
        bool checkEnd = false;
        Node<T> *current = this->head;
        for (int i = 0; i < this->length; i++) {
            if (current->data < item) {
                if (current->next == nullptr) {
                    std::cout << "aokkokrok" << std::endl;
                    checkEnd = true;
                }
                else {
                    current = current->next;
                }
            }
        }
        if (checkEnd == true){
            current->next = nodeToAdd;
            nodeToAdd->before = current;
        }
        else {
            nodeToAdd->before = current->before;
            nodeToAdd->next = current;
            current->before->next = nodeToAdd;
            current->before = nodeToAdd;
            if (current == this->head) {
                this->head = nodeToAdd;
            }
        }
    }
    this->length++;
}

/*
 * Function to remove the largest element in the list.
 * Precondition:
 *      The list is not empty.
 * Postcondition:
 *      The largest element in the list has been removed.
 */
template <typename T>
T CirDubLinkedList<T>::removeLargest(){
    Node<T>* current = this->head->before;
    current->before->next = current->next;
    current->next->before = current->before;
    T val = current->data;
    delete current;
    this->length--;
    return val;
}

/*
 * Function to remove the smallest element in the list
 * Precondition:
 *      The list is not empty.
 * Postcondition:
 *      The smallest element in the list has been removed.
 */
template <typename T>
T CirDubLinkedList<T>::removeSmallest(){
    Node<T>* current = this->head;
    Node<T>* newHead = this->head->next;
    current->before->next = current->next;
    current->next->before = current->before;
    T val = current->data;
    delete current;
    this->head = newHead;
    this->length--;
    return val;
}

/*
 * Function to remove the first occurrence of a specific value in the list
 * Precondition:
 *      The list is not empty.
 * Postcondition:
 *      If the element is not in the list, null is returned.
 *      Otherwise the first occurrence of the specified element is removed from the list.
 */
template <typename T>
T CirDubLinkedList<T>::remove(T item) {
    if (this->length == 0) return NULL;
    else if (this->length == 1) {
        if (this->head->data == item) {
            delete this->head;
            this->length--;
            return item;
        }
    }
    else if (this->length == 2) {
        if (this->head->data == item) {
            Node<T> *newHead = this->head->next;
            delete this->head;
            this->head = newHead;
            this->head->before = nullptr;
            this->head->next = nullptr;
            this->length--;
            return item;
        } else if (this->head->next->data == item) {
            delete this->head->next;
            this->head->before = nullptr;
            this->head->next = nullptr;
            this->length--;
            return item;
        }
    }
    else {
        Node<T> *current = this->head;
        for (int i = 0; i < this->length; i++) {
            if (current->data == item) {
                continue;
            }
            if (i == this->length - 1) return NULL;
        }
        if (current == this->head) {
            Node<T> *newHead = this->head->next;
            Node<T> *nextHead = this->head->next->next;
            Node<T> *beforeHead = this->head->before;
            delete this->head;
            this->head = newHead;
            this->head->before = beforeHead;
            this->head->next = nextHead;
            this->length--;
            return item;
        } else {
            current->before->next = current->next;
            current->next->before = current->before;
            delete current;
            this->length--;
            return item;
        }
    }
}

/*
 * Function to remove the element at a specific index in the list
 * Precondition:
 *      The list is not empty.
 *      0 <= i < elementCount
 * Postcondition:
 *      If the index is not valid, null is returned.
 *      Otherwise the element at the desired index has been removed.
 */
template <typename T>
void CirDubLinkedList<T>::removeAt(int i){
    Node<T>* current = this->head;
    for (int i = 0; i < this->length; i++){
        current = current->next;
    }
    current->before->next = current->next;
    current->next->before = current->before;
    delete current;
}

/*
 * Function to clear the contents of the list and reset it to capacity 0
 * Precondition:
 *      The contents of the list need to be cleared out and the list reset
 * Postcondition:
 *      All data in the list has been deleted, and the list
 *      is reset to be completely empty with no available space
 */
template <typename T>
void CirDubLinkedList<T>::resetList(){
    /*Node<T> *current;
     for (int j = 0; j < this->length-1; j++) {
        current = this->head;
        for (int i = this->length - 2; i >= 0; i--) {
            current = current->next;
        }
        delete [] current;

    }*/
}

/*
 * Function to check if a provided element is in the list
 * Precondition:
 *      item is an element of matching datatype and not null
 * Postcondition:
 *      returns true if the element is in the list, false otherwise
 */
template <typename T>
bool CirDubLinkedList<T>::contains(T item) const{
    if (item == NULL) return false;
    Node<T>* current = this->head;
    for (int i = 0; i < this->length; i++){
        if(current->data == item) return true;
    }
    return false;
}

/*
 * Access function, to retrieve a value at a specific index
 * Precondition:
 *     0 <= i < elementCount && i < intMax
 * Postcondition:
 *      If the index is not valid, null is returned.
 *      Otherwise, the value of the element at desired index (i) is returned
 */
template <typename T>
T CirDubLinkedList<T>::get(int i) const{
    if (this->length <= i) return NULL;
    else{
        Node<T>* current = this->head;
        for (int j = 0; j < i; j++){
            current = current->next;
        }
        return current->data;
    }
}

/*
 * Function to determine if the list is empty or not
 * Precondition:
 *      The instance of the CirDubLinkedList class has been initialized
 * Postcondition:
 *      Returns true if the list is empty, false otherwise
 */
template <typename T>
[[nodiscard]] bool CirDubLinkedList<T>::isEmpty() const{
    return this->head == nullptr;
}

/*
 * Function to return the current number of elements within the list
 * Precondition:
 *      The instance of the CirDubLinkedList class has been initialized
 * Postcondition:
 *      The current number of elements in the list is returned
 */
template <typename T>
int CirDubLinkedList<T>::GetLength() const{
    return this->length;
}

/*
 * Function to delete the current list, and create a new list containing the values from the passed list
 * Precondition:
 *      list2 is a valid CirDubLinkedList object that has been initialized with a matching datatype
 * Postcondition:
 *      The data currently in the list has been deleted, and memory released.
 *      A new list is created and filled with data to match the data in list2
 */
template <typename T>
void CirDubLinkedList<T>::copyFrom(const CirDubLinkedList &list2) {
    Node<T> *current;
    while (this->head != nullptr) {
        current = this->head;
        this->head = this->head->next;
        delete current;
    }
    if (&list2->length == 0){
        this->head = nullptr;
        this->length = 0;
    }
    else if (&list2->length == 1){
        Node<T>* add = new Node<T>;
        add = &list2->head;
        this->head = add;
        this->head->data = &list2->head->data;
        this->head->before = nullptr;
        this->head->next = nullptr;
        this->length = 1;
    }
    else {
        Node<T>* addHead = new Node<T>;
        addHead = &list2->head;
        this->head = addHead;
        this->head->data = &list2->head->data;

        Node<T>* readCurrent = &list2->head->next;
        for (int i = 0; i < &list2->length-1; i++){
            Node<T>* add = new Node<T>;
            add = readCurrent;
            readCurrent = readCurrent->next;
        }
        this->length = &list2.length;
    }
}

/*
 * Function to print the contents of the list to the terminal
 * Precondition:
 *      The instance of the CirDubLinkedList class has been initialized
 * Postcondition:
 *      The data currently stored within the list has been printed to the terminal
 */
template <typename T>
void CirDubLinkedList<T>::printList() const{
    if (this->length == 0);
    else if (this->length == 1) std::cout << "0 \t\t " << this->head->data << std::endl;
    else if (this->length > 1){
        Node<T> *start = this->head;
        std::cout << "Contents of list:" << std::endl;
        std::cout << "Index \t\t Value" << std::endl;
        int index = 0;
        std::cout << index << " \t\t " << this->head->data << std::endl;
        Node<T> *current = this->head->next;
        while (current != start) {
            std::cout << ++index << " \t\t " << current->data << std::endl;
            current = current->next;
        }
    }
}

/*
 * Default constructor for a Circular Doubly Linked List object
 * Precondition:
 *      User wants to create a default circular doubly linked list object
 * Postcondition:
 *      An empty list has been created.
 */
template <typename T>
CirDubLinkedList<T>::CirDubLinkedList(){
    this->head = nullptr;
    this->length = 0;
}

/*
 * CirDubLinkedList copy constructor
 * Precondition:
 *      list2 is a valid CirDubLinkedList object that has been initialized
 * Postcondition:
 *      A new instance of a CirDubLinkedList object has been created that is a copy of the instance list2
 */
template <typename T>
CirDubLinkedList<T>::CirDubLinkedList(const CirDubLinkedList &list2){
    Node<T>* newHead = new Node<T>;
    newHead = &list2->head;
    this->head = newHead;

    Node<T>* readCurrent = &list2->head->next;
    for (int i = 0; i < &list2->length-1; i++){
        Node<T>* add = new Node<T>;
        add = readCurrent;
        readCurrent = readCurrent->next;
    }
    this->length = &list2.length;
}

/*
 * Destructor for a CirDubLinkedList
 * Precondition:
 *      It is time to delete the instance of our object
 * Postcondition:
 *      All dynamic data held within the list has been deleted,
 */
template <typename T>
CirDubLinkedList<T>::~CirDubLinkedList(){}


#endif //PA2_C00424036_CIRDUBLINKEDLIST_H
