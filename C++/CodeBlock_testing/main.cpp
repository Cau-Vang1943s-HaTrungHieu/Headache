#include <iostream>
#include <limits>
#include <cctype>
#include <string>

static bool running = true;

void wait_for_input()
{
    std::cout << "Nhan Enter de tiep tuc..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void to_lowercase(std::string& str)
{
    for (char& s : str) s = std::tolower(static_cast<unsigned char>(s));
}

bool allowed_to_continue()
{
    std::string permission;
    std::cout << "Tiep? (yes/no): "; std::cin >> permission;
    to_lowercase(permission);
    return permission == "yes";
}

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head = NULL;
    Node* tail = NULL;
public:

    // Modifications
    void append(int value);
    void prepend(int value);
    void insert(int value, int posistion);
    void truncate();
    void behead();
    void remove(int position);

    // Operations
    void print();
    bool contain(int value);
    Node* find(int value);
    void clear();

    ~LinkedList()
    {
        clear();
        std::cout << "Xoa DSLK, bo nho duoc giai phong." << std::endl;
    }
};

void execute(LinkedList& list)
{
    system("cls");

    int choice = 0;
    int val = 0;
    int pos = 0;
    list.print();

    std::cout << "Danh sach lien ket:"
    << "\n1. Them phan tu vao cuoi danh sach"
    << "\n2. Them phan tu vao dau danh sach"
    << "\n3. Them phan tu vao vi tri bat ky"
    << "\n4. Xoa phan tu cuoi danh sach"
    << "\n5. Xoa phan tu dau danh sach"
    << "\n6. Xoa phan tu o vi tri bat ky"
    << "\n7. Tim phan tu trong danh sach"
    << "\nNhap -1 de thoat chuong trinh"
    << "\nChon: "; std::cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            std::cout << "Nhap gia tri: "; std::cin >> val;
            list.append(val);
        }
        while (allowed_to_continue());
        break;
    case 2:
        do
        {
            std::cout << "Nhap gia tri: "; std::cin >> val;
            list.prepend(val);
        }
        while (allowed_to_continue());
        break;
    case 3:
        do
        {
            std::cout << "Nhap gia tri va vi tri: "; std::cin >> val >> pos;
            list.insert(val, pos);
        }
        while (allowed_to_continue());
        break;
    case 4:
        do list.truncate(); while (allowed_to_continue());
        break;
    case 5:
        do list.behead(); while (allowed_to_continue());
        break;
    case 6:
        do
        {
            std::cout << "Nhap vi tri can xoa: "; std::cin >> pos;
            list.remove(pos);
            break;
        }
        while (allowed_to_continue());
        break;
    case 7:
        do
        {
            std::cout << "Nhap gia tri cua node can tim: "; std::cin >> val;
            std::cout << (list.contain(val) ? "true" : "false") << std::endl;
        }
        while (allowed_to_continue());
        break;
    case -1:
        running = false;
        break;
    default:
        std::cout << "Lua chon khong hop le" << std::endl;
        break;
    }

    if (choice != -1) wait_for_input();
}

int main()
{
    LinkedList list;

    do execute(list); while (running);

    return 0;
}

void LinkedList::append(int value)
{
    Node* new_node = new Node{value, NULL};
    if (head == NULL)
    {
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = tail->next;
}

void LinkedList::prepend(int value)
{
    Node* new_head = new Node{value, NULL};
    if (head == NULL)
    {
        head = tail = new_head;
        return;
    }
    new_head->next = head;
    head = new_head;
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
        std::cout << "Het danh sach, them node that bai." << std::endl;
        delete new_node;
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
    if (new_node->next == NULL) tail = new_node;
}

void LinkedList::truncate()
{
    if (head == NULL)
    {
        std::cout << "Danh sach rong" << std::endl;
        return;
    }

    if (head == tail)
    {
        delete head;
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
        std::cout << "Danh sach trong" << std::endl;
        return;
    }
    Node* previous_node = head;
    head = head->next;
    delete previous_node;
}

void LinkedList::remove(int position)
{
    if (head == NULL)
    {
        std::cout << "Danh sach rong." << std::endl;
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
        std::cout << "Khong hop le, vi tri khog nam trong danh sach." << std::endl;
        return;
    }

    Node* it = current->next;
    current->next = it->next;
    if (it == tail) tail = current;
    delete it;
}

// Operations
void LinkedList::print()
{
    Node* current = head;
    while (current != NULL)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL";
    std::cout << std::endl;
}

bool LinkedList::contain(int value)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

Node* LinkedList::find(int value)
{
    Node* current = head;
    while (current != NULL)
    {
        if (contain(value)) return current;
        current = current->next;
    }
    return NULL;
}

void LinkedList::clear()
{
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
