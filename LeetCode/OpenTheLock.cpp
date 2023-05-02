class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> us;
        for (const auto &e: deadends) {
            us.insert(e);
        }
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        string initial(target.size(), '0');
        q.push({initial, 0});
        int answer = INT_MAX;
        char prev;
        visited.insert(initial);
        pair<string, int> top;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            if (us.find(top.first) != us.cend()) {
                continue;
            }
            if (top.first == target) {
                answer = min(answer, top.second);
                break;
            } 
            for (int i = 0; i != top.first.size(); ++i) {
                prev = top.first[i];
                if ((prev - '0') < 9) {
                    top.first[i] = prev + 1;
                    if (visited.find(top.first) == visited.cend()) {
                        q.push({top.first, top.second + 1});
                        visited.insert(top.first);
                    }
                    top.first[i] = prev; 
                }
                if ((prev - '0') > 0) {
                    top.first[i] = prev - 1;
                    if (visited.find(top.first) == visited.cend()) {
                        q.push({top.first, top.second + 1});
                        visited.insert(top.first);
                    }
                    top.first[i] = prev;
                } else if ((prev - '0') == 0) {
                    top.first[i] = '9';
                    if (visited.find(top.first) == visited.cend()) {
                        q.push({top.first, top.second + 1});
                        visited.insert(top.first);
                    }
                    top.first[i] = prev;            
                }
            }
        }
        return (answer == INT_MAX) ? -1 : answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
