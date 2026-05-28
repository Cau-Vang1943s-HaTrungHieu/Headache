#include <iostream>
using namespace std;

// Khai báo node
struct Node
{
    int data;
    Node* next;
};

// Tạo node mới
Node* createNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm node vào cuối danh sách
void addTail(Node*& head, int x)
{
    Node* p = createNode(x);

    if (head == NULL)
    {
        head = p;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;
}

int main()
{
    int n;
    cin >> n;

    Node* head = NULL;

    // Nhập danh sách liên kết
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addTail(head, x);
    }

    // Khởi tạo min và max
    int maxValue = head->data;
    int minValue = head->data;

    // Duyệt tìm min và max
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data > maxValue)
            maxValue = temp->data;

        if (temp->data < minValue)
            minValue = temp->data;

        temp = temp->next;
    }

    // In giá trị lớn nhất
    cout << maxValue << endl;

    // In vị trí các phần tử lớn nhất
    temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == maxValue)
            cout << pos << " ";

        temp = temp->next;
        pos++;
    }

    cout << endl;

    // In giá trị nhỏ nhất
    cout << minValue << endl;

    // In vị trí các phần tử nhỏ nhất
    temp = head;
    pos = 1;

    while (temp != NULL)
    {
        if (temp->data == minValue)
            cout << pos << " ";

        temp = temp->next;
        pos++;
    }

    return 0;
}