#include <bits/stdc++.h>
using namespace std;

class Base
{
private:
    int x, y;

public:
    Base() : x(0), y(0) {}

    Base(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int add(int a, int b)
    {
        return a + b;
    }

    virtual void myself()
    {
        cout << "in base class" << endl;
    }

    ~Base()
    {
        cout << "destroying base" << endl;
    }
};

class Base2
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    virtual void myself()
    {
        cout << "in base2 class" << endl;
    }

    ~Base2()
    {
        cout << "destroying base2" << endl;
    }
};

class Child : public Base
{
public:
    void myself()
    {
        cout << "in child class" << endl;
    }

    ~Child()
    {
        cout << "desstroying child" << endl;
    }
};

class Child2 : public Child
{
public:
    void myself()
    {
        cout << "in child2 class" << endl;
    }

    ~Child2()
    {
        cout << "desstroying child2" << endl;
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Child base = Child();
    cout << sizeof(base);

    return 0;
}