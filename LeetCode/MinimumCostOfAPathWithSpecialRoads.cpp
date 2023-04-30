struct hashF {
    size_t operator ()(const pair<int, int> &p) const {
        return hash<int>{}(p.first)^hash<int>{}(p.second);
    }
};

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        unordered_map<pair<int, int>, int, hashF> um;
        int i = 1;
        um[{start[0], start[1]}] = i;
        ++i;
        for (const auto &e: specialRoads) {
            if (um[{e[0], e[1]}] == 0) {
                um[{e[0], e[1]}] = i;
                ++i;
            }
            if (um[{e[2], e[3]}] == 0) {
                um[{e[2], e[3]}] = i;
                ++i;
            }
        }
        if (um[{target[0], target[1]}] == 0) {
            um[{target[0], target[1]}] = i;
        }
        unordered_map<int, vector<pair<int, int>>> unor;
        for (const auto &e: specialRoads) {
            unor[um[{e[2], e[3]}]].push_back({um[{target[0], target[1]}], abs(target[0] - e[2]) + abs(target[1] - e[3])});         
            unor[um[{e[0], e[1]}]].push_back({um[{e[2], e[3]}], e[4]});
            unor[um[{start[0], start[1]}]].push_back({um[{e[2], e[3]}], abs(e[2] - start[0]) +
            abs(e[3] - start[1])});
            unor[um[{start[0], start[1]}]].push_back({um[{e[0], e[1]}], abs(e[0] - start[0]) +
            abs(e[1] - start[1])});
            unor[um[{e[0], e[1]}]].push_back({um[{start[0], start[1]}], abs(e[0] - start[0]) +
            abs(e[1] - start[1])});
        }
        i = 0;
        for (; i != specialRoads.size(); ++i) {
            for (int j = 0; j != specialRoads.size(); ++j) {
                if (i != j) {
                    unor[um[{specialRoads[i][2], specialRoads[i][3]}]].push_back({um[{specialRoads[j][0], specialRoads[j][1]}], abs(specialRoads[i][2] - specialRoads[j][0]) +
                abs(specialRoads[i][3] - specialRoads[j][1])});
                }
            }
        }
        unor[um[{start[0], start[1]}]].push_back({um[{target[0], target[1]}], abs(start[0] - target[0]) + abs(start[1] - target[1])});
        vector<bool> visited(um.size(), false);
        priority_queue< pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> >> pq;
        pq.push({0, 1});
        vector<int> dist(um.size(), 1000000);
        dist[1 - 1] = 0;
        pair<int, int> top;
        int newDist = 0;
        while (!pq.empty()) {
            top = pq.top();
            pq.pop();
            visited[top.second - 1] = true;
            for (const auto &e: unor[top.second]) {
                if (visited[e.first - 1] == true) {
                    continue;
                }
                newDist = dist[top.second - 1] + e.second;
                if (newDist < dist[e.first - 1]) {
                    dist[e.first - 1] = newDist;
                    pq.push({dist[e.first - 1], e.first});
                } 
            }
        }
        return dist[um[{target[0], target[1]}] - 1];
    }
};

int main() {
  
  
  
  
  return 0; 
}
