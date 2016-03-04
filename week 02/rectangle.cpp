#include <iostream>
using namespace std;

struct Rectangle
{
    int length; // дължина
    int width; // широчина
};

////точка 1
void print_rectangle(Rectangle r)
{
    cout << r.length << r.width << endl;
}

////точка 2
void init_rectangle(Rectangle& r)
{
    do
    {
        cout << "length: "; 
        cin >> r.length;
        cout << "width: ";
        cin >> r.width;
    } 
    while(r.length <= 0 || r.width <= 0);
}

////точка 3
Rectangle init_rectangle()
{
    Rectangle r;
    
    do
    {
        cout << "length: ";
        cin >> r.length;
        cout << "width: "; 
        cin >> r.width;
    } 
    while(r.length <= 0 || r.width <= 0);

    return r;
}

int main()
{
    Rectangle r;

    r = init_rectangle();

    print_rectangle(r);

    init_rectangle(r);

    print_rectangle(r);

    return 0;
}
