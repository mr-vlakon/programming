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
    void count(TreeNode *&root) {
        if (root == nullptr) return;
        ++cnt;
        count(root->left);
        count(root->right);
    }

    void func(int &t) {
        visited[t] = true;
        if (t == dest) {
            ans = answer;
            return;
        }
        if (ans.size() != 0) return;
        for (auto &e: um[t]) {
            if (!visited[e.first]) {
                visited[e.first] = true;
                answer.push_back(e.second);
                func(e.first);
                answer.pop_back();        
            }
        }    
    }

    void traverseTo(TreeNode * &root, const int &destValue) {
        if (root == nullptr) return;
        if (root->left) {
            um[root->val].push_back({root->left->val, 'L'});
        }
        if (root->right) {
            um[root->val].push_back({root->right->val, 'R'});
        }
        traverseTo(root->left, destValue);
        traverseTo(root->right, destValue);
    }
    
    void traverseFrom(TreeNode * &root, const int &startValue) {
        if (root == nullptr) return;
        if (root->left) {
            um[root->left->val].push_back({root->val, 'U'});
        }
        if (root->right) {
            um[root->right->val].push_back({root->val, 'U'});
        }
        traverseFrom(root->left, startValue);
        traverseFrom(root->right, startValue);
    }
    

    string getDirections(TreeNode* root, int startValue, int destValue) {
        count(root);
        um.resize(cnt + 1);
        traverseTo(root, destValue);
        traverseFrom(root, startValue);
        dest = destValue;
        visited.resize(cnt + 1, false);
        func(startValue);
        return ans;
    }
private:
    int dest;
    string ans;
    int cnt = 0;
    vector<int> visited;
    string answer;
    vector<vector<pair<int, char>>>  um;
};

int main() {
  
  
  
  return 0;  
}
