class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans = -1;
        int n=chalk.size();

        if(chalk[0] > k){
            return 0;
        }

        // find pref sum and if k exhaust, then  return ans index
       for(int i=1;i<n;i++){
        chalk[i]=chalk[i-1]+chalk[i];
        if(chalk[i] > k){
            return i;
        }
       }

        // get count of final rotation
        int remain = k%chalk[n-1];

        for(int i=0;i<n;i++){
            if(remain < chalk[i]){
                return i;
            }
        }

        return 0;
    }
};