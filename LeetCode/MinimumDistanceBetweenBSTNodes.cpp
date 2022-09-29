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
    
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        sort(v.begin(), v.end());
        int min = 1000000000;
        for (decltype(v.size()) i = 0; i != v.size() - 1; ++i) {
            if (abs(v[i] - v[i + 1]) < min)
                min = abs(v[i] - v[i + 1]);
            if (min == 0)
                return 0;
        }
        
        return min;
        
    }
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
