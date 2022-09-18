#include <bits/stdc++.h>
using namespace std;

// Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3)
// Area of triangle A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2

double findArea(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    int x1 = p1.first, y1 = p1.second;
    int x2 = p2.first, y2 = p2.second;
    int x3 = p3.first, y3 = p3.second;

    double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;

    return abs(area);
}

int main()
{
    // triangle coordinates
    pair<int, int> p1 = {0, 0};
    pair<int, int> p2 = {10, 30};
    pair<int, int> p3 = {20, 10};

    // point to find if it lies inside triangle
    pair<int, int> q = {30, 15};

    double triangleArea = findArea(p1, p2, p3);

    double part1Area = findArea(p1, p2, q);
    double part2Area = findArea(p3, p2, q);
    double part3Area = findArea(p1, p3, q);

    cout << (triangleArea == part1Area + part2Area + part3Area);
}