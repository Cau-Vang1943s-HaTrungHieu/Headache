#include <iostream>

struct Node
{
    int data;
    Node* next;
};

struct LinkedList
{
    Node* head;
    Node* tail;

    void add_tail(int value)
    {
        Node* new_node = new Node{value, nullptr};

        if (head == nullptr)
        {
            head = tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = tail->next;
    }

    void print()
    {
        Node* current = head->next;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

    int size()
    {
        int result = 0;
        Node* current = head;
        while (current != nullptr)
        {
            result += 1;
            current = current->next;
        }
        return result;
    }

    int even_nodes()
    {
        int result = 0;
        Node* current = head->next;
        while (current != nullptr)
        {
            if (current->data % 2 == 0) result++;
            current = current->next;
        }
        return result;
    }
};

int main()
{
    int n;
    LinkedList list{nullptr, nullptr};

    while (std::cin >> n) list.add_tail(n);

    if (list.size() == 0) std::cout << "NO";
    else std::cout << list.size();
    std::cout << std::endl;

    if (list.size() < 2) std::cout << "NO";
    else list.print();
    std::cout << std::endl;

    if (list.even_nodes() == 0) std::cout << "NO";
    else std::cout << list.even_nodes();

    return 0;
}