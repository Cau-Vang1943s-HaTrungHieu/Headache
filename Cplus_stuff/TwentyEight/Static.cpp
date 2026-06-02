/**

Static data members are something that work out of the lifespan of a code block.
A static data member is a class variable that is shared across all objects of that class; in other word, static data only associates with classes
Only one copy exists in memory, regardless of how many objects you create.

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
    User user, user1, user2, user3, user4;
    std::cout << user.get_user_count() << std::endl;
    user.~User(); // Destroy user object
    std::cout << User::get_user_count() << std::endl; // You can do this?

    return 0;
}
