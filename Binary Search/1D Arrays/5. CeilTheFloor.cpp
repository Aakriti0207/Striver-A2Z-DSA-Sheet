//Ceil The Floor

//Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

//Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
//Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

//Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.


//Brute Force 
class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int n=arr.size();
        vector<int>ans;
        int floor=-1, ceil=-1;
        for(int i=0 ; i<n ; i++){
            if(arr[i] >= x){
                if(ceil == -1 || i < ceil) ceil = arr[i];
            }
            if(arr[i] <= x){
                if(floor == -1 || i > floor) floor = arr[i];
            }
        }
        ans.push_back(floor);
        ans.push_back(ceil);
        return ans;
    }
}; // TC-> O(n)

//OPTIMAL APPROACH -> Binary Search
// We cannot write the code of Floor and Ceil together atonce using binary search- If you want to find both in a single code you'll need O(n) TC.

//Floor
class Solution {
  public:
    vector<int> getFloor(int x, vector<int> &arr) {
        int n=arr.size();
        int low=0 , high=n-1 , ans=-1;
        while(low<=high){
          int mid= low + (high-low)/2;
          if(arr[mid] <= x){
            ans=mid;
            low=mid+1;
          }else{
            high=mid-1;
          }
        }
      return ans;
    }
};

//Ceil
class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int n=arr.size();
        int low=0 , high=n-1 , ans=-1;
        while(low<=high){
          int mid = low + (high-low)/2;
          if(arr[mid] >= x){
            ans=mid;
            high=mid-1;
          }else{
            low=mid+1;
          }
        }
      return ans;
    }
};




