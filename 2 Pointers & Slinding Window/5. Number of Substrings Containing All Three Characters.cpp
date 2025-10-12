//Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

//Brute Force
  use 2 nested loops and iterate all possible substrings and check if condition is true using hashmaps
//Code
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0 ; i<n ; i++){
            unordered_map<char,int>mpp;
            for(int j=i ; j<n ; j++){
                mpp[s[j]]++;
                if(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                    count++;
                }
            }
        }
        return count;
    }
}; TC -> O(n^2) SC -> O(3)

  //Better Approach-
  We know that when we encounter any valid substring the substrings generated after that for same 'i' index will be valid as well since it's already proved that they have 1 a b c
    so the count can be written as- count + (n-j)
  //Code
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0 ; i<n ; i++){
            unordered_map<char,int>mpp;
            for(int j=i ; j<n ; j++){
                mpp[s[j]]++;
                if(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                    count += n-j;
                    break;
                }
            }
        }
        return count;
    }
}; time complexity remains same
//Optimal Approach- 
  we use sliding window in the same approach as above-
  initialise left and right, increment right till it is a valid substring then increase count += n-right , then increment left and remove that element from map till it is invalid
//code
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int left = 0 , right = 0;
        unordered_map<char,int> mpp;
        while(right < n){
            mpp[s[right]]++;
            while(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                count += n-right;
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};TC-> o(n)
