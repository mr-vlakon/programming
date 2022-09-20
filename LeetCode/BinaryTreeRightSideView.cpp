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
    void deapth(TreeNode* &root, int i) {
        if (root == nullptr) {
            dep.push_back(i);
            return;
        }
        deapth(root->left, i + 1);
        deapth(root->right, i + 1);
    }
    
    void trv(TreeNode* &root, int i) {
        if (root == nullptr) return;
        result[i].push_back(root->val);
        trv(root->left, i + 1);
        trv(root->right, i + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        deapth(root, 0);
        int max = *max_element(dep.cbegin(), dep.cend());
        result.resize(max);
        trv(root, 0);
        vector<int> res;
        for (const auto &e: result) {
            res.push_back(e.back());
        }
        return res;
    }
private:
    vector<int> dep;
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
