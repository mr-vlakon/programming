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

    void traverse(TreeNode *root) {
        if (root == nullptr) return;
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        traverse(root);      
        vector<int> nums(v);
        nums.push_back(val);
        create(head, nums);            
        return head;
    }
private:
    vector<int> v;
    TreeNode *head = nullptr;
};

int main() {
  
  
  return 0;  
}
