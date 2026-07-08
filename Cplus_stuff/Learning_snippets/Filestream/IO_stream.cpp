/*

I/O stream

- When you type something into a program, it will take what you
type an input and output something that has been processed
from your input into the console. Such concept can be illustrated
like so:

    Keyboard --> Program --> Console

- However, it turns out there is a process that handles your
input before it goes into the program. It is called the Buffer

    Keyboard --> Buffer --> Program --> Console

Buffer

- Each output stream manages a buffer, which temporarily stores data 
waiting to be written to its destination (console, file, network, 
string, etc.).
- Buffers improve performance by reducing the number of expensive I/O 
operations. Instead of writing every character immediately, the 
stream accumulates data in memory and writes it in larger chunks.
- Flushing the buffer means to force the buffered data to be written
to its destination immediately. After that, the buffer is emptied.
- For the input buffer, data input from a keyboard is sent to a
buffer AS YOU TYPE. When an input operation such as std::cin >> x 
is performed, the stream reads characters from that buffer and 
convert it to the requested data type and stores it in the 
destination variable. This process is called "Formatted input" and
that's why we have printf(), scanf() --> print formatted, scan 
formatted.
- For an output buffer, data written by an output stream 
(e.g., std::cout or std::ofstream) is first stored in a buffer. 
Instead of immediately writing every piece of data to its 
destination, the stream accumulates the data in the buffer. The 
buffered data is then written to the destination when the buffer is 
flushed, becomes full, or the stream is closed.

A Buffer can be clear or flushed by different MANIPULATORS:
- endl; go to a new line after writing something, then flushes the buffer
- flush; just flushes the buffer
- ends; inserts a null character ('\0') into the stream and then 
flushes the stream.
- unibuf; this manipulator tells the buffer to flush every subsequent write.
- nounitbuf; this deactivates unitbuf


- The previous illustrations are the I/O stream.
- We can work with this stream via classes, such as istream, 
istream, ostream, ofstream, ifstream
- Notice that the objects of istream and ostream are respectively
std::cin and std::cout that you've already got used to.
- Since we're working with file stream, ifstream and ofstream are
what you are looking for.
- And because these classes don't have their default objects like
i/ostream, you need to declare an object for each of them.
EX:
    ifstream read("path");
    ofstream write("path");


ifstream enforces std::ios::in
ofstream enforces std::ios::out
fstream is flexibly but requires you to explicitly pass either modes
or both.
*/

/*
Abbreviation:
    - seekg(); 
        --> seekg(pos); Moves the get pointer (read position) to that exact
        byte offset in the line
        --> seekg(offset, dir); Moves the get pointer away from a 
        particular position.
            offset: a relative position
            dir: a direction
                std::ios::beg
                std::ios::cur
                std::ios::end
    - tellg(); Tells where the get pointer is
*/

#include <iostream>

int main()
{
    std::cout << "hello world" << std::ends;
    std::cout << "hi" << std::endl;
    std::cout << "hello world" << std::flush;
    std::cout << "hello word" << std::unitbuf;
    std::cout << "hello";

    return 0;
}