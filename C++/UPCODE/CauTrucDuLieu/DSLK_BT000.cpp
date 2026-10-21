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

    LinkedList zeros_list()
    {
        LinkedList result{nullptr, nullptr};
        LinkedList non_zeroList{nullptr, nullptr};
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == 0) result.append(current->data);
            else non_zeroList.append(current->data);
            current = current->next;
        }

        if (result.head == nullptr) return non_zeroList;
        if (non_zeroList.head == nullptr) return result;

        result.tail->next = non_zeroList.head;
        result.tail = non_zeroList.tail;
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

    void delete_list()
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
};

int main()
{
    int n; std::cin >> n;
    LinkedList list{nullptr, nullptr};

    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        list.append(val);
    }

    list.zeros_list().print();

    list.delete_list();
    return 0;
}