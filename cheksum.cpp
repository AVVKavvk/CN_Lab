#include<bits/stdc++.h>
using namespace std;
int binary_decimal(string s[]){
    int i,N,decimal_number=0,p=0;
    N=s.size(); // storing the size of string in N
    for(i=N-1;i>=0;i--) // starting the loop from LSB
    {
        if(s[i]=='1') // Checking if string element is 1
        {
            decimal_number+=pow(2,p); // if yes, adding the pth power of 2 to the decimal_number
        }
        p++; // incrementing the value of p as we move towards MSB
    }
    return decimal_number;
}
int main(){
    int n;
    cout<<"Enter the no. of bits : ";
    cin>>n;
    char s[2][4];
    cout<<"Enter the string : ";
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<string>v;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            v[i].push_back(s[i][j]);
        }
    }

    int d=binary_decimal(v[0]);
    return 0;
    
}