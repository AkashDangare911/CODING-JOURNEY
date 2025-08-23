class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        // we can't divide array in equal parts
        if(n%groupSize)
            return false;
        
        unordered_map<int,int>mp;
        int minEle=INT_MAX;

        // count freq of element
        for(int i:hand)
            mp[i]++;

        // get the min element from map
        // check if it's consecutive elements also exist in map or not
        while(mp.size())
        {
            minEle=INT_MAX;
            for(auto p:mp)
                minEle=min(minEle,p.first);

            int cnt=0, minFreq=mp[minEle];
            int cur=minEle;
            while(cnt<groupSize)
            {
                if(mp[cur]<minFreq)
                    return false;
                
                mp[cur]-=minFreq;
                if(mp[cur]<=0)
                    mp.erase(cur);
                cur++;
                cnt++;
            }
        }

        return true;
    }
};