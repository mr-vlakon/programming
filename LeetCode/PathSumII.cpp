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
    void traversal(TreeNode *root, vector<int> v, int sum) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            v.push_back(root->val);    
            if (sum == target)
                result.push_back(v);
            return;
        }
        v.push_back(root->val);
        sum += root->val;
        traversal(root->left, v, sum);
        traversal(root->right, v, sum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traversal(root, {}, 0);
        return result;
    }
private:
    int target = 0;
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
