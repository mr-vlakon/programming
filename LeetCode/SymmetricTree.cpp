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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (q == nullptr || p == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(q->right, p->left) && isSameTree(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);        
    }
};

int main() {
  
  return 0; 
}
