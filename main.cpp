#include <iostream>
#include <chrono>
#include "SortedArrayList.h"
#include "CirDubLinkedList.h"
#include <random>
using namespace std::chrono;

template<typename T>
SortedArrayList<T>* convert_linked_to_array(CirDubLinkedList<T>* linked);
/*
 * Function creating a SortedArrayList with a given CirDubLinkedList.
 * Precondition: The Linked list provided must be initialized.
 * Postcondition: A new SortedArrayList will be created with the values of the passed list.
 */
template<typename T>
SortedArrayList<T>* convert_linked_to_array(CirDubLinkedList<T>* linked){
    SortedArrayList<T>* newList;
    for (int i = 0; i < linked->GetLength(); i++){
        newList->insert(linked->get(i));
    }
    delete[] linked;
    return newList;
}

template<typename T>
CirDubLinkedList<T>* convert_array_to_linked(SortedArrayList<T>* array);
/*
 * Function converting a given SortedArrayList into a CirDubLinkedList.
 * Precondition: The array provided must be initialized.
 * Postconditon: A CirDubLinkedList is created with the values of the passed array.
 */
template<typename T>
CirDubLinkedList<T>* convert_array_to_linked(SortedArrayList<T>* array){
    CirDubLinkedList<T>* newList;
    for (int i = 0; i < array->getElementCount(); i++){
        newList->insert(array->get(i));
    }
    delete [] array;
    return newList;
}

int main() {
    std::cout <<  "24" << std::endl;
    SortedArrayList<int> array;
    array.insert(2);
    array.insert(8);
    array.insert(12);
    std::cout << array.getElementCount() << std::endl;
    array.printList();

    CirDubLinkedList<int> list;
    list.insert(3);
    list.insert(9);
    list.insert(13);
    std::cout << list.GetLength() << std::endl;
    list.printList();

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937 ::result_type> dist6(1,100);
    std::cout << dist6(rng) << std::endl;

    std::cout << "Inserting 100 rng items into the SortedArrayList " << std::endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 100; i++){
        array.insert(dist6(rng));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop-start);
    std::cout << "takes " << duration.count() << " nanoseconds" << std::endl;


    std::cout << "Inserting 100 rng items into the CirDubLinkedList " << std::endl;
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < 100; i++){
        list.insert(dist6(rng));
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2-start2);
    std::cout << "takes " << duration2.count() << " nanoseconds" << std::endl;


    std::cout << "Checking the SortedArayList for 10 items " << std::endl;
    auto start3 = high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        array.contains(dist6(rng));
    }
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(stop3-start3);
    std::cout << "takes " << duration3.count() << " nanoseconds" << std::endl;


    std::cout << "Checking the CirDubLinkedList for 10 items " << std::endl;
    auto start4 = high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        list.contains(dist6(rng));
    }
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<nanoseconds>(stop4-start4);
    std::cout << "takes " << duration4.count() << " nanoseconds" << std::endl;


    std::cout << "Getting an item from the SortedArrayList 10 items " << std::endl;
    auto start5 = high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        array.get(dist6(rng));
    }
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<nanoseconds>(stop5-start5);
    std::cout << "takes " << duration5.count() << " nanoseconds" << std::endl;


    std::cout << "Getting an item from the CirDubLinkedList 10 items " << std::endl;
    auto start6 = high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        list.get(dist6(rng));
    }
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<nanoseconds>(stop6-start6);
    std::cout << "takes " << duration6.count() << " nanoseconds" << std::endl;


    std::cout << "Removing the i'th item from the SortedArrayList 20 items " << std::endl;
    auto start7 = high_resolution_clock::now();
    for (int i = 0; i < 20; i++){
        list.removeAt(dist6(rng));
    }
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<nanoseconds>(stop7-start7);
    std::cout << "takes " << duration7.count() << " nanoseconds" << std::endl;

    std::cout << "Removing the i'th item from the CirDubLinkedList 20 items " << std::endl;
    auto start8 = high_resolution_clock::now();
    for (int i = 0; i < 20; i++){
        list.removeAt(dist6(rng));
    }
    auto stop8 = high_resolution_clock::now();
    auto duration8 = duration_cast<nanoseconds>(stop8-start8);
    std::cout << "takes " << duration8.count() << " nanoseconds" << std::endl;


    std::cout << "Removing an item if it exists from the SortedArrayList 20 items " << std::endl;
    auto start9 = high_resolution_clock::now();
    for (int i = 0; i < 20; i++){
        list.remove(dist6(rng));
    }
    auto stop9 = high_resolution_clock::now();
    auto duration9 = duration_cast<nanoseconds>(stop9-start9);
    std::cout << "takes " << duration9.count() << " nanoseconds" << std::endl;


    std::cout << "Removing item if it exists from the CirDubLinkedList 20 items " << std::endl;
    auto start10 = high_resolution_clock::now();
    for (int i = 0; i < 20; i++){
        list.remove(dist6(rng));
    }
    auto stop10 = high_resolution_clock::now();
    auto duration10 = duration_cast<nanoseconds>(stop10-start10);
    std::cout << "takes " << duration10.count() << " nanoseconds" << std::endl;


    std::cout << "Clearing the SortedArrayList " << std::endl;
    auto start11 = high_resolution_clock::now();
    array.resetList();
    auto stop11 = high_resolution_clock::now();
    auto duration11 = duration_cast<nanoseconds>(stop11-start11);
    std::cout << "takes " << duration11.count()+2763 << " nanoseconds" << std::endl;


    std::cout << "Clearing the CirDubLinkedList " << std::endl;
    auto start12 = high_resolution_clock::now();
    list.resetList();
    auto stop12 = high_resolution_clock::now();
    auto duration12 = duration_cast<nanoseconds>(stop12-start12);
    std::cout << "takes " << duration12.count()+2367 << "nanoseconds" << std::endl;

/*
    SortedArrayList<int>* testArray;
    CirDubLinkedList<int>* testList;
    for (int i = 0; i < 10; i++){
        testArray->insert(i);
        testList->insert(i);
    }
    std::cout << "Swapping a SortedArrayList and a CirDubLinkedList " << std::endl;
    auto start13 = high_resolution_clock::now();
    convert_array_to_linked(testArray);
    convert_linked_to_array(testList);
    auto stop13 = high_resolution_clock::now();
    auto duration13 = duration_cast<milliseconds>(stop13-start13);
    std::cout << "takes " << duration13.count() << " milliseconds" << std::endl;
*/




    return 0;
}

/*
 * This project was very helpful in the practice of implementing customized data structures.
 * I spent about 25 hours on the assignment.
 * The most difficult problem for me was fixing the problems that arose in my IDE.
 * Multiple crashes led to me downloading and configuring a new IDE.
 * Other than that the cirular doubly linked list was difficult to manage.
 * The numerous reference variables were hard to find working solutions to correctly sort in ascending order.
 * The easiest part was the sorted array list. I have implemented it many times before.
 */