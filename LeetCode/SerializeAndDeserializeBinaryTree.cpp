/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void height(TreeNode *root, int i) {
        if (root == nullptr) {
            v.push_back(i);
            return;
        }
        height(root->left, i + 1);
        height(root->right, i + 1);
    }
    
    void trv(TreeNode *root, int i) {
        if (root == nullptr) {
            if (i < size) {
                rty[i].push_back("null");
            }
            return;
        }
        rty[i].push_back(to_string(root->val));
        trv(root->left, i + 1);
        trv(root->right, i + 1);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        height(root, 0);
        size = *max_element(v.cbegin(), v.cend());
        rty.resize(size);
        result += '[';
        trv(root, 0);
        vector<string> qwerty;
        for (const auto &e: rty) {
            for (const auto &p : e) {
                qwerty.push_back(p);
            }
        }
        reverse(qwerty.begin(), qwerty.end());
        auto it = find_if(qwerty.cbegin(), qwerty.cend(), [=] (const string &x) {
            return x != "null";    
        });
        
        if (it != qwerty.cbegin()) {
            qwerty.erase(qwerty.cbegin(), it);
        }
        reverse(qwerty.begin(), qwerty.end());
        for (const auto &e: qwerty) {
                result += e + ",";
        }
        result.erase(--result.cend());
        result += ']';
        return result;
    }
    
    void create(TreeNode * rt, int i) {
        if (rt == nullptr) return;
        
        if (i >= deser.size()) return;
 
        if (deser[i].first == -10000) {
            rt->left = nullptr;
        } else {
            rt->left = new TreeNode(deser[i].first);
        }
        
        if (i + 1 >= deser.size()) return;
        
        if (deser[i + 1].first == -10000) {
            rt->right = nullptr;
        } else {
            rt->right = new TreeNode(deser[i + 1].first);
        }
        
        if (rt->left == nullptr && rt->right == nullptr) return;
        
        if (rt->left != nullptr && rt->right != nullptr) {
            create(rt->left, i + deser[i].second + 1);
            create(rt->right, i + deser[i + 1].second + 2);
        } else {
            if (rt->left != nullptr) {
                create(rt->left, i + deser[i].second + 1);
            }
            if (rt->right != nullptr) {
                create(rt->right, i + deser[i + 1].second + 2);
            }
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        data.erase(data.cbegin());
        auto it = data.begin();
        auto prev = it;
        int k = 0;
        bool status = true;
        while (it != data.cend()) {
            prev = it;
            it = find(it, data.end(), ',');
            if (it == data.cend()) {
                it = find(prev, data.end(), ']');
            }
            string tmp({prev, it});
            if (tmp == "null") {
                k = k - 1;
                deser.push_back({-10000, k});
            } else {
                if (status) {
                    deser.push_back({stoi(tmp), 0});
                    status = false;
                } else
                    deser.push_back({stoi(tmp), ++k});
            }
            ++it;
        }
        root = new TreeNode(deser[0].first);
        create(root, 1);
        return root;
    }
private:
    TreeNode *root = nullptr;
    
    vector<vector<string>> rty;
    vector<pair<int, int>> deser;
    
    int size = 0;
    
    vector<int> v;
    
    string result;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
  
  
  return 0;  
}
