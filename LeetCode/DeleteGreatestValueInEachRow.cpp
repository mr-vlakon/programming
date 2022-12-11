class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int i = 0;
        int answer = 0;
        while(i != grid[0].size()) {
            priority_queue<int> pq;
            for (auto &e: grid) {
                pq.push(*max_element(e.cbegin(), e.cend()));
                *max_element(e.begin(), e.end()) = -100000;
            }
            auto top = pq.top();
            answer += top;
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
