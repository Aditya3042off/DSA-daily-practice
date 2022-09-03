// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=0
bool blackBox(vector<int> &stalls, int dist, int k)
{
    int count = 1;
    int prev = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - prev >= dist)
        {
            count++;
            prev = stalls[i];
        }
        if (count == k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int low = 1;
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());
    int high = maxi - mini;
    int ans = 1;
    sort(stalls.begin(), stalls.end());
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (blackBox(stalls, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}