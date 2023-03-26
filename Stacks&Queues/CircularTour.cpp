// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
// Approach: Traverse maintain totalFuel, totalDistance, remainingFuel.
// if remainingFuel < 0, make it 0. start = i+1.

int tour(petrolPump p[], int n)
{
    int remainingFuel = 0, totalFuel = 0, totalDistance = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        totalFuel += p[i].petrol;
        totalDistance += p[i].distance;

        remainingFuel += p[i].petrol - p[i].distance;
        if (remainingFuel < 0)
        {
            start = i + 1;
            remainingFuel = 0;
        }
    }
    // If totalFuel < totalDistance, you can't reach no matter where you start
    if (totalFuel < totalDistance)
    {
        return -1;
    }
    return start;
}