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
        std::cout << current->data;
        current = current->next;
    }
    std::cout << std::endl;
}

void delete_list(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        Node* it = current;
        current = current->next;
        delete it;
    }
}

int main()
{
    int num;
    Node* h = NULL;
    Node* t = NULL;
    Node* n;

    std::cin >> num;

    for (int i = 0; i < num; i++)
    {
        char c; std::cin >> c;
        n = new Node;
        n->data = c;
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

    print(h);

    for (char c = 'A'; c <= 'Z'; c++) std::cout << c;
    std::cout << std::endl;

    delete_list(h);
    return 0;
}