class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans=3600;
        int n=timePoints.size();

        for(int i=0;i<n-1;i++)
        {
            int h1=(timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0');
            int h2=(timePoints[i+1][0]-'0')*10 + (timePoints[i+1][1]-'0');

            int m1=(timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');
            int m2=(timePoints[i+1][3]-'0')*10 + (timePoints[i+1][4]-'0');

            // int diff = (h2-h1)*60 + (60-m1) + m2;
            int t1 = h1*60 + m1;
            int t2 = h2*60 + m2;
            // cout<<h1<<" "<<m1<<endl;
            // cout<<h2<<" "<<m2<<endl;
            // cout<<"ans is: "<<ans<<endl;
            ans = min(ans,t2-t1);
        }
        
        int h1=(timePoints[0][0]-'0')*10 + (timePoints[0][1]-'0');
        int m1=(timePoints[0][3]-'0')*10 + (timePoints[0][4]-'0');

        int h2=(timePoints[n-1][0]-'0')*10 + (timePoints[n-1][1]-'0');
        int m2=(timePoints[n-1][3]-'0')*10 + (timePoints[n-1][4]-'0');

        int diff = (23-h2)*60 + (60-m2) + h1*60 + m1;
        ans = min(ans,diff);

        return ans;
    }
};