//Count Inversions

/*
What is an Inversion?
An inversion means:
For indices: i < j
but:
arr[i] > arr[j]
*/

//Brute Force
//Idea: Check every pair
class Solution {
public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] > arr[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
//Time Complexity: O(n²) TLE for large input.

//Optimal Approach → Merge Sort
/*
  Because merge sort gives:
  sorted left
  sorted right
  which lets us count efficiently.
*/
class Solution {
public:

    int merge(vector<int>& arr,int low,int mid,int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0;
        while(left <= mid &&
              right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                // inversion count
                count += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i <= high; i++) {
            arr[i] =
            temp[i - low];
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int count = 0;
        if(low >= high)
            return count;
        int mid =
        (low + high) / 2;
        count += mergeSort(arr,low,mid);
        count += mergeSort(arr,mid+1,high);
        count += merge(arr,low,mid,high);

        return count;
    }

    int inversionCount(vector<int> &arr) {

        return mergeSort(arr,0,arr.size() - 1);
    }
};
//Time: Merge sort: O(n log n)
//Space: Temp array: O(n)
