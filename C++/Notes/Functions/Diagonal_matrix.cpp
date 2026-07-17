#include <iostream>

const int MAX = 200;

int main()
{
    int rows, cols;
    do std::cin >> rows >> cols; 
    while (rows != cols);

    int matrix[MAX][MAX];

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            std::cin >> matrix[r][c];
        }
    }

    std::cout << "Diagonal elements: ";
    for (int i = 0; i < rows; i++)
    {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;

    return 0;
}