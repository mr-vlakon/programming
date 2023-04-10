class Solution {
public:
    void binary(const vector<int> &potions, const int &sp, const long long &success, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if ((static_cast<long long>(potions[mid]) * sp) >= success) {
            answer = min(answer, mid);
            right = mid - 1;
            binary(potions, sp, success, left, right);
        } else {
            left = mid + 1;
            binary(potions, sp, success, left, right);
        }
        
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int left = 0;
        int right = potions.size() - 1;
        for (int i = 0; i != spells.size(); ++i) {
            left = 0;
            right = potions.size() - 1;
            answer = 10000000;
            binary(potions, spells[i], success, left, right);
            if (answer == 10000000) {
                ans.push_back(0);
            } else {
                ans.push_back(potions.size() - answer);
            }
        }     
        return ans;
    }
private:
    int mid = 0;
    int answer = 0;
};

int main() {
  
  
  
  
  return 0;  
}
