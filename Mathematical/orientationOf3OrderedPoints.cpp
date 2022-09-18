// https://stackoverflow.com/questions/17592800/how-to-find-the-orientation-of-three-points-in-a-two-dimensional-space-given-coo
// https://www.youtube.com/watch?v=bbTqI0oqL5U

// given points p1 p2 p3
// we need to find orientation of p3 wrt p1->p2

// we'll be using vector algebra
// if p3p2 X p3p1 is +ve then orientaton is clockwise
// if p3p2 X p3p1 is -ve then orientaton is anti-clockwise

// if (x1,y1),(x2,y2),(x3,y3) are the points the compute
// (x3-x2) * (y3-y1) - (x3-x1) * (y3-y2)

// A C++ program to find orientation of three points
#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p1, Point p2, Point p3)
{

    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;
    int x3 = p3.x, y3 = p3.y;

    int val = ((x3 - x2) * (y3 - y1)) - ((x3 - x1) * (y3 - y2));

    if (val == 0)
        return 0; // collinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Driver program to test above functions
int main()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    cout << endl;

    p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 1};
    o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    cout << endl;

    p1 = {1, 2}, p2 = {4, 4}, p3 = {0, 0};
    o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    return 0;
}
