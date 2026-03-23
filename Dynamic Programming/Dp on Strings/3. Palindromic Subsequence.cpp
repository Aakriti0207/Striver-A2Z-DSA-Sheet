//Here we are given just one string and we need to find the length of longest PALINDROMIC subsequence

/* 
Trick- Use the original string as S1 and reverse it to use it as S2, now this is a simple longest subsequence problem
WHY?
because a palindrome reads forward and backward, thus, it must be the common subsequence of both strings
*/

class Solution {
private:
    int memoi(int i, int j, string& s1, string& s2, vector<vector<int>>&dp, int& ans){
        if(i==0 || j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int curr = 0;
        
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + memoi(i-1,j-1,s1,s2,dp,ans);
        }else{
            return dp[i][j] = max(memoi(i-1,j,s1,s2,dp,ans), memoi(i,j-1,s1,s2,dp,ans));
        }
        return dp[i][j];
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        int ans = 0;
        //memoi(i,j,s1,s2,dp,ans)
        return memoi(n,n,s,s1,dp,ans);
    }
};

//Tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string orig = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(orig[i-1] == s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

//Space Optimisation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());//reversed the copy rather than original
        vector<int> prev(n+1,0);
        vector<int> curr(n+1);
        
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};

