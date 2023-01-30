class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;
        for (const auto &e: nums) {
            m[e]++;
        }
        int answer = 0;
        int size = m.size();
        auto it = --m.end();
        while (it != m.begin()) {
            answer += (it->second) * (size - 1);
            --size;
            --it;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
