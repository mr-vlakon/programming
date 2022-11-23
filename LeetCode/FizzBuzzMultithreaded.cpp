class FizzBuzz {
private:
    mutex m;
    std::condition_variable cv;

    
    int tmp = 0;
    int n;
    int i = 1;

    int f = 3;
    int b = 5; 
    int fb = 15;
    int num = 0;
    
    int max_f = 0;
    int max_b = 0;
    int max_fb = 0;
    int max_num = 0;
    
public:
    FizzBuzz(int n) {
        this->n = n;
        
        int k1 = n;
        while (k1) {
            if (k1 % 3 != 0 && k1 % 5 != 0) {
                max_num = k1;
                break;
            }
            --k1;
        }
        
        int k2 = n;
        while (k2) {
            if (k2 % 3 == 0 && k2 % 5 == 0) {
                max_fb = k2;
                break;
            }
            --k2;
        }

        int k3 = n;
        while (k3) {
            if (k3 % 3 == 0 && k3 % 5 != 0) {
                max_f = k3;
                break;
            }
            --k3;
        }

        int k4 = n;
        while (k4) {
            if (k4 % 3 != 0 && k4 % 5 == 0) {
                max_b = k4;
                break;
            }
            --k4;
        }        
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (f <= max_f && f <= n && i <= max_f) {
            std::unique_lock<std::mutex> lck(m);
            while (tmp != 2) cv.wait(lck);
            f = i;
            printFizz();
            ++i;
            if (i % 3 == 0 && i % 5 == 0) {
                tmp = 1;
            } else if (i % 3 == 0 && i % 5 != 0) {
                tmp = 2;
            } else if (i % 5 == 0 && i % 3 != 0) {
                tmp = 3;
            } else {
                tmp = 0;
            }            
            cv.notify_all();
        }     
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (b <= max_b && b <= n && i <= max_b) {
            std::unique_lock<std::mutex> lck(m);
            while (tmp != 3) cv.wait(lck);
            b = i;
            printBuzz();
            ++i;
            if (i % 3 == 0 && i % 5 == 0) {
                tmp = 1;
            } else if (i % 3 == 0 && i % 5 != 0) {
                tmp = 2;
            } else if (i % 5 == 0 && i % 3 != 0) {
                tmp = 3;
            } else {
                tmp = 0;
            }            
            cv.notify_all();
        } 
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (fb <= max_fb && fb <= n && i <= max_fb) {
            std::unique_lock<std::mutex> lck(m);
            while (tmp != 1) cv.wait(lck);
            fb = i;
            printFizzBuzz();
            ++i;
            if (i % 3 == 0 && i % 5 == 0) {
                tmp = 1;
            } else if (i % 3 == 0 && i % 5 != 0) {
                tmp = 2;
            } else if (i % 5 == 0 && i % 3 != 0) {
                tmp = 3;
            } else {
                tmp = 0;
            }            
            cv.notify_all();
        }       
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (num <= max_num && num <= n && i <= max_num) {
            std::unique_lock<std::mutex> lck(m);
            while (tmp != 0) cv.wait(lck);
            num = i;
            printNumber(num);
            ++i;
            if (i % 3 == 0 && i % 5 == 0) {
                tmp = 1;
            } else if (i % 3 == 0 && i % 5 != 0) {
                tmp = 2;
            } else if (i % 5 == 0 && i % 3 != 0) {
                tmp = 3;
            } else {
                tmp = 0;
            }            
            cv.notify_all();
        }    
    }   
};

int main() {
  
  
  
  return 0;  
}
