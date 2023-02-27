class Solution {
public:
    void generate(const vector<int> &bit, int i, int cnt) {
        if (i == (bit.size() - 1)) {
            if (cnt == 0) {
                status = true;
            }
            return;
        }
        if (i >= bit.size()) {
            return;
        }
        if (cnt == 0) {
            if (bit[i] == 0) {
                generate(bit, i + 1, 0);
            } else if (bit[i] == 1) {
                generate(bit, i + 2, 0);    
            }
        } else if (cnt == 1) {
            if (bit[i] == 1) {
                generate(bit, i + 2, 0);   
            }
        }
    }
    bool isOneBitCharacter(vector<int>& bits) {
        generate(bits, 0, 0);
        return status;
    }
private:
    bool status = false;
};

int main() {
  
  return 0;  
}
