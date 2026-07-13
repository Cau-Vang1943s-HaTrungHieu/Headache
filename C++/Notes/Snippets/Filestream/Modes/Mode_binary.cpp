#include <iostream>
#include <fstream>

int main()
{
    // binary
    std::ofstream writing_file("binary.txt", std::ios::binary | std::ios::app);
    writing_file << "Di cho khac viet!";
    /*
        - Khong co thay doi gi tron file output.txt.
        Tuy nhien ve ban chat ios::binary vo hieu hoa tinh nang tu dong
        dich tu \n sang \r\n cua text mode
    */
    
    std::cout << writing_file.tellp() << std::endl;
    
    writing_file.close();
    return 0;
}