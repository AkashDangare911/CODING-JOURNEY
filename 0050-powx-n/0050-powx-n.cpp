class Solution {
private:
    double solve(double x, long long power, double ans)
    {
        // base case
        if(power==0)
            return ans;
        
        if(power&1)
        {
            ans*=x;
            return solve(x,power-1,ans);
        }
        else
        {
            x*=x;
            return solve(x,power/2,ans);
        }
    }

public:
    // USING RECURSION
    double myPow(double x, int n) {
        // base case 0^100 || 1^100
        if(x==0 || x==1)
            return x;

        long long power = n;
        power=abs(power);
        
        double ans = solve(x,power,(double)1);

        if(n<0)
            ans=1/ans;
        
        return ans;
    }
};