class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=(n*m)-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return false;
        
    }
};

// do the normal binary search in 2d matrix just flatten the 2d matrix in to 1d array not physically just do in head to form the formula
// so do get the 2d coordinates we will mind mid in n*m matrix and after dividing with m we will get row and modulo by m we will get col 
// and then doing normal binary search

// TC O(LOG(N*M))
// SC O(1)
