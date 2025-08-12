class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n=cards.size();
        int left=0,right=n-1;
        int ans=0, sum=0;

        // pick starting 'k' cards
        while(left<k)
        {
            sum+=cards[left];
            left++;
        }

        // we got leftSum till far
        ans=max(ans,sum);
        left--;

        // pick rightmost elements while removing leftmost elements in a turn
        while(left>=0)
        {
            sum-=cards[left--];
            sum+=cards[right--];
            ans=max(ans,sum);
        }

        return ans;
    }
};