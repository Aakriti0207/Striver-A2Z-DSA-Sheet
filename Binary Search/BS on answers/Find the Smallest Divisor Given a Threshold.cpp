//Find the Smallest Divisor Given a Threshold
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }
        for(int i=1 ; i<=maxi ; i++){       //Less than equal to
            int sum = 0;
            for(int j=0 ; j<n ; j++){
                int div = ceil ( (double) (nums[j]) / (double) (i) );
                sum = sum + div;
            }
            if(sum <= threshold){
                return i;
            }
        }
        return -1;
    }
};
