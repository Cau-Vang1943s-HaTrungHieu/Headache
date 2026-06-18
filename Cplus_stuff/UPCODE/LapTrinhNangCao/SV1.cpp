#include <iostream>

struct Student
{
    std::string full_name;
    int subject1, subject2, subject3;

    double average()
    {
        return (subject1 + subject2 + subject3) / 3.0;
    }

    friend std::istream& operator >> (std::istream& input, Student& their)
    {
        /*
        std::cin.ignore(); 
        --> if theer are multiple whitespace characters 
        (\n\r or spaces before the name), it only discards 
        the first one unless you tell it to ignore more
        */ 

        getline(input >> std::ws /*use this one for robust whitespace clearing*/, their.full_name);
        input >> their.subject1 >> their.subject2 >> their.subject3;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const Student& their)
    {
        output 
        << their.full_name << " "
        << their.subject1 << " "
        << their.subject2 << " "
        << their.subject3;
        return output;
    }

    bool operator < (Student& other)
    {
        return average() < other.average();
    }
};

struct ListOfStudents
{
    Student indices[99];
    int amount;

    Student& operator [] (int index)
    {
        return indices[index];
    }

    friend std::istream& operator >> (std::istream& input, ListOfStudents& list)
    {
        list.amount = 0;
        while (input >> list.indices[list.amount])
        {
            list.amount++;
        }
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const ListOfStudents& list)
    {
        for (int i = 0; i < list.amount; i++)
        {
            output << list.indices[i];
        }
        return output;
    }

    Student highest_average()
    {
        Student that_one = indices[0];
        for (int i = 0; i < amount; i++)
        {
            if (that_one < indices[i]) 
            {
                that_one = indices[i];
            }
        }
        return that_one;
    }
};

int main()
{
    ListOfStudents list;

    std::cin >> list;
    std::cout << list.highest_average().full_name;

    return 0;
}