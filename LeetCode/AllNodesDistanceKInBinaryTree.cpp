/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void traversal(TreeNode *&root) {
        if (root == nullptr) return;
        if (root->left) {
            v.push_back({root->val, root->left->val});
        }
        if (root->right) {
            v.push_back({root->val, root->right->val});   
        }
        traversal(root->left);
        traversal(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) {
            return {target->val};
        }
        traversal(root);
        unordered_map<int, unordered_set<int>> um;
        for (const auto &e: v) {
            um[e[0]].insert(e[1]);
            um[e[1]].insert(e[0]);
        }
        queue<pair<int, int>> q;
        unordered_set<int> us;
        for (const auto &e: um[target->val]) {
            if (k == 1) {
                result.push_back(e);
            }
            if (e != target->val)
                q.push({e, 1});
        }
        unordered_set<int> search;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            for (const auto &e: um[top.first]) {
                if ((us.find(e) == us.cend()) && (e != target->val) && (search.find(e) == search.cend())) {    
                    if (((top.second + 1) == k) ) { 
                        result.push_back(e);
                    }
                    us.insert(e);
                    search.insert(e);
                    q.push({e, top.second + 1});
                }
            }
            search.insert(top.first);
        }
        return result; 
    }
private:
    vector<vector<int>> v;
    vector<int> result;
};

int main() {
  
  
  return 0;  
}
