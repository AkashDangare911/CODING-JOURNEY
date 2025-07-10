class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        int xorr = start^goal;

        while(xorr)
        {
            if(xorr&1)
                count++;
            xorr=xorr>>1;
        }

        return count;
    }
};