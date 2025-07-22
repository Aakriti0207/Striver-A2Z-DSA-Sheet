//Find Kth Rotation

Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

OBSERVATIONS->
  1. The number of rotations in an array is equal to the index of its **minumum element**

//BRUTE FORCE -> LINEAR SEARCH O(n) tc. 
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] < arr[ans]){
                ans = i;
            }
        }
        return ans;
        
    }
};

//OPTIMAL SOLUTION -> BINARY SEARCH O(logN) TC

// Just like find min but we need to return index here..
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int low = 0 , high=n-1;
        int index , mini = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            //MOST OPTIMAL -> IF SEARCH SPACE IS ALREADY SORTED
            if(arr[low] <= arr[high]){
                if(arr[low] < mini){
                    index = low;
                    mini = arr[low];
                }
                break;
            }
            //IF LEFT HALF IS SORTED
            if(arr[low] <= arr[mid]){
                if(arr[low] < mini){
                    mini = arr[low];
                    index = low;
                }
                
                low = mid+1;   //ELIMINATE LEFT SEARCH SPACE
                
            }else{ //RIGHT HALF SORTED
                if(arr[mid] < mini){
                    mini = arr[mid];
                    index = mid;
                }
                
                high = mid-1; //ELIMINATING RIGHT SEARCH SPACE
            }
        }
        
        return index;
        
    }
};
