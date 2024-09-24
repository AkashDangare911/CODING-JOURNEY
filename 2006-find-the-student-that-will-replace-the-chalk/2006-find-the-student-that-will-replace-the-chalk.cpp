class Solution {
private:
    int getIndexOfStudent(vector<int> chalk,int remain){
        int l=0,r=chalk.size()-1;
        int mid;
        // 3 7 8 10
        while(l<r)
        {
            mid = (l+r)/2;
            int ele = chalk[mid];

            if(ele <= remain){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
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
        if(remain == 0){
            return 0;
        }

        return getIndexOfStudent(chalk,remain);
    }
};