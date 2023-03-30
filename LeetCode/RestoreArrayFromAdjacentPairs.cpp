class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> um;
        unordered_map<int, vector<int>> unor;
        unordered_map<int, bool> visit;
        for (const auto &e: adjacentPairs) {
            um[e[0]]++;
            um[e[1]]++;
            unor[e[0]].push_back(e[1]);
            unor[e[1]].push_back(e[0]); 
        }
        int find = 0;
        for (const auto &e: um) {
            if (e.second == 1) {
                find = e.first;
                break;
            }
        }   
        int size = adjacentPairs.size() + 1;
        int i = 0;
        vector<int> answer;
        while (i != size) {
            visit[find] = true;
            answer.push_back(find);
            for (const auto &e: unor[find]) {
                if (visit[e] == false) {
                    find = e;
                    visit[e] = true;
                    break;
                }
            }
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
