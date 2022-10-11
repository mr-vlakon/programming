class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int cnt = 0;
        for (decltype(s.size()) i = 0; i <= s.size() - k; ++i) {
            string tmp(s.cbegin() + i, s.cbegin() + i + k);
            int x = stoi(tmp);
            if (x != 0) {
                if (num % x == 0)
                    ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
