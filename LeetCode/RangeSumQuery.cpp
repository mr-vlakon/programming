class NumArray {
public:
    NumArray(vector<int>& nums) : v(nums){
    }
    
    int sumRange(int left, int right) {
        int result = 0;
        for(decltype(v.size()) i = left; i <= right; ++i) {
            result += v[i];
        }
        return result;
    }
private:
    vector<int> v;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {

  return 0;  
}
