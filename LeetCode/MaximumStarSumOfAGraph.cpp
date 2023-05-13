class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> um(vals.size());  
        for (const auto &e: edges) {
            if (vals[e[1]] > 0)
                um[e[0]].push_back(vals[e[1]]);
            if (vals[e[0]] > 0)
                um[e[1]].push_back(vals[e[0]]);
        }
        for (auto &e: um) {
            sort(e.rbegin(), e.rend());
        }
        int answer = INT_MIN;
        int tmp = 0;
        int i = 0;
        for (const auto &e: um) {
            tmp = vals[i] + accumulate(e.cbegin(), e.cbegin() + min(k, static_cast<int>(e.size() )), 0);
            ++i;
            answer = max(tmp, answer);
        }
        return answer;

    }
};
/*
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> um(vals.size());  
        for (const auto &e: edges) {
            if (vals[e[1]] > 0)
                um[e[0]].push_back(vals[e[1]]);
            if (vals[e[0]] > 0)
                um[e[1]].push_back(vals[e[0]]);
        }
        int i = 0;
        for (auto &e: um) {
            e.push_back(vals[i]);
            ++i;
        }
        for (auto &e: um) {
            sort(e.rbegin() + 1, e.rend());
        }
        int answer = INT_MIN;
        int tmp = 0;
        for (const auto &e: um) {
            tmp = e.back() + accumulate(e.cbegin(), e.cbegin() + min(k, static_cast<int>(e.size() - 1)), 0);
            answer = max(tmp, answer);
        }
        return answer;

    }
};
*/
int main() {
  
  
  
  
  return 0;  
}
