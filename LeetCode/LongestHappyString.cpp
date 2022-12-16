class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string answer;
        priority_queue<pair<int, char>, deque<pair<int, char>>, less<pair<int, char>>> pq;
        if (a != 0) {
            pq.push({a, 'a'});
        }
        if (b != 0) {
            pq.push({b, 'b'});
        }
        if (c != 0) {
            pq.push({c, 'c'});
        }
        char prev;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (prev != top.second) {
                answer.push_back(top.second);
                --top.first;
                prev = top.second;
            }
            if (top.first > 0) {
                answer.push_back(top.second);
                --top.first;
                prev = top.second;
            }
    
            if(pq.size() == 0) {
                if (top.first > 0) {
                    pq.push(top);
                }
                continue;
            }
            auto top2 = pq.top();
            pq.pop();
            if (prev != top2.second) {
                answer.push_back(top2.second);
                --top2.first;
                prev = top2.second;
            }
            if (top.first > 0) {
                pq.push(top);
            }
            if (top2.first > 0) {
                pq.push(top2);
            }
        }
        string result;
        result.push_back(answer[0]);
        int cnt = 1;
        for (int i = 1; i != answer.size(); ++i) {
            if (answer[i] == answer[i - 1] && cnt < 2) {
                result.push_back(answer[i]);
                ++cnt;
            } else if (answer[i] != answer[i - 1]) {
                cnt = 1;
                result.push_back(answer[i]);
            }
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
