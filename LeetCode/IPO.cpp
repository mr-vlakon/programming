class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> v;
        for (int i = 0; i != profits.size(); ++i) {
            v.push_back({profits[i], capital[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        });
        priority_queue<int> pq;
        int answer = w;
        int remI = 0;
        for (int i = 0; i != v.size(); ++i) {
            if (v[i].second <= answer) {
                pq.push(v[i].first);
            } else {
                remI = i;
                break;
            }
        }
        int j = 0;
        bool status = false;
        while (j != k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            answer += top;
            if (!status) {
                int newI = remI;
                for (int i = newI; i != v.size(); ++i) {
                    if (v[i].second <= answer) {
                        if (i == v.size() - 1) {
                            status = true;
                        }
                        pq.push(v[i].first);
                    } else {
                        remI = i;
                        break;
                    }
                }
            }
            ++j;
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0; 
}
