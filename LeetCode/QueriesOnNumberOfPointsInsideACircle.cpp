class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (const auto &e: queries) {
            int cnt = 0;
            for (const auto &p: points) {
                if (pow((e[0] - p[0]), 2) + pow((e[1] - p[1]), 2) <= pow(e[2], 2)) {
                    ++cnt;
                }
            }
            res.push_back(cnt);
        }   
        return res;
    }
};

int main() {
  
    
  return 0; 
}
