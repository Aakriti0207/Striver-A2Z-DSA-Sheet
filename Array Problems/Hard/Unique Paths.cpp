//62. Unique Paths

BRUTE FORCE - RECURSION

//At every cell , try: Down and Right

class Solution {
public:
    int solve(int i, int j, int m, int n) {
        if(i == m - 1 && j == n - 1) return 1; // base case - end cell
        if(i >= m || j >= n) return 0; // out of bounds

        int down = solve(i + 1, j , m , n);
        int right =
            solve(i, j+1 , m , n)
        return down + right;
    }

    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};
//TIME COMPLEXITY : O(2^(m+n)) TLE

BETTER APPROACH : DP MEMOISATION
  class Solution {
  public:
    int solve(int i, int j, int m , int n, vector<vector<int>>& dp) {
        if(i == m - 1 && j == n - 1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int down =solve(i + 1, j , m , n , dp);
        int right = solve(i , j+1 , m , n , dp);
        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};
//Time: O(m*n) Space: O(m*n)


OPTIMAL APPROACH : Permutation and Combination
/*
  To go from: top-left to bottom-right
  Need fixed moves
Example:
  m = 3
  n = 7
Need:
  Down: m-1 = 2
  Right: n-1 = 6
  Total moves: 8
Now question becomes:
In 8 positions, where do we place 2 downs?
Combination problem => 8C2 (nCr)
*/
class Solution {
    //PnC solution => nCr , n->totalmoves r->chosenmoves 
public:
    int uniquePaths(int m, int n) {
        int total = m+n-2; //m-1 down n-1 right
        int steps = min(m-1 , n-1); //out of "total" moves where do I place r downs/rights (same thing)
        double ans = 1;
        for(int i=1 ; i<=steps ; i++){
            ans = ans * (total-steps+i)/i; //simplification of factorial
        }
        return (int) ans;
    }
};

//TIME COMPLEXITY : O(min(m,n)) SPACE COMPLEXITY : O(1) => Most Optimal
