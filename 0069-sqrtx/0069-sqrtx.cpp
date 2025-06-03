class Solution {
public:
    int mySqrt(int x) {
        int s=0, e=x;
        long long mid;

        while(s<=e)
        {
            mid = (s+e)/2;

            if(mid*mid == x)
                return mid;
            else if(mid*mid < x)
                s=mid+1;
            else
                e=mid-1;

        }

        // in last iteration of loop, s == e == mid, now 's' would have moved forward by 1
        // if we didn't got our ans by mid*mid, and as stated in description, we have to round off the root
        // we must return the lower number than the mid i.e., s-1 or e
        // Also can use 'ans' variable to store the ans
        return e;
    }
};