class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        long long ans=0;
        long long temp=n;
        ans=temp*(temp-1);
        bool isCircle=false;
        if(edges.size()==n)
            isCircle=true;

        while(temp-2 > 0)
        {
            ans = ans+temp*(temp-2);
            temp-=2;
        }

        temp=n-1;

        while(temp-2 > 0)
        {
            ans = ans+temp*(temp-2);
            temp-=2;
        }

        if(isCircle)
            return ans+2;
        return ans;
    }
};


