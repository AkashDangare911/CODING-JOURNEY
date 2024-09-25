class Solution {
    
class Trie {
     Trie[] arr;
     int count;

     Trie() {
        arr = new Trie[26]; // Array for 26 lowercase letters
        count = 0;
    }
}
    public int[] sumPrefixScores(String[] words) {
         Trie root = new Trie();

        // Inserting words into the Trie
        for (String word : words) {
            Trie cur = root;
            for (char c : word.toCharArray()) {
                int ind = c - 'a';

                if (cur.arr[ind] == null) {
                    cur.arr[ind] = new Trie();
                }
                cur = cur.arr[ind];
                cur.count++;
            }
        }

        // Calculating prefix scores
        int ans[] = new int[words.length];
        int i =0;
        for (String word : words) {
            Trie cur = root;
            int cnt = 0;
            for (char c : word.toCharArray()) {
                int ind = c - 'a';
                cur = cur.arr[ind];
                cnt += cur.count;
            }
            ans[i++] = cnt;
        }

        return ans;
    }
}