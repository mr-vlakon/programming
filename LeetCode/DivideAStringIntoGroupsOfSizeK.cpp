class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        for (decltype(s.size()) i = 0; i < s.size(); i += k) {
            if (s.cbegin() + i + k > s.cend())
                v.push_back(string{s.cbegin() + i, s.cend()});
            else
                v.push_back(string{s.cbegin() + i, s.cbegin() + i + k});
        }
        while (v.back().size() < k) {
            v.back().push_back(fill);
        }
        return v;
    }
};

int main() {
  
  
  
  return 0;  
}
