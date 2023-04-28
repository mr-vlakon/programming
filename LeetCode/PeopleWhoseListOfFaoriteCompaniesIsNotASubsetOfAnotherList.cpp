class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> unor;    
        for (const auto &e: favoriteCompanies) {
            for (const auto &p: e) {
                unor[p];
            }
        }
        int i = 0;
        for (auto &e: unor) {
            e.second = i;
            ++i;
        }
        vector<vector<int>> v(favoriteCompanies.size());
        for (int i = 0; i != favoriteCompanies.size(); ++i) {
            for (int j = 0; j != favoriteCompanies[i].size(); ++j) {
                v[i].push_back(unor[favoriteCompanies[i][j]]);
            }
        }
        for (auto &e: v) {
            sort(e.begin(), e.end());
        }
        int start1 = 0;
        int start2 = 0;
        int cnt = 0;
        bool status = false;
        vector<int> answer;
        for (int i = 0; i != v.size(); ++i) {
            status = false;
            for (int j = 0; j != v.size(); ++j) {
                if (i != j) {
                    start1 = 0;
                    start2 = 0;
                    cnt = 0;
                    while ((start1 < v[i].size()) && (start2 < v[j].size())) {   
                        if (v[i][start1] == v[j][start2]) {
                            ++start1;
                            ++start2;
                            ++cnt;
                        } else {
                            ++start2;
                        }
                    }
                    if (cnt == v[i].size()) {
                        status = true;
                        break;
                    }
                }
            }
            if (!status) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
