class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> us;
        for (const auto &e: nums) us.insert(e);
        for (int i = 0; i != moveFrom.size(); ++i) {
            us.erase(moveFrom[i]);
            us.insert(moveTo[i]);
        }
        vector<int> result;
        for (const auto &e: us) result.push_back(e);
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {


  
  return 0;
}
