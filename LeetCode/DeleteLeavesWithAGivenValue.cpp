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
        if (root->left == nullptr && root->right == nullptr && root->val == targ) {
            ++cnt;
            root = nullptr;
            return;
        }
        traverse(root->left);
        traverse(root->right);
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        targ = target;
        traverse(root);
        cnt = 0;
        do {
            cnt = 0;
            traverse(root);
        } while(cnt != 0);
        return root;
    }
private:
    int cnt = 0;
    int targ = 0;
};

int main() {
  
  return 0;  
}
