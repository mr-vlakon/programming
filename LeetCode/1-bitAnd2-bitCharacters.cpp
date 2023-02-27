class Solution {
public:
    void generate(const vector<int> &bit, int i) {
        if (i == (bit.size() - 1)) {
            status = true;
            return;
        }
        if (i >= bit.size()) {
            return;
        }
        if (bit[i] == 0) {
            generate(bit, i + 1);
        } else if (bit[i] == 1) {
            generate(bit, i + 2);    
        }
    }
    bool isOneBitCharacter(vector<int>& bits) {
        generate(bits, 0);
        return status;
    }
private:
    bool status = false;
};

int main() {
  
  return 0;  
}
