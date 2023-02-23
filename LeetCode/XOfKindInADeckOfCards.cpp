class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> um;
        for (const auto &e: deck) {
            ++um[e];
        }
        int gcd = um.begin()->second;
        for (const auto &e: um) {
            gcd = std::gcd(gcd, e.second);
        }
        return gcd != 1;

    }
};

int main() {
  
  
  
  return 0;  
}
