class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={};
        int maxFreq=0;

        // build freq map & find max freq
        for(char c: tasks)
        {
            freq[c-'A']++;
            maxFreq = max(maxFreq,freq[c-'A']);
        }

        // find elements with freq = maxFreq
        int eleWithMaxFreq=0;
        for(int i: freq)
        {
            if(i==maxFreq)
                eleWithMaxFreq++;
        }

        // now, spread the element with maxFreq with gap of 'n' in between
        
        // we have maxFreq-1 slots of length n+1, A _ _ A _ _ A ==> 2*2
        int slotLength = (maxFreq-1)*(n+1); 

        // as eleWithMaxFreq will be appended after last element (after _ _ A)
        int finalLength = slotLength+eleWithMaxFreq;

        // if we have less to put in empty slots, finalLength would accomodate all elements,
        //  including empty slots
        // OR if we have plenty elements than empty slots, our CPU would not be idle anymore
        // and we have to return the length of tasks as ans

        int ans = max(finalLength,(int)tasks.size());
        return ans;
    }
};