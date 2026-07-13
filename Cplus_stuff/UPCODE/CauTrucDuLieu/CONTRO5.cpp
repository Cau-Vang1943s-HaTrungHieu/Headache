#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void print(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void delete_list(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

bool found_trio(Node* head)
{
    for (Node* a = head; a != NULL; a = a->next)
    {
        for (Node* b = head; b != NULL; b = b->next)
        {
            for (Node* c = head; c != NULL; c = c->next)
            {
                if (a != b and a != c and b != c) // Ensure distinct nodes
                {
                    if (a->data == b->data + c->data) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    Node* h = NULL, * t = NULL, * n;
    
    int num; std::cin >> num;

    for (int i = 0; i < num; i++)
    {
        int val; std::cin >> val;
        n = new Node{val, NULL};
        if (h == NULL) h = t = n;
        else
        {
            t->next = n;
            t = t->next;
        }
    }
    std::cout << (found_trio(h) ? "YES" : "NO") << std::endl;

    delete_list(h);
    return 0;
}