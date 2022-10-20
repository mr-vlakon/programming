class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> v;
        unordered_map<string, size_t> um;
        for (const auto &e: arr) {
            ++um[e];
        }
        for (const auto &e: arr) {
            auto it = um.find(e);
            if (it->second == 1) {
                v.push_back(e);
            }
        }
        if (k - 1 < v.size())
            return v[k - 1];
        else
            return "";
        
    }
};

int main() {
  
  
  return 0;  
}
