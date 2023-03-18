/*
Problem Link: https://www.spoj.com/problems/NAJPF/
*/
#include<bits/stdc++.h>
using namespace std;
#define int                    long long
#define double                 long double
#define PI                     3.1415926535897932384626
#define mod                    1000000007
#define inf                    LONG_LONG_MAX
#define minf                   LONG_LONG_MIN
#define pb                     push_back
#define F                      first
#define S                      second
#define all(x)                 x.begin(), x.end()
#define rall(x)                x.rbegin(), x.rend()
#define sortall(x)             sort(all(x))
typedef pair<int , int>         pii;
typedef vector<int>            vi;
typedef vector<pii>            vpii;
typedef vector<vi>             vvi;
#define endl                   "\n"
#define w(x)                   int x; cin >> x; while (x--)

/* Vector overload */
template <typename T> //vector output using <<
ostream& operator<<(ostream& os , const vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i] << " ";
    }
    return os;
}
template<typename T> //vector input using >>
std::istream& operator>>(std::istream& input , std::vector<T>& data)
{
    for (auto& item : data)
    {
        input >> item;
    }
    return input;
}

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)//debugger
template<typename ...Args>
void logger(string vars , Args&&... values)
{
#ifndef ONLINE_JUDGE //will debug only when not in oj
    cerr << vars << " = ";
    string delim = "";
    (... , (cerr << delim << values , delim = ", "));
#endif
}
inline void fileio()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt" , "w" , stderr);
#endif
}
/* ========== YOUR CODE HERE ========= */
bool check(string& s1 , string& s2 , int i)
{
    for (int j = 0; j < s2.size(); j++ , i++)
    {
        if (s2[j] != s1[i]) return false;
    }
    return true;
}
void solve(set<int>& st , string& s1 , string& s2)
{
    int m = 10009;
    int p = 7;
    int hash_s2 = 0;
    int s1_sz = s1.size() , s2_sz = s2.size();
    for (int i = 0; i < s2_sz; i++)
    {
        hash_s2 += (( int )s2[i]) * pow(p , i);
    }
    int curr_hash = 0;
    int i , k = 0;
    for (i = 0; i < s2_sz; i++)
    {
        curr_hash += (( int )s1[i]) * pow(p , i);
    }
    if (curr_hash == hash_s2)
    {
        if (check(s1 , s2 , k)) st.insert(k + 1);
    }
    for (; i < s1_sz; i++)
    {
        k++;
        curr_hash = (curr_hash - ( int )s1[k - 1]) / p;
        curr_hash = curr_hash + ( int )s1[i] * pow(p , s2_sz - 1);
        if (curr_hash == hash_s2)
        {
            if (check(s1 , s2 , k)) { st.insert(k + 1); }
        }
    }
}
int32_t main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    fileio();
    // Start from here
    int t; cin >> t;
    while (t--)
    {
        string s1 , s2;
        cin >> s1 >> s2;
        set<int>st;
        solve(st , s1 , s2);
        if (!st.size())
        {
            cout << "Not Found" << endl << endl;
            continue;
        }
        cout << st.size() << endl;
        for (auto& e : st)
            deb(e);
        cout << endl << endl;
    }
    return 0;
}


