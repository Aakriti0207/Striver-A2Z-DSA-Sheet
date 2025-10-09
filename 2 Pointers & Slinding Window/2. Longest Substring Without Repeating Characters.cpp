Given a string s, find the length of the longest substring without duplicate characters.

// Brute Force
  find out all substrings using loops - i & j
  eliminate repeating characters using hashmaps
//Code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0 , maxLen = 0;
        for(int i=0 ; i<n ; i++){
            int hash[256] = {0};
            for(int j=i ; j<n ; j++){
                if(hash[s[j]] == 1) break;
                len = j-i+1;
                hash[s[j]] = 1;
                maxLen = max(maxLen , len);
            }
        }
        return maxLen;
    }
}; TC -> O(n^2) SC -> O(256)

//Optimal Solution
  whenever you see substring- use 2 pointers/sliding window
create a map with (char,index) 
initialise left = right = 0
  check if char already exists in map- 
    -> if yes, update the index in map , update left to (repeating char+1)
    -> if no, update length & add char in map with its index

//Code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0 , right=0;
        vector<int> mpp(256 , -1);
        int len = 0 , maxlen = 0;
        while(right<n){
            if(mpp[s[right]] != -1){
                left = max(left , mpp[s[right]] + 1);
            }
            mpp[s[right]] = right;
            len = right-left+1;
            maxlen = max(maxlen , len);
            right++;
        }
        return maxlen;
    }
}; TC -> O(n) // We don't consider iterating of map because it just an array and all operations in array are O(1)
  SC -> O(256)
