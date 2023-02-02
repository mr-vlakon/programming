class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> um;
        int i = 1;
        for (const auto &e: edges) {
            um[e[0]].push_back(e[1]);
            um[e[1]].push_back(e[0]);
        }
        i = 0;
        queue<int> q;
        unordered_set<int> us;
        long long answer = 0;
        long long sum = 0;
        while (i < n) {
            if (us.find(i) != us.cend()) {
                ++i;
                continue;
            }
            long long tmp = 1;
            q.push(i);
            us.insert(i);
            while(!q.empty()) {
                auto top = q.front();
                q.pop();
                for (const auto &e: um[top]) {
                    if ((us.find(e) == us.cend())) {    
                        ++tmp;
                        us.insert(e);
                        q.push(e);
                    }
                }   
            }
            answer += sum * tmp;
            sum += tmp;
            ++i;
        }
        return answer;  
    }
};

int main() {
  
  
  return 0;  
}
