//Longest Common Subsequence

/*
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".
*/

//Approach-

/*
1. Create a 2D dp 
2. Insert elements into the dp-
    -> if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1]
    -> else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
3. Find LCS by backtracking the entire 2D DP
    -> Start from (n-1,m-1)
    -> if both elements are same - add them in the string and move diagonally i.e. i-1,j-1
    -> else if (dp[i-1][j] > dp[i][j-1]) i--
    -> else j--
4. Reverse the string to get the desired LCS
*/

//CODE
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        //creating dp table
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        //filling up the dp table
        for(int i=1; i<=n; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        //Backtracting
        string lcs = "";
        int i=n, j=m;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                lcs += s1[i-1];
                i--;
                j--;
            }else if (dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        return lcs.size();
    }
};
