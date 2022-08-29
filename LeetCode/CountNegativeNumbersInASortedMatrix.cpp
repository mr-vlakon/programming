class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        vector<int> result;
        for (const auto &e: grid) {
            for(const auto &p : e) {
                result.push_back(p);
            }
        }
        int cnt = count_if(result.cbegin(), result.cend(),[](const int &x) {
            return x < 0;
        });   
        return cnt;
    }
};

int main() {
 
  return 0;  
}
