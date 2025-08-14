class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int left=0, ans=-1;

        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1] && num[i]==num[i+2])
            {
                if((num[i]-'0') > ans)
                {
                    left=i;
                    ans=num[i]-'0';;
                }
            }
        }

        if(ans!=-1)
            return num.substr(left,3);
        return "";
    }
};