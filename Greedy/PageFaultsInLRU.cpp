// https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1
// Approach: Maintain a vector frame of size memory
// If ele not found. fault++, if frame full - erase front
// Else add ele back
// TC: O(pages.length())
// SC: O(memory size) for frame

int pageFaults(int N, int C, int pages[])
{
    int pageFault = 0;
    vector<int> frame;
    for (int i = 0; i < N; i++)
    {
        auto it = find(frame.begin(), frame.end(), pages[i]);
        if (it == frame.end())
        {
            pageFault++;
            if (frame.size() == C)
            {
                frame.erase(frame.begin());
            }
            frame.push_back(pages[i]);
        }
        else
        {
            frame.erase(it);
            frame.push_back(pages[i]);
        }
    }
    return pageFault;
}