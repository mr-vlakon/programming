class Solution {
public:
    void generate(const string &digits, int i, string &s) {
        if (i == digits.size()) {
            if (s.size() == digits.size()) {
                result.push_back(s);
            }
        }
        for (const auto &e: um[digits[i] - '0']) {
            s.push_back(e);
            generate(digits, i + 1, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        string s;
        um[2] = {'a', 'b', 'c'};
        um[3] = {'d', 'e', 'f'};
        um[4] = {'g', 'h', 'i'};
        um[5] = {'j', 'k', 'l'};
        um[6] = {'m', 'n', 'o'};
        um[7] = {'p', 'q', 'r', 's'};
        um[8] = {'t', 'u', 'v'};
        um[9] = {'w', 'x', 'y', 'z'};
        generate(digits, 0, s);
        return result;
    }
private:
    unordered_map<int, vector<char>> um;
    vector<string> result;
};

int main() {
  
  
  
  return 0;  
}
