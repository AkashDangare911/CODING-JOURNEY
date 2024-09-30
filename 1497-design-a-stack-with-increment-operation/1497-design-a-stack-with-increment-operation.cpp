class CustomStack {
public:
    int *arr;
    int ind,mx;
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        ind=-1;
        mx=maxSize;
    }
    
    void push(int x) {
        if(ind==mx){
            arr[ind]=x;
            ind++;
        }

        if(ind+1<mx){
            ind++;
            arr[ind]=x;
        }
    }
    
    int pop() {
        if(ind<0){
            return -1;
        }

        if(ind>=mx)
            ind--;

        return arr[ind--];
    }
    
    void increment(int k, int val) {
        int i=0;
        while(i<min(mx,k)){
            arr[i]+=val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */