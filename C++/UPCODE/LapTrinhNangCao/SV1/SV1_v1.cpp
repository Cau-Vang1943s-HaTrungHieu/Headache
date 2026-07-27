#include <iostream>

struct Student
{
    std::string fullname;
    int subject[3];

    double average()
    {
        return (subject[0] + subject[1] + subject[2]) / 3.0;
    }

    friend std::istream& operator>> (std::istream& input, Student& their)
    {
        std::getline(input >> std::ws, their.fullname);
        input
        >> their.subject[0] 
        >> their.subject[1]
        >> their.subject[2];
        return input;
    }

    bool operator < (Student other)
    {
        return average() < other.average();
    }
};

int main()
{
    Student students[100];
    int amount = 0;
    while (std::cin >> students[amount])
    {
        std::cin.ignore();
        amount++;
    }

    Student max_avg = students[0];
    for (int i = 1; i < amount; i++)
    {
        if (max_avg < students[i]) max_avg = students[i];
    }

    std::cout << max_avg.fullname << std::endl;

    return 0;
}