/* author: gigawhiz */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool isSafe(int x, int y, vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueens(int x, int n, vector<vector<int>> &arr)
{
    if (x >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(x, i, arr))
        {
            arr[x][i] = 1;
            if (nQueens(x + 1, n, arr))
                return true;

            arr[x][i] = 0;
        }
    }
    return false;
}
int main()
{
    FIO;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        if (nQueens(0, n, arr))
        {
            for (auto x : arr)
            {
                for (auto y : x)
                    cout << y << " ";
                cout << endl;
            }
        }
    }
}
