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
class BSTIterator {
public:
    void trv(TreeNode *root) {
        if (root == nullptr) return;
        v.push_back(root->val);
        trv(root->left);
        trv(root->right);
    }
    
    BSTIterator(TreeNode* root) : head(root) {
        trv(root);
        sort(v.begin(), v.end());
        it = v.begin();
    }
    
    int next() {
        return *it++;
    }
    
    bool hasNext() {
        return it != v.cend() ? true : false;
    }
private:
    vector<int> v;
    vector<int>::iterator it;
    TreeNode *head = nullptr;    
};


int main() {
  
  
  return 0;  
}
