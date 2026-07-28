// Devlop a prg to demostrate parameter passing technique , call by value , call by referce , cal by address and analyse there effts on varible modificattion
#include <iostream>
using namespace std;

void callByValue(int x)
{
    x = x + 10;
    cout << "Inside Call by Value: " << x << endl;
}

void callByReference(int &x)
{
    x = x + 10;
    cout << "Inside Call by Reference: " << x << endl;
}

void callByAddress(int *x)
{
    *x = *x + 10;
    cout << "Inside Call by Address: " << *x << endl;
}

int main()
{
    int num = 20;

    cout << "Original Value: " << num << endl;

    callByValue(num);
    cout << "After Call by Value: " << num << endl;

    callByReference(num);
    cout << "After Call by Reference: " << num << endl;

    callByAddress(&num);
    cout << "After Call by Address: " << num << endl;

    return 0;
}