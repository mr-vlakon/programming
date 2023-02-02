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
    int amountOfTime(TreeNode* root, int start) {
        traversal(root);
        unordered_map<int, unordered_set<int>> um;
        for (const auto &e: v) {
            um[e[0]].insert(e[1]);
            um[e[1]].insert(e[0]);
        }
        queue<pair<int, int>> q;
        unordered_set<int> us;
        for (const auto &e: um[start]) {
            if (e != start)
                q.push({e, 1});
        }
        int answer = 0;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            answer = top.second;
            us.insert(top.first);                  
            for (const auto &e: um[top.first]) {
                if ((us.find(e) == us.cend()) && (e != start)) {    
                    us.insert(e);
                    q.push({e, top.second + 1});
                }
            }
        }
        return answer; 
    }
private:
    vector<vector<int>> v;
};

int main() {
  
  
  
  return 0;  
}
