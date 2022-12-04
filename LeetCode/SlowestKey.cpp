class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        unordered_map<char, int> um;
        um[keysPressed[0]] = releaseTimes[0];
        int max = releaseTimes[0];
        for (int i = 1; i != releaseTimes.size(); ++i) {
            auto it = um.find(keysPressed[i]);
            if (it == um.cend()) {
                um[keysPressed[i]] = releaseTimes[i] - releaseTimes[i - 1];
            } else {
                if (it->second < releaseTimes[i] - releaseTimes[i - 1]) {
                    um[keysPressed[i]] = releaseTimes[i] - releaseTimes[i - 1];
                }
            }
            if (releaseTimes[i] - releaseTimes[i - 1] > max) {
                max = releaseTimes[i] - releaseTimes[i - 1];
            }
        }
        char answer;
        for (const auto &e: um) {
            if (e.second == max && e.first > answer) {
                answer = e.first;
            }
        }
        return answer;        
    }
};

int main() {
  
  
  
  return 0;  
}
