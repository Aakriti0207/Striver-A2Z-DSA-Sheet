//1482. Minimum Number of Days to Make m Bouquets

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 //BRUTE
class Solution {
public:
    bool possibility(vector<int>& bloomDay , int day , int m , int k){
        int n=bloomDay.size();
        int count=0 , bouquets=0;
        for(int i=0 ; i<n ; i++){
            if(bloomDay[i] <= day){
                count++;
            }else{
                bouquets = bouquets + (count / k);
                count = 0;
            }
        }
        bouquets = bouquets + (count / k);
        if(bouquets >= m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        //Find Min and Max
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(bloomDay[i] < mini) mini = bloomDay[i];
        }
        for(int i=0 ; i<n ; i++){
            if(bloomDay[i] > maxi) maxi = bloomDay[i];
        }
        for(int i=mini ; i<=maxi ; i++){
            bool possible = possibility(bloomDay , i , m , k);
            if(possible){
                return i;
            }
        }
        return -1;
    }
};
