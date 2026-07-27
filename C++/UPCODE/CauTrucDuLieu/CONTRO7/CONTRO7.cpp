#include <iostream>
#include <fstream>
#include <climits>

struct Node
{
    int data;
    Node* next;
};

Node* tail_insertion(Node*& head, Node*& tail, int value)
{
    Node* new_node = new Node{value, nullptr};

    if (head == nullptr)
    {
        head = tail = new_node;
        return head;
    }
    tail->next = new_node;
    tail = tail->next;
    return head;
}

Node* head_insertion(Node*& head, Node*& tail, int value)
{
    Node* new_head = new Node{value, nullptr};

    if (head == nullptr)
    {
        head = tail = new_head;
        return head;
    }
    new_head->next = head;
    head = new_head;
    return head;
}

Node* insertion(Node*& head, Node*& tail, int position, int value)
{
    Node* new_node = new Node{value, nullptr};

    if (head == nullptr)
    {
        head = tail = new_node;
        return head;
    }

    if (position == 1)
    {
        delete new_node;
        head = head_insertion(head, tail, value);
        return head;
    }

    int index = 1;
    Node* current = head;
    while (current != nullptr and index < position - 1)
    {
        current = current->next;
        index++;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

void print(Node*& head)
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

void delete_list(Node*& head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    std::ifstream fin("CONTRO.inp");
    std::ofstream fout("CONTRO.out");

    int list_size; fin >> list_size;
    
    int val;
    for (int i = 0; i < list_size; i++)
    {
        fin >> val;
        head = tail_insertion(head, tail, val);
    }

    int min_dist = INT_MAX;
    for (Node* a = head; a != nullptr; a = a->next)
    {
        for (Node* b = a->next; b != nullptr; b = b->next)
        {
            int dist = abs(a->data - b->data);
            if (dist < min_dist)
            {
                min_dist = dist;
            }
        }
    }

    int pair_count = 0;
    for (Node* a = head; a != nullptr; a = a->next)
    {
        for (Node* b = a->next; b != nullptr; b = b->next)
        {
            int dist = abs(a->data - b->data);
            if (dist == min_dist) pair_count++;
        }
    }

    fout << pair_count << " " << min_dist << std::endl;
    for (Node* a = head; a != nullptr; a = a->next)
    {
        for (Node* b = a->next; b != nullptr; b = b->next)
        {
            int dist = abs(a->data - b->data);
            if (dist == min_dist)
            {
                int x = std::min(a->data, b->data);
                int y = std::max(a->data, b->data);
                fout << "(" << x << ", " << y << ")" << " ";
            }
        }
    }
    fout << std::endl;


    fin.close();
    fout.close();
    delete_list(head);
    return 0;
}