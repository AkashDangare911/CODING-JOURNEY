class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int left=0,right=n-1;

        while(left<=right)
        {
            int mid = (left+right)/2;

            if((arr[mid]-(mid+1)) < k)
                left=mid+1;
            else
                right=mid-1;
        }
        
        // now 'right' is at the last index where missing nos < k
        // e.g., if arr[right]=7, and right=3, then missing nos would be 1,5,6 i.e., arr[right]-(right+1)
        // Now, we have 4 non-missing nos, then we have our ans as k+4
        return left+k;      // as left=right+1 at the end of loop
    }
};