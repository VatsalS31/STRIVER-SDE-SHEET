//FULL TRIANGLE
//OPTIMAL CODE FOR THIS
    vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}



/*
TO FIND JUST ELEMENT IN PASCAL TRIANGLE THIS IS FORMULA
R-1  
    C 
        C -1

TO PRINT THE ANY PARTICUALR ROW OF PASCAL TRIANGLE
 int ncr(int n,int r)
    {
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return (int)res;

    }
    for(int c=1;c<=n;c++)
    {
     PRINT(ncr(n-1,c-1));
    }


TO PRINT FULL TRIANGLE BASED ON N belo
class Solution {
    public:
    int ncr(int n,int r)
    {
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return (int)res;

    }
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n=numRows;
        for(int i=1;i<=n;i++)
        
            vector<int>temp;
            for(int j=1;j<=i;j++)
            {
                temp.push_back(ncr(i-1,j-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
   TC O(N*N*R) ~~ O(N^3)

   //OPTIMAL CODE FOR THIS is ABOVE CODE WE WROTE
     TC O(N*N)

*/