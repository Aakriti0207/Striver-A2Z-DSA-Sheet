//Count Subarrays with given XOR

//Very similar to Largest subarray with 0 sum - https://github.com/Aakriti0207/Striver-A2Z-DSA-Sheet/blob/main/Array%20Problems/Medium/Largest%20subarray%20with%200%20sum.cpp

//Just here we use XOR insted of sum and target is k

BRUTE FORCE- 2 loops
//Try every subarray

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int count = 0;
        for(int i=0 ; i<n ; i++){
            int xr = 0;
            for(int j=i ; j<n ; j++){
                xr ^= arr[j];
                if(xr == k){
                    count++;
                }
            }
        }
        return count;
    }
};

//TIME COMPLEXITY => O(n^2)

OPTIMAL APPROACH- Prefix XOR + HashMap

/*
  Suppose: Current prefix XOR: xr
  We want: subarray XOR = K
  Then:  prefixXorBefore = xr ^ K
WHY?
  If A ^ B = C Then A = C ^ B

Maintain: xr and hashmap: xorValue → frequency

Eg- Start: xr = 0 mp = {0:1} count = 0
Take: 4 XOR: xr = 4
Need: 4^6 = 2 Not found (let k=6)
Store: 4
*/

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        int count = 0;
        int xr = 0;
        mpp[0] = 1;
        for(int i=0 ; i<n ; i++){
            xr ^= arr[i];
            int x = xr^k;
            if(mpp.find(x) != mpp.end()){
                count += mpp[x];
            }
            mpp[xr]++;
        }
        return count;
    }
};

//TIME COMPLEXITY => O(n)
//SPACE COMPLEXITY => O(n)
  

  
