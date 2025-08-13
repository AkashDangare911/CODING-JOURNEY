class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;

        // keep dividing n by 3 until, we eventually comes to 1
        // or if the remainder is not 0
        while(n%3==0)
            n/=3;

        return n==1;;
    }
};