 /**
    == Concept, theory ==:
    - Structs and classes are the same things.
    - People tend to use structs for smaller applications and classes for larger ones.
    - Access modifiers (Both struct and class)
        + public: data, methods can be accessed by its objects anywhere in the program
        + private: data, methods can only be accessed via class or struct's boundary
        + protected: like private except its data, methods can be passed down through inheritance.

        Note:
        + access modifier of a class is private by default
        + access modifier of a struct is public by default.
 **/

 #include <iostream>

 struct User
 {
    std::string first_name;
    std::string last_name;
    std::string age;
    std::string get_id()
    {

        return id;
    }
private:
    std::string id = "123";
 };

 int main()
 {
    std::cout << "Hello World!" << std::endl;

    return 0;
 }


