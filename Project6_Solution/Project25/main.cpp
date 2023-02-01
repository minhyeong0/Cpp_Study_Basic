#include <iostream>

using namespace std;


int main()
{
    const int row = 3;
    const int col = 5;

    const int s2da[row][col] =
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
    };

    //int* r1 = new int[col] {1, 2, 3, 4, 5};
    //int* r2 = new int[col] {6, 7, 8, 9, 10};
    //int* r3 = new int[col] {11, 12, 13, 14, 15};

    //int* 배열 만들기
    //int** rows = new int* [row]{r1, r2, r3};

    //for (int r = 0; r < row; ++r)
    //{
    //    for (int c = 0; c < col; ++c)
    //        cout << rows[r][c] << " ";
    //    cout << endl;
    //}

    int** matrix = new int* [row];

    for (int r = 0; r < row; ++r)
        matrix[r] = new int[col];

    for (int r = 0; r < row; ++r)
        for (int c = 0; c < col; ++c)
            matrix[r][c] = s2da[r][c];

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)      
            cout << matrix[r][c] << " ";
        cout << endl;
    }
    
    //delete[] r1, r2, r3;
    //delete[] rows;

    for (int r = 0; r < row; ++r)
        delete[] matrix[r];
    delete[] matrix;

    return 0;
}