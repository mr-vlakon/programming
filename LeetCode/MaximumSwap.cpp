class Solution {
public:
    int maximumSwap(int num) {
        string t = to_string(num);
        int maxInd = -1;
        char maxV;
        for (int i = 0; i != t.size() - 1; ++i) {
            for (int j = i + 1; j != t.size(); ++j) {
                if (t[i] < t[j]) {
                    if (t[j] >= maxV) {
                        maxV = t[j];
                        maxInd = j;
                    }
                }
            }
            if (maxInd != -1) {
                swap(t[maxInd], t[i]);
                return stoi(t);
            }
        }
        return num;
    }
};

int main() {



  return 0;
}
