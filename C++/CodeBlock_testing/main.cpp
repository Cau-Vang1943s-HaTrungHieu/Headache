#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>

using namespace std;

// Ham lam sach man hinh
void xoaManHinh()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Ham tam dung man hinh va thong bao quay ve menu
void dungManHinh()
{
    cout << "\n -> Nhan [Enter] de quay lai menu...";
    cin.get();
}

// Ham kiem tra nhap so nguyen
int nhapSoNguyen(const string& thongBao)
{
    int giaTri;
    while (true)
	{
        cout << thongBao;
        if (cin >> giaTri)
		{
            char nextChar = cin.peek();
            // Ney ky tu la xuong dong hoac khoang trong -> Hop le
            if (nextChar == '\n' || nextChar == ' ')
			{
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        // Xu ly nhap sai
        cout << "[!] Gia tri khong hop le! Vui long chi nhap so nguyen.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return giaTri;
}

// Ham kiem tra nhap vi tri
int nhapViTri(const string& thongBao)
{
    int viTri;
    while (true)
	{
        viTri = nhapSoNguyen(thongBao);
        if (viTri >= 1)
		{
            break;
        }
        cout << " [!] Vi tri khong hop le! Vui long nhap so nguyen >= 1.\n";
    }
    return viTri;
}

//Struct va cac thao tac
struct Node
{
    int data;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

void initList(List& l)
{
    l.head = l.tail = nullptr;
}

Node* createNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

// 1. AddTail
void addTail(List& l, int x)
{
    Node* p = createNode(x);
    if (l.head == nullptr)
	{
        l.head = l.tail = p;
    }
	else
	{
        l.tail->next = p;
        l.tail = p;
    }
}

// 2. AddHead
void addHead(List& l, int x)
{
    Node* p = createNode(x);
    if (l.head == nullptr)
	{
        l.head = l.tail = p;
    }
	else
	{
        p->next = l.head;
        l.head = p;
    }
}

// 3. Them vao vi tri bat ki
void addAt(List& l, int x, int pos)
{
    if (pos == 1 || l.head == nullptr)
	{
        addHead(l, x);
        return;
    }
    Node* p = l.head;
    int idx = 1;
    while (p->next != nullptr && idx < pos - 1)
	{
        p = p->next;
        idx++;
    }
    if (p->next == nullptr)
	{
        addTail(l, x);
    }
	else
	{
        Node* newNode = createNode(x);
        newNode->next = p->next;
        p->next = newNode;
    }
}

// 5. RemoveHead
bool removeHead(List& l)
{
    if (l.head == nullptr) return false;
    Node* temp = l.head;
    l.head = l.head->next;
    if (l.head == nullptr) l.tail = nullptr;
    delete temp;
    return true;
}

// 4. RemoveTail
bool removeTail(List& l)
{
    if (l.head == nullptr) return false;
    if (l.head == l.tail)
	{
        delete l.head;
        l.head = l.tail = nullptr;
        return true;
    }
    Node* p = l.head;
    while (p->next != l.tail)
	{
        p = p->next;
    }
    delete l.tail;
    l.tail = p;
    l.tail->next = nullptr;
    return true;
}

// 6. Xóa vi tri bat ki
bool removeAt(List& l, int pos)
{
    if (l.head == nullptr) return false;
    if (pos == 1)
	{
        return removeHead(l);
    }
    Node* p = l.head;
    int idx = 1;
    while (p->next != nullptr && idx < pos - 1)
	{
        p = p->next;
        idx++;
    }
    if (p->next == nullptr) return false; // Vi tri vuot chieu dai danh sach

    Node* temp = p->next;
    p->next = temp->next;
    if (temp == l.tail)
	{
        l.tail = p;
    }
    delete temp;
    return true;
}

// Giai phong toan bo danh sach
void clearList(List& l)
{
    while (l.head != nullptr)
	{
        removeHead(l);
    }
}

// Hien thi danh sach lien ket
void printList(const List& l)
{
    Node* p = l.head;
    while (p != nullptr)
	{
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

// 7. Luu DSLK vào file save.txt
void saveToFile(const List& l, const string& filename)
{
    ofstream outFile(filename, ios::trunc);
    if (!outFile.is_open())
	{
        cout << "[!] Loi: Khong the mo file " << filename << " de ghi!\n";
        return;
    }
    Node* p = l.head;
    while (p != nullptr)
	{
        outFile << p->data << "\n";
        p = p->next;
    }
    outFile.close();
    cout << "[v] Da luu danh sach vao file " << filename << " thanh cong!\n";
}

// 8. Tai DSLK tu file save.txt
void loadFromFile(List& l, const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
	{
        cout << "[!] Loi: Khong tim thay file " << filename << "!\n";
        return;
    }

    clearList(l); // Giai phong danh sach cu

    int val;
    int count = 0;
    while (inFile >> val)
	{
        addTail(l, val);
        count++;
    }
    inFile.close();
    cout << "[v] Da tai " << count << " phan tu tu file " << filename << " vao danh sach!\n";
}

int main()
{
    List l;
    initList(l);
    int luaChon, giaTri, viTri;

    do {
        // Lam sach man hinh khi quay lai Menu
        xoaManHinh();

        cout << "======================================================\n";
        // Hien thi DSLK
        cout << " DSLK hien tai: ";
        printList(l);
        cout << "======================================================\n";
        cout << " 1. Them node vao cuoi danh sach (Add Tail)\n";
        cout << " 2. Them node vao dau danh sach (Add Head)\n";
        cout << " 3. Them node vao vi tri bat ky trong danh sach\n";
        cout << " 4. Xoa node cuoi danh sach\n";
        cout << " 5. Xoa node dau danh sach\n";
        cout << " 6. Xoa node tai vi tri bat ky trong danh sach\n";
        cout << " 7. Luu DSLK (Save to save.txt)\n";
        cout << " 8. Tai DSLK (Load from save.txt)\n";
        cout << " 0. Thoat chuong trinh\n";
        cout << "------------------------------------------------------\n";

        luaChon = nhapSoNguyen(" -> Chon chuc nang (0-8): ");
        cout << "\n";

        switch (luaChon) {
            case 1:
                giaTri = nhapSoNguyen(" Nhap gia tri can them cuoi: ");
                addTail(l, giaTri);
                cout << "[v] Da them node [" << giaTri << "] vao cuoi danh sach.\n";
                break;
            case 2:
                giaTri = nhapSoNguyen(" Nhap gia tri can them dau: ");
                addHead(l, giaTri);
                cout << "[v] Da them node [" << giaTri << "] vao dau danh sach.\n";
                break;
            case 3:
                giaTri = nhapSoNguyen(" Nhap gia tri can them: ");
                viTri = nhapViTri(" Nhap vi tri can them (>= 1): ");
                addAt(l, giaTri, viTri);
                cout << "[v] Da them node [" << giaTri << "] vao vi tri " << viTri << ".\n";
                break;
            case 4:
                if (removeTail(l))
                    cout << "[v] Da xoa node cuoi danh sach.\n";
                else
                    cout << "[!] Danh sach rong, khong co node de xoa!\n";
                break;
            case 5:
                if (removeHead(l))
                    cout << "[v] Da xoa node dau danh sach.\n";
                else
                    cout << "[!] Danh sach rong, khong co node de xoa!\n";
                break;
            case 6:
                viTri = nhapViTri(" Nhap vi tri node can xoa (>= 1): ");
                if (removeAt(l, viTri))
                    cout << "[v] Da xoa node tai vi tri " << viTri << ".\n";
                else
                    cout << "[!] Khong the xoa! Vi tri " << viTri << " khong ton tai hoac danh sach rong.\n";
                break;
            case 7:
                saveToFile(l, "save.txt");
                break;
            case 8:
                loadFromFile(l, "save.txt");
                break;
            case 0:
                cout << "[v] Dang thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "[!] Chuc nang khong ton tai! Vui long chon tu 0 den 8.\n";
                break;
        }

        // Tam dung man hinh khi thuc hien xog 1 yeu cau ( tru thoat chuong trinh )
        if (luaChon != 0) {
            dungManHinh();
        }

    } while (luaChon != 0);

    clearList(l);
    return 0;
}
