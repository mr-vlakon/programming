class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char top;
        for (int i = 0; i != s.size(); ++i) {
            if (!st.empty() && s[i] == 'c') {
                top = st.top();
                if (top != 'b') return false;
                st.pop();
                st.pop();
            } else {
                if (s[i] == 'b' && (st.empty() || st.top() != 'a')) return false;
                st.push(s[i]);
            }
        }
        return st.size() == 0;
    }
};

int main() {
  
  
  return 0;  
}
