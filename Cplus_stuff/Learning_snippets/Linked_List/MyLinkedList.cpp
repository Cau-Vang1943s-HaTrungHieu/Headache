/*
    My linked list:
    - Create node:
    - Traversal function
    - Print list
    - Insertion: beginning - end - specification
    - Removal: above
    - Updating data
    - Searching
*/

#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node *head; // Currently contains garbage address
    Node *tail; // Currently contains garbage address

public:
    LinkedList() // Don't leave head and tail pointers uninitialized
    {
        head = NULL;
        tail = NULL;
    }
    /*
    Advanced - Constructor initializer list
    LinkedList() : head(NULL), tail(NULL) {}    
    */

    ~LinkedList()   // Delete both this list and its nodes
    {
        Node* current = head;
        while (current != NULL)
        {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        std::cout << "The list has been terminated. Memory is freed up." << std::endl;
    }

    void append(int value);
    void prepend(int value);
    void insert(int value, int position);
    void truncate();
    void behead();
    void remove(int position);
    void print() const;
};

void open_menu()
{
    std::cout << "\nC++ Linked List:" << std::endl;
    std::cout 
    << "- use \"append {value}\" if you'd like to add a node at the end of the list."
    << "\n- use \"prepend {value}\" to add a node at the beginning or the list."
    << "\n- use \"insert {value} {position}\" to add a node at a specific position in the list."
    << "\n- use \"truncate\" to remove the tail node."
    << "\n- use \"behead\" to remove the head node."
    << "\n- use \"remove {position}\" to remove a specific node in the list."
    << "\n- use \"print\" to print out the list.";
}

int main()
{
    bool is_running = true;
    
    LinkedList list;
    int val;
    while (std::cin >> val and val != -1) list.append(val);
    list.print();
    
    while (std::cin >> val and val != -1) list.prepend(val);
    list.print();

    int pos;
    std::cout << "Test insert method: "; std::cin >> val >> pos;
    list.insert(val, pos);
    list.print();

    std::cout << "Test node removal methods: " << std::endl;
    list.truncate();
    std::cout << "Truncate: "; list.print();
    list.behead();
    std::cout << "Behead: "; list.print();
    std::cout << "Test remove method: "; std::cin >> pos;
    list.remove(pos);
    list.print();


    return 0;
}

void LinkedList::append(int value)
{
    Node* new_node = new Node{value, NULL};
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
		return;
    }
    tail->next = new_node;
    tail = tail->next;
}

void LinkedList::prepend(int value)
{
    Node* new_head = new Node{value, head};
    head = new_head;
    /*
    or directly add head
    head = new Node{value, head};    
    */
    if (tail == NULL) tail = head; // Because your class maintains a tail pointer you 
}

void LinkedList::insert(int value, int position)
{
    Node* new_node = new Node{value, NULL};
    if (head == NULL)
    {
        head = tail = new_node;
        return;
    }

    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* current = head;
    int index = 1;
    while (current != NULL and index < position - 1)
    {
        current = current->next;
        index++;
    }

    if (current == NULL)
    {
        std::cout << "Out of bound. Cancelling insertion." << std::endl;
        delete new_node;
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
    if (new_node->next == NULL) tail = new_node; // Update tail too
}

void LinkedList::truncate()
{
    if (head == NULL)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* current = head;
    while (current->next != tail) current = current->next;
    delete tail;
    tail = current;
    tail->next = NULL;
}

void LinkedList::behead()
{
    if (head == NULL)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node* old_head = head;
    head = head->next;
    delete old_head;

    if (head == NULL) tail = NULL;
    /*
    In case head becomes NULL after deletion, tail has to be 
    pointed to NULL too.
    */
}

void LinkedList::remove(int position)
{
    if (head == NULL)
    {
        std::cout << "The list is empty. There's nothing to remove." << std::endl;
        return;
    }

    if (position == 1)
    {
        this->behead();
        return;
    }

    Node* current = head;
    int index = 1;
    while (current != NULL and index < position - 1)
    {
        current = current->next;
        index++;
    }

    if (current == NULL or current->next == NULL) 
    {
        std::cout << "Invalid, position goes out of bound." << std::endl;
        return;
    }

    Node* it = current->next;
    current->next = it->next;
    if (it == tail) tail = current;
    delete it; 
}

void LinkedList::print() const
{
    Node* current = head;
    while (current != NULL)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}