class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> umL2;
        for (int i = 0; i != list2.size(); ++i) {
            umL2[list2[i]] = i;
        }
        map<int, vector<string>> mp;
        for (int i = 0; i != list1.size(); ++i) {
            auto it = umL2.find(list1[i]);
            if (it != umL2.cend()) {
                mp[i + it->second].push_back(it->first);
            }
        }
        return mp.begin()->second;
    }
};

int main() {
  
  
  
  return 0;  
}
