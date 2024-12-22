// BRUTE FORCE
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>temp;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           temp[j][i]=matrix[i][j];
       }
   }
   
   int k=0;
   while(k<n)
   {
       int i=0;
       int j=n-1;
       while(i<=j)
       {
         swap(temp[k][i],temp[k][j]);
         i++;
         j--;
       }
       k++;
   }
        
    }
};

//TC O(N^2) SC O(N*M)

//OPTIMAL UPROACH
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
   // TRANSPOSING WITHOUT USING TEMP MATRXI ARRAY
      
   for(int i=0;i<n-1;i++)
   {
       for(int j=i+1;j<m;j++)
       {
           swap(matrix[i][j],matrix[j][i]);
       }
   }
   
   for(int i=0;i<n;i++)
   {
    reverse(matrix[i].begin(),matrix[i].end());
   }
        
    }
};

//TC O(N*M)  SC O(1)
// ROTATING THE MATRIX BY 90 DEGREE SO THE UPROACH IS TAKING THE TRANSPOSE OF MATRIX AND THEN AFTER OBSERVING SWAPPING THE ELEMENTS ACCORDINGLY
