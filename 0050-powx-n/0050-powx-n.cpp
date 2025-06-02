class Solution {
public:
    double myPow(double x, int n) {
        if(x==0 || x==1)
            return x;
        
        bool neg=n<0;
        double ans=1;       // used to temporary store the multiplication of x ^ (odd powers) 
        long long power = n;
        power=abs(power);

        // If we square the base, we must have to decrease the power by half
        // we can only decrease power by half iff n is even
        // if n is odd, then decrease it by 1, and continue the process
        // keep the multi. of odd powers in ans variable, if will form final ans when power==1 in the ene
        while(power>0)
        {
            // odd power
            // - we have formed our current value in 'x'
            // hence to decrease the power by 1, we need to ans by the current value i.e., 'x'
            if(power&1)
            {
                ans = ans*x;
                power--;
            }
            // event power - square the base, halve the power
            else
            {
                x*=x;
                power/=2;
            }
        }

        // check if power was negative
        if(neg)
            ans = 1/ans;
        
        return ans;
    }
};