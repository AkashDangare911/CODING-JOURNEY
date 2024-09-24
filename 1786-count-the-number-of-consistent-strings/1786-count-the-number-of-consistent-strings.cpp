class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26]={0}, ans=0;
        for(char c:allowed)
            arr[c-'a']++;

        for(string word: words){
            for(char c: word){
                if(arr[c-'a'] == 0){
                    ans++;
                    break;
                }
            }
        }

        return words.size() - ans;
    }
};