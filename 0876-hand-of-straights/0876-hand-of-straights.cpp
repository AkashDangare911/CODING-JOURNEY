class Solution {
private:
    bool canFormSequence(vector<int> &hand, int size, int ind)
    {
        int count=1;
        int prev=hand[ind];
        hand[ind]=-1;
        ind++;

        while(ind<hand.size() && count<size)
        {
            if(hand[ind] == prev+1)
            {
                prev=hand[ind];
                hand[ind]=-1;
                count++;
            }
            ind++;
        }
        
        return count==size;
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        // we can't divide array in equal parts
        if(n%groupSize)
            return false;

        // to keep smallest element at start
        sort(hand.begin(),hand.end());

        for(int i=0;i<n;i++)
        {
            if(hand[i]!=-1)
            {
                if(!canFormSequence(hand,groupSize,i))
                    return false;
            }
        }

        return true;
    }
};