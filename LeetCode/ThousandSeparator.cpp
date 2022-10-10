class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        if (s.size() <= 3) return s;
        reverse(s.begin(), s.end());
        auto it = s.insert(s.begin() + 3, '.');
        ++it;
        while (it != s.cend()) {
            if (s.end() - it <= 3) break;
            it = s.insert(it + 3, '.');
            ++it;
            
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
  
  
  return 0; 
}
