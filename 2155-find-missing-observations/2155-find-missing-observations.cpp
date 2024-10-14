class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        int total = (m+n)*mean;
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int remain = total-sum;
        
        int each = remain/n;
        // cout<<"each"<<each<<endl;
        // cout<<"total"<<total<<endl;
        // cout<<"remain"<<remain<<endl;
        // cout<<"sum"<<sum<<endl;

        if(n>remain || each>6 || sum>total)  return {};

        int extra = remain - (each*n);
        if(extra && each==6){
            return {};
        }

        n-=extra;
        each++;
        
        while(extra--){
            ans.push_back(each);
            remain-=each;
        }
        each--;

        while(--n)
        {
            ans.push_back(each);
            remain-=each;
        }

        // cout<<"greattt\n";
        // cout<<"remain"<<remain<<endl;
        if(remain){
            if(remain>6)
                return {};
            ans.push_back(remain);
        }
        return ans;
    }
};