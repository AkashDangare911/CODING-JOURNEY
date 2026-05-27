class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        int small[26], capital[26];

        // initialize with -1
        for(int i=0;i<26;i++)
            small[i]=capital[i]=-1;

        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            int diff=ch-'A';

            if(diff<26)
            {
                // entering first time --> store only leftmost occurence of CAPITAL letter
                if(capital[ch-'A'] == -1)
                    capital[ch-'A']=i;
            }
            else
                // store rightmose occurence of SMALL letters
                small[ch-'a']=i;
        }

        for(int i=0;i<26;i++)
        {
            // if both small & capital letters appears in the array
            if(small[i]!=-1 && capital[i]!=-1)
            {
                // small ones appear first than capitals
                if(small[i]<capital[i])
                    ans++;
            }
        }

        return ans;
    }
};