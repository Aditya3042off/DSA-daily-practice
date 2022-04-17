// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

// Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

// If it cannot be done, return -1.

// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation:
// The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
// Example 2:

// Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
// Output: -1
// Explanation:
// In this case, it is not possible to rotate the dominoes to make one row of values equal.

// https://www.youtube.com/watch?v=VD9NACqBCw4

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        vector<int> temp(7, 0);
        int m = tops.size();
        for (int i = 0; i < m; i++)
        {
            temp[tops[i]]++;
            if (tops[i] != bottoms[i])
                temp[bottoms[i]]++;
        }

        int elmnt = -1, top = 0, btm = 0;

        for (int i = 1; i < 7; i++)
        {
            if (temp[i] == m)
            {
                elmnt = i;
                break;
            }
        }
        if (elmnt == -1)
            return -1;

        for (int i = 0; i < m; i++)
        {
            if (tops[i] != elmnt)
                top++;
            if (bottoms[i] != elmnt)
                btm++;
        }

        return min(top, btm);
    }
};