class Solution {
public:
    // Binary Search only works on sorted arrays.
    // Hence we have to identify the sorted part and search in it only
    // Searching in un-sorted part will not help find element

    // STEPS:
    // - identify the sorted half
    // - check if the element lies in it or not
    // - minimize the array at each iteration
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        while(left<=right)
        {
            int mid = (left+right)/2;
            int currentElement = nums[mid];

            cout<<mid<<endl;
            // if target is found, return the index
            if(currentElement==target)
                return mid;

            // identify the sorted part and search the element in it only
            // sorted part maybe left part / right part
            if(nums[left] <= currentElement)
            {
                if(nums[left]<=target && target<=currentElement)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            else
            {
                if(currentElement<=target && target<=nums[right])
                {
                    left=mid+1;
                }
                else
                    right=mid-1;
            }
        }

       return -1;
    }
};