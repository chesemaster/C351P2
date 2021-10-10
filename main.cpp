#include <iostream>
#include <chrono>
#include "SortedArrayList.h"
#include "CirDubLinkedList.h"
using namespace std::chrono;

int main() {
    std::cout <<  "24" << std::endl;
    SortedArrayList<int> list;
    list.insert(2);
    list.insert(8);
    std::cout << list.getElementCount() << std::endl;
    list.printList();

    CirDubLinkedList<int> list2;
    list2.insert(3);
    list2.insert(9);
    std::cout << list2.GetLength() << std::endl;
    list2.printList();

  
    /*
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 1000; i++){
        std::cout << i;
    }
    std::cout << std::endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop-start);

    std::cout << duration.count() << std::endl;
*/
    return 0;
}
