public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> ans;
        unordered_map<int, int> un;
        for (const auto &e: changed) {
            ++un[e];
        }
        for (const auto &e: changed) {
            if ((e % 2) == 1 && un[e] > 0) {
                un[e]--;
                un[e * 2]--;
                ans.push_back(e);
            } else if ((e % 2) == 0 && un[e] > 0){
                ans.push_back(e);
                un[e]--;
                un[e * 2]--;
            }
        }
        if ((ans.size()*2) != changed.size()) return {};
        return ans;
   }
};

int main() {
  
  
  
  return 0;  
}
