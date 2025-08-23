class Solution {
private:
    bool canFormSequence(vector<int> &nums, int size, int ind)
    {
        int count=1;
        int prev=nums[ind];
        nums[ind]=-1;
        ind++;

        while(ind<nums.size() && count<size)
        {
            if(nums[ind] == prev+1)
            {
                prev=nums[ind];
                nums[ind]=-1;
                count++;
            }
            ind++;
        }
        
        return count==size;
    }
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        // we can't divide array in equal parts
        if(n%k)
            return false;

        // to keep smallest element at start
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                if(!canFormSequence(nums,k,i))
                    return false;
            }
        }

        return true;
    }
};