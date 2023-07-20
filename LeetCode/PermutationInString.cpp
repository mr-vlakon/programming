class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26, 0);
        for (const auto &e: s1) {
            ++v[e - 'a'];
        }
        if (s1.size() > s2.size()) return false;
        vector<int> hash(26, 0);
        for (int i = 0; i != s1.size(); ++i) {
            ++hash[s2[i] - 'a'];
        }
        if (v == hash) return true;
        for (int i = 1; i <= (static_cast<int>(s2.size()) - s1.size()); ++i) {
            --hash[s2[i - 1] - 'a'];
            ++hash[s2[i + s1.size() - 1] - 'a'];
            if (hash == v) return true;
        }
        return false;
    }
};

int main() {



  return 0;
}
