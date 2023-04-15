class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        for (const auto &e: edges) {
            um[e[0]].push_back({e[1], e[2]});
        }
        n_ = n;
    }
    
    void addEdge(vector<int> edge) {
        um[edge[0]].push_back({edge[1], edge[2]});      
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> visited(n_, false);
        vector<int> dist(n_, 2147483647);
        dist[node1] = 0;
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        int newLenght = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            visited[top.second] = true;
            for(const auto &e: um[top.second]) {
                if (visited[e.first]) {
                    continue;
                }
                newLenght = dist[top.second] + e.second;
                if (newLenght < dist[e.first]) {
                    dist[e.first] = newLenght;
                    pq.push({newLenght, e.first});
                }
            }
        }
        return (dist[node2] == 2147483647) ? -1 : dist[node2];      
    }
private:
    int n_ = 0;
    unordered_map<int, vector<pair<int, int>>> um;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main() {
  
  
  return 0;  
}
