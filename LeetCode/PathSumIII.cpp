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
    void sum(TreeNode * &root, long long s = -100000) {
        if (s == target) {
            ++cnt;
        }  
        if (root == nullptr) return ;
        if (s == -100000) {
            s = 0;
        }
        s += root->val;
        sum(root->left, s);
        sum(root->right, s);
    }
    void traverse(TreeNode * &root) {
        if (root == nullptr) {
            return;
        }
        sum(root);
        traverse(root->left);
        traverse(root->right);
    }
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverse(root);
        return cnt / 2;
    }
private:
    int cnt = 0;
    int target = 0;
};

int main() {
  
  
  
  return 0;  
}
