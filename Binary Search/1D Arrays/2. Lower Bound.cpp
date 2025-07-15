//Implement Lower Bound
//Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. 
//The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.
//Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

//BRUTE FORCE
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n=arr.size();
        int ans;
        for(int i=0 ; i<n ; i++){
            if(arr[i] >= target){
                ans = i;
                break;
            }else{
                ans=i+1;
            }
        }
        return ans;
        
    }
}; // TC-> O(n)

//OPTIMAL APPROACH- Binary Search
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0 , high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(arr[mid] >= target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
}; //TC-> O(logn)
