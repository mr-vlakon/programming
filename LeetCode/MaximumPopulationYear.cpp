class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(3000);
        for (const auto &e: logs) {
            int i = e[0];
            while (i != e[1]) {
                ++v[i];
                ++i;
            }   
        }
        return max_element(v.cbegin(), v.cend()) - v.cbegin();   
    }
};

int main() {
  
  
  return 0;  
}
