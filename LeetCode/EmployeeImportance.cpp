/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> um;
        for (const auto &e: employees) {
            um[e->id].first = e->importance;
            for (const auto &p: e->subordinates) {
                um[e->id].second.push_back(p);
            }
        }
        queue<int> q;
        q.push(id);
        vector<bool> visited(2000, false);
        visited[id - 1] = true;
        int total = um[id].first;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (const auto &e: um[top].second) {
                if (!visited[e - 1]) {
                    total += um[e].first;
                    q.push(e);
                }
            }
            visited[top - 1] = true;
        }
        return total;
    }
};

int main() {
  
  
  
  return 0;  
}
