class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int rem = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (st.size() != 0 && st.top().first == s[i]) {
                rem = st.top().second;
                st.pop();
                st.push({s[i], rem + 1});
            } else {
                st.push({s[i], 1});
            }
            if (st.size() != 0 && s[i] == st.top().first && st.top().second == k) {
                st.pop();
            }
        }
        string result;
        while(!st.empty()) {
            result += string(st.top().second, st.top().first);
            st.pop();
        }
        return {result.rbegin(), result.rend()};   
    }
};

int main() {
  
  
  
  return 0;  
}
