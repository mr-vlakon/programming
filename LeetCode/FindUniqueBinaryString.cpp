class Solution {
public:
void generate(char set[], string prefix,
                                    int n, int k) {
        if (k == 0)
        {
            if (st.find(prefix) == st.cend()) {
                v.push_back(prefix);
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            string newPrefix;
            newPrefix = prefix + set[i];
            generate(set, newPrefix, n, k - 1);
        } 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for (const auto &e: nums) {
            st.insert(e);
        }
        char set[2] = {'0', '1'};
        generate(set, "", 2, nums.size());
        return v.back();
    }
private:
    set<string> st;
    vector<string> v;
};

int main() {
  
  
  return 0;  
}
