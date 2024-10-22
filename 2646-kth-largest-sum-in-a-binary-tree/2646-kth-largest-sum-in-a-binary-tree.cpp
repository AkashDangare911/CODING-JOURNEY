/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        while(!q.empty())
        {
            int n = q.size();
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode *cur = q.front();
                q.pop();

                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
                sum+=cur->val;
            }

            level++;
            pq.push(sum);
            if(pq.size()>k)
                pq.pop();
        }

        return (k > level) ? -1 : pq.top();
    }
};