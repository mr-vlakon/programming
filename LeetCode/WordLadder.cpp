class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> us;
        char prev;
        for (const auto &e: wordList) {
            us[e];
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int answer = INT_MAX;
        pair<string, int> top;
        unordered_map<string, bool>::iterator iter;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            if (top.second >= answer) continue;
            if (top.first == endWord) {
                answer = min(answer, top.second);
            }
            for (int j = 0; j != top.first.size(); ++j) {
                for (int i = 0; i != 26; ++i) {
                    prev = top.first[j];
                    top.first[j] = i + 'a';
                    iter = us.find(top.first);
                    if (iter != us.cend()) {
                        if (us[top.first] == false) {
                            q.push({top.first, top.second + 1});
                            us[top.first] = true;
                        }
                    }
                    top.first[j] = prev;   
                }            
            }
        }
        if (answer == INT_MAX) return 0;
        return answer;
    }
};
/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (const auto &e: wordList) {
            us.insert(e);
        }
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        int answer = INT_MAX;
        pair<string, int> top;
        unordered_set<string>::iterator it;
        unordered_set<string>::iterator iter;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            if (top.second >= answer) continue;
            if (top.first == endWord) {
                answer = min(answer, top.second);
            }
            for (int j = 0; j != top.first.size(); ++j) {
                for (int i = 0; i != 26; ++i) {
                    prev = top.first[j];
                    top.first[j] = i + 'a';
                    iter = visited.find(top.first);
                    if (iter == visited.cend()) {
                        it = us.find(top.first);
                        if (it != us.cend()) {
                            q.push({top.first, top.second + 1});
                        }
                        visited.insert(top.first);    
                    }
                    top.first[j] = prev;   
                }            
            }
        }
        if (answer == INT_MAX) return 0;
        return answer;
    }
private:   
    char prev;
    unordered_set<string> us;
};
*/

int main() {
  
  
  
  
  return 0;  
}
