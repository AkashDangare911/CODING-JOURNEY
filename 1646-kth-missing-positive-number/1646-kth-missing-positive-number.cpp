class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur=1;
        int i=0, n=arr.size();

        while(k && i<n)
        {
            if(arr[i]==cur)
            {
                cur++,i++;
            }
            else
            {
                cur++;
                k--;
            }
        }
        
        return cur+k-1;
    }
};