class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
           
        }
        for(int i=n-2;i>=0;i--)
        {
             suffix[i]=max(suffix[i+1],height[i]);
        }
        int total=0;
        for(int i=0;i<n;i++)
        {
            int left=prefix[i];
            int right=suffix[i];
            if(left>height[i] && right>height[i])
            {
                total+=min(left,right)-height[i];
            }
        }
        return total;

        
    }
};

/*
BRUTE FORCE IS THAT KI 1ST CALCULATE MAX HEIGHT OF RIGHT AND LEFT AND THEN TAKE MINIMUM OF BOTH TO CHECK KI KAHA TAK PANI BARA HOGA
SIMPLE EX.... KI DO BADI BUILDING KE BICH ME KITNA PANI HAI WO DEKHNA OR USME AGR EK BUILDING 5 HAI OR DUSRI 8 TOH 5 TAK HE PANI HOGA
UPAR KA KHALI HOGA..TOH LEFT,RIGHT MAX NIKL KE LIYE PREFIX SUM KA KHEL KIYA...OR CHECK KIYA KI LEFT RIGHT HAMARE CURRENT BUILDING SE BADE HAI NA
NAI TOH PATA CHALA KI LEFT,RIGHT SE HUM BADE HAI..HAMRE BICH ME PANI HE NAI HAI...

TC O(2N)+O(N)
SC O(2N)//PREFIX SUM WALA ARRAY
*/

//OPTIMAL SOLUTION
/*
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=0;
        int rmax=0;
        int total=0;
        int l=0;
        int r=n-1;

        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(lmax>height[l])
                {
                    total+=lmax-height[l];
                }
                else
                {
                    lmax=height[l];
                }
                l+=1;
            }
            else
            {
                if(rmax>height[r])
                {
                    total+=rmax-height[r];
                }
                else
                {
                    rmax=height[r];
                }
                r-=1;
            }
        }
        return total;
        
        return total;

        
    }
};

Approach: Take 2 pointers l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively.
Take two variables leftMax and rightMax and initialize them to 0. 
If height[l] is less than or equal to height[r] then if leftMax is less than height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the right i.e l++. 
If height[r] is less than height[l], then now we are dealing with the right block. If height[r] is greater than rightMax, then update rightMax to height[r] else add rightMax-height[r] to the final answer.
Now move r to the left. Repeat these steps till l and r crosses each other.

Intuition: We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r] we increase l++, so we can surely say that there is a block with a height more than height[l] to the right of l.
And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height[r].
So by traversing these cases and using two pointers approach the time complexity can be decreased without using extra space.

TC O(N)
SC O(1)
*/
