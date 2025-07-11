class Solution {
public:
    // INTUITION - If we XOR the nos again, they will be canceled out
    // So, to delete the xor of elements beside the query range,
    // we have to XOR the undesired elements using XORprefix Sum technique
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorPrefix, ans;
        int cur=0;

        xorPrefix.push_back(0);
        for(int i:arr)
        {
            cur=cur^i;
            xorPrefix.push_back(cur);
        }
        xorPrefix.push_back(0);

        for(vector<int> v: queries)
        {
            int temp = xorPrefix[v[0]] ^ xorPrefix[v[1]+1];
            ans.push_back(temp);
        }

        return ans;
    }
};