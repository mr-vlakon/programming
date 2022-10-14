class Solution {
public:
    void generate(int index = -1, vector<int> curr = {}) {
        if (index == v.size())
            return; 
        if (!curr.empty()) {
            res.push_back(curr);
        }
        for (int i = index + 1; i < v.size(); i++) {
            curr.push_back(v[i]);
            generate( i, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        v = nums;
        res.resize(1);
        generate();
        return res;
    }
private:
    vector<int> v;
    vector<vector<int>> res;
};

int main() {
  
  
  return 0;  
}
