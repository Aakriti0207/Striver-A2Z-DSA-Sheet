//Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


//Brute 

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0 ; i<n ; i++){
            if(weights[i] > maxi) maxi = weights[i];
            sum +=weights[i];
        }
        //Got the range - min- max element , max - sum of weights

        for(int i=maxi ; i<=sum ; i++){
            int sumW = 0;
            int day = 1;    //We start from Day 1
            for(int w=0 ; w<n ; w++){
                if(sumW + weights[w] <= i){
                    sumW += weights[w];
                }
                else{
                    day++;
                    sumW = weights[w];
                }
            }
            if(day <= days){
                return i;
            }
        }
        return -1;
    }
}; TC-> O(N * sum-maxi+1)
