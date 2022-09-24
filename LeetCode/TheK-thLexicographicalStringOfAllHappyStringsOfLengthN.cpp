class Solution {
public:
    bool isHappy(const string &s) {
        for (decltype(s.size()) i = 0; i != s.size() - 1; ++i) {
            if (s[i] == s[i + 1])
                return false;
        }
        return true;
    }
    
    void generate(const string &prefix, int n, int k) {
        if (k == 0) {
            if (isHappy(prefix)) {
                v.push_back(prefix);
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            string newPrefix;
            newPrefix = prefix + set[i];
            generate(newPrefix, n, k - 1);
        }
    }
    string getHappyString(int n, int k) {
        generate("", 3, n);
        sort(v.begin(), v.end());
        if (k > v.size())
            return "";
        else
            return *(v.begin() + k - 1);
    }    
private:
    const vector<char> set = {'a', 'b', 'c'};
    vector<string> v;
};

int main() {
  
  
  return 0;  
}
