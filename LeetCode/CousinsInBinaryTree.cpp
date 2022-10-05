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
    void traversal(TreeNode * root, int i, TreeNode * parent) {
        if (root == nullptr) return;
        if (root->val == xx) {
            xxTuple.first = i;
            xxTuple.second = parent; 
        }
        
        if (root->val == yy) {
            yyTuple.first = i;
            yyTuple.second = parent; 
        }
        
        traversal(root->left, i + 1, root);
        traversal(root->right, i + 1, root);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        xx = x;
        yy = y;
        traversal(root, 1, nullptr);
        return (xxTuple.first == yyTuple.first) && (xxTuple.second != yyTuple.second);
    }
private:
    pair<size_t, TreeNode*> xxTuple;
    pair<size_t, TreeNode*> yyTuple;
    int xx = 0;
    int yy = 0;
};

int main() {
  
  
  return 0;  
}
