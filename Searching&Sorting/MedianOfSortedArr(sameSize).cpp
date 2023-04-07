// https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1
// Striver - https://www.youtube.com/watch?v=NTop3VTjmxk
// Read the solution of median of different size. It is just a slight modification

int findMidSum(int arr1[], int arr2[], int n)
{
    // // O(nlogn) - Merging O(n) and sorting O(nlogn)
    // int i = n-1;
    // int j = 0;
    // while(i >= 0 && j < n && arr1[i] > arr2[j]){
    //     swap(arr1[i--],arr2[j++]);
    // }
    // sort(arr1, arr1+n);
    // sort(arr2, arr2+n);
    // return arr1[n-1] + arr2[0];

    // // TC: O(n) SC: O(n) -> Merging with extra space
    // vector<int> ans;
    // int i = 0;
    // int j = 0;
    // while(i < n && j < n) {
    //     if(arr1[i] <= arr2[j]) {
    //       ans.push_back(arr1[i++]);
    //     } else {
    //       ans.push_back(arr2[j++]);
    //     }
    // }
    // while(i < n) {
    //   ans.push_back(arr1[i++]);
    // }
    // while(j < n) {
    //   ans.push_back(arr2[j++]);
    // }
    // int idx = (n+n) / 2;
    // return (ans[idx] + ans[idx-1]);

    // // TC: O(n) SC: O(1) -> Merging with count
    // int count = 0, sum = 0;
    // int i = 0, j = 0;
    // int idx = (n+n) / 2;

    // while(i < n && j < n) {
    //     if(arr1[i] <= arr2[j]) {
    //       count++;
    //       if(count == idx) sum += arr1[i];
    //       if(count == idx+1) {sum += arr1[i]; break;}
    //       i++;
    //     } else {
    //       count++;
    //       if(count == idx) sum += arr2[j];
    //       if(count == idx+1) {sum += arr2[j]; break;}
    //       j++;
    //     }
    // }
    // while(i < n && count <= idx+1) {
    //     count++;
    //     if(count == idx) sum += arr1[i];
    //     if(count == idx+1) {sum += arr1[i]; break;}
    //     i++;
    // }
    // while(j < n && count <= idx+1) {
    //     count++;
    //     if(count == idx) sum += arr2[j];
    //     if(count == idx+1) {sum += arr2[j]; break;}
    //     j++;
    // }
    // return sum;

    // TC: O(logn) SC: O(1) -> Binary search
    int low = 0, high = n;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = (n + n + 1) / 2 - mid1;
        int left1 = mid1 == 0 ? INT_MIN : arr1[mid1 - 1];
        int left2 = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];
        int right1 = mid1 == n ? INT_MAX : arr1[mid1];
        int right2 = mid2 == n ? INT_MAX : arr2[mid2];
        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2) + min(right1, right2);
        }
        if (left1 > right2)
        {
            high = mid1 - 1;
        }
        if (left2 > right1)
        {
            low = mid1 + 1;
        }
    }
    return -1;