// The Vita Sum
// Tom the cat is brushing up his Math skills. He has a bag containing N balls of different colors. Now Tom can randomly pick any even number of balls from the bag. Tom wants to find out the sum of all such combinations of balls that he can pull out from the bag. He can pull out at max K balls in one pick.

// Input Format:
// First line contains two space separated numbers N and K

// Output Format:
// The output is the sum of all the combinations of balls he can pull out modulo 10^9+7 i.e. (1000000007)

// Constraints:
// 0<=N<=10^14
// 0<=k<=10^6
// N >= k
// Sample Input and Output
// Input
// 4 4

// Output
// 8

// Explanation
// We need
// 4C0 + 4C2+ 4C4= 1+6+1=8

// Input
// 8 3

// Output
// 29

// Explanation
// We need 8C0 + 8C2= 1+28=29