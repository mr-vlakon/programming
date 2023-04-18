class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : num2(nums2) {
        for (const auto &e: nums2) {
            um[e]++;
        }
        for (const auto &e: nums1) {
            un[e]++;
        }
    }
    
    void add(int index, int val) {
        um[num2[index]]--;
        if (um[num2[index]] == 0) {
            um.erase(num2[index]);
        }
        num2[index] += val;
        um[num2[index]]++;
    }
    
    int count(int tot) {
        answer = 0;
        for (const auto &e: un) {
            it = um.find(tot - e.first);
            if (it != um.cend()) {
                answer += um[tot - e.first] * e.second;
            }
        }
        return answer;
    }
private:
    unordered_map<int, int>::iterator it;
    int answer = 0;
    vector<int> num2;
    unordered_map<int, int> un;
    unordered_map<int, int> um;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main() {
  
  
  
  
  
  return 0;  
}
