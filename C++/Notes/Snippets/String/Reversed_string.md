

```cpp
int reversed_value(std::string& text)
{
    std::string reversed = text;
    std::reverse(reversed.begin(), reversed.end());
    return stoi(reversed);
    /*
        reverse(begin_iterator, end_iterator); // this function belongs to <algorithm> library
        - begin_iterator: the starting position of the range
        - end_iterator: the position just past the last element of the range.
        - Works on containers (array, vector, string)

        stoi --> string to integer
        stoll --> string to long long
        ...
		
		text.begin(), text.end() are two iterators
		Chars:	1	2	3
		Iterators:
		text.begin() points to 1
		text.end() points PAST 3
		
		An iterator in C++ is an object that acts like a pointer which is used to traverse through containers (arrays, vectors, strings, lists, etc.)
    */
}
```