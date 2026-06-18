/**

You define an overloading operator function so that the function can access private data members of a class.
Despite the fact that the friend function is in the class/struct, it is not a part of them
    > So when you want to call it out, you just type out the name of the function in the main block

**/

#include <iostream>
#include <vector>

class User
{
    std::string id = "123";
    static int user_count;

public:
    std::string first_name;
    std::string last_name;
    std::string age;

    static int get_user_count() // this method is declared static, so it doesn't depend on any particular object, you can call it with your class name inside main block
    {
        return user_count;
    }

    std::string get_id()
    {
        return id;
    }

    void set_id(std::string new_id)
    {
        for (char c : new_id)
        {
            if (!isdigit(c))
            {
                std::cerr << "Invalid ID: must contain only digits\n";
                return;
            }
        }

        // Check if the id is greater than zero using stoi (string to integer)
        if (std::stoi(new_id) <= 0)
        {
            std::cerr << "Invalid ID: must be greater than zero\n";
            return;
        }
        this->id = new_id;
    }

    User() // Default constructor has no parameters
    {
        user_count++;
        std::cout << "Object instantiated\n";
    }

    User(std::string first_name, std::string last_name, std::string id /*You can also instantiate with private attributes*/) // Custom Constructor
    {
        // You can pass the parameters that are exactly the same as the attributes, so here is the solution.
        this->first_name = first_name;
        this->last_name = last_name;
        this->id = id;

        user_count++;
    }

    ~User() // Destructor is called automatically
    {
        std::cout << "Object destroyed\n";
        user_count--;
    }

    friend std::istream& operator >> (std::istream& input, User& user)
    {
        input >> user.first_name >> user.last_name >> user.id;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const User& user)
    {
        output
        << "First name: " << user.first_name
        << "\nLast name: " << user.last_name
        << "\nID: " << user.id;
        return output;
    }
    /*
    You might want to pass "user" by reference instead in order to avoid
    making further copies of user. This will result in the program destroying
    the same objects multiple time although you only declare and instantiate
    only one object in your main block.
    */
};

int User::user_count = 0; // YOU HAVE TO DEFINE A STATIC DATA MEMBER "OUT OF LINE" outside of the class.

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
    User user;

    std::cin >> user;
    std::cout << user << std::endl;

    return 0;
}
