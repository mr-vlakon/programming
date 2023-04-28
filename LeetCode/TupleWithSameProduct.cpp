class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 0; i != nums.size() - 1; ++i) {
            for (int j = i + 1; j != nums.size(); ++j) {
                um[nums[i]*nums[j]]++;
            }
        }
        int answer = 0;
        for (const auto &e: um) {
            answer += 4*(e.second - 1)*e.second;
        }
        return answer;  
    }
};

int main() {
  
  
  
  return 0;  
}
