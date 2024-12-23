class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long c=n;
        if(c<0)
        c=-1*c;
        while(c){
      
            if(c%2){
                ans=ans*x;
                c=c-1;

            }
            else{
                x=x*x;
                c=c/2;
            }
        }
        if(n<0)
        ans=(double)(1.0)/(double)(ans);
        return ans;

        
    }
};

/* x=2,n=5
Loop (while c > 0):
Iteration 1:

c = 5, c % 2 = 1 (odd):
ans = ans * x = 1.0 * 2.0 = 2.0
c = c - 1 = 5 - 1 = 4.
Iteration 2:

c = 4, c % 2 = 0 (even):
x = x * x = 2.0 * 2.0 = 4.0
c = c / 2 = 4 / 2 = 2.
Iteration 3:

c = 2, c % 2 = 0 (even):
x = x * x = 4.0 * 4.0 = 16.0
c = c / 2 = 2 / 2 = 1.
Iteration 4:

c = 1, c % 2 = 1 (odd):
ans = ans * x = 2.0 * 16.0 = 32.0
c = c - 1 = 1 - 1 = 0.
After Loop:
c = 0 → Exit the loop.
Since n > 0, no adjustment is needed.
*/
