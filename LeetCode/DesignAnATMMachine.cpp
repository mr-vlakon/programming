class ATM {
public:
    ATM() {
        bank.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i != banknotesCount.size(); ++i) {
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        end = bank.size() - 1;
        tmp = amount;
        t = 0;
        x = 0;
        temp.assign(5, 0);
        while (end >= 0 && tmp > 0) {
            if (end == 4) {
                t = 500;
            } else if (end == 3) {
                t = 200;
            } else if (end == 2) {
                t = 100;
            } else if (end == 1) {
                t = 50;
            } else {
                t = 20;
            }
            if (tmp >= t) {
                x = tmp / t;
                temp[end] += min(x, bank[end]);
                tmp -= min(x, bank[end]) * t;
            }
            --end;
        }
        
        if (tmp != 0) {
            return {-1};
        }
        for (int i = 0; i != temp.size(); ++i) {
            bank[i] -= temp[i];
        }
        return temp;
    }
private:
    long long x = 0;
    long long t = 0;
    vector<int> temp;
    int tmp = 0;
    int end = 0;
    vector<long long> bank;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

int main() {
  
  
  
  
  return 0;  
}
