// Method remains the same 
/*
When s1[i] and s2[j] don't match dp[i][j] is 0
and to return length we need the max of all elements of DP
*/

//CODE (Tabulation)-
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size(), m  = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int ans = 0;
        //Filling up the table
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

//Memoization-
class Solution {
  private:
    int memoi(int i, int j, string& s1, string& s2, vector<vector<int>>& dp, int &ans){
        if(i==0 || j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int curr = 0;
        if(s1[i-1] == s2[j-1]){
            curr = 1 + memoi(i-1,j-1,s1,s2,dp,ans);
            ans = max(ans,curr);
        }
        memoi(i-1,j,s1,s2,dp,ans);
        memoi(i,j-1,s1,s2,dp,ans);
        return dp[i][j] = curr;
    }
  public:
    int longCommSubstr(string& s1, string& s2) {
        // Memoization
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int ans = 0;
        //memoi(i,j,s1,s2,dp,ans)
        memoi(n,m,s1,s2,dp,ans);
        return ans;
    }
};

//Space Optimisation
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // Space Optimisation
        /* Instead of using 2D dp we just use prev and curr variables*/
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1+prev[j-1];
                    ans = max(ans, curr[j]);
                }else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};
