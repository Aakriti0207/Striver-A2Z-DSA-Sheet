Given: Frog standing at stone 0- there are n stones each with SOME height
       Frog can jump i+1 & i+2 steps
       cost of a jump = abs(height[i] - height[j])
Return: Minimum total energy to reach stone n-1

step1: Defining Dp state:
  dp[i] = min energy to reach stone i
step2: Base Case:
  dp[0]=0
step3: Recurrence Relation:
  cost1 = dp[i-1] + abs(h[i] - h[i-1])
  cost2 = dp[i-2] + abs(h[i] - h[i-2]) => only for i>1
  dp[i] = min(cost1,cost2)

//Memoization- 
  class Solution {
private:
    int recur(int curr, vector<int>& stones, vector<int>& dp){
        if(curr == 0) return 0;
        if(dp[curr] != -1) return dp[curr];
        
        int cost1 = recur(curr-1,stones,dp) + abs(stones[curr] - stones[curr-1]);
        int cost2 = INT_MAX;
        if(curr > 1){
            cost2 = recur(curr-2,stones,dp) + abs(stones[curr] - stones[curr-2]);
        }
        return dp[curr] = min(cost1,cost2);
    }
public:
    int minCost(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n,-1);
        int curr = n-1;
        return recur(curr,stones,dp);
    }
};


//Tabulation- 
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n);
        dp[0] = 0;
        for(int i=1 ; i<n ; i++){
            int cost1 = dp[i-1] + abs(height[i] - height[i-1]);
            int cost2 = INT_MAX;
            if(i>1){
                cost2 = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(cost1 , cost2);
        }
        return dp[n-1];
        
    }
};


//Space Optimization-
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = abs(height[1] - height[0]);;
        int prev2 = 0;
        for(int i=2 ; i<n ; i++){
            int cost1 = prev1 + abs(height[i] - height[i-1]);
            int cost2 = prev2 + abs(height[i] - height[i-2]);
            
            int curr = min(cost1 , cost2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
};
