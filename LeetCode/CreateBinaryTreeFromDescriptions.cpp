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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, bool>>> neigh;
        for (const auto &e: descriptions) {
            neigh[e[0]].push_back({e[1], e[2]});
        }
        unordered_map<int, int> um;
        for (const auto &e: descriptions) {
            um[e[1]]++;
        }
        int rootV = 0;
        for (const auto &e: descriptions) {
            if (um[e[0]] == 0) {
                rootV = e[0];
                break;
            }
        }
        TreeNode *head = new TreeNode(rootV);
        queue<pair<int, TreeNode *>> q;
        q.push({rootV, head});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (const auto &e: neigh[top.first]) {
                TreeNode *t;
                if (e.second == 0) {
                    top.second->right = new TreeNode(e.first);
                    t = top.second->right;
                } else {
                    top.second->left = new TreeNode(e.first);
                    t = top.second->left;
                }
                q.push({e.first, t});
            }
        }
        return head;
    }
};

int main()
{


  return 0;
}  
