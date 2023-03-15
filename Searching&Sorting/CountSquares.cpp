// https://practice.geeksforgeeks.org/problems/count-squares3649/1

int countSquares(int N)
{
    int squareCount = 0;
    for (int i = 1; i * i < N; i++)
    {
        squareCount++;
    }
    return squareCount;
}