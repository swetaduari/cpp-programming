#include <iostream>
using namespace std;

class shape
{ 
public:
    int l;
    int b;

    void get_data()
    {
        cout << "Enter the length of shape: ";
        cin >> l;
        cout << "Enter the breadth of shape: ";
        cin >> b;
    }
};

class rectangle : public shape
{
public:
    void area()
    {
        cout << "Area of rectangle is " << l * b << endl;
    }
};

class square : public shape
{
public:
    void area()
    {
        cout << "Area of square is " << l * l << endl;
    }
};

int main()
{
    rectangle r;
    square s;

    cout << "--- Rectangle ---" << endl;
    r.get_data();
    r.area();

    cout << "\n--- Square ---" << endl;
    s.get_data();  // Square also needs input for side
    s.area();

    return 0;
}
