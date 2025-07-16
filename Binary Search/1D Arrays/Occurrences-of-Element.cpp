//Find Occurrences of an Element in an Array
//You are given an integer array nums, an integer array queries, and an integer x.

//For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

//Return an integer array answer containing the answers to all queries.

//BRUTE
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int> occurrences;
        vector<int>ans;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == x){
                occurrences.push_back(i);
            }
        }
        int a=queries.size();
        int b=occurrences.size();
        for(int i=0 ; i<a ; i++){
            if(queries[i] <= b){
                ans.push_back(occurrences[queries[i]-1]); //Mistake-> occurrences mai queries ka index laana h
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

 
