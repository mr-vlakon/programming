class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) :big_(big), medium_(medium),
    small_(small){
        
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (big_ > 0) {
                --big_;
                return true;
            }
        }
        if (carType == 2) {
            if (medium_ > 0) {
                --medium_;
                return true;
            }
        }
        if (carType == 3) {
            if (small_ > 0) {
                --small_;
                return true;
            }
        }
        return false;
    }
private:
    int big_ = 0;
    int medium_ = 0;
    int small_ = 0;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {
  
  
  return 0;  
}
