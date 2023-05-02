class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> hash1(10, 0);
        vector<int> hash2(10, 0);
        int bulls = 0;
        for (int i = 0; i != secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                hash1[secret[i] - '0']++;
                hash2[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for (int i = 0; i != hash1.size(); ++i) {
            cows += min(hash1[i], hash2[i]);
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};

int main() {
  
  
  
  return 0;  
}
