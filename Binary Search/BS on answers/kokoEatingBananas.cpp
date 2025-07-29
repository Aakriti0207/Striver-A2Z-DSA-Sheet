//875. Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 //UNDERSTANDING THE PROBLEM->
  //Watch the dry run done by striver in his video

//Brute Force->
class Solution {
public:
    int maxElement(vector<int>& piles){
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(piles[i] > maxi){
                maxi=piles[i];
            }
        }
        return maxi;
    }
    int totalHours(vector<int>& piles , int hourly){
        int n=piles.size();
        int totalHours=0;
        for(int i=0 ; i<n ; i++){
            totalHours += ceil((double) (piles[i]) / (double) (hourly) );  // We use double because if we wouldn't the division would provide an interger always which will fail the purpose of ceil
        }                                                                    //Eg-> 9/2=4.5, division will return integer i.e. 4 X right answer should be 5
                                                                               // (Double) 9/2=4.5 => ceil(4.5) = 5 
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //This will require 2 more functions- to find max and to find the totalTime
        int maxi = maxElement(piles);
        for(int i=1 ; i<maxi ; i++){            //Mistake-> i should start from 1
            int totalTime = totalHours(piles , i);
            if(totalTime <= h) return i;
        }
        return maxi;
    }
};

TC-> O(max(piles) * N) //max(piles) from main function where we calculate minElement and N for finding max element

//OPTIMAL CODE 
  int minEatingSpeed(vector<int>& piles, int h) {
        //This will require 2 more functions- to find max and to find the totalTime
        int low = 1 , high = maxElement(piles); //MISTAKE -> 
        while(low <= high){
            int mid = low + (high-low)/2;
            int totalH = totalHours(piles , mid);
            if(totalH <= h){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};//ONLY change the main function above 2 max and totalHours will remain the same

USE long long in above 2 functions to avoid OVERFLOW 
