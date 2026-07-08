#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* createList(int nodeNumber)
{
    if (nodeNumber <= 0) return NULL;
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= nodeNumber; i++)
    {
        Node* new_node = new Node;
        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) // First node becomes head and tail
        {
            head = new_node;
            tail = new_node;
        }
        else 
        {
            // Link the new node to the tail and move tail forward
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head; // return the head pointer so caller can use the list
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
}

int main()
{
    Node* h = createList(5); // create list with nodes starting with head

    // Print the list
    print_list(h);

    delete_list(h);

    return 0;
}