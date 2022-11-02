class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int> > um;
        int i = 0;
        for (const auto &e: groupSizes) {
            um[e].push_back(i++);
        }
        
        vector<vector<int>> answer;
        
        for (auto &e: um) {
            if (e.first >= e.second.size()) {
                answer.push_back(e.second);
            } else {
                int size = e.second.size();
                int k = 0;
                while (e.first <= size) {
                    answer.push_back({e.second.cbegin() + k * e.first, e.second.cbegin() + (k + 1) *e.first});
                    size -= e.first;
                    ++k;
                }
                
                if (size != 0) {
                    answer.push_back({e.second.cbegin() + k*e.first, e.second.cend()});
                }
                
            }
            
        }
        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
