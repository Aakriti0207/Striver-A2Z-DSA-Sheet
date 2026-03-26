//115. Distinct subsequences

/*
Find: Number of distinct subsequences of s that equal t
At every character in s, you have two choices:
Take it (if it matches with t[j-1])
Skip it
*/

/*
Base Cases
dp[i][0] = 1   // empty t can always be formed
dp[0][j] = 0   // non-empty t from empty s → impossible
*/

//CODE-
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>>dp(n+1, vector<double>(m+1,0));
        //Creating dp table
        for(int i=0 ; i<=n ; i++) dp[i][0] = 1;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};

//MEMOI
class Solution {
private:
    double memoi(int i, int j, string& s, string& t, vector<vector<double>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            int take = memoi(i+1,j+1,s,t,dp);
            int nottake = memoi(i+1,j,s,t,dp);
            return dp[i][j] = take + nottake;
        }else{
            return dp[i][j] = memoi(i+1,j,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>>dp(n+1, vector<double>(m+1,-1));
        return (int) memoi(0,0,s,t,dp);
        // return (int)dp[n][m];
    }
};

//Space Optimisation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m+1,0);
        vector<double> curr(m+1,0);
        prev[0] = 1;
        curr[0] = 1;
        for(int i=1 ; i<=n ; i++){
            curr[0] = 1;
            for(int j=1 ; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int) prev[m];
    }
};
