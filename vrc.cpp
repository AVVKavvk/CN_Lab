#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, p;
    cin >> p;
    s = p;
    if (count(s.begin(), s.end(), '1') % 2 == 1)
    {
        s += "1";
    }
    else
    {
        s += "0";
    }
    cout << "result " << s << endl;

    if (count(p.begin(), p.end(), '1') % 2 == 0)
    {
        cout << " error" << '\n';
    }
    else
    {
        cout << "No Error" << '\n';
    }

    // cout << '1' - '0';

    return 0;
}