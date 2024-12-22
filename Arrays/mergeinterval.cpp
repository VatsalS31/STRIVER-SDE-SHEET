class Solution {
    
 

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty() || intervals[i][0]>ans.back()[1])
            {
                ans.push_back(intervals[i]);
                
            }
            
            else
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }

        }
        
        return ans;
        
       
        
      
        
    }
};


// SORTING THE INTERVALS AND CHECKING EACH INTERVAL WHETEHR THEY LIE IN THAT PARTICULAR INTERVAL OR NOT AGAR NAI TOH EXAPND KREGE INTERVAL KO 
// TC O(NLOGN)+O(N)  SC O(N)
