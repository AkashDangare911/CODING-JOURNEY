class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int big=0, biggest=0;

        for(int i:nums)
        {
            if(i>=biggest)
            {
                big=biggest;
                biggest=i;
            } 
            else if(i>big)
                big=i;
        }

        return (big-1)*(biggest-1);
    }
};