class Solution {
public:
    bool isCapital(const char &c) {
        return (c >= 'A') && (c <= 'Z');
    }
    string countOfAtoms(string formula) {
        unordered_map<string, int> um;
        stack<pair<string, int> > st;
        int rem = 0;
        string tmp;
        pair<string, int> q;
        stack<pair<string, int>> temp;
        size_t pos = 0;
        int x = 0;
        for (int i = 0; i != formula.size();) {
            rem = i + 1;
            tmp.resize(0);
            if (formula[i] != ')' && formula[i] != '(') {
                tmp.push_back(formula[i]);
                while (rem < formula.size() && !isCapital(formula[rem]) && formula[rem] != '(' && formula[rem] != ')') {
                    tmp.push_back(formula[rem]);
                    ++rem;
                }
                pos = tmp.find_first_of("0123456789");
                if (pos != string::npos) {
                    string substr1{tmp.cbegin() + pos, tmp.cend()};
                    string substr2{tmp.cbegin(), tmp.cbegin() + pos};
                    st.push({substr2, stoi(substr1)});
                } else {
                    st.push({tmp, 1});
                }
                i = rem;
            } else if (formula[i] == '(') {
                st.push({"(", 0});
                ++i;
            } else if (formula[i] == ')') {
                rem = i + 1;                
                while (rem < formula.size() && isdigit(formula[rem])) {
                    tmp.push_back(formula[rem]);
                    ++rem;
                }
                x = (tmp.size() != 0) ? stoi(tmp) : 1;
                i = rem;
                while (!st.empty() && st.top().first != "(") {
                    q = st.top();
                    q.second *= x;
                    temp.push(q);
                    st.pop();
                }
                if (st.top().first == "(") {
                    st.pop();
                }
                while (!temp.empty()) {
                    st.push(temp.top());
                    temp.pop();
                }
            }
        }
        while (!st.empty()) {
            um[st.top().first] += st.top().second;
            st.pop();
        }
        vector<pair<string, int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
            
        }
        sort(v.begin(), v.end(), [](pair<string, int> &lhs, pair<string, int> &rhs) {
            return lhs.first < rhs.first;
        });
        string answer;
        for (const auto &e: v) {
            if (e.second != 1) {
                answer += e.first + to_string(e.second);
            } else {
                answer += e.first;
            }
        }
        return answer;
  }
};

int main() {
  
  
  
  
  return 0;  
}
