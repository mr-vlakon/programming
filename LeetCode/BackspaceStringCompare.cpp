class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for (const auto &e: s) {
            if (e == '#' && st1.size() != 0) {
                st1.pop();
            } else if (e != '#'){
                st1.push(e);
            }
        }
        stack<char> st2;
        for (const auto &e: t) {
            if (e == '#' && st2.size() != 0) {
                st2.pop();
            } else if (e != '#'){
                st2.push(e);
            }
        }
        return st1 == st2;

    }
};

int main() {
  
  
  
  return 0;  
}
