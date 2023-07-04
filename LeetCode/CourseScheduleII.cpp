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
        answer.push_back(x);
        mark[x] = false;
        visited[x] = true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if (cycle || cnt != numCourses) return {};
        return {answer.rbegin(), answer.rend()};
    }
private:
    vector<int> answer;
    bool cycle = false;
};

int main() {


  return 0;
}
