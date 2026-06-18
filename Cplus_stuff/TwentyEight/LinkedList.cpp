// *****************************************************

// LinkedList =  Nodes are in 2 parts (data + address)
//                        Nodes are in non-consecutive memory locations
//                        Elements are linked using pointers

//    advantages?
//    1. Dynamic Data Structure (allocates needed memory while running)
//    2. Insertion and Deletion of Nodes is easy. O(1)
//    3. No/Low memory waste

//    disadvantages?
//    1. Greater memory usage (additional pointer)
//    2. No random access of elements (no index [i])
//    3. Accessing/searching elements is more time consuming. O(n)

//    uses?
//    1. implement Stacks/Queues
//    2. GPS navigation
//    3. music playlist
//

// *****************************************************

#include <iostream>

int main()
{
    int a = 8, b = 7;
    a = a + (b--);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
