/*
Frog standing at zero & there are n stones with same height
Frog can jump i+kth steps till it reaches end
cost of jump = abs(heigh[i] - height[j])

Return min total energy to reach stone n-1
*/

#include<bits/stdc++.h>
using namespace std;

int recur(int curr, int k, vector<int>& stones, vector<int>& dp){
    if(curr == 0) return 0;
    if(dp[curr] == -1) return dp[curr];

    for(int i=0 ; i<k ; i++){

    }
}

int minCost(vector<int>& stones, int k){
    int n = stones.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    for(int i=1 ; i<n ; i++){
        int cost = INT_MAX;
        for(int j=1 ; j<=k ; j++){
            if(i-j >= 0){
                cost = dp[i-j] + abs(stones[i] - stones[i-j]);
            }
            dp[i] = min(dp[i],cost);
        }
    }
    return dp[n-1];
}