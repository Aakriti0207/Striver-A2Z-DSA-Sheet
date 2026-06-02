//121. Best Time to Buy and Sell Stock

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

//BRUTE FORCE-
we can simply use 2 loops-
//CODE-
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit;
        int maxi = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(prices[j] > prices[i]){
                    profit = prices[j] - prices[i];
                    maxi = max(maxi,profit);
                }
            }
        }
        return maxi;
    }
};
//TIME COMPLEXITY -> O(n^2) => not optimal

//OPTIMAL APPROACH-
solve in one pass
//CODE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_price = INT_MAX;
        int maxPro = 0;
        for(int i=0 ; i<n ; i++){
            min_price = min(min_price , prices[i]);
            maxPro = max(maxPro , prices[i]-min_price);
        }
        return maxPro;
    }
};
