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
    int average(TreeNode * &root, int &cnt) {
        if (root == nullptr) return 0;
        cnt++;
        return root->val + average(root->left, cnt) + average(root->right, cnt);
    }
    
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        int cnt = 0;
        int sum = average(root, cnt);
        int avg = sum / cnt;
        if (root->val == avg) ++res;
        traverse(root->left);
        traverse(root->right);
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return res;
    }
    
private:
    int res = 0;
};

int main() {
  
  
  return 0;  
}
