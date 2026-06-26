#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* create_node(int data)
{
    Node* new_node = new Node;
    if (new_node == NULL) return NULL; // Extra step to check if it is possible to create a new node
    new_node->data = data;
    new_node->next = NULL; // Remember to point it to NULL
    return new_node;
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
    std::cout << "\nThe list has been removed!" << std::endl;
}

int main()
{
    Node* n, * t, * h = NULL;
    int data;
    
    while (std::cin >> data)
    {
        n = create_node(data);
        
        if (h == NULL) // First node becomes head and tail
        {
            h = n;
            t = n;
        }
        else 
        {
            t->next = n;
            t = t->next;
        }
    }

    print_list(h);
    delete_list(h);

    return 0;
}