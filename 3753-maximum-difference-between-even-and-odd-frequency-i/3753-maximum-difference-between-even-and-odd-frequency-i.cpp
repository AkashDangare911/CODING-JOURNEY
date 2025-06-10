class Solution {
public:
    int maxDifference(string s) {
        int freq[26]={0};
        int odd=0,even=INT_MAX;

        for(char c:s)
            freq[c-'a']++;
        
        for(int i=0;i<26;i++)
        {
            // odd
            if(freq[i]&1)
                odd=max(odd,freq[i]);
                
            //freq not '0'
            else if(freq[i])    
                even=min(even,freq[i]);
        }

        return odd-even;
    }
};