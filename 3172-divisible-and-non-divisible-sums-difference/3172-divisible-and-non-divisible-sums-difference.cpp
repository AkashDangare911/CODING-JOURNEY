class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum=(n*(n+1))/2;
        int i=1;

        while(i<=n)
        {
            if(i%m == 0)
                sum-=i*2;
            i++;
        }
        return sum;
    }
};