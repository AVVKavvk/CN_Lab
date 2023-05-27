#include <bits/stdc++.h>

using namespace std;

class CRC
{

    string s, key, dividend, result, rem;
    int len_dividend, key_length, s_length;

public:
    string fun_xor(string a, string b)
    {

        string result = "";
        // cout<<a[0];
        if (a[0] == '0')
        {

            return a.substr(1);
        }
        else
        {
            for (int i = 0; i < key_length; i++)
            {

                result = result + (a[i] == b[i] ? '0' : '1');
            }
            return result.substr(1);
        }
    }

    void modulo_div()
    {

        string temp_div = key;
        string temp_divident = dividend.substr(0, key_length);


        int j = key_length;
        while (j < len_dividend)
        {

            temp_divident = fun_xor(temp_divident, temp_div);
            temp_divident = temp_divident + dividend[j];

            j++;
        }
        rem = fun_xor(temp_divident, temp_div);
        // cout<<"rem"<<temp_divident<<endl;
        result = s + rem;
    }

    void getdata()
    {

        cout << "ENTER THE DATA TO BE SENT BY THE SENDER : ";
        cin >> s;

        cout << "ENTER THE KEY BY WHICH THE DATA IS TO CHECKED : ";
        cin >> key;

        key_length = key.length();
        s_length = s.length();
        dividend = s;
        int r = key_length - 1;
        for (int i = 0; i < r; i++)
        {
            dividend = dividend + '0';
        }
        len_dividend = dividend.length();

        modulo_div();
    }

    void sender_side()
    {
        cout << "THE REMAINDER IS : " << rem << endl;
    }

    void receiver_side()
    {

        string r;
        cout << "ENTER THE DATA RECEIVED BY THE RECEIVER : ";
        cin >> r;

        string temp_div = key;
        string temp_divident = r.substr(0, key_length);
        int j = key_length;

        while ((j < r.length()))
        {
            temp_divident = fun_xor(temp_divident, temp_div);
            temp_divident = temp_divident + r[j];
            j++;
        }

        string error = fun_xor(temp_divident, temp_div);
        cout << endl
             << "THE REMAINDER IS : " << error << endl;

        bool flag = 1;
        if (count(error.begin(), error.end(), '0') == error.length())
            flag = 0;

        if (flag == 0)
            cout << "--NO ERROR IS PRESENT--" << endl;
        else
            cout << "--THERE IS AN ERROR PRESENT--" << endl;
    }
};

int main()
{

    CRC crc;

    crc.getdata();
    int option = 0;
    cout << "ENTER AN OPTION :" << endl
         << "1 : SENDER\n2 : RECEIVER\n3 : EXIT" << endl;

    while (option != 3)
    {

        cout << "\nOPTIOPN : ";
        cin >> option;
        switch (option)
        {
        case 1:
            crc.sender_side();
            break;
        case 2:
            crc.receiver_side();
            break;
        case 3:
            cout << "--PROGRAM EXITING--";
            break;

        default:
            cout << "INVALID OPTION";
            break;
        }
    }
}
