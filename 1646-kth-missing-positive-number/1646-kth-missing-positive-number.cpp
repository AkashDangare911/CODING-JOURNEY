class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for empty arr, missing 'k'th value would be k......{1)
        // then if we keep adding numbers to array, it means they were not missing
        // and we have to now search for higher k value
        // however, if any value is greater than k, it meansthe kth missing would lie in between  
        for(int i: arr)
        {
            if(i<=k)
                k++;
            else
                break;
        }

        return k;
    }
};