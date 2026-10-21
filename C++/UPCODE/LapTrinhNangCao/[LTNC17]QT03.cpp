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

    void append(int value)
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

    LinkedList without(int k)
    {
        LinkedList result{nullptr, nullptr};
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data != k) result.append(current->data);
            current = current->next;
        }
        return result;
    }

    int nodes()
    {
        Node* current = head;
        int result = 0;
        while (current != nullptr)
        {
            result += 1;
            current = current->next;
        }
        return result;
    }

    void print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

    void clear()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = tail = nullptr;
    }

    ~LinkedList()
    {
        clear();
    }
};

int main()
{
    int n, k; std::cin >> n >> k;

    LinkedList list{nullptr, nullptr};

    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        list.append(val);
    }

    LinkedList list_without_k = list.without(k);

    std::cout << list_without_k.nodes() << std::endl;
    list_without_k.print();

    list.clear();
    return 0;
}