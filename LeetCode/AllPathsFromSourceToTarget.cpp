class Solution {
public:
    void generate(vector<int> &v, int &i) {
        if (i == n_) {
            v.push_back(i);
            result.push_back(v);
            return;
        }   
        v.push_back(i);
        for (auto &e: um[i]) {
            generate(v, e);
            v.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n_ = graph.size() - 1;
        for (int i = 0; i != graph.size(); ++i) {
            for (const auto &e: graph[i]) {
                um[i].push_back(e);
            }
        }
        int i = 0;
        vector<int> empty;
        generate(empty, i);
        return result;
    }
private:
    int n_ = 0;
    unordered_map<int, vector<int>> um;
    vector<vector<int>> result;
};

int main() {
  
  
  
  return 0;  
}
