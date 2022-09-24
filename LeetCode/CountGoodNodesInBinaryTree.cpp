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
    void traverse(TreeNode *root, int max) {
        if (root == nullptr) return;
        if (root->val >= max) {
            max = root->val;
            ++cnt;
        }
        traverse(root->left, max);
        traverse(root->right, max);
    }
    
    int goodNodes(TreeNode* root) {
        traverse(root->left, root->val);
        traverse(root->right, root->val);
        return cnt;
    }
private:
    int cnt = 1;
};

int main() {
  
  
  return 0;  
}
