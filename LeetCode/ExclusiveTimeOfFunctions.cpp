class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>> st;
        vector<int> answer(n, 0);
        size_t pos = 0;
        int id;
        char type;
        int time = 0;
        size_t prev = 0;
        pair<int, int> top;
        for (int i = 0; i != logs.size(); ++i) {
            pos = logs[i].find(':', 0);
            prev = pos + 1;
            id = stoi(string{logs[i].cbegin(), logs[i].cbegin() + pos});
            pos = logs[i].find(':', prev);
            if (logs[i][prev] == 's') {
                type = 's';
            } else {
                type = 'e';
            }
            prev = pos + 1;
            time = stoi(string{logs[i].cbegin() + prev, logs[i].cend()});
            if (type == 's') {
                if (!st.empty()) { 
                    answer[st.top().first] += time - st.top().second;
                }
                st.push({id, time}); 
            } else {
                answer[id] += time - st.top().second + 1;
                st.pop();
                if (!st.empty()) {
                    top = st.top();
                    st.pop();
                    st.push({top.first, time + 1});
                }
            }
        }
        return answer;
    }
};
/*
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>> st;
        vector<int> answer(n, 0);
        size_t pos = 0;
        int id;
        string type;
        int time = 0;
        size_t prev = 0;
        pair<int, int> top;
        for (int i = 0; i != logs.size(); ++i) {
            pos = logs[i].find(':', 0);
            prev = pos + 1;
            id = stoi(string{logs[i].cbegin(), logs[i].cbegin() + pos});
            pos = logs[i].find(':', prev);
            type = string{logs[i].cbegin() + prev, logs[i].cbegin() + pos};
            prev = pos + 1;
            time = stoi(string{logs[i].cbegin() + prev, logs[i].cend()});
            if (type == "start") {
                if (!st.empty()) { 
                    answer[st.top().first] += time - st.top().second;
                }
                st.push({id, time}); 
            } else {
                answer[id] += time - st.top().second + 1;
                st.pop();
                if (!st.empty()) {
                    top = st.top();
                    st.pop();
                    st.push({top.first, time + 1});
                }
            }
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  
  return 0;  
}
