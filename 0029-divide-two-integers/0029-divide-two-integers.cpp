class Solution {
private:
    bool checkSign(int n, int d)
    {
        if( (n>0 && d<0) || (n<0 && d>0) )
            return false;

        return true;
    }

public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        
        bool isPositive = checkSign(dividend,divisor);
        
        long num = abs(1ll*dividend), deno=abs(1ll*divisor);
        long low=1, high=num, ans=0;

        while(low<=high)
        {
            long mid = abs((low + (high-low)/2));

            if(mid*deno>num)
                high=mid-1;
            else
            {
                ans=mid;
                low=mid+1;
            }       
        }

        if(!isPositive)
            return -1*ans;
        return ans;
    }
};