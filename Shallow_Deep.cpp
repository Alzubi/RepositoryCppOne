#include <iostream>
using namespace std;
 
class c{
private:  int * x; 
public: 
    c(int m) {          x = new int;
                        *x = m;
                        cout << "constructor 1 *x= " << *x << "    &x address= " << &x << endl;
    }
    // Copy Constructor and Deep Copy
    c(const c& obj)  {  x = new int;
                        *x = obj.GetX();
                        cout << "constructor 2 *x= " << *x << "    &x address= " << &x << endl;
    }
    ~c() {              cout << "~c()          *x= " << *x << "    &x address= " << &x << endl;
                        delete x; 
    }     

    int GetX() const {  cout << "inside GetX() *x= " << *x << "    &x address= " << &x << endl;
                        return *x;  
    }        
    void SetX(int m) {  *x = m;     }
    void PrintX() {     cout << "PrintX() Int   x=" << *x << "     address is  " << &x << endl; }
};
 
int main(){
    c ob1(10);                      cout << "============== " << endl;
    c ob2 = ob1;                    cout << "============== " << endl;
    ob1.PrintX(); ob2.PrintX();     cout << "============== " << endl;
    ob1.SetX(12);                   cout << "============== " << endl;
    ob1.PrintX();
    ob2.PrintX();
    return 0;
}

// OUTPUT:
// constructor 1 *x= 10    &x address= 0x23fe38
// ============== 
// inside GetX() *x= 10    &x address= 0x23fe38
// constructor 2 *x= 10    &x address= 0x23fe30
// ============== 
// PrintX() Int x=10       address is  0x23fe38
// PrintX() Int x=10       address is  0x23fe30
// ============== 
// ============== 
// PrintX() Int x=12       address is  0x23fe38
// PrintX() Int x=10       address is  0x23fe30
// ~c() *x= 10             &x address= 0x23fe30
// ~c() *x= 12             &x address= 0x23fe38