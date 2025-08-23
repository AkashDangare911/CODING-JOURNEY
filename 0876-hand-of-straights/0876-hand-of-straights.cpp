class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        // we can't divide array in equal parts
        if(n%groupSize)
            return false;
        
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>> pq;
        int minEle=INT_MAX;

        // count freq of element
        for(int i:hand)
            mp[i]++;
        
        // keep all unique elements in min-heap to get smallest element fast
        for(auto &p:mp)
            pq.push(p.first);

        // get the min element from min-heap
        // check if it's consecutive elements also exist in map or not
        while(mp.size())
        {
            minEle=pq.top();
            pq.pop();

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