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
        if (v.empty()) return;
        auto itMax = max_element(v.cbegin(), v.cend());
        int max = *max_element(v.cbegin(), v.cend());
        root = new TreeNode(max);
        create(root->left, {v.cbegin(), itMax});
        create(root->right,{itMax + 1, v.cend()});
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        create(head, nums);            
        return head;
    }
private:
    TreeNode *head = nullptr;
};

int main() {
  
  
  return 0;  
}
