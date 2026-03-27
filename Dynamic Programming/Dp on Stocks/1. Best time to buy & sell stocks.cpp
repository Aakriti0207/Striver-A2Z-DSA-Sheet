//121. Best Time to Buy and Sell Stock

/*
We need max profit with only ONE transaction
buy once sell once- buy at lowest, sell ar highest
*/

//Brute force Approach- 2 pointers
class Solution {
public:
    //Brute Force
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


//Optimal Approach-
//Keep track of minimum element and the corresponding maxProfit in just one loop
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