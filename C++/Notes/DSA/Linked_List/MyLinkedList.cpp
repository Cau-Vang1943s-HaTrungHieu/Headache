#include <iostream>
#include <string>
#include <limits>
#include <cctype>

static bool running = true;
static bool duplicate_check_ON = false; // Cau 8
static bool running_split_list = false;

void wait_for_input()
{
    std::cout << "Nhan Enter de tiep tuc...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void to_lowercase(std::string& str)
{
    for (char& s : str) s = std::tolower(static_cast<unsigned char>(s));
}

bool permission_to_continue()
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
    Node *head;
    Node *tail;
    size_t node_count;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        node_count = 0;
    }

    ~LinkedList()
    {
        clear();
    }

    size_t get_size() const; // Cau 3

    Node* created(int value) // NO USE
    {
        Node* new_node = new Node;
        ++node_count;
        if (new_node == NULL) return NULL; // return nothing if your potato computer doesn't have enough memory to allocate!
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }

    void append(int value);
    void prepend(int value); // Cau 4
    void insert(int value, int position);
    void truncate(); // cau 6
    void behead(); // Cau 5
    void remove(int position);
    void clear();
    /*
        use function to delete list instead of destructor to avoid
        "undefined behaviour"
    */
    
    void print() const;
    int sum(); // Cau 1
    Node* max_node(); // Cau 2
    int instances_of(int x); // Cau 7
    bool contains(int value) const; // Cau 8

    void split_copy(int x, LinkedList& smaller, LinkedList& greater) const; // cau 9
    void split_move(int x, LinkedList& smaller, LinkedList& greater); // Cau 9
    void append(Node* node); // Cau 9
};

void execute(LinkedList& list)
{
    system("cls");

    int choice = 0;
    int val = 0;
    int pos = 0;

    list.print();
    std::cout
    << "\n1. Tinh tong gia tri cac phan tu tren danh sach. (Cau 1)"
    << "\n2. Gia tri lon nhat trong danh sach. (Cau 2)"
    << "\n3. So luong phan tu cua danh sach. (Cau 3)"
    << "\n4. Them phan tu vao cuoi danh sach (Cau 4)"
    << "\n5. Them phan tu vao dau danh sach"
    << "\n6. Them phan tu vao diem bat ky trong danh sach"
    << "\n7. Xoa phan tu cuoi danh sach (Cau 6)"
    << "\n8. Xoa phan tu dau danh sach (Cau 5)"
    << "\n9. Xoa phan tu bat ky trong danh sach"
    << "\n10. So luong phan tu trung voi gia tri x (Cau 7)"
    << "\n11. " << (duplicate_check_ON ? "(ON)" : "(OFF)") << " DSLK khac nhau tung doi mot (Cau 8)"
    << "\n12. Tach DSLK"
    << "\nChon: "; std::cin >> choice;

    switch (choice)
    {
        case 1:
            std::cout << list.sum() << std::endl;
            break;
        case 2:
            if (Node* max = list.max_node()) std::cout << max->data << std::endl;
            else std::cout << "NULL" << std::endl;
            break;
        case 3:
            std::cout << list.get_size() << std::endl;
            break;
        case 4: 
            do
            {
                std::cin >> val; 
                list.append(val);
            }
            while (permission_to_continue());
            break;
        case 5:
            do
            {
                std::cin >> val;
                list.prepend(val);
            }
            while (permission_to_continue());
            break;
        case 6:
            do
            {
                std::cout << "Nhap theo thu tu (gia_tri vi_tri): ";
                std::cin >> val >> pos;
                list.insert(val, pos);
            } 
            while (permission_to_continue());
            break;
        case 7: 
            do list.truncate(); while (permission_to_continue());
            break;
        case 8:
            do list.behead(); while (permission_to_continue());
            break;
        case 9:
            do
            {
                std::cin >> pos;
                list.remove(pos);
            }
            while (permission_to_continue());
            break;
        case 10:
            int x;
            std::cout << "Nhap x: "; std::cin >> x;
            std::cout << list.instances_of(x) << std::endl;
            break;
        case 11:
            if (duplicate_check_ON)
            {
                duplicate_check_ON = false;
                std::cout << "Kiem tra cap phan tu giong nhau = OFF" << std::endl;
            }
            else
            {
                std::cout << "Xoa danh sach truoc? (1 - co/ 0 - ko): ";
                std::cin >> choice;
                if (choice == 1) list.clear();
                duplicate_check_ON = true;
                std::cout << "Kiem tra cap phan tu giong nhau = ON" << std::endl;
            }
            break;
        case 12:
            running = false;
            running_split_list = true;
            break;
        case -1:
            running = false;
            break;
        default: 
            std::cout << "Lua chon khong hop le." << std::endl;
            break;
    }

    if (choice != -1) wait_for_input();
}

void execute(LinkedList& original_list, LinkedList& greater, LinkedList& smaller)
{
    system("cls");

    int choice = 0;
    int x;
    original_list.print();
    std::cout << "> x:"; greater.print();
    std::cout << "< x:"; smaller.print();

    std::cout
    << "\n1. DSLK ban dau khong can ton tai."
    << "\n2. DSLK ban dau bat buoc phai ton tai."
    << "\nNhap -1 de tro ve"
    << "\nChon: "; std::cin >> choice;
    
    if (choice != -1)
    {
        std::cout << "x = ";
        std::cin >> x;
    }

    switch (choice)
    {
    case 1: original_list.split_move(x, smaller, greater); break;
    case 2: original_list.split_copy(x, smaller, greater); break;
    case -1: running = true; running_split_list = false; break;
    default: std::cout << "Khong hop le!" << std::endl; break;
    }

    if (choice != -1) wait_for_input();
}

int main()
{
    LinkedList list;
    LinkedList list2;
    LinkedList list3;

    // here: // --> Dung xai goto
    // do execute(list); while (running); // Cac cau con lai
    
    // do execute(list, list2, list3); while (running_split_list); // Cau 9
    
    while (true)
    {
        while (running) execute(list);
        while (running_split_list) execute(list, list2, list3);
        
        if (!running) break;
    }


    return 0;
}

size_t LinkedList::get_size() const
{
    return node_count;
}

void LinkedList::append(int value)
{
    if (duplicate_check_ON and contains(value))
    {
        std::cout << "Gia tri da ton tai." << std::endl;
        return;
    }

    Node* new_node = new Node{value, NULL}; ++node_count;
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
    if (duplicate_check_ON and contains(value))
    {
        std::cout << "Gia tri da ton tai." << std::endl;
        return;
    }

    Node* new_head = new Node{value, head}; ++node_count;
    head = new_head;

    if (tail == NULL) tail = head;
}

void LinkedList::insert(int value, int position)
{
    if (duplicate_check_ON and contains(value))
    {
        std::cout << "Gia tri da ton tai." << std::endl;
        return;
    }

    Node* new_node = new Node{value, NULL}; ++node_count;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
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
        std::cout << "Het danh sach. Them node that bai." << std::endl;
        delete new_node; --node_count;
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
        std::cout << "Danh sach rong." << std::endl;
        return;
    }

    if (head == tail)
    {
        delete head; --node_count;
        head = tail = NULL;
        return;
    }

    Node* current = head;
    while (current->next != tail) current = current->next;
    delete tail; --node_count;
    tail = current;
    tail->next = NULL;
}

void LinkedList::behead()
{
    if (head == NULL)
    {
        std::cout << "Danh sach rong." << std::endl;
        return;
    }
    Node* old_head = head;
    head = head->next;
    delete old_head; --node_count;

    if (head == NULL) tail = NULL;
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
        std::cout << "Khong hop le, vi tri khong nam trong danh sach." << std::endl;
        return;
    }
    
    Node* it = current->next;
    current->next = it->next;
    if (it == tail) tail = current;
    delete it; --node_count;
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
    head = NULL;
    tail = NULL;
    node_count = 0;
    std::cout << "Xoa DSLK, bo nho node duoc giai phong." << std::endl;
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

int LinkedList::sum()
{
    int result = 0;
    Node* current = head;
    while (current != NULL)
    {
        result += current->data;
        current = current->next;
    }
    return result;
}

Node* LinkedList::max_node() 
{
    if (head == NULL)
    {
        std::cout << "Danh sach rong." << std::endl;
        return NULL;
    }

    Node* result = head;
    Node* current = head->next;
    while (current != NULL)
    {
        if (current->data > result->data) 
            result = current; 
        current = current->next;
    }
    return result;
}

int LinkedList::instances_of(int x)
{
    int instances = 0;
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == x) instances++;
        current = current->next;
    }
    return instances;
}

bool LinkedList::contains(int value) const
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void LinkedList::split_copy(int x, LinkedList& smaller, LinkedList& greater) const
{
    smaller.clear();
    greater.clear();

    Node* current = head;
    while (current != NULL)
    {
        if (current->data < x) smaller.append(current->data);
        else if (current->data > x) greater.append(current->data);
        current = current->next;
    }
}

void LinkedList::split_move(int x, LinkedList& smaller, LinkedList& greater)
{

    smaller.clear();
    greater.clear();

    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        current->next = NULL;

        if (current->data < x) smaller.append(current);
        else if (current->data > x) greater.append(current);
        else delete current;
        current = next;
    }
    head = tail = NULL;
    node_count = 0;
}

void LinkedList::append(Node* node)
{
    if (node == NULL) return;
    node->next = NULL; ++node_count;

    if (head == NULL)
    {
        head = node;
        tail = node;
        return;
    }
    tail->next = node;
    tail = tail->next;
}