class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(decltype(v.size()) i = 1; i != n + 1; ++i) {
            v.push_back(i);
        }
        size_t index = 1;
        string result;
        do {
            if (index == k) {
                for (const auto &j : v) {
                    result += to_string(j);
                }
                return result;
            }
            ++index;
        } while(next_permutation(v.begin(), v.end()));
        return "";
    }
};

int main() {
  
  return 0;  
}
