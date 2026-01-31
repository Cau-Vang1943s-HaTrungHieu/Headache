/*

    Fun math problem generator for kids

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;



int main()
{
    srand(time(0));

    do {
        int right_answer = 0;
        int answer = 0;
        int questions = rand() % 11;
        
        cout << "There are " << questions << " questions to solve." << endl;
        
        for (int i = 0; i < questions; ++i) {
            int bOperand = rand() % 101;
            int aOperand = rand() % 101;
            char operators[] = {'+', '-', '*', '/'};
            char operat0r = operators[rand() % 4];

            if (aOperand < bOperand) swap(aOperand, bOperand);

            cout << aOperand << " " <<  operat0r << " " << bOperand << " = ";
            cin >> answer;

            int correctAnswer;
            switch (operat0r) {
                case '+': correctAnswer = aOperand + bOperand; break;
                case '-': correctAnswer = aOperand - bOperand; break;
                case '*': correctAnswer = aOperand * bOperand; break;
                case '/': 
                    if (bOperand != 0) correctAnswer = aOperand / bOperand;
                    else correctAnswer = 0;
                    break;
            }
            
            if (answer == correctAnswer) {
                cout << "Correct!";
                right_answer++;
            } else {
                cout << "Incorrect!";
            }
            cout << endl;
        }

        if (right_answer == questions) {
            cout << "Congrat! You are 100% correct!";

            char choice;
            cout << " Do you want to try again? (Y/N): ";
            cin >> choice;
            if (tolower(choice) == 'n') {
                cout << "See you again soon!";
                break;
            }
        } else {
            cout << "Not quite, let's try again!";
        } 
        cout << endl;
    } while (true);

    return 0;
}