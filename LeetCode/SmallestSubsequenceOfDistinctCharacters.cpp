class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> v(26, 0);
        for (const auto &e: s) {
            v[e - 'a']++;
        }
        stack<char> st;
        st.push(s[0]);
        vector<bool> vis(26, 0);        
        v[s[0] - 'a']--;
        vis[s[0] - 'a'] = true;
        char top;
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] < st.top()) {
                while (!st.empty() && s[i] < st.top() && v[st.top() - 'a'] >= 1 && vis[s[i] - 'a'] == false) {
                    top = st.top();
                    vis[top - 'a'] = false;
                    st.pop();
                } 
            }   
            if (vis[s[i] - 'a'] == false) {
                vis[s[i] - 'a'] = true;
                st.push(s[i]);
            }
            v[s[i] - 'a']--;
        }
        string str(st.size(), ' ');
        int pos = str.size() - 1;
        while (!st.empty()) {
            str[pos] = st.top();
            --pos;
            st.pop();
        }
        return str;
    }
};
/*
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> v(26, 0);
        for (const auto &e: s) {
            v[e - 'a']++;
        }
        stack<char> st;
        st.push(s[0]);
        vector<bool> vis(26, 0);        
        v[s[0] - 'a']--;
        vis[s[0] - 'a'] = true;
        char top;
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] < st.top()) {
                while (!st.empty() && s[i] < st.top() && v[st.top() - 'a'] >= 1 && vis[s[i] - 'a'] == false) {
                    top = st.top();
                    vis[top - 'a'] = false;
                    st.pop();
                } 
                if (vis[s[i] - 'a'] == false) {
                    vis[s[i] - 'a'] = true;
                    st.push(s[i]);
                }
            } else {
                if (vis[s[i] - 'a'] == false) {
                    vis[s[i] - 'a'] = true;
                    st.push(s[i]);
                }
            }
            v[s[i] - 'a']--;
        }
        string str(st.size(), ' ');
        int pos = str.size() - 1;
        while (!st.empty()) {
            str[pos] = st.top();
            --pos;
            st.pop();
        }
        return str;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
