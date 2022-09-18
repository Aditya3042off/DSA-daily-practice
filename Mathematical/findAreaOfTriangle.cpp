// Given three sides of a triangle A, B and C in the form of integers. Find the area of the triangle.
// Note: The triangle may not exist. In such cases, the area is 0.

// Example 1:

// Input: A = 2, B = 2, C = 3
// Output: 1.984313
// Explanation:
// The area formed by the triangle whose
// sides are 2,2 and 3 units respectively is
// 1.984313 units2.
// Example 2:

// Input: A = 1, B = 3, C = 1
// Output: 0.000
// Explanation:
// Such a triangle does not exist whose
// sides are 1,3 and 1 respectively.Thus,Area is
// 0.

// https://practice.geeksforgeeks.org/problems/area-of-a-triangle5739/1

//{ Driver Code Starts
// Initial template for C++

// if given lengths of three sides of triangle are a,b,c
// area of triangle is sqrt(s * (s-a) * (s-b) * (s-c)) where s = (a+b+c)/2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findArea(int a, int b, int c)
    {
        // code here

        if (a + b < c or a + c < b or b + c < a)
            return 0;

        double s = (a + b + c) / 2.0;

        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << fixed << setprecision(3);
        cout << ob.findArea(A, B, C) << "\n";
    }
}
