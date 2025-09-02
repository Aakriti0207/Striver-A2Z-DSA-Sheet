//Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

//Brute Force Approach- 
  //We use Prefix and Suffix Sum here.
  // we know that for calculating total water contained between rods the main method is- 
      //totalWater = min(leftMax , rightMax) - arr[i];
        //Add all of this in total water and we'll get the final capacity between all rods

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int prefix[n] , suffix[n];
        prefix[0] = height[0];
        for(int i=1 ; i<n ; i++){
            prefix[i] = max(prefix[i-1] , height[i]);
        }
        suffix[n-1] = height[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            suffix[i] = max(suffix[i+1] , height[i]);
        }
        int totalWater = 0;
        for(int i=0 ; i<n ; i++){
            totalWater += min(prefix[i] , suffix[i]) - height[i];
        }
        return totalWater;
    }
}; TC -> O(3N) SC-> O(N) + O(N) // Prefix + Suffix

//Optimal Apprach
  // We'll need to optimise space complexity. 
    //INTUITION-> understanding we do not need both leftmax and rightmax at the same time.
      // If the height of next bar is less than the height of previous bar we can calculate total water by- 
        //totalWater = Left/RightMax - height[left/right]

  class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax = 0 , rightMax = 0;
        int left = 0 , right = n-1;
        int totalWater = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > leftMax){
                    leftMax = height[left];
                }else{
                    totalWater += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }else{
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
}; TC-> O(N) SC-> O(1)
  
  
