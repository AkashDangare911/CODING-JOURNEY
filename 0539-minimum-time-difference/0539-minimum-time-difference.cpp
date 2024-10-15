class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        int ans=3600;
        int n=timePoints.size();

        for(int i=0;i<n;i++)
        {
            int h=(timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0');
            int m=(timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');

            int t = h*60 + m;
            time.push_back(t);
        }
        sort(time.begin(),time.end());

        for(int i=0;i<n-1;i++)
            ans = min(ans,time[i+1]-time[i]);
        
        ans = min(ans,1440-time[n-1]+time[0]);

        return ans;
    }
};