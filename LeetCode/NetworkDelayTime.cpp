class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n, false);
        vector<int> dist(n, 10000);
        unordered_map<int, vector<pair<int, int>>> um;
        for (const auto &e: times) {
            um[e[0] - 1].push_back({e[1] - 1, e[2]});
        }
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            visited[top.second] = true;
            for(const auto &e: um[top.second]) {
                if (visited[e.first]) {
                    continue;
                }
                int newTime = dist[top.second] + e.second;
                if (newTime < dist[e.first]) {
                    dist[e.first] = newTime;
                    pq.push({newTime, e.first});
                }
            }
        }
        int maxV = 0;
        for (const auto &e: dist) {
            maxV = max(maxV, e);
        }    
        if (maxV == 10000) {
            return -1;
        }
        return maxV;
    }
};

int main() {
  
  
  return 0;  
}
