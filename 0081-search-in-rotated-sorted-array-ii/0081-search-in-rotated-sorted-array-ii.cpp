class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        while(left<=right)
        {
            int mid = (left+right)/2;
            int currentElement = nums[mid];

            if(currentElement==target)
                return true;

            // if we encountered this condition, we are unable to identify the sorted part
            // hence, we trim down the search space, by moving left & right pointers
            if(nums[left]==nums[mid] && nums[mid]==nums[right])
            {
                left++,right--;
                // we are not sure if now the elements have changed or not,
                // hence check them in next iteration, if are same, do above comparison again
                continue;       
            }

            // identify the sorted part and search the element in it only
            if(nums[left] <= currentElement)
            {
                if(nums[left]<=target && target<=currentElement)
                    right=mid-1;
                else
                    left=mid+1;
                
            }
            else
            {
                if(currentElement<=target && target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }

       return false;
    }
};