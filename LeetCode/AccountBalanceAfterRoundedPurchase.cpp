class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int ost = purchaseAmount % 10;
        if (ost >= 5) {
            return 100 - ((purchaseAmount / 10)*10 + 10);
        } else
            return 100 - ((purchaseAmount / 10)*10);
    }
};

int main() {

  return 0;
}
