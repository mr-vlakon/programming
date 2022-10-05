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
    
    void height(TreeNode * &root, int i) {
        if (root == nullptr) {
            if (i > maxH) {
                maxH = i;
            }
            return;
        }
        height(root->left, i + 1);
        height(root->right, i + 1);
    }
    
    bool trv(TreeNode *root) {
        if (root == nullptr) return true;
        height(root->left, 0);
        maxL = maxH;
        maxH = 0;
        height(root->right, 0);
        maxR = maxH;
        maxH = 0;
        if (abs(maxR - maxL) > 1) return false;
        
        return trv(root->left) && trv(root->right);
        
    }

    
    bool isBalanced(TreeNode* root) {
        return trv(root);
    }
private:
    int maxH = 0;
    int maxL = 0;
    int maxR = 0;
    
};

int main() {
  
  return 0;  
}
