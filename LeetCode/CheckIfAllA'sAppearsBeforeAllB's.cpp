class Solution {
public:
    bool checkString(string s) {
        if (s.size() == 0) return true;
        char prev = s[0];
        for(decltype(s.size()) i = 1; i != s.size(); ++i) {
            if (s[i] == 'a') {
                if (prev == 'b')
                    return false;
            }
            prev = s[i];
        }   
        return true;
    }
};

int main() {
  
  return 0;  
}
