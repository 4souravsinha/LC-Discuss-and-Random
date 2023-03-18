/*
Problem Link: https://www.codechef.com/problems/SHIFTPAL
*/
#include<bits/stdc++.h>
using namespace std;
#define int                    long long
#define double                 long double
#define PI                     3.1415926535897932384626
#define mod                    (long long)1e18+9
#define inf                    (long long)5e18
#define minf                   -inf
#define pb                     push_back
#define all(x)                 x.begin(), x.end()
#define rall(x)                x.rbegin(), x.rend()
typedef pair<int , int>         pii;
typedef vector<int>            vi;
typedef vector<pii>            vpii;
typedef vector<vi>             vvi;
#define endl                   "\n"

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
    cerr<<endl;
#endif
}
inline void fileio()
{
#ifndef ONLINE_JUDGE

    // freopen("input.txt" , "r" , stdin);
    // freopen("output.txt" , "w" , stdout);
    freopen("error.txt" , "w" , stderr);
#endif
}
/* ========== YOUR CODE HERE ========= */
vi power((int)2e5 + 5);
void fillpow(int p , int org_sz)
{
    power[0] = 1;
    for(int i = 1 ; i < org_sz+1 ; i++)
    {
        power[i] = power[i-1] * p;
    }
}
bool check(int i , int j , string& s)
{
    while(i < j)
        if(s[i++] != s[j--])
            return false;
    return true;
}
void solve()
{
    int ans = 0;
    string s;
    cin>>s;
    int org_len = s.size();
    s += s;
    int new_len = s.size();
    int p = 2; //prime number with which we will multiply
    int k = 0 , i = 0;
    int hashval1 = 0;
    int hashval2 = 0;
    fillpow(p , org_len);
    for(i = 0 ; i < org_len ; i++)
    {
        int to_add = s[i] - 'a' + 1;
        hashval1 += (to_add * power[i]);
        hashval2 += (to_add * power[org_len - 1 - i]);
    }
    deb(hashval1 , hashval2);
    if(hashval1 == hashval2 and check(k , i - 1 , s)){ 
        ans++;
    }
        
    for(; i < new_len - 1 ; i++)
    {
        k++;
        int to_sub = s[k-1] - 'a' + 1;
        int to_add = s[i] - 'a' + 1;
        hashval1 = (hashval1 - to_sub) / p;
        hashval1 = hashval1 + to_add * power[org_len - 1];
        hashval2 =  (hashval2 - to_sub * power[org_len - 1]) * p;
        hashval2 = hashval2 + to_add * power[0];
        deb(hashval1 , hashval2);
        if(hashval1 == hashval2 and check(k , i , s))
        { 
            ans++;
        }
    }
    cout<<ans<<endl;
    return;
}
int32_t main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    fileio();

    // Start from here
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    cerr<<(int)1e18;
    return 0;
}

