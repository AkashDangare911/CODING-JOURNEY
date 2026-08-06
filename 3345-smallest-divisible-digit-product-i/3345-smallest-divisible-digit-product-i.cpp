class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1)
        {
            int cur=n;
            int prod=1;
            while(cur)
            {
                prod = prod*(cur%10);
                cur=cur/10;
            }

            if(prod%t == 0)
                return n;
            
            n++;
        }

        return -1;
    }
};