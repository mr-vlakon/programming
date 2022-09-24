class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(), s.end());
        int steps = 0;
        while (true) {
            if (count(s.cbegin(), s.cend(), '1') == 1 && s[0] == '1') break;
            ++steps;
            if (s[0] == '1') {
                s[0] = '0';
                int perenos = 1;
                for(decltype(s.size()) i = 1; i != s.size(); ++i) {
                    if (perenos == 1) {
                        if (s[i] == '0') {
                            s[i] = '1';
                            perenos = 0;
                        } else {
                            s[i] = '0';
                            perenos = 1;
                        }
                    }
                }
                if (perenos == 1) {
                    s.push_back('1');
                    perenos = 0;
                }
            } else {
                s.erase(s.cbegin());
            }
        }
        return steps;
    }
};

int main() {
  
  
  return 0;  
}
