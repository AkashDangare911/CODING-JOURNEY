class Solution {
    public List<Integer> lexicalOrder(int n) {
        
        List<Integer> ans = new LinkedList<>();
        for(int j=1; j<=9;j++){
            if(j<=n) fun(j, n, ans);
        }
        
    
        return ans;

    }

    static void fun(int i, int n,  List<Integer> ans){
        ans.add(i);

        for (int j = 0; j <= 9 ; j++) {
            int num = i * 10 + j;
            if(num<=n) fun(num, n, ans);
        }
    }
}