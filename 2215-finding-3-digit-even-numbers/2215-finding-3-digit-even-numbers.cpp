class Solution {
private:
    bool isPossible(int n, vector<int> freq)
    {
        while(n)
        {
            int dig=n%10;
            n/=10;
            if(freq[dig])
                freq[dig]--;
            else
                return false;
        }
        return true;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10,0);
        for(int i:digits)
            freq[i]++;

        for(int i=100;i<1000;i++)
        {
            if(i%2==0 && isPossible(i,freq))
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};