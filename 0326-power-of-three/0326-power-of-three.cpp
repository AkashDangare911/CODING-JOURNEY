class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        
        long long ans=1;

        while(ans<INT_MAX)
        {
            if(ans==n)
                return true;
            
            ans*=3;
        }

        return false;
    }
};