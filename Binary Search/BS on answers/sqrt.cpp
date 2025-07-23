//Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

//BRUTE FORCE -> LINEAR SEARCH 
class Solution {
public:
    int mySqrt(int x) {
       int ans = 0;
       for(long long i=1 ; i<=x ; i++){
        if(i*i <= x){
            ans = i;
        }else{
            break;
        }
       } 
       return ans;
    }
};

//OPTIMAL SOLUTION->
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;  //REMEMBER EDGE CASES
        int low = 1 , high = x-1;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(mid*mid <= x){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};

//WE CAN ALSO USE BUILT-IN FUNCTION TO FIND SQRT - TC is same - O(logN)