// https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1
// Approach: 
// If product*arr[index-1] <= k -> Try both include and exclude
// Else only exclude

int solve(int arr[], int k, int index, int product) {
    if(index == 0) {
        if(product <= k) {
            return 1;
        } else {
            return 0;
        }
    }
    
    // If product*arr[index-1] <= k -> Try both include and exclude
    // Else only exclude
    if(product * arr[index-1] <= k) {
        return solve(arr, k, index-1, product*arr[index-1]) + solve(arr, k, index-1, product);
    } else {
        return solve(arr, k, index-1, product);
    }
}

int solveMem(int arr[], int k, int index, int product, vector<vector<int>> &dp) {
    if(index == 0) {
        if(product <= k) {
            return 1;
        } else {
            return 0;
        }
    }
    if(dp[index][product] != -1) {
        return dp[index][product];
    }
    
    // If product*arr[index-1] <= k -> Try both include and exclude
    // Else only exclude
    if(product * arr[index-1] <= k) {
        return dp[index][product] = solveMem(arr, k, index-1, product*arr[index-1], dp) + solveMem(arr, k, index-1, product, dp);
    } else {
        return dp[index][product] = solveMem(arr, k, index-1, product, dp);
    }
}

int solveTab(int arr[], int k, int n) {
    vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
    for(int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }
    for(int index = 1; index <= n; index++) {
        for(int product = k; product >= 0; product--) {
            if(product * arr[index-1] <= k) {
                dp[index][product] = dp[index-1][product*arr[index-1]] + dp[index-1][product];
            } else {
                dp[index][product] = dp[index-1][product];
            }
        }
    }
    return dp[n][1];
}

int solveSO(int arr[], int k, int n) {
    vector<int> prev(k+1, 0);
    vector<int> curr(k+1, 0);
    
    for(int i = 0; i <= k; i++) {
        prev[i] = 1;
    }
    for(int index = 1; index <= n; index++) {
        for(int product = k; product >= 0; product--) {
            if(product * arr[index-1] <= k) {
                curr[product] = prev[product*arr[index-1]] + prev[product];
            } else {
                curr[product] = prev[product];
            }
        }
        prev = curr;
    }
    return prev[1];
}

int numOfSubsets(int arr[], int N, int K) {
    // -1 to remove empty set
    // vector<vector<int>> dp(N+1, vector<int> (K+1, -1));
    // return solve(arr, K, N, 1) - 1;
    // return solveMem(arr, K, N, 1, dp) - 1;
    // return solveTab(arr, K, N) - 1;
    return solveSO(arr, K, N) - 1;
}
