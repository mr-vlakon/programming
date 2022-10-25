class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> answer;        
        for (const auto &e: nums) {
            if (e < pivot)
                answer.push_back(e);
        }
        for (const auto &e: nums) {
            if (e == pivot)
                answer.push_back(e);
        }
        for (const auto &e: nums) {
            if (e > pivot)
                answer.push_back(e);
        }

        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
