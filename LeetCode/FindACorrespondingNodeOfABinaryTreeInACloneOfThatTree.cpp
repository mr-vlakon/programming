/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    
    void traversalOr(TreeNode * &root) {
        if (root == nullptr) return;
        if (root == trg) {
            targetVal = root->val;
            return;
        }
        traversalOr(root->left);
        traversalOr(root->right);
    }
    
    void traversalCl(TreeNode * &root) {
        if (root == nullptr) return ;
        if (root->val == targetVal) {
            answer = root;
            return;
        }
        traversalCl(root->left);
        traversalCl(root->right);
        
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        trg = target;
        traversalOr(original);
        traversalCl(cloned);
        return answer;
    }
private:
    TreeNode * trg = nullptr;
    int targetVal = 0;
    TreeNode * answer = nullptr;
};

int main() {
  
  return 0;  
}
