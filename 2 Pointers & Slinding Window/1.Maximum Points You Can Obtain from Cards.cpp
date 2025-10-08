//There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

//In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

//Your score is the sum of the points of the cards you have taken.

//Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Optimal Approach, 2 Pointer/Sliding Window

-> Pick k number of cards from beginning, reduce the index by 1 from left and add by 1 from right so as to check sum of elements from front as well as back

//Code
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int maxSum = 0, lsum=0 , rsum=0;
        for(int i=0 ; i<k ; i++){
            lsum += cardPoints[i];
            maxSum = max(maxSum , lsum);
        }
        int r=size-1;
        for(int i=k-1 ; i>=0 ;i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[r];
            r--;
            maxSum = max(maxSum , lsum+rsum);
        }
        return maxSum;
    }
};TC -> O(2k)