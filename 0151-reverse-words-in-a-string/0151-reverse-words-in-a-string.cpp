class Solution {
public:
    string reverseWords(string s) {
        int left=0, n=s.size();
        string ans="",temp="";

        while(left<n)
        {
            char c=s[left];
            if(c!=' '){
                temp.push_back(c);
            }
            else{
                if(ans==""){
                    ans = temp;
                }else if(temp!=""){
                    ans = temp+" "+ans;
                }
                temp="";
            }
            left++;
        }
        
        // for last word
        if(ans==""){
            ans=temp;
        }
        else if(temp!="")
            ans = temp+" "+ans;

        return ans;
    }
};