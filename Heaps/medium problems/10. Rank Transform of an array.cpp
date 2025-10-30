//1331. Rank Transform of an Array
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible

//Brute Force Approach-
We could think of making a variable count = 1 and iterate every element in the array, if the element is smaller increment the count
NOTE-> this approach does not work for duplicate eliments
//Better Approach
  //Use Sorting + Hashmaps
1. Copy all elements in another array
2. Sort that array
3. Create a map to assign ranks to each element
4. Check for duplicates and assign rank
5. Switch the eliments in the array with their corresponding ranks in map
6. Return arr
//Code
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr; //Duplicate Array
        sort(temp.begin() , temp.end());
        unordered_map<int,int> rank;
        //Assign Ranks- 
        int r = 1;
        for(int i=0 ; i<temp.size() ; i++){
            if(rank.find(temp[i]) == rank.end()){ /*Check if element is already present in map- avoid duplicates */
                rank[temp[i]] = r++;
            }
        }
        for(int i=0 ; i<arr.size() ; i++){
            //Switch the array elements with their corresponding ranks in the map
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
}; TC -> O(2NlogN) SC -> O(N)
