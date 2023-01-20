class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int, pair<int, int>> > v;
        for (const auto &e: tasks) {
            v.push_back({e[1] - e[0], {e[0], e[1]}});
        }
        sort(v.begin(), v.end(), [&](pair<int, pair<int, int>> & lhs, 
                                     pair<int, pair<int, int>> &rhs)     {
            return lhs.second.second > rhs.second.second;
        });
        stable_sort(v.begin(), v.end(), [&](const pair<int, pair<int, int>> & lhs,  const pair<int, pair<int, int>> &rhs)     {
            return lhs.first > rhs.first;
        });
        int answer = v[0].second.second;
        int x = answer;
        answer -= v[0].second.first;
        for (int i = 1; i != v.size(); ++i) {
            if (v[i].second.second > answer) {
                x += abs(v[i].second.second - answer);
                answer = v[i].second.second;
            }
            answer -= v[i].second.first;  
        }
        return x;
    }
};

int main() {
  
  
  
  
  return 0;  
}
