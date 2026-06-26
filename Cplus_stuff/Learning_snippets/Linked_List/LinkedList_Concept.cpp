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

struct Node
{
    int data;
    Node* next;
};
/*
    A linked list is a linear data structure where each element (node) contains:
    - data: the value stored 
    - pointer/address: a reference to the next node
*/

// Function to traverse and print the linked list
void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

// Function to delete the entire linked list
void deleteList(Node* head)
{
    Node* current = head;
    Node* nextNode;

    while (current != NULL)
    {
        nextNode = current->next; // Save the next node
        delete current; // Free the current node
        current = nextNode; // Move to the next node
    }
}

int main()
{
    // To create a Linked List, we need more than 1 node pointers
    /*
        - n for new node or end, whatever
        - t for temporary node, the next pointer of which 
        extends its reach to where the n pointer pointing to whenever
        n created a new node.
        - h for head node, the pointer that keeps track of the starting
        node.

        Notice that the pointer roles n, t, and h are respectively:
        - n: a temporary pointer for creating new node.
        - t: they call this "tail" and it is used to track the last node created
        - h: permanent reference to the starting node.
    */

    Node* n;
    Node* t;
    Node* h;

    n = new Node; // Create a new node containing 2 attributes: data and the address to the next node
    n->data = 1; // Assign a proper value to the data of the newly created node
    t = n; // Make pointer t point to where n is pointing.
    h = n; // h too
    // Congratulate! you've just created your first node.
    /*
        Actually "n = new Node" doesn't explicitly create a new node 
        at all. It requests memory from the heap and constructs a Node object
        from there.
    */

    n = new Node; // Make n leave the old node and point to a new one
    n->data = 2; // Assign the value 2 to the data of that node.
    t->next = n; // Extend pointer next of t to reach the new node.
    t = t->next; // Update: Make t fully point to the new node where n is pointing.
    /*
        Great, you created your second node, keep this up and you
        will have a long list of nodes soon.

        Notice that "t = t->next" expression is equivalent to 
        t = n; 
        Which basically means that we just make t point to where n is pointing
    */

    n = new Node; // Continue?
    n->data = 3;
    t->next = n;
    t = t->next;
 
    // That should be enough
    // To end the list you just need to make the next pointer of n point to NULL
    n->next = NULL;
    
    printList(h);
    deleteList(h);

    return 0;
}
