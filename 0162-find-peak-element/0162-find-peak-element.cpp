class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // for single element it will always be a peak (from given conditions)
        // leftmost & rightmost elements can be a peak if adjacent element is smaller
        // Otherwise, consider we have to find only a peak, & eventually it will be found in array for sure
        
        // - Use binary search & find mid
        // - if (mid < mid+1), mid is on increasing slope
        // - if(mid > mid+1), mid is on decreasing slope
        // if confirms that a peak element exists in between, so move left/right accordingly
        // at end of loop, both pointers will land on same element, breaking the loop

        int left=0, right=nums.size()-1;
        int mid;

        while(left<right)
        {
            mid = (left+right)/2;

            // mid is on increasing slope
            if(nums[mid] < nums[mid+1])
                left=mid+1;
            else
                right=mid;
        }

        return left;    // can return 'right' as well
    }
};