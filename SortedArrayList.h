//
// Created by cmps351 on 9/28/21.
//

#ifndef PA2_C00424036_SORTEDARRAYLIST_H
#define PA2_C00424036_SORTEDARRAYLIST_H
#include <iostream>

template <typename T>
class SortedArrayList{
    public:
        void insert(T item);
        T removeLargest();
        T removeSmallest();
        T remove(T item);
        T removeAt(int i);
        void resetList();
        bool contains(T item) const;
        T get(int i) const;
        [[nodiscard]] bool isEmpty() const;
        [[nodiscard]] int getCapacity() const;
        [[nodiscard]] int getElementCount() const;
        void copyFrom(const SortedArrayList &list2);
        void printList() const;
        SortedArrayList();
        SortedArrayList(const SortedArrayList &list2);
        ~SortedArrayList();

    private:
        void resize(bool increase);
        T* arr;
        int capacity;
        int elementCount;
};


/*
 * Sorted Array List default constructor
 * Precondition: User wishes to create a default sorted array list object.
 * Postcondition: An empty list has been created with its capacity and element count set to zero.
 */
template<typename T>
SortedArrayList<T>::SortedArrayList() {
    this->arr = nullptr;
    this->capacity = 0;
    this->elementCount = 0;
}

/*
 * Sorted Array List copy constructor
 * Precondition: List2 is a valid and initialized SortedArrayList.
 * Postcondition: A new instance of a SortedArrayList object has been created as a copy of the parameter given.
 */
template<typename T>
SortedArrayList<T>::SortedArrayList(const SortedArrayList &list2){
    this->arr = new T[&list2.getElementCount()];
    this->capacity = &list2.getElementCount();
    this->elementCount = &list2.getElementCount();
    for (int i = 0; i < &list2.getElementCount(); i++){
        this->arr[i] = *&list2.get(i);
    }
}

/*
 * Sorted Array List destructor
 * Precondition: User wishes to delete the instance of the list object.
 * Postcondition: Dynamic data held within the list has been deleted.
 */
template<typename T>
SortedArrayList<T>::~SortedArrayList() {}

/*
 * Insert function used to add an item to the list in the correct place
 * Precondition: Parameter item given matches the type to the class instance.
 * Postcondition: Item inserted into list based on an increasing sort. If full size is increased by 2.
 */
template<typename T>
void SortedArrayList<T>::insert(T val){
    if (this->capacity == this->elementCount) resize(true);
    if (this->elementCount == 0){
        this->arr[0] = val;
    }
    else {
        int position;
        for (int i = 0; i <= this->elementCount; i++) {
            if (val < this->arr[i]) {
                position = i;
                for (int j = this->elementCount; j >= position; j--) {
                    this->arr[j] = this->arr[j - 1];
                }
                continue;
            }
            if (i == this->elementCount) position = i;
        }
        this->arr[position] = val;
    }
    this->elementCount++;
}

/*
 * Function to remove the largest element in the list.
 * Precondition: List cannot be empty.
 * Postcondition: Largest element in the list has been removed
 */
template<typename T>
T SortedArrayList<T>::removeLargest() {
    if (this->elementCount < 1) return NULL;
    if (this->capacity - this->elementCount >= 2) resize(false);
    T largest = this->arr[this->elementCount-1];
    delete this->arr[this->elementCount-1];
    this->elementCount--;
    return largest;
}

/*
 * Function to remove the smallest element.
 * Precondition: List cannot be empty.
 * Postcondition: The smallest element has been removed.
 */
template<typename T>
T SortedArrayList<T>::removeSmallest() {
    if (this->elementCount < 1) return NULL;
    if (this->capacity - this->elementCount >= 2) resize(false);
    T smallest = this->arr[0];
    for (int i = smallest; i < this->elementCount-1; i++){
        this->arr[i] = this->arr[i+1];
    }
    delete this->arr[this->elementCount-1];
    this->elementCount--;
    return smallest;
}

/*
 * Function to remove the first occurrence of a value given.
 * Precondition: List cannot be empty.
 * Postcondition: If the value is not in list null is returned, otherwise it is removed and returned.
 */
template<typename T>
T SortedArrayList<T>::remove(T val) {
    if (this->elementCount < 1) return NULL;
    if (this->capacity - this->elementCount >= 2) resize(false);
    int index = -1;
    int i = 0;
    while (index < 0 || i < this->elementCount) {
        if (this->arr[i] = val) index = i;
        i++;
    }
    if (index == -1) return NULL;
    for (int j = index; j < this->elementCount-1; j++){
        this->arr[j] = this->arr[j+1];
    }
    delete this->arr[this->elementCount-1];
    this->elementCount--;
    return index;
}

/*
 * Function to remove the element at the index given.
 * Precondition: List must not be empty.
 * Postcondition: If the index is invalid, null is returned, otherwise element is removed.
 */
template<typename T>
T SortedArrayList<T>::removeAt(int i){
    if (i < 0 || i >= this->elementCount) return NULL;
    else {
        if (this->capacity - this->elementCount >= 2) resize(false);
        T element = this->arr[i];
        for (int j = i; j < this->elementCount - 1; j++) {
            this->arr[j] = this->arr[j + 1];
        }
        delete this->arr[this->elementCount-1];
        this->elementCount--;
        return element;
    }
}

/*
 * Function to clear the contents of the list and set its capacity to 0.
 * Precondition: List needs to be reset.
 * Postcondition: All data has been deleted, capacity and element count are set to 0.
 */
template<typename T>
void SortedArrayList<T>::resetList() {
    this->capacity,this->elementCount = 0;
    delete [] this->arr;
    this->arr = nullptr;
}

/*
 * Function clearing the current memory of the list and copying nodes from another list.
 * Precondition: Both lists must be initialized and of the same type.
 * Postcondition: The new list is a copy of the given one.
 */
template<typename T>
void SortedArrayList<T>::copyFrom(const SortedArrayList &list2){
    delete [] this-> arr;
    this->capacity = &list2->capacity;
    this->elementCount = &list2->elementCount;
    this->arr = &list2;
}

/*
 * Function to resize the list to the provided size.
 * Precondition: Increase is passed to be true or false.
 * Postcondition: Increase if true or decrease if false by two.
 */
template<typename T>
void SortedArrayList<T>::resize(bool increase){
    T *arr;
    if (increase == true) {
        this->capacity += 2;
        arr = new T[this->capacity + 2];
    }
    else {
        this->capacity -= 2;
        arr = new T[this->capacity - 2];
    }
    for (int i = 0; i < this->elementCount; i++) {
        arr[i] = this->arr[i];
    }
    delete [] this->arr;
    this->arr = arr;
}

/*
 * Function determining if a given value is contained within the list.
 * Precondition: The list must be initialized and nonzero.
 * Postcondition: If the value is found return true, otherwise return false.
 */
template<typename T>
bool SortedArrayList<T>::contains(T item) const{
    for (int i = 0; i < this->elementCount; i++){
        if (this->arr[i] == item) return true;
    }
    return false;
}

/*
 * Function to return the value of the index given
 * Precondition: The list must be initialized and the index must be valid inside the array.
 * Postcondition: If valid the value is returned
 */
template<typename T>
T SortedArrayList<T>::get(int i) const {
    if (i >= 0 && i < capacity) return this->arr[i];
    else return NULL;
}

/*
 * Function seeing if the list is empty.
 * Precondition: The list must be initialized.
 * Postcondition: If capacity is zero true is returned, otherwise false is returned.
 */
template<typename T>
bool SortedArrayList<T>::isEmpty() const{
    return this->capacity == 0;
}

/*
 * Function printing the contents of the list.
 * Precondition:
 */
template<typename T>
void SortedArrayList<T>::printList() const {
    std::cout << "Contents of the list are as follows: " << std::endl;
    std::cout << "Index \t\t Value" << std::endl;
    for (int i = 0; i < this->elementCount; i++){
        std::cout << i << " \t\t " << this->arr[i] << std::endl;
    }
}

/*
 * Function accessor for capacity.
 * Precondition: List must be initialized.
 * Postcondition: Capacity is returned.
 */
template<typename T>
int SortedArrayList<T>::getCapacity() const {
    return this->capacity;
}

/*
 * Function accessor for element count.
 * Precondition: List must be initialized.
 * Postcondition: Element count is returned.
 */
template<typename T>
int SortedArrayList<T>::getElementCount() const {
    return this->elementCount;
}



#endif //PA2_C00424036_SORTEDARRAYLIST_H
