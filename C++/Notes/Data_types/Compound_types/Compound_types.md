# Compound types

There are:

1. Reference (A variable's alias, not an object)
2. Pointer (its data is the address of a variable)
3. Array (Object, container)

As far as I know, they call this "dynamic array" though I don't know how it is so.

```cpp
<type>* <type_name> = new <type>[<number of elements>];
// For example
int* parray = new int[10];
```

## Array

An array is actually a pointer holding the address to the first element (0-based index) of that array. The rest of the elements in turn are separated by a specific amount of byte depending on the array data type (e.g. int is 4 bytes, long long is 8 bytes).

```cpp
int a[5];
cout << a << std::endl;
for (int i = 0; i < 5; i++)
{
    cout << &a[i] << " ";
}
```