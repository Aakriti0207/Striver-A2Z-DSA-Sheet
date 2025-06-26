//SECOND LARGEST
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int largest=INT_MIN , second_largest=INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(arr[i]>largest){
                second_largest=largest;
                largest=arr[i];
            }else if(arr[i]>second_largest && arr[i] != largest){
                second_largest=arr[i];
            }
        }
        if(largest==second_largest){
            return-1;
        }else if(second_largest == INT_MIN){
            return -1;
        } else{
         return second_largest;
        }
    }
};

//MIN AND SECOND MIN
class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ans;
        int min = INT_MAX , second_min = INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(arr[i] < min){
                second_min = min;
                min=arr[i];
            }
            else if(arr[i] < second_min && arr[i] != min){
                second_min = arr[i];
            }
        }
        if(min == second_min){
            ans.push_back(-1);
        }else if(second_min == INT_MAX) ans.push_back(-1);
        else{
            ans.push_back(min);
            ans.push_back(second_min);
        }
        return ans;
    }
};