//48. Rotate Image

//Problem - we are given a matrix nXn -> need to return another matrix which has rows of original as its column and column as its row

//BRUTE FORCE APPROACH-
  //Creating another dummy matrix

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> image(n, vector<int>(n,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                image[j][n-i-1] = matrix[i][j];
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                matrix[i][j] = image[i][j];
            }
        }
    }
};

//TIME COMPLEXITY => O(n^2) + O(n^2)
//SPACE COMPLEXITY => O(n^2)

//OPTIMAL APPROACH-
  //Transpose the original matrix and then reverse
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                swap(matrix[i][j] , matrix[j][i]); //tanspose
            }
        }
        for(int i=0 ; i<n ; i++){
            reverse(matrix[i].begin() , matrix[i].end()); //reverse
        }
    }
};

//TIME COMPLEXITY -> O(N*N) + O(N*N)
//SPACE COMPLEXITY -> O(1)
