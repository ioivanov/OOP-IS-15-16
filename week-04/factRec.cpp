#include <iostream.h>

class fact
{ 

public:
    // конструктор
    fact(int a)
    { 
        x = a;
    }

    // намиране на x!
    unsigned int value() const
    { 
        if(x == 1) 
        {
            return 1;
        }
        else
        { 
            fact t(x-1);
            return x*t.value();
        }
    }

private:
    int x;
};
