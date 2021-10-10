//
// Created by cmps351 on 9/28/21.
//

#ifndef PA2_C00424036_SORTEDARRAYLIST_H
#define PA2_C00424036_SORTEDARRAYLIST_H


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


#endif //PA2_C00424036_SORTEDARRAYLIST_H
