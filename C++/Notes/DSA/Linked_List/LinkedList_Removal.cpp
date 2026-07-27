#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* create_node(int value)
{
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

Node* delete_head(Node* head)
{
    if (head == NULL) return NULL;

    Node* old_head = head;
    head = old_head->next;
    delete old_head;
    return head;
}

Node* delete_tail(Node* head, Node*& tail)  // delete the end node with tail pointer
{
    if (head == NULL) return NULL; // Empty list
    if (head == tail)  // Only one node
    {
        delete head;
        tail = NULL;
        return NULL;
    }

    // Find the node before the tail
    Node* current = head;
    while (current->next != tail) current = current->next;

    delete tail;
    tail = current;
    tail->next = NULL;

    return head;
}

Node* delete_tail(Node* head)   // delete the end node without tail pointer
{
    if (head == NULL) return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node* current = head;
    while (current->next->next != NULL) current = current->next;

    delete current->next;
    current->next = NULL;

    return head;
}

Node* delete_here(Node* head, int position)
{
    if (head == NULL) return NULL;
    if (position == 1)
    {
        Node* old_head = head;
        head = head->next;
        delete old_head;
        return head;
    }
    Node* current = head;
    int index = 1;
    while (current != NULL and index < position - 1)
    {
        current = current->next;
        index++;
    }

    if (current == NULL or current->next == NULL) return head;
    
    Node* it = current->next;
    current->next = it->next;
    delete it;

    return head;
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
    Node* n;
    Node* h = NULL;
    Node* t = NULL;
    int val;

    while (std::cin >> val and val != -1) // Use "sentinel" value to prevent EOF
    {
        n = create_node(val);
        
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

    std::cout << "Initial list: "; print_list(h); std::cout << std::endl;
    
    h = delete_head(h);
    std::cout << "After head removal: "; print_list(h); std::cout << std::endl;
    
    h = delete_tail(h, t);
    std::cout << "After tail removal: "; print_list(h); std::cout << std::endl;
    
    h = delete_tail(h);
    std::cout << "Attempt to remove tail again: "; print_list(h); std::cout << std::endl;

    int pos;
    std::cout << "Delete: "; std::cin >> pos;
    h = delete_here(h, pos);
    print_list(h); std::cout << std::endl;

    delete_list(h);
    return 0;
}