/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void height(Node *root, int i) {
        if (root == nullptr) return;
        if (root->children.size() == 0) {
            hght.push_back(i);
            return;
        }
        for (auto e: root->children) {
            height(e, i + 1);
        }
    }
    
    void trv(Node *root, int i) {
        vector<int> v;
        if (root == nullptr) return;
        if (root->children.size() == 0) {
            return;
        }
        for (const auto &e: root->children) {
            v.push_back(e->val);
        }
        if (v.size() != 0) {
            for (const auto &e: v)
                result[i].push_back(e);
        }
        for (const auto &e: root->children) {
            trv(e, i + 1);
        }
        
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        int i = 0;
        height(root, i);
        int max = *max_element(hght.cbegin(), hght.cend());
        result.resize(max);
        trv(root, 0);
        deque<vector<int>> res(result.cbegin(), result.cend());
        res.push_front({root->val});
        vector<vector<int>> tmp(res.cbegin(), res.cend());
        return tmp;
    }
private:
    vector<int> hght;
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
