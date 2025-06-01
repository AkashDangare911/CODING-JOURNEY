class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // every even index and it's +1 index elements are same (every element occurs 2 times)
        int ans=0;
        int start=0,end=nums.size()-1;
        int mid = start+(end-start)/2;

        while(start<end)
        {
            if(mid%2 == 1)
            {
                // some element has occured only once and it caused this malfunctioning
                if(nums[mid] != nums[mid-1]){
                    end = mid;
                }
                else{
                    start = mid+1;
                }
            }
            else
            {
                // all elements on left have occured twice
                if(nums[mid] == nums[mid+1]){
                    start = mid+2;
                }
                else{
                    // some element has occured only once and it caused this malfunctioning
                    end = mid;
                }
            }

            mid = start+(end-start)/2;
        }

        return nums[mid];
    }
};