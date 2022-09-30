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
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root);
        sort(v.begin(), v.end());
        auto beg = find_if(v.cbegin(), v.cend(), [=] (const int &x) {
            return x >= low;
        });
        auto end = find_if(v.cbegin(), v.cend(), [=] (const int &x) {
            return x > high;
        });

        return accumulate(beg, end, 0);        
    }
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
