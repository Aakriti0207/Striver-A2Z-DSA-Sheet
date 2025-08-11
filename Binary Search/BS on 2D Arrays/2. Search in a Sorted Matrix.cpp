//Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

//Brute Force Solution - Linear Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
}; TC-> O(n*m)

//BETTER APPROACH- BINARY SEARCH ON ALL ROWS
    //Since we cannot reduce tc on column traversal we should reduce TC on Row Traversal

class Solution {
public:
    bool BinarySearch(vector<int>& nums , int target){            //BINARY SEARCH CODE ON SPECIFIC ROW WHICH CONSISTS OF THE ELEMENT
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size() , m=matrix[0].size();
        for(int i=0 ; i<n ; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]){  //MISTAKE-> EQUAL TO, Finding the row which contains the element
                return BinarySearch(matrix[i] , target);
            }
        }
        return false;
    }
}; TC-> O(n * log m)


//OPTIMAL APPROACH- 
    //HERE we try to conside the matrix as a 1D array
    //We do NOT actually do that since it will take O(n*m) time and it will not be optimal then- we only assume the matrix to be 1D
    // with observation we can conclude that row = i/m and col = i%m

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size() , m=matrix[0].size();
        int low = 0 , high = n*m - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = mid/m , col = mid%m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
}; TC-> O(log(N*M))
