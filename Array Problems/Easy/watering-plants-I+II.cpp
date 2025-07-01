//WateringPlants1
//You want to water n plants in your garden with a watering can. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i. There is a river at x = -1 that you can refill your watering can at.

//Each plant needs a specific amount of water. You will water the plants in the following way:

//Water the plants in order from left to right.
//After watering the current plant, if you do not have enough water to completely water the next plant, return to the river to fully refill the watering can.
//You cannot refill the watering can early.
//You are initially at the river (i.e., x = -1). It takes one step to move one unit on the x-axis.

//Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and an integer capacity representing the watering can capacity, return the number of steps needed to water all the plants.

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int cap_after=capacity;
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(cap_after < plants[i]){
                cap_after=capacity;
                cap_after=cap_after-plants[i];
                count = count + i + i + 1;
            }else{
                cap_after=cap_after-plants[i];
                count++;
            }
        }
        return count;
    }
};

//Watering Plants- II
//Alice and Bob want to water n plants in their garden. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i.

//Each plant needs a specific amount of water. Alice and Bob have a watering can each, initially full. They water the plants in the following way:

//Alice waters the plants in order from left to right, starting from the 0th plant. Bob waters the plants in order from right to left, starting from the (n - 1)th plant. They begin watering the plants simultaneously.
//It takes the same amount of time to water each plant regardless of how much water it needs.
//Alice/Bob must water the plant if they have enough in their can to fully water it. Otherwise, they first refill their can (instantaneously) then water the plant.
//In case both Alice and Bob reach the same plant, the one with more water currently in his/her watering can should water this plant. If they have the same amount of water, then Alice should water this plant.
//Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and two integers capacityA and capacityB representing the capacities of Alice's and Bob's watering cans respectively, return the number of times they have to refill to water all the plants.

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int cap_afterA=capacityA , cap_afterB=capacityB;
        int count=0;
        int left=0 , right=n-1;
        while(left<right){
            if(cap_afterA < plants[left]){
                count++;
                cap_afterA=capacityA;
            }
            cap_afterA = cap_afterA - plants[left];
            left++;
            if(cap_afterB < plants[right]){
                count++;
                cap_afterB=capacityB;
            }
            cap_afterB = cap_afterB - plants[right];
            right--;
        }
        if(left==right){
                if(max(cap_afterA , cap_afterB) < plants[left]){
                    count++;
                }
            }

        return count;
    }
};
