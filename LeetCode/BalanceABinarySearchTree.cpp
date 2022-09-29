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
    void traversal(TreeNode *root) {
        if (root == nullptr) return;
        traversal(root->left);
        v.push_back(root->val);
        traversal(root->right);
    }
    
    void construct(TreeNode * &root, vector<int> nums) {
        if (nums.size() == 0) return;
        root = new TreeNode(nums[nums.size()/2]);
        construct(root->left, {nums.cbegin(), nums.cbegin() + nums.size()/2});
        construct(root->right, {nums.cbegin() + nums.size()/2 + 1, nums.cend()});
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        traversal(root);
        sort(v.begin(), v.end());
        head = root;
        construct(head, v);
     
        return head;
    }
private:
    vector<int> v;
    TreeNode *head = nullptr;
};

int main() {
  
  
  return 0;  
}
