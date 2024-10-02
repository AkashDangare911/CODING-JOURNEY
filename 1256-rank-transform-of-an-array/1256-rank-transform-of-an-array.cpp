class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0)
            return {};
        
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int rank=1;
        mp[temp[0]]=rank;
        rank++;

        for(int i=1;i<n;i++){
            while(i<n && temp[i]==temp[i-1]){
                i++;
            }
            if(i<n){

            mp[temp[i]]=rank;
            rank++;
            }
        }

        for(int i=0;i<n;i++){
            arr[i]=mp[arr[i]];
        }

        return arr;
    }
};