<<<<<<< HEAD
#include <iostream>
using namespace std;
// local variable is same as the member's name
class Test
{
private:
    int x;
public:
    void setX (int x)
    {
        // the 'this' pointer is used to retrieve the object's x
        // hidden by the local variable 'x'
        this->x = x;
    }
    void print() { cout << "x = " << x << endl; }
};

int main (){
    Test obj;
    int x = 20;
    obj.setX(x);
    obj.print();
    return 0;
}
=======
#include <iostream>
using namespace std;
// local variable is same as the member's name
class Test
{
private:
    int x;
public:
    void setX (int x)
    {
        // the 'this' pointer is used to retrieve the object's x
        // hidden by the local variable 'x'
        this->x = x;
    }
    void print() { cout << "x = " << x << endl; }
};

int main (){
    Test obj;
    int x = 20;
    obj.setX(x);
    obj.print();
    return 0;
}
>>>>>>> e494c07ad24dd4a5c0c1f04ca84f9f14fa7d3296
