class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        st.push('/');
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '.' && (!st.empty() && st.top() != '/')) {
                while (path[i] == '.') {
                    st.push('.');
                    ++i;
                }
                if (i < path.size()) {
                    st.push(path[i]);
                }
            } else if (path[i] == '.' && path[i + 1] == '.' && ( (i + 2) >= path.size() || path[i + 2] == '/')) {
                st.pop();
                while (!st.empty() && st.top() != '/') {
                    st.pop();
                }
                while (!st.empty() && st.size() != 1 && st.top() == '/') {
                    st.pop();
                }    
                ++i;
            } else if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '.' && ( (i + 3) >= path.size() || path[i + 3] == '/')) {
                st.push('.');
                st.push('.');
                st.push('.');
                i += 2;
            } else if (path[i] == '.' && ((i + 1) >= path.size() ||  path[i + 1] == '/')) {
                if (!st.empty())
                    st.pop();
            } else {
                if (!(path[i] == '/' && !st.empty() && st.top() == '/')) {
                    st.push(path[i]);
                }
            }
        }
        while (!st.empty() && st.top() == '/') {
            st.pop();
        }
        string answer;
        if (st.empty()) {
            answer.push_back('/');
        }
        while (!st.empty()) {
            if (st.top() == '/') {
                while (!st.empty() && st.top() == '/') {
                    st.pop();
                }
                answer.push_back('/');
            } else {
                answer.push_back(st.top());
                st.pop();
            }
        }    
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
