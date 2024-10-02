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

        for(int i=0;i<n;i++){
            while(i+1<n && temp[i]==temp[i+1]){
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