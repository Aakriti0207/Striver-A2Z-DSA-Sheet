//122. Best Time to Buy and Sell Stock II

/*
Here we can, 
buy and sell MULTIPLE TIMES 
just we cannot buy more than 1 stock simultaneously you'll have to sell it first before buying another
*/

//Greedy Approach
class Solution {
public:
//Greedy Approach
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i=1 ; i<n ; i++){
            if(prices[i] > prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};

//DP 

/*
state - dp[i][buy] -> i is the index & buy is the boolean value - 0 or 1
0 -> can sell , 1 -> can buy
Recursion formula 
For buy = 1 & buy = 0
*/

//Memoization
class Solution {
private:
    int memoi(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy == 1){
            int take = -prices[i] + memoi(i+1, 0, prices, dp);
            int notTake = memoi(i+1, 1, prices, dp);
            profit = max(take,notTake);
        }else{
            int sell = prices[i] + memoi(i+1, 1, prices, dp);
            int notSell = memoi(i+1, 0, prices, dp);
            profit = max(sell,notSell);
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return memoi(0,1,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1 ; i>=0 ; i--){
            for(int buy=0 ; buy<2 ; buy++){
                int profit = 0;
                if(buy == 1){
                    int take = -prices[i] + dp[i+1][0];
                    int skip = dp[i+1][1];
                    profit = max(take,skip);
                }else{
                    int sell = prices[i] + dp[i+1][1];
                    int skip = dp[i+1][0];
                    profit = max(sell,skip);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//Space Optimisation
class Solution {
public:
    //Space Optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);
        for(int i=n-1 ; i>=0 ; i--){
            int take = -prices[i] + ahead[0];
            curr[1] = max(take, ahead[1]);
            int sell = prices[i] + ahead[1];
            curr[0] = max(sell, ahead[0]);
            ahead = curr;
        }
        return ahead[1];
    }
};
