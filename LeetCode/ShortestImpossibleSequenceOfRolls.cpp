class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> us;
        int score = 0;
        for (int i = 0; i != rolls.size(); ++i) {
            us.insert(rolls[i]);
            if (us.size() == k) {
                ++score;
                us.clear();
            }
        }
        return score + 1;     
    }
};

int main() {
  
  
    
  return 0;   
}
