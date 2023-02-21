class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> tmp;
        if (veganFriendly) {
            for (const auto &e: restaurants) {
                if (e[2] && e[3] <= maxPrice && e[4] <= maxDistance) {
                    tmp.push_back(e);
                }
            }
        } else {
            for (const auto &e: restaurants) {
                if (e[3] <= maxPrice && e[4] <= maxDistance) {
                    tmp.push_back(e);
                }
            }        }
        sort(tmp.begin(), tmp.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] > rhs[0];
        });
        stable_sort(tmp.begin(), tmp.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] > rhs[1];
        });
        vector<int> answer;
        for (const auto &e: tmp) {
            answer.push_back(e[0]);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
