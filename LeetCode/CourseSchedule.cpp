class Solution {
public:
    void visit(const vector<vector<int>> &um, vector<bool> &mark, vector<bool> &visited, int x) {
        if (visited[x] == true) return;
        if (mark[x] == true) {
            cycle = true;
            return;
        }
        mark[x] = true;
        for (const auto &e: um[x]) {
            visit(um, mark, visited, e);
        }
        mark[x] = false;
        visited[x] = true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> um(numCourses, vector<int>());
        for (const auto &e: prerequisites) {
            um[e[1]].push_back(e[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> mark(numCourses, false);
        for (int i = 0; i != numCourses; ++i) {
            if (visited[i] == false) visit(um, mark, visited, i);
        }
        int cnt = 0;
        for (const auto &e: visited) {
            if (e == true) ++cnt;
        }
        if (cycle) return false;
        return cnt == numCourses;
    }
private:
    bool cycle = false;
};

int main() {


  
  return 0;
}
