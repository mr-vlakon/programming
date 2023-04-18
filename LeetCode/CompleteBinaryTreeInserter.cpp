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
/*
class CBTInserter {
public:
    CBTInserter(TreeNode* root) : root_(root) {
        
    }
    
    void firstInsert(TreeNode * &root, const int &val, int i) {
        if (status) return;
        if (root == nullptr) return;
        if (root->left == nullptr  && i < (dept - 1) && !status) {
            par = root->val;
            root->left = new TreeNode(val);
            status = true;
            return;
        } else if (root->right == nullptr && i < (dept - 1) && !status) {
            par = root->val;
            root->right = new TreeNode(val);
            status = true;
            return;
        }
        firstInsert(root->left, val, i + 1);
        firstInsert(root->right, val, i + 1);
    }
    
    void secondInsert(TreeNode * &root, const int &val, int i) {
        if (status) return;
        if (root == nullptr) return;
        if (root->left == nullptr && !status) {
            par = root->val;
            root->left = new TreeNode(val);
            status = true;
            return;
        } 
        secondInsert(root->left, val, i + 1);
        secondInsert(root->right, val, i + 1);
    }

    int depth(TreeNode * &root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    int insert(int val) {
        dept = depth(root_);
        status = false;
        par = 0;
        firstInsert(root_, val, 0);
        if (status == false) {
            secondInsert(root_, val, 0);
        }
        return par;
    }
    
    TreeNode* get_root() {
        return root_;
    }
private:
    int par = 0;
    int dept = 0;
    bool status = false;
    TreeNode *root_;
};
*/
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) : root_(root) {
        v.resize(depth(root), {});
        traverse(root, 0);
        t = pow(2, v.size() - 1);
    }
    
    void traverse(TreeNode * &root, int i) {
        if (root == nullptr) return;
        v[i].push_back(root);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    
    int insert(int val) {
        if (t > v.back().size()) {
            v[v.size() - 1].push_back(new TreeNode(val));
            temp = v.back().size() - 1;
            x = temp / 2;
            y = temp % 2;
            if (y == 0) {
                v[v.size() - 2][x]->left = v.back().back();
            } else {
                v[v.size() - 2][x]->right = v.back().back();
            }
            return v[v.size() - 2][x]->val;
        } else {
            t *= 2;
            v.push_back({new TreeNode(val)});
            v[v.size() - 2][0]->left = v.back()[0];
            return v[v.size() - 2][0]->val;
        }
    }
    
    TreeNode* get_root() {
        return root_;
    }
    
    int depth(TreeNode * &root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
private:
    vector<vector<TreeNode*>> v;
    int t = 0;
    int temp = 0;
    int x = 0;
    int y = 0;
    int level = 0;
    TreeNode *root_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

int main() {
  
  
  
  return 0;  
}
