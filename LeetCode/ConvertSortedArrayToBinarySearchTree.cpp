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
    void create(TreeNode * &root, vector<int> v) {
        if (v.size() == 0) return;
        root = new TreeNode(v[v.size()/2]);
        create(root->left,{v.cbegin(), v.cbegin() + v.size() /2});
        create(root->right,{v.cbegin() + v.size() /2 + 1, v.cend()});
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        create(hd, nums);
        return hd;
    }
private:
    TreeNode * hd = nullptr;
};

int main() {
  
  
  return 0;  
}
