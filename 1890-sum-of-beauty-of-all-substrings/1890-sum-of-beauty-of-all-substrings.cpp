class Solution {
private:
    int findBeauty(string s)
    {
        int arr[26]={0};
        int mx=-1,mn=INT_MAX;
        for(char c:s)
            arr[c-'a']++;

        for(int i=0;i<26;i++)
        {
            mx=max(mx,arr[i]);
            if(arr[i])
               mn=min(mn,arr[i]);
        }
        return (mx>0 && mn!=INT_MAX) ? mx-mn : 0;
    }
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            string str="";
            for(int j=i;j<n;j++)
            {
                str.push_back(s[j]);
                ans+=findBeauty(str);
            }
        }

        return ans;
    }
};