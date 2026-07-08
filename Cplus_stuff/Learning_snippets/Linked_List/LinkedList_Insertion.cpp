#include <iostream>

struct Node
{
    int data;
    Node* next;
};

// Beginning of a node should always be the head
Node* insert_head(Node* current_head, int value)
{
    Node* new_head = new Node;
    new_head->data = value; // assign data to the new node
    new_head->next = current_head; // link new node to the old head
    return new_head; // return new head to caller, this also updates the head pointer
}

Node* insert_tail(Node* head /*No need to pass head by reference because we'll return it anyway*/, Node*& tail, int value)
{
    Node* new_tail = new Node;
    new_tail->data = value;
    new_tail->next = NULL;
    
    if (head == NULL)
    {
        // If the list is empty then assign new tail as head and tail.
        head = new_tail;
        tail = new_tail;
    }
    else
    {
        tail->next = new_tail;
        tail = new_tail;
    }
    return head;
}

Node* insert_here(Node* head, int position, int value)
{
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;

    // Case 1: Empty list or inserting at position 1
    if (head == NULL or position == 1) 
    {
        new_node->next = head; // link new node to old head (the head may also be NULL)
        head = new_node; // Update head pointer
        return head;
    }
    
    // Case 2: General insertion
    Node* current = head;
    int count = 1;

    // Traverse until the node just before the desired position
    while (current != NULL and count < position - 1)
    {
        current = current->next;
        count++;
    }

    // If position is out of bounds (too large), just insert at the end
    if (current == NULL)
    {
        std::cout << "Out of bound, inserting at the end...";
        current = head;
        while (current->next != NULL) current = current->next;        
        current->next = new_node;
        return head;
    }

    // Splice in the new node
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Slide's head insertion method
void add_head(Node*& current_head, int value)
{
    Node* new_head = new Node;
    new_head->data = value;
    if (current_head == NULL) current_head = new_head;
    /*
        If the list doesn't have any nodes then just assign the 
        new head as the current head.
    */
    else 
    {
        new_head->next = current_head;
        current_head = new_head; // Update head pointer
    }
}

void print_list(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL";
}

void delete_list(Node* head)
{
    Node* current = head;
    Node* next_node;
    while (current != NULL)
    {
        next_node = current->next;
        delete current;
        current = next_node;
    }
    std::cout << "The list has been deleted!";
}

int main()
{
    Node* n, * t, * h;

    n = new Node;
    n->data = 1;
    t = n;
    h = n;

    n = new Node;
    n->data = 2;
    t->next = n;
    t = t->next;

    n = new Node;
    n->data = 3;
    t->next = n;
    t = t->next;

    n->next = NULL;

    std::cout << "\nBefore insertion: "; print_list(h);
    std::cout << std::endl;

    h = insert_head(h, 0); // Your method
    std::cout << "\nAfter insertion: "; print_list(h);
    std::cout << std::endl;

    add_head(h, 10); // Slide method
    std::cout << "\nAfter second insertion: "; print_list(h);
    std::cout << std::endl;

    h = insert_tail(h, t, 18);
    std::cout << "\nTail insertion: "; print_list(h);
    std::cout << std::endl;

    int position;
    std::cout << "\nInsert at: "; std::cin >> position;
    h = insert_here(h, position, 27);
    print_list(h);
    std::cout << std::endl;

    delete_list(h);
    return 0;
}