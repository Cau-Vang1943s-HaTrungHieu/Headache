#include <iostream>

class User
{
public:
    std::string first_name;
    std::string last_name;
    int age;
};

std::ostream& operator << (std::ostream& output, const User& user)
{
    output
    << "First name: " << user.first_name
    << "\nLast name: " << user.last_name
    << "\nAge: " << user.age;
    return output;
}

std::istream& operator >> (std::istream& input, User& user)
{
    input
    >> user.first_name
    >> user.last_name
    >> user.age;
    return input;
}

int main()
{
    User user1;
    std::cin >> user1;
    std::cout << std::endl;
    std::cout << user1;

    return 0;
}
