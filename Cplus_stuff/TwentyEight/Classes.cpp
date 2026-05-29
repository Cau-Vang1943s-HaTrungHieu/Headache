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

 int main()
 {
    User me;
    std::cout << me.get_id() << std::endl;

    return 0;
 }
