//56. Merge Intervals

/*
Given an array with [start,end] - we need to merge all overlapping arrays
ie when end(i) > start(i+1)
*/

//BRUTE FORCE-
//sort all intervals based on their starting points and run loops to check overlapping intervals-
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin() , intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;
        while(i<n){
            if(intervals[i][0] > end){
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }else{
                end = max(end , intervals[i][1]);
            }
            i++;
        }
        ans.push_back({start,end});
        return ans;
    }
};
//Time Complexity: O(nlogn) + O(N^2), for every interval we check all future intervals.
//Space Complexity: O(N), additonal space used to store the non-overlapping intervals.

//OPTIMAL SOLUTION

/*
Imagine laying out all intervals on a number line , we initialise an empty list - 
    -> If the list is empty or the current interval starts after the last one ends, it means there is no overlap
    -> If the current(start) <= next(end) it means there is overlap. So, combine both 
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> merged;
        for(int i=0 ; i<n ; i++){
            if(merged.empty() || intervals[i][0] > merged.back()[1]){
                merged.push_back(intervals[i]);
            }else{
                merged.back()[1] = max(merged.back()[1] , intervals[i][1]);
            }
        }
        return merged;
    }
};
//TIME COMPLEXITY => O(N*logN) + O(N)
//SPACE COMPLEXITY => O(N)