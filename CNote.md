CƠ BẢN
---
 
# Làm tròn số:
   - Làm tròn một số thực đến một con số thập phân nào đó.
   - Ở phần gọi thư viện nhớ ghi dòng lệnh này để sử dụng hàm setprecision.
```cpp
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(5) << // số thực nào đó;
    return 0;
}
```

*Ví dụ*:
```cpp
// Ma: H_TINHTONG
// Ten: Tính tổng

#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

double S_n(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += 1.0 / (i * (i + 1));
    }
    return sum;
}

int main()
{
    int n; cin >> n;
    cout << fixed << setprecision(5) << S_n(n) << endl; // làm tròn số đến số thập phân thứ 5

    return 0;
}
```

# Random number
1. rand() function
    - You can use rand() function in the <cstdlib> library to generate a random number.
    - To print out a number in a specific range (for example 0 and 100), consider using this formula:
```cpp
int randomNum = rand() % 101;
cout << randomNum;
return 0;
```
2. srand() and time() functions
    - To output different random numbers each time the program runs, you can use srand() and time() functions from the <ctime> library

*Example:*
```cpp
srand(time(0));
int randomNum = rand() % 101;
cout << randomNum
return 0;

// Randomize operator
char math_op = “+-*”[rand() % 3];
```

# Built-in functions:
### cctype library
- `tolower() / toupper()`

NÂNG CAO
---

# Con trỏ (Pointer)

## Khái niệm:
- Con trỏ là **loại biến** được dùng để **chứa địa chỉ** của biến khác và cho phép truy xuất địa chỉ của một biến trong bộ nhớ.
	+ Một ô nhớ đặc trưng bởi hai thành phần:
		*Địa chỉ của ô nhớ*
		*Giá trị hiện thời của ô nhớ*
	+ 1 ô = 1 byte
	+ Địa chỉ của biến = địa chỉ ô nhớ đầu tiên -> địa chỉ của mảng = địa chỉ của phần tử đầu tiên.
- Cách khai báo:
```cpp
<tên kiểu dữ liệu>* <tên biến con trỏ>;
// VD:
int* myPtr;
float* myFloatPtr;
```

## Thao tác với con trỏ

### Truy xuất địa chỉ và truy xuất vùng nhớ
- Toán tử `&` dùng để truy xuất **địa chỉ** của biến, lưu ý là con trỏ kiểu gì thì nhận địa chỉ của biến kiểu đó.
	+ Cú pháp: `&<tên biến>;`
```cpp
	int x = 6;
    int* x_address = &x; 
    // &x la bien int* thi x_address cung phai la int*

    cout << &x << endl;
    cout << x_address << endl;
    return 0;
```

- Toán tử `*` dùng để truy xuất **vùng nhớ** của bién: VD:
	+ Cú pháp: `*<tên biến con trỏ>;`
```cpp
	int x = 6;
    int* x_address = &x; 
    int x_value = *x_address;
    // x_value = x_address --> value of x

    cout << x_value << endl; // 6
```
>> Hai khái niệm trên là **toán tử** khác với **con trỏ** (Reference and Dereference operators)

### Gán con trỏ cho con trỏ khác
- Thực chất là phép copy **địa chỉ** mà con trỏ gốc đang giữ sang con trỏ khác. Cho nên thao tác này tạo ra hai con trỏ cùng trỏ vào một vùng nhớ.
```cpp
	int a = 6;
    int* my_pointer = &a;
    // int* my_second_pointer = *my_pointer;
    // Không thể làm vậy bởi vì ta không thể gán con trỏ cho vùng nhớ.
    // int* -/-> int

    int* my_second_pointer = my_pointer;
    // * --> * --> địa chỉ của a

    cout << &a << endl;
    cout << my_pointer << endl;
    cout << my_second_pointer << endl;
```

### Truyền tham số con trỏ với hàm
- Truyền tham trị **(pass-by-value)** có nghĩa là truyền **bản sao của con trỏ** vào hàm, giá trị truyền vào là **địa chỉ con trỏ** vùng nhớ gốc có thể bị thay đổi.
```cpp
void passByValFunc(int* number) 
{
    *number = *number + 1; // Dereference xong + 1 ra 6
    // number = number + 1; --> Này là lấy địa chỉ + 1
}

int main()
{
    int x = 5;
    int* x_pointer = &x;

    passByValFunc(x_pointer);
    cout << x;
}
```

- Truyền tham chiếu **(pass-by-reference)** có nghĩa là truyền **bản gốc** của con trỏ vào hàm, giá trị truyền vào cũng là **địa chỉ** con trỏ, và vùng nhớ gốc cũng có thể bị thay đổi.
```cpp
void passByRefFunc(int* &number) 
{
    *number = *number + 1; // Dereference xong + 1 ra 6
    // number = number + 1; --> Này là lấy địa chỉ + 1
}

int main()
{
    int x = 5;
    int* x_pointer = &x;

    passByValFunc(x_pointer);
    cout << x;
}
```

### Các thao tác khác

- Khai báo con trỏ **rỗng**:
```cpp
	int* myPtr = NULL;
	int* myPtr = nullptr;
```

- Con trỏ **có cấu trúc** (struct pointer):
	+ Cú pháp `<tên kiểu cấu trúc>* <tên con trỏ>;`
```cpp
	struct HocSinh
	{
		float diem_van;
		float diem_toan;
	};
	HocSinh hs;
	HocSinh* p = &hs;
```

## Con trỏ vs mảng
- Mảng cũng là một con trỏ (địa chỉ nằm ở phần tử đầu tiên của mảng)
```cpp
	int a[3];
    // int* a_pointer = &a; --> Sai
    int *a_pointer = a;

    cout << &a[0] << endl;
    cout << a << endl; // Như trên
    cout << a_pointer << endl; // Như trên
```

### Truy xuất mảng bằng con trỏ
- Để **truy xuất phần tử cụ thể** trong mảng với con trỏ ta sử dụng **toán tử +/-** (_+ thì sao mà trừ thì sao thì chưa rõ_).
- Công thức: `<con trỏ> +/- i` <=> `<địa chỉ> +/- i*sizeof(<kiểu dữ liệu>)
- Truy xuất **địa chỉ** ta sử dụng công thức trên:
```cpp
	int a[] = {3, 5, 7};
    int *a_pointer = a;

    cout << a_pointer+1 << endl; // &a[1]
    cout << a_pointer+2 << endl; // &a[2]
```

- Truy xuất **giá trị vùng nhớ** ta sử dụng toán tử `*`:
```cpp
int a[] = {3, 5, 7};
    int *a_pointer = a;

    cout << *(a_pointer+1) << endl; // a[1] = 5
    cout << *(a_pointer-1) << endl; // a[-1] = ???
    cout << *(a_pointer+2) << endl; // a[2] = 7
```

- Truy xuất **giá trị vùng nhớ** trực tiếp bằng toán tử `[]`:
```cpp
	int a[] = {3, 5, 7};
    int *a_pointer = a;

    cout << a_pointer[0] << endl; // a[0] = 3
    cout << a[0] << endl;
```

### Truyền tham số là mảng vào hàm
- Khi truyền tham số mảng vào hàm thực chất ta đang truyền con trỏ vào hàm đó, cho nên giá trị của mảng có thể bị thay đổi sau khi thực thi hàm.
```cpp
void putArrayInHere(int array[])
{
    array[2] = 1;
}

int main()
{
    int a[] = {3, 5, 7};
    putArrayInHere(a);
    cout << a[2] << endl; // 1
}
```

# Con trỏ nâng cao

## Quản lý bộ nhớ

### Cấp phát bộ nhớ (memory allocation)
- Cấp phát bộ nhớ cho một vùng nhớ để sử dụng
- Toán tử `new` cấp phát bộ nhớ: `new <kiểu dữ liệu>[<số phần tử];`
- Toán tử `delete` để giải phóng bộ nhớ (luôn nhớ phải giải phóng sau khi sử dụng): `delete <biến kiểu con trỏ>;`
```cpp
	int* a = new int;
    delete a;

    int* b = new int[3];
    delete[]b;
```

### Mảng động một chiều (dynamic array)
- Cấp phát bộ nhớ khi cần.
- Không cần phải khai báo trước phần tử
- Cần chủ động giải phóng bộ nhớ
- Cách khai báo:
```cpp
	int n;
    cin >> n;
    int* dynamic_array = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> dynamic_array[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << dynamic_array[i] << " ";
    }
```

## Con trỏ nhiều cấp
- Biến và con trỏ có địa chỉ riêng biệt
	+ Biến có địa chỉ là `int*`
	+ Con trỏ có địa chỉ là `int**` 
- Số lượng toán tử `*` biểu thị cấp của con trỏ hoặc ta có thể khai báo
con trỏ nhiều cấp bằng typedef.
```cpp
	int a = 3;
    int* pointer_lv1;
    int** pointer_lv2;

    pointer_lv1 = &a;
    // pointer_lv2 = &a; Vì int* -/-> int**
    pointer_lv2 = &pointer_lv1;
    
    cout << pointer_lv1 << endl;
    cout << pointer_lv2 << endl;
```

- Chỉ có thể truy xuất với đúng cấp của con trỏ.
```cpp
	int a = 3;
    int* pointer_lv1;
    int** pointer_lv2;

    pointer_lv1 = &a;
    // pointer_lv2 = &a; Vì int* -/-> int**
    pointer_lv2 = &pointer_lv1;
    
    // 
    cout << pointer_lv1 << endl; // Truy xuất địa chỉ a
    cout << *pointer_lv2 << endl; // Truy xuất địa chỉ pointer_lv1
    cout << *pointer_lv1 << endl; // Truy xuất giá trị vùng nhớ a
    cout << **pointer_lv2 << endl; // Truy xuất giá trị vùng nhớ a

    *pointer_lv1 = 5;
    **pointer_lv2 = 7;
    cout << a << endl;
```

### Mảng động nhiều chiều:
- Mảng động một chiều là con trỏ cấp một.
- Mảng 2 chiều là mảng động chứa các con trỏ cấp 1 -> ma trận
- Và ma trận thực chất chỉ là một **vùng nhớ liên tiếp** trong RAM
```cpp
	int M, N;
    cin >> M >> N;
    int** matrix = new int* [M]; // cấp phát bộ nhớ cho con trỏ cấp 2

    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];    // Khai báo con trỏ cấp 1
        for (int j = 0; j < N; j++) {
            cout << "Nhap a[" << i << "][" << j << "]= ";
            cin >> matrix[i][j];
        }
    }
    delete[]matrix;
```

### Truy xuất các phần tử của ma trận nhiều chiều
- Sử dụng toán tử `[]`
- Truy xuất vùng nhớ thông qua địa chỉ và toán tử (công thức)
- Đối với mỗi ma trận `a[i][j]` ta có `a[i][j] == *(*(a + i) + j)`
```cpp
#include <iostream>
using namespace std;

int main()
{
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Cách thông thường
    cout << a[1][2] << endl;

    // Cách dùng con trỏ
    cout << *(*(a + 1) + 2) << endl;

    return 0;
}
```

## 