#include<bits/stdc++.h>
using namespace std;

void solve(){
string a;cin>>a;
int m = a.length();
// checking for valid r value
int r = 0;
set<int> r_value;
int power_2 = 1;
while(power_2<m+r+1){
    r_value.insert(power_2);
power_2*=2;r++;

}
cout<<"value of r = " << r<<endl;
int ptr = 0;
reverse(a.begin(),a.end());
for(auto x : r_value)cout<<x<<" ";cout<<endl;
int arr[m+r];
for(int i=0;i<m+r;i++){
    auto it = r_value.find(i+1);
    
    if(it!=r_value.end()){
        arr[i]=-1;
       
    }
    else {
arr[i] = a[ptr] - 48; ptr++;
    }

}
reverse(arr,arr+m+r);
for(auto x : arr)cout<<x<<" ";cout<<endl;
    
    reverse(arr,arr+m+r);
for(int i=0;i<m+r;i++){
    if(arr[i]==-1){
        int sum = 0;
        int skip = i+2;
        bool f  = 0;
        int inner_loop = i+1;
    for(int k = i  ; k<m+r ; k+=skip){
        if(f==1)break;
        for(int j = 0 ; j<inner_loop ; j++){
           if(k+j>m+r-1){f=1;break;}
           if(arr[k+j]==-1){cout<<"R"<<inner_loop<<" ";}

           else cout<<arr[k+j]<<" ";

           if(arr[k+j]!=-1)sum+=arr[k+j];

        } k+=inner_loop-1;
    }
cout<<endl;

            if(sum%2==0)arr[i]=0;
            else arr[i] = 1;


    }
}
cout<<"Final answer"<<endl;
reverse(arr,arr+m+r);
for(auto x : arr)cout<<x<<" ";cout<<endl;
string inn;
cout<<"Reciever side"<<endl;
cin>>inn;

for(int i=0;i<inn.length();i++){
    if(arr[i]!=inn[i]-'0'){
        cout<<inn.length()-i<<endl;
    }
   
}

return;}
int main(){
    solve();
    return 0;
}