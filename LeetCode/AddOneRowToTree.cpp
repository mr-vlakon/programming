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
    void traverse(TreeNode * &root, int i) {
        if (root == nullptr) {
            return;
        }
        if (i == dep) {
            TreeNode* lf = new TreeNode(value, root->left, nullptr);
            TreeNode* rg = new TreeNode(value, nullptr, root->right);
            root->left = lf;
            root->right = rg;            
        }
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        value = val;
        if (depth == 1) {
            TreeNode *new_root = new TreeNode(value,  root, nullptr);
            return new_root;
        }        
        dep = depth;
        traverse(root, 2);
        return root;
    }
private:
    int value = 0;
    int dep = 0;
};

int main() {
  
  return 0;  
}
