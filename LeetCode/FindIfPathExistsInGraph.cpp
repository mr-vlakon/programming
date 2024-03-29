/*
struct Edge {
    int top = 0;
    int adj = 0;
    string color;
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (edges.size() == 0) return true;
        if (edges[0][0] == source && edges[0][1] == destination) return true;
        vector<Edge> v;
        for (const auto &e: edges) {
            Edge tmp;
            tmp.color = "White";
            tmp.top = e[0];
            tmp.adj = e[1];
            v.push_back(tmp);
        }
        deque<int> q;
        q.push_front(source);
        while(!q.empty()) {
            auto t = q.back();
            q.pop_back();
            for (auto &e: v) {
                if (e.adj == t || e.top == t) {
                    if (e.top == destination || e.adj == destination)
                        return true;
                    if (e.color == "White") {
                        e.color = "Gray";
                        if (e.top != t) {
                            q.push_front(e.top);
                        } else {
                            q.push_front(e.adj);
                        }
                    }
                }
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        queue<int> q;
        unordered_set<int> us;
        unordered_map<int, vector<int>> um;
        for (const auto &e: edges) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);
        }
        q.push(source);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            for (const auto &e: um[top]) {
                if (us.find(e) == us.cend()) {
                    if (e == destination) {
                        return true;
                    }    
                    us.insert(e);
                    q.push(e);
                }
            }
        }
        return false; 
    }
};

int main() {
  
  
  return 0;  
}
