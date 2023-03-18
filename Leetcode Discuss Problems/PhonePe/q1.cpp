/**
 * @file q1.cpp
 * @author Sourav Sinha
 * @brief OA Question - https://leetcode.com/discuss/interview-question/3308603/PhonePe-Interview-Questions-or-SSE-or-DSA-Round
 * @version 0.1
 * @date 2023-03-18
 *
First Problem

There are N stocks in the array. Each stock can belong to one of the M categories. The customer wants to form a diversified portfolio by choosing a contiguous subsequence of stocks from that array such that there are exactly C1 count of stocks of category 1, C2 count of stocks of category 2,..., Cm count of stocks of category M.

Help your system find the minimum number of stocks to be removed from the array to achieve the contiguous subsequence or return -1 if it’s impossible.
Input Format
The first line of the input contains n and m (1 ≤ m ≤ n). The second line contains n integers in the range {1, 2, ..., m} representing stocks. The third line contains m integers C1, C2, ..., Cm (with ) – the desired counts of stocks of each category from 1 to m.

Sample Input
8 3
3 3 1 2 2 1 1 3
3 1 1

Output
1
(you can remove stock at position 5 with category 2, then you can form subsequence from position 3 to position 8 meeting the requirements)

Second problem:
https://leetcode.com/problems/accounts-merge/
 */
#include<bits/stdc++.h>
using namespace std;
bool conditionSatisfy(vector<int>& cf, vector<int>& rf)
{
    for (int i = 0; i < size(cf); i++)
    {
        if (cf[i] < rf[i]) return false;
    }
    return true;
}
int solve(int n, int m, vector<int>arr, vector<int>requiredFrequency)
{
    for (auto& e : arr) e -= 1;
    vector<int> currentFrequency(m,0);
    int smallestChunkRequired = INT_MAX;
    for (int start = 0, end = 0; end < n; end++)
    {
        currentFrequency[arr[end]]++;
        while (conditionSatisfy(currentFrequency, requiredFrequency))
        {
            // cout<<start<<" "<<end<<endl;
            smallestChunkRequired = min(smallestChunkRequired, end - start + 1);
            currentFrequency[arr[start]]--;
            start++;
        }
    }
    int totalRequired = accumulate(requiredFrequency.begin(), requiredFrequency.end(), 0);

    return smallestChunkRequired - totalRequired;
}
int main()
{
    int n{ 8 }, m{ 3 };

    vector<int>arr = { 3 ,3 ,1, 2, 2, 1, 1, 3 };
    vector<int>required = { 3,1,1 };

    cout << solve(n, m, arr, required);
    return 0;

}
