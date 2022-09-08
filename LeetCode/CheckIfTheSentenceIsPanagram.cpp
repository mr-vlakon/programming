class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> um;
        for (const auto &e: sentence)
            ++um[e];
        return um.size() == 26;
    }
};

int main() {
  
  return 0;  
}
