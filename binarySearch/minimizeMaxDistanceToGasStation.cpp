// // On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1],
// // where N = stations.length.

// // Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

// // Return the smallest possible value of D.

// // Example
// // Example 1:

// // Input stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]K = 9
// // Output 0.50
// // Explanation The distance between adjacent gas stations is 0.50
// // Example 2:

// // Input stations = [3,6,12,19,33,44,67,72,89,95]K = 2
// // Output 14.00
// // Explanation construction of gas stations at 86 locations

// https://www.lintcode.com/problem/848/
// https://www.tutorialspoint.com/minimize-max-distance-to-gas-station-in-cplusplus
// https://www.youtube.com/watch?v=gcDUAw3vQlg

class Solution
{
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    bool f(vector<int> &v, int k, double x)
    {
        int ret = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            ret += ceil((v[i + 1] - v[i]) / x) - 1;
        }
        return ret <= k;
    }

    double minmaxGasDist(vector<int> &stations, int k)
    {
        // Write your code here
        double low = 0.0;
        double high;

        for (int i = 0; i < stations.size() - 1; i++)
        {
            double dist = (double)stations[i + 1] - (double)stations[i];
            if (dist > high)
                high = dist;
        }
        double mid;
        while (high - low >= 0.000001)
        {
            mid = (low + high) / 2.0;

            if (f(stations, k, mid))
                high = mid;
            else
                low = mid;
        }
        return high;
    }
};