#include <iostream>
using namespace std;

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // For element in matrix, check with itself
    cout << "\nFor element in matrix, check with itself\n"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "i: " << i << "   j: " << j << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    // For element in matrix, check with all elements in its row
    cout << "\nFor element in matrix, check with all elements in its row\n"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "i: " << i << "   j: " << j << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << mat[i][k] << " ";
            }
            cout << endl;
        }
    }
    // For element in matrix, check with all elements in its column
    cout << "\nFor element in matrix, check with all elements in its column\n"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "i: " << i << "   j: " << j << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << mat[k][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}