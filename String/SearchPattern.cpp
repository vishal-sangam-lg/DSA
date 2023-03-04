// https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1
// Abdul Bari - https://www.youtube.com/watch?v=qQ8vS2btsxI

vector<int> search(string pat, string txt)
{
    // // Sliding window
    // vector<int> indexes;
    // int i = 0, j = 0;
    // string window = "";
    // while(j < txt.size()){
    //     window += txt[j];
    //     if(j - i + 1 == pat.size()){
    //         if(window == pat){
    //             indexes.push_back(i+1);
    //         }
    //         window = window.substr(1);
    //         i++;
    //     }
    //     j++;
    // }
    // if(indexes.empty()){
    //     indexes = {-1};
    // }
    // return indexes;

    // Rabin-Karp Algorithm
    vector<int> indexes;
    // k is constant -> no. of characters in input
    int k = 256, m = INT_MAX;
    int patLen = pat.length(), txtLen = txt.length();
    int patHash = 0, txtHash = 0, hash = 1;
    // Hash co-efficient of leading digit in window
    // i.e pow(k, patLen-1) % m
    for (int i = 0; i < patLen - 1; i++)
    {
        hash = (hash * k) % m;
    }
    // Hash value of first window and pattern
    for (int i = 0; i < patLen; i++)
    {
        patHash = (k * patHash + pat[i]) % m;
        txtHash = (k * txtHash + txt[i]) % m;
    }
    for (int i = 0; i <= txtLen - patLen; i++)
    {
        if (patHash == txtHash)
        {
            bool match = true;
            for (int j = 0; j < patLen; j++)
            {
                if (txt[i + j] != pat[j])
                    match = false;
            }
            if (match)
                indexes.push_back(i + 1);
        }
        // Calculate the hash value by removing hash value of leading digit
        // Adding hash of next digit in window
        if (i < txtLen - patLen)
        {
            txtHash = (k * (txtHash - txt[i] * hash) + txt[i + patLen]) % m;
            if (txtHash < 0)
                txtHash += m;
        }
    }
    if (indexes.empty())
        indexes.push_back({-1});
    return indexes;
}