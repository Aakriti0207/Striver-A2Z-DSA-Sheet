//Find the repeating and missing numbers

//BRUTE FORCE-
// Iterate through the array and calculate the frequency of each element if freq is greater than 2 - repeated if 0 - missing
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeated = -1, missing = -1;
        for(int i=1 ; i<=n ; i++){
            int count = 0;
            for(int j=0 ; j<n ; j++){
                if(arr[j] == i) count++;
            }
            if(count == 0) missing = i;
            else if(count == 2) repeated = i;
            if(repeated != -1 && missing != -1) break;
        }
        return {repeated, missing};
        
    }
};
//TIME COMPLEXITY -> O(n^2)

//BETTER APPROACH-
//Using frequency vectors
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1,0);
        for(int num : arr){
            freq[num]++;
        }
        int repeating = -1 , missing = -1;
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                repeating = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
            if (repeating != -1 && missing != -1) break;
        }
        return {repeating, missing};
    } 
};
//Time Complexity: O(2*N)
//Space Complexity: O(N)


//OPTIMAL APPROACH-
//XOR everything-
//Take XOR of all array elements AND all numbers from 1 to n
//Because: a ^ a = 0 everything cancels except: missing ^ repeating
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        int n = arr.size();

        long long xr = 0;

        // XOR all elements and 1 to n
        for(int i = 0; i < n; i++) {

            xr ^= arr[i];
            xr ^= (i + 1);
        }

        // Rightmost set bit
        long long bitNo = xr & (-xr);
        long long zero = 0;
        long long one = 0;

        // Divide array elements
        for(int i = 0; i < n; i++) {

            if(arr[i] & bitNo)
                one ^= arr[i];
            else
                zero ^= arr[i];
        }

        // Divide numbers 1 to n
        for(int i = 1; i <= n; i++) {

            if(i & bitNo)
                one ^= i;
            else
                zero ^= i;
        }

        // Check which repeats
        int count = 0;

        for(int num : arr) {

            if(num == one)
                count++;
        }

        if(count == 2) {

            return {(int)one,
                    (int)zero};
        }

        return {(int)zero,
                (int)one};
    }
};
