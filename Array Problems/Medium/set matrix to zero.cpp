/*
73. Set Matrix to zero
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
*/

/*
Problem-
We are given a matrix and we need to find if there's any cell which contains zero(0) as value
If we find a cell with value 0 - we need to convert its ENTIRE row and ENTIRE column to 0
BUT the converted row and column will NOT be considered as element 0 of the matrix thus, the column and row of this converted 0 are not going to be modified
This condition in itself gives rise to our brute force
*/

//BRUTE FORCE

/*
Here, we find the zero element of the matrix and to stop the converted zeros to be mistaken as elements of the matrix - we set the non-zero rows and columns to -1 and after the entire process is completed - switch all -1's to 0s
*/

//CODE-
class Solution {
private:
    void markRow(vector<vector<int>>& matrix , int& i , int& m){
        for(int j=0 ; j<m ; j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void markCol(vector<vector<int>>& matrix , int& j , int& n){
        for(int i=0 ; i<n ; i++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == 0){
                    markRow(matrix,i,m);
                    markCol(matrix,j,n);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//TIME COMPLEXITY

/*
1. Traversing Matrix to find zero -> O(N*M)
2. Marking row and column with -1 -> O(N+M)
3. Mark all -1 with 0 at end -> O(N*M)
TC = O((O(N*M)*O(N+M)) + O(N*M))
*/

//SPACE COMPLEXITY -> O(1)

//Problem - using -1 is risky -> there's a possibility that matrix already contains -1 => leetcode testcase

//BETTER APPROACH

/*
Use extra arrays-
store -
    -> which rows should become zero 
    -> which column should become zero

we make row[n] and col[m] if matrix[i][j] == 0 then row[i] = 1 and col[j] = 1 
later, if row[i] == 1 || col[j] == 1 make matrix[i][j] = 0
*/

//CODE-
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Mark rows and cols
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == 0) {

                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Fill zeroes
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(row[i] == 1 || col[j] == 1) {

                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//TIME COMPLEXITY-
/*
Traversing the entire matrix twice -> O(2*(N*M))
*/
//SPACE COMPLEXITY-
//O(N) + O(M)


//But here we NEED to optimise space

//OPTIMAL APPROACH-
/*

Instead of separate row[] and col[] arrays,

we use:
First row → column marker
First column → row marker

i.e make the changes inside the matrix itself!

eg - if at [1][1] = 0 we make [0][1] and [1][0] = 0
first row stores column infor
first column stores row infor
BUT for case [0][0] -> we'll need to create an extra variable-
*/

//CODE-
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0 = 1; //Extra Column
        for(int i=0 ; i<n ; i++){  // Marking rows and colums as 0 
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    if(j!=0){
                        matrix[0][j] = 0;
                    }else{
                        col0 = 0;
                    }
                }
            }
        }
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        //Check for first column and row if they had zero or not
        if(matrix[0][0] == 0){
            for(int j=0 ; j<m ; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0 ; i<n ; i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
//TIME COMPLEXITY -> O(2 * N*M)
//SPACE COMPLEXITY -> O(1)