class Solution {
public:
    // INTUITION
    // The single elements must have 1 different bit, so when we XOR all elements, 
    // the resultant XOR will have that different bit set (i.e., 1)
    // So, we will group all the elements will that set bit in one group and 
    // rest nos in other group 
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        int n1=0, n2=0;
        int diffBitIndex=0;

        // xor all elements
        for(int i:nums)
            XOR=XOR^i;

        // find first set bit i.e., different bit in both the nos
        while(XOR)
        {
            if(XOR & (1<<diffBitIndex))
                break;
            diffBitIndex++;
        }

        // form two groups, one with bit at 'diffBitIndex' as 1 and other with 0
        for(int i:nums)
        {
            // set bits group
            if(i & (1<<diffBitIndex))
                n1^=i;
            // unset bits group
            else
                n2^=i;
        }

        return{n1,n2};
    }
};