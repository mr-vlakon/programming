class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == '*' && st.size() != 0) {
                st.pop();
            } else if (s[i] != '*') {
                st.push(s[i]);
            }
        }
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return {result.rbegin(), result.rend()};
    }
};

int main() {
  
  
  return 0;  
}
