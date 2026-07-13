#include <iostream>

struct Node
{
    char data;
    Node* next;
};

void filter_increasing(Node* head, Node*& tail)
{
    if (head == NULL) return;
    Node* current = head->next;
    Node* prev = head;
    while (current) // this equivalents to current != NULL
    {
        if (current->data > prev->data)
        {
            prev = current; // keep node
            current = current->next;
        }
        else
        {
            // remove node
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
            if (prev->next == NULL) tail = prev;
        }
    }
}

void print(Node* head)
{
    Node* current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    char val;
    Node* h = NULL;
    Node* t = NULL;
    Node* n;

    while (std::cin >> val)
    {
        n = new Node;
        n->data = val;
        n->next = NULL;
        if (h == NULL)
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

    filter_increasing(h, t);
    print(h);

    return 0;
}