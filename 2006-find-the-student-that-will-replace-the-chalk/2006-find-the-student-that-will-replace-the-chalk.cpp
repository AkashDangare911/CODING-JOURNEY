class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans = -1;
        int n=chalk.size();
        vector<int> prefixSum(n,0);
        prefixSum[0]=chalk[0];

        if(prefixSum[0] > k){
            return 0;
        }
        // find pref sum and if k exhaust, then  return ans index
       for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+chalk[i];
        if(prefixSum[i] > k){
            return i;
        }
       }

        // get count of final rotation
        int remain = k%prefixSum[n-1];

        for(int i=0;i<n;i++){
            if(remain < prefixSum[i]){
                return i;
            }
        }

        return 0;
    }
};