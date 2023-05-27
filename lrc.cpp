#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<string> vs;

    int row;
    cin >> row;
    int row1 = row;
    while (row--)
    {
        string s;
        cin >> s;
        vs.push_back(s);
        // 10001
        // 10011
        // 11110
    }

    int col = vs[0].size();
    vector<int> lrc;

    for (int i = 0; i < col; i++)
    {
        int ct = 0;
        for (int j = 0; j < vs.size(); j++)
        {
            ct += vs[j][i] - '0';
            // cout<<vs[j][i];
        }
        if (ct % 2)
        {
            lrc.push_back(1);
            continue;
        }
        lrc.push_back(0);
    }

    // message send => vs + lrc
    // for(auto it: lrc){
    //     cout<<it<<" ";
    // }
    cout << "Result ";
    for (int i = 0; i < lrc.size(); i++)
    {
        cout << lrc[i];
    }
    cout << '\n';

    // check
    vector<int> check;
    vector<string> vs1;
    cout << "enter reciver string ";
    string s1;
    while (row1--)
    {

        cin >> s1;
        vs1.push_back(s1);
    }

    for (int i = 0; i < col; i++)
    {
        int ct = 0;
        for (int j = 0; j < vs1.size(); j++)
        {
            ct += vs[j][i]-'0';
            // if (vs1[j][i] == '1')
            // {
            //     ct++;
            // }
        }
        if (ct % 2)
        {
            check.push_back(1);
            continue;
        }
        check.push_back(0);
    }
    bool f = 1;
    for (int i = 0; i < lrc.size(); i++)
    {
        if (check[i] != lrc[i])
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        cout << "No error"
             << "\n";
    }
    else
    {
        cout << "Error" << '\n';
    }

    return 0;
}