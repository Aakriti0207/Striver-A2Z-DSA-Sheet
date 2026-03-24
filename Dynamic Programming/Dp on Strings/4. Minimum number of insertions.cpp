//1312. Minimum Insertion Steps to Make a String Palindrome

//The idea remains the same as palindromic subsequence
//Find the longest palindromic subsequence & subtract its length by total string length -> that will be the length of characters NEEDED to make the entire string palindrome

//CODE-

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (n-dp[n][n]);
    }
};

//Memoization
class Solution {
private:
    int memoi(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + memoi(i-1,j-1,s1,s2,dp);
        }else{
            return dp[i][j] = max(memoi(i-1,j,s1,s2,dp),memoi(i,j-1,s1,s2,dp));
        }
        return dp[i][j];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        int ans = 0;
        //memoi(i,j,s1,s2,dp,ans)
        int lps = memoi(n,n,s,t,dp);
        return (n-lps);
    }
};
