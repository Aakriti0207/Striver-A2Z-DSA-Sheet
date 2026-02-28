//ninja's training

/*Given: 
    matrices consisting of days and the activities ninja performs- 
    A ninja can perform 3 activities a day and we need to return maximum total points after each day
*/

/*
Step1: State Finding
    Both day & last activity keeps on changing and at the end we need to achieve max points Thus,
    dp[day][last] = maximum points till this day if activity != last

Step2: Recurrence Relation
    for each day- we need to try all three activities and find the one with maximum points BUT it should NOT be equal to the last activity performed

Step3: Base Conditions
    The activities conducted on day 0 must be the base cases
    when day=0 & i=0 there's no last, thus find the max in other 2 elements
*/

//MEMOIZATION
int recur(int day, int last, vector<vector<int>>& points,vector<vector<int>>& dp){
    if(dp[day][last] != -1) return dp[day][last];
    //Edge Case
    if(day == 0){
        int maxi = 0;
        for(int i=0 ; i<=2 ; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    //Normal conditions
    int maxi = 0;
    for(int i=0 ; i<=2 ; i++){
        if(i != last){
            int activity = points[day][i] + recur(day-1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
//Memoization
{
    vector<vector<int>>dp(n, vector<int> (4,-1));
    return recur(n-1, 3, points, dp);
}
