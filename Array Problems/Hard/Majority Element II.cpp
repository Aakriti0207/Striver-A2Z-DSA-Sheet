//229. Majority Element II

BRUTE FORCE-

  /*
Using LOOPS -> But we need to figure out when can we stop iterating so that time complexity can be reduced in easy cases-
We observe that in order for an array to have elements more than n/3 times there cannot be more than 2 such elements present because then no. of elements will be > n
So we create another array- iterate through the given array using 2 loops and count frequency of each element, if ele occurs more than n/3 time add it into array
If 2 elements are pushed into array break out of loop and return!
  */

  //TIME COMPLEXITY => O(n^2) -> NOT OPTIMAL

  BETTER APPROACH-

  /*
HASHING - use a hash map and count frequency of each element and repeat the same process above
  */

  //TIME COMPLEXITY => O(n) ; SPACE : O(n)

  OPTIMAL APPROACH : Boyer Moore Voting Algorithm

/*
  Since max: 2 majority elements

  We maintain: 2 candidates and 2 counts

  Rest, Same idea as Majority Element I
    If number matches candidate: Increase count
    Else if count becomes zero: Replace candidate
    Else: Decrease counts
*/

class Solution {
    //Boyer's Moore Voting Algorithm
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MIN , ele2 = INT_MIN;
        int count1 = 0 , count2 = 0;
        for(int i=0 ; i<n ; i++){
            if(count1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                count1 = 1;
            }else if(count2 == 0 && nums[i] != ele1){
                ele2 = nums[i];
                count2 = 1;
            }else if(nums[i] == ele1){
                count1++;
            }else if(nums[i] == ele2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        //Recheck for n/3
        count1 = 0;
        count2 = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2)count2++;
        }
        vector<int> ans;
        if(count1 > n/3) ans.push_back(ele1);
        if(count2 > n/3) ans.push_back(ele2);
        return ans;
    }
};

/*
Why Recheck?
Example:
[1,2,3,4]
Candidates may survive
But none actually > n/3
*/

//TIME : O(n) SPACE : O(1)
