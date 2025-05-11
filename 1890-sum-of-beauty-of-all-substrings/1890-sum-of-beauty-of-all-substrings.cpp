class Solution {
private:
    int findBeauty(vector<int> &arr)
    {
        int mx=-1,mn=INT_MAX;

        for(int i=0;i<26;i++)
        {
            if(arr[i])
            {
                mx=max(mx,arr[i]);
                mn=min(mn,arr[i]);
            }
        }
        return (mx>0 && mn!=INT_MAX) ? mx-mn : 0;
    }
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                ans+=findBeauty(freq);
            }
        }

        return ans;
    }
};