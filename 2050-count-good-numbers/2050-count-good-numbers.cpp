class Solution {
private:
    int mod=1e9+7;

    // find x^n in log(n)
    long long fastExponent(long long x, long long n)
    {
        long long ans=1;
        while(n>0)
        {
            if(n&1)
            {
                ans=(ans*x)%mod;
                n--;
            }
            else
            {
                x=(x*x)%mod;
                n/=2;
            }
        }

        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long ans=1;
        int i=1;

        long long odd = n/2;
        long long even = n-odd;

        return (fastExponent(5,even)*fastExponent(4,odd))%mod;
    }
};