#include <iostream>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<cmath>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define spc " "
#define pb push_back
#define mp make_pair

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r=0,m;
    cout<<"Enter the total number of data bits"<<endl;
    cin>>m;
    while(pow(2,r)< r+m+1){
        r++;
    }
    cout<<"enter the bits\n";
    int a[10000];
    f(i,1,m){
        cin>>a[i];
    }
    int start = 1, end = m;
    while (start < end) 
    { 
        int temp = a[start];  
        a[start] = a[end]; 
        a[end] = temp; 
        start++; 
        end--; 
    }
    f(i,1,m){
        cout<<a[i];
    }
    int data[1000];
    int x = 0,y = 1;
    f(i,1,m+r){
        if(i == pow(2,x)){
            data[i] = 0;
            x++;
        }
        else{
            data[i] = a[y];
            y++;
        }
    }

    f(i,0,r-1){
        int count = 0;
        x = pow(2,i);
        for(int j=1;j<=m+r;j++){
            if((j&x) != 0 && j!=x){
                if(data[j]==1){
                    count++;
                }
            }
        }
        if(count%2==0){
            data[x] = 0;
        }
        else{
            data[x] = 1;
        }
    }
    cout<<"The bits are: "<<endl;

    f(i,1,m+r){
        cout<<data[i]<<spc;
    }

    cout<<"The error is generated at:"<<endl;
    int ans = 0;

    f(i,0,r-1){
        x = pow(2,i);
        ans = ans + x*data[x];
    }
    cout<<ans<<endl;




    
    return 0;
}
