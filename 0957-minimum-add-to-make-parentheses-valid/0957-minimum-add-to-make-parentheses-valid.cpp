class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;

        for(char c: s)
        {
            if(c == ')'){
                if(open)
                    open--;
                else
                    close++;
            }else{
                open++;
            }
        }

        return open+close;
    }
};