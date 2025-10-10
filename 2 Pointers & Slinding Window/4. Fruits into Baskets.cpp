You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

//Brute Force Approach
  1. Make subsets using 2 loops and Use set data structure to store non-duplicate elements
  2. stop when set.size > 2
  3. record max length
//code
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0 , right = 0;
        unordered_map<int,int> mpp;
        int maxlen = 0;
        while(right < n){
            mpp[fruits[right]]++;
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen , right-left+1);
            right++;
        }
        return maxlen;
    }
}; TC-> O(n^2) SC -> O(3)

//Better Approach 
  1. Use sliding window with 2 pointers left and right, make a map data structure to store elements and their frequencies
  2. if map.size > 2 , shrink from left 
  -> inrement left till size of map reaches back < 2 - delete the elements whose frequency is turning 0
  3. Record max length
//Code- 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0 , right = 0;
        unordered_map<int,int> mpp;
        int maxlen = 0;
        while(right < n){
            mpp[fruits[right]]++;
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen , right-left+1);
            right++;
        }
        return maxlen;
    }
};TC -> O(2N) , SC-> O(3)

//To optimise this '2' - we use the same approach we used before- 

  class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0 , right = 0;
        unordered_map<int,int> mpp;
        int maxlen = 0;
        while(right < n){
            mpp[fruits[right]]++;
            if(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }else{
                maxlen = max(maxlen , right-left+1);
            }
            right++;
        }
        return maxlen;
    }
}; TC->O(n)
