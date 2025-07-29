//Find nth root of m

//You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.


class Solution {
  public:
  
    int func(int mid , int n , int m){
        long long ans=1;
        for(int i=1 ; i<=n ; i++){      //Mistake-> Should be <=
            ans = ans*mid;
            if(ans > m){
                return 2;       // As soon as the multiplication gets past m return
            }
        }
        if(ans == m) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        int low = 1 , high = m;
        while(low <= high){
            int mid = (high+low)/2;
            int midN = func(mid , n , m);
            if(midN == 1) return mid;
            else if(midN == 2) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};


TC-> Binary Search take O(log m)
     The function func() takes O(n) 
so, O(n * logm)

//THIS CAN BE FURTHER OPTIMISED BY EXPONENTIAL METHOD BUT I HAVE NOT STUDIED THAT YET
