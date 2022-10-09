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
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        sort(v.begin(), v.end());
        for (decltype(v.size()) i = 0; i != v.size() - 1; i++) {
            for (decltype(v.size()) j = i + 1; j != v.size(); j++) {
                if (v[i] + v[j] == k)
                    return true;
            }    
        }
        return false;
    }
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
