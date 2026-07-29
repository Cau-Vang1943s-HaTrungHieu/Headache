# Linked List

## Size of a linked list

```cpp
int size()
{
    int result = 0;
    Node* current = head;

    while (current != nullptr)
    {
        result += 1;
        current = current->next;
    }
    return result;
}
```
