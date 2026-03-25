/*
Let:
n = len(s1)
m = len(s2)
lcs = LCS(s1, s2)

Then:
Deletions = n - lcs
Insertions = m - lcs

Total operations: (n - lcs) + (m - lcs)
The code remains same
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs = dp[n][m];
        int deletion = n - lcs;
        int insertion = m - lcs;
        return deletion + insertion;

    }
};
