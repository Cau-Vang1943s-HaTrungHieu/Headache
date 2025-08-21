#include <iostream>
using namespace std;

struct Person
{
    string ID;
    string name;
    int age;

    void getInfo()
    {
        cin.ignore(); getline(cin, ID);
        cin.ignore(); getline(cin, name);
        cin >> age;
    }

    void info()
    {
        cout << ID << " " << name << " " << age;
    }
};

int main()
{
    cout << "Fill an array with limitted amounts n:" << endl;
    int n;
    Person person[100]; // You could initialise with n elements instead of 100
    cin >> n;
    
    for (int i = 0 ; i < n; ++i) {
        person[i].getInfo();
    }
    for (int i = 0; i < n; ++i) {
        person[i].info(); cout << endl;
    }

    cout << endl;

    cout << "Input an array until cin reaches end of file state:" << endl;
    cout << "Method 1 - declare a temporary value, which is used to contain your input value then use loop to assign it to each element of the array:" << endl;

    int m = 0; 
    int a[100];
    int value; // tmp
    while (cin >> value) {
        a[m++] = value;
    }

    for (int i = 0; i < m; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Method 2 - directly insert value into all the elements of an array using loop:" << endl;
    int k = 0;
    int b[100];
    while (cin >> b[k]) {
        k++;
    }
    for (int i = 0; i < k; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Method 3 - Check SMGGateway" << endl;
    // while (n < 100) {
    //     sim[n].layThongTin();
    //     if (cin.fail()) break;
    //     n++;
    // }
    return 0;
}