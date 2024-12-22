
//BETTER
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>col(m,0);
        vector<int>row(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    col[j]=1;
                    row[i]=1;
                }
            }
        }        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};



/*
//BRUTE
TC O(N*M) * (N+M) + (N*M) ~O(N^3)
iterat trough complete matrix and where ever u got 0 mark all the element s corresodign to that row,col to -1 to avoid re marking of 
0 again and after that again travers to matrix where u got -1 change to 0

//BETTER UPROACH 
TC O(2*N*M)
SC 0(N)+O(M)
in this 1st we will iteraye thrugh the 2d array and we will check where ever we got 0 we will mark that corresponding row,col to 1 
and after that again we will iterate an chck which row,colm in marked and correcsponding index wala box we will mark to 0

//OPTIMAL UPROACH
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}


*/