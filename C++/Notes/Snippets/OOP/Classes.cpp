/**

    == Concept - theory ==
    - The process of a class forming into multiple instances or objects is called instantiation.
    - When creating a new object from a class, we define it as the class type. Basically, the class is a new type that we created.
    - In C++, a constructor of a class is called whenever an object is defined (or created, whatever!)
        + A constructor is a special method inside a class and possesses the class's name itself.
        + Its job is to create a new user and make sure its state is appropriate.
    - Operator overloading
    - Static members

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
    std::vector<User> users;

    User user1, user2, user3;
    user1. first_name = "Sally";
    user1.last_name = "Swan";

    user2.first_name = "Jake";
    user2.last_name = "Johnson";

    user3.first_name = "Caleb";
    user3.last_name = "Curry";

    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);

    User user;
    user.first_name = "Jacob";
    user.last_name = "Johnson";

    std::cout << add_user_if_not_exist(users, user) << std::endl;
    std::cout << users.size() << std::endl;

    return 0;
}
