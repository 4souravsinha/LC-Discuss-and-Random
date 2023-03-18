/**
 * @file q1.cpp
 * @author Sourav Sinha
 * @brief Yandex | OA | Count common elements for prefixes(https://leetcode.com/discuss/interview-question/3305189/Yandex-or-OA-or-Count-common-elements-for-prefixes)
 * @version 0.1
 * @date 2023-03-18
 Given two lists of integers of length N. You need to return the number of common elements for all prefixes of length 1 to N.

    Example 1:

    Input:
    N = 4
    A = [1,1,2,3]
    B = [2,1,3,1]
    Output: [0,1,2,3]
    Example 2:

    Input:
    N = 4
    A = [1,1,1,1]
    B = [2,1,1,1]

    Output: [0,1,1,1]
    Note: solve with O(N) time and space complexity.

 */
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int N, vector<int> A, vector<int> B)
{
    unordered_map<int, int>countA;
    unordered_map<int, int>countB;
    int runningAns = 0;
    vector<int>ans;
    for (int i = 0; i < N; i++)
    {
        if (countA[B[i]] and !countB[B[i]])
            runningAns++;
        countB[B[i]]++;
        if (countB[A[i]] and !countA[A[i]])
            runningAns++;
        countA[A[i]]++;
        ans.push_back(runningAns);
    }
    return ans;
}
int main()
{
    int N{ 4 };
    vector<int>A{1, 1, 2, 3};
    vector<int>B{2, 1, 3, 1};

    auto ans = solve(N, A, B);
    for (auto& e : ans) cout << e << " ";
    return 0;
}