class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<bool> visited(n, false);
        vector<double> dist(n, -1.0);
        unordered_map<int, vector<pair<int, double>>> um;
        int i = 0;
        for (const auto &e: edges) {
            um[e[0]].push_back({e[1], succProb[i]});
            um[e[1]].push_back({e[0], succProb[i]});
            
            ++i;
        }  
        for (const auto &e: um[start]) {
            dist[e.first] = e.second;
        }
        dist[start] = 1.0;
        priority_queue<pair<double, int>, deque<pair<double, int>>, less<pair<double, int>>> pq;
        pq.push({1.0, start});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            visited[top.second] = true;
            for(const auto &e: um[top.second]) {
                if (visited[e.first]) {
                    continue;
                }
                double newProb = dist[top.second] * e.second;
                if (newProb >= dist[e.first]) {
                    dist[e.first] = newProb;
                    pq.push({newProb, e.first});
                }
            }
        }
        return (dist[end] == -1.0) ? 0.0 : dist[end];
    }
};

int main() {
  
  
  
  return 0;  
}
