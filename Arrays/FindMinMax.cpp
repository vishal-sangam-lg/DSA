// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
// Approach: Traverse LTR and update min, max variables
// TC: O(n)
// SC: O(1)

#include<iostream>
using namespace std;

class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int minNum = A[0];
        int maxNum = A[0];
    	for(int i= 0; i < N; i++) {
    	    if(A[i] > maxNum) {
    	        maxNum = A[i];
    	    }
    	    if(A[i] < minNum) {
    	        minNum = A[i];
    	    }
    	}
    	return maxNum + minNum;
    }

};

int main()
{
	int arr[] = {2, 3, 1, 5};
	Solution ob;
	int ans = ob.findSum(arr, 4);
	cout << ans << endl;
	return 0;
}