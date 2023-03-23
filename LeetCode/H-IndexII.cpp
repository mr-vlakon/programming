class Solution {
public:
    void binary(const vector<int> &cit, int left, int right) {
        if (left < 0) return;
        if (right > cit.size()) return;
        if (left > right) return;
        mid = (left + right) / 2;
        if (cit[mid] >= (cit.size() - mid)) {
            ans = max(ans, static_cast<int>(cit.size()) - mid);
            if (left != right) {
                binary(cit, left, mid - 1);
            }
            return;
        } else {
            if (left != right) {
                binary(cit, mid + 1, right);
            }
            return;
        }
    }
    int hIndex(vector<int>& citations) {
        binary(citations, 0, citations.size() - 1);
        return ans;
    }
private:
    int ans = 0;
    int mid = 0;
};

int main() {

  
  return 0;
}
