class Solution {
private:
    void solve(int ind, string digits, string temp, vector<string> &keyPad, vector<string> &ans)
    {
        if(ind==digits.size())
        {
            ans.push_back(temp);
            return;
        }

        int key = digits[ind]-'0';
        string curKey=keyPad[key];

        for(char c:curKey)
        {
            temp.push_back(c);
            solve(ind+1,digits,temp,keyPad,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;

        vector<string> keyPad = {"","","abc","def",
                                "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"};

        solve(0,digits,"",keyPad,ans);

        return ans;
    }
};