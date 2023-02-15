class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i != s.size(); ++i) {
            if (st.size() != 0 && s[i] == st.top()) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
