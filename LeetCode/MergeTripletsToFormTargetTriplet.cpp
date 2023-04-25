class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tmp(3);
        for (int i = 0; i != triplets.size(); ++i) {
            if ((triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])) {
                tmp[0] = max(triplets[i][0], tmp[0]);
                tmp[1] = max(triplets[i][1], tmp[1]);
                tmp[2] = max(triplets[i][2], tmp[2]);
            }
        }
        return tmp == target;
    }
};

int main() {
  
  
  return 0;  
}
