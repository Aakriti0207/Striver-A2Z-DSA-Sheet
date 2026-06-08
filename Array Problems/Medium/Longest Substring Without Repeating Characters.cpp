//3. Longest Substring Without Repeating Characters

BRUTE FORCE - 2 loops

class Solution {
public:
//brute
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i=0 ; i<n ; i++){
            unordered_set<char>st;
            for(int j=i ; j<n ; j++){
                if(st.find(s[j]) != st.end()){
                    break;
                }
                st.insert(s[j]);
                maxi = max(maxi , j-i+1);
            }
        }
        return maxi;
    }
};

//TIME COMPLEXITY => O(n^2)
//SPACE COMPLEXITY => O(256)

OPTIMAL - Slinding Window + HashMap

/*
  Maintain window [l...r]
  If character repeats: Shrink from left
  Else: Expand right
*/

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
};

//Time: O(n) Space: O(256)
