//You are given an integer array nums, an integer array queries, and an integer x.

//For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

//Return an integer array answer containing the answers to all queries.
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int>ans;
        vector<int> occurences;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == x){
                occurences.push_back(i);
            }
        }
        int m=queries.size();
        int p=occurences.size();
        for(int i=0 ; i<m ; i++){
            if(queries[i] <= p){
                ans.push_back(occurences[queries[i]-1]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};