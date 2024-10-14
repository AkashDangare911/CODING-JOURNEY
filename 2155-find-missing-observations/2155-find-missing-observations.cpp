class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // vector<int> ans;
        int m = rolls.size();
        int total = (m+n)*mean;
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int remain = total-sum;
        
        // unsatisfied conditions
        if(n>remain || remain>n*6 || sum>total)  return {};

        // divide remained equally, then distribute the remained
        int each = remain/n;
        vector<int> ans(n,each);
        int extra = remain - (each*n);
        int i=0;

        while(extra--){
            ans[i++]++;
        }
        return ans;
    }
};