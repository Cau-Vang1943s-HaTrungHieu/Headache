/**

Or abstraction, all of the unnecessary things are hidden to the public so that they can only care about controlling or using it.
Can be achieved through access modifiers or getter, setter

Briefly on how getter and setter works:
- Getter gets the private data value and present them properly.
- Setter sets the data to an appropriate value (often through if statement)

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
        std::cout << "Object instantiated\n";
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
    std::cout << "Old ID: " << user.get_id() << std::endl;

    std::string id;
    std::cout << "Please input your id: ";
    std::cin >> id;
    user.set_id(id);
    std::cout << "New ID: " << user.get_id() << std::endl;

    return 0;
}
