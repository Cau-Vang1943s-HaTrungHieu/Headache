/**

Constructor is a method that is implicitly executed during instance instantiation
We can instantiate our objects in different way by creating more Constructors with parameters.
Destructor is called when an object is destroyed, this process happened automatically when the program ends

**/

#include <iostream>
#include <vector>

class User
{
    std::string id = "123";
public:
    std::string first_name;
    std::string last_name;
    std::string age;
    std::string get_id()
    {

        return id;
    }

    User() // Default constructor has no parameters
    {
        std::cout << "Constructor\n";
    }

    User(std::string first_name, std::string last_name, std::string id /*You can also instantiate with private attributes*/) // Custom Constructor
    {
        // You can pass the parameters that are exactly the same as the attributes, so here is the solution.
        this->first_name = first_name;
        this->last_name = last_name;
        this->id = id;
    }

    ~User() // Destructor is called automatically
    {
        std::cout << "Object destroyed\n" << std::endl;
    }
};

int add_user_if_not_exist(std::vector<User>& users, User user)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].first_name == user.first_name and
            users[i].last_name == user.last_name)
        {
            return i;
        }
    }
    users.push_back(user);
    return users.size() - 1;
}

int main()
{
    User user("John", "Doe", "000");
    std::cout << user.first_name << std::endl;
    std::cout << user.get_id() << std::endl;

    // For Destructor implement in main please see the "Static.cpp" file

    return 0;
}
