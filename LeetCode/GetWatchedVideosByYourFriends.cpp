class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<pair<int, int>> q;
        unordered_map<string, int> unor;
        q.push({id, 0});
        vector<bool> visited(friends.size(), false);
        pair<int, int> top;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            visited[top.first] = true;
            if (top.second > level) {
                break;
            }
            if (top.second == level) {
                for (const auto &e: watchedVideos[top.first]) {
                    unor[e]++;
                }
                for (const auto &e: friends[top.first]) {
                    visited[e] = true;
                }
                continue;
            }
            for (const auto &e: friends[top.first]) {
                if (visited[e] == false) {
                    visited[e] = true;
                    if ((top.second + 1) <= level)
                        q.push({e, top.second + 1});
                }
            }
        }
        vector<pair<string, int>> v;
        for (const auto &e: unor) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), [](pair<string, int> &lhs, pair<string, int> &rhs) {
            return lhs.first < rhs.first;
        });
        stable_sort(v.begin(), v.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
            return lhs.second < rhs.second;
        });
        vector<string> answer;
        for (const auto &e: v) {
            answer.push_back(e.first);
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
