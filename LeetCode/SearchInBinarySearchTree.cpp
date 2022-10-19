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
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        if (root->val == val_) answer = root;
        traverse(root->left);
        traverse(root->right);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        val_ = val;
        traverse(root);
        return answer;
    }
private:
    int val_ = 0;
    TreeNode *answer = nullptr;
};

int main() {

  
  return 0;  
}
