<<<<<<< HEAD
// reference to the calling object can be returned
/* Reference to the calling object can be returned */
/*Test& Test::func ()
{
   // Some processing
   return *this;
}
*/
#include <iostream>
using namespace std;

class Test
{
private:
    int x;
    int y;
public:
    Test(int x = 0, int y = 0) {this->x = x; this->y = y;}
    Test &setX(int a) { x = a; return *this; }
    Test &setY(int b) { y = b; return *this; }
    void print() {
        cout << " x = " << x << " y = " << y << endl;
    }
};

int main()
{
    Test obj1(5, 5);
    obj1.print();
    obj1.setX(10).setY(20);
    obj1.print();
    return 0;
}
=======
// reference to the calling object can be returned
/* Reference to the calling object can be returned */
/*Test& Test::func ()
{
   // Some processing
   return *this;
}
*/
#include <iostream>
using namespace std;

class Test
{
private:
    int x;
    int y;
public:
    Test(int x = 0, int y = 0) {this->x = x; this->y = y;}
    Test &setX(int a) { x = a; return *this; }
    Test &setY(int b) { y = b; return *this; }
    void print() {
        cout << " x = " << x << " y = " << y << endl;
    }
};

int main()
{
    Test obj1(5, 5);
    obj1.print();
    obj1.setX(10).setY(20);
    obj1.print();
    return 0;
}
>>>>>>> e494c07ad24dd4a5c0c1f04ca84f9f14fa7d3296
