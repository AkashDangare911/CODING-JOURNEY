class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        if(sentence1==sentence2)return true;
        string small,big;
        if(sentence1.size()<sentence2.size()){
            small=sentence1;
            big=sentence2;
        }
        else{
            small=sentence2;
            big=sentence1;
        }

        int s=0,es=small.size()-1,eb=big.size()-1;
        while(s<small.size()&&big[s]==small[s]){
            s++;
        }
        while(s<small.size()&&(s>=0&&small[s]!=' '))s--;
        if(s==small.size()||(s>=0&&small[s]==' '))s--;
        
        while(es>s&&big[eb]==small[es]){
            eb--;
            es--;
        }
        // if(e!=-1)e++;
        cout<<s<<" "<<es<<endl;
        if(s==es&&(big[s+1]==' '||big[big.size()-small.size()-1]==' '))return true;
        return false;
    }
};