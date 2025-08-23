class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTime=0;
        int freq[26]={};
        priority_queue<int> pq;

        // count freq of each task
        for(char c:tasks)
            freq[c-'A']++;

        // put frequencies in the heap
        for(int num: freq)
            if(num) pq.push(num);
        
        while(!pq.empty())
        {
            vector<int> temp;
            int completed=0;
            int cycle=n+1;

            // execute cycle of n+1 tasks
            while(cycle && !pq.empty())     // .....step 1
            {
                // if more tasks are available of same type, (avoid pushing 0)
                // keep them aside to put back them in heap later
                if(pq.top()>1)
                    temp.push_back(pq.top()-1);
                
                pq.pop();
                totalTime++;
                cycle--;
            }

            // put back extra same type task in heap
            for(int i:temp)
                pq.push(i);

            // it will hit if there are less than 'n' types of tasks to schedule as per step 1
            // so in that case, we have to keep slots idle
            if(!pq.empty())
                totalTime+=cycle;
        }

        return totalTime;
    }
};