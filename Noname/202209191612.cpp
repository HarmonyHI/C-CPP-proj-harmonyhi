#include<bits/stdc++.h>
using namespace std;
int multi_func(int *ans_arr,int *serial_arr, int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=ans_arr[i]*serial_arr[i];
    }
    return ans;
}
bool all_one(int *data,int n){

    for(int i=0;i<n;i++){
        if(data[i]==false){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int goal;
    cin>>goal;
    int data[n+5];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    int choose[n+5]={0};
    int ans[500000];
    int ctr=0;
    while(true){
        int tans = multi_func(choose,data,n);
        if(tans>=goal){
            ans[ctr++]=tans;
        }
        if(all_one(choose,n)){
            break;
        }
        choose[n-1]++;
        for(int i=n-1;i>=0;i--){
            if(choose[i]>1){
                choose[i]=0;
                if(i!=0){
                    choose[i-1]++;
                }
            }
        }

    }
    int minx=ans[0];
        for(int i=1;i<ctr;i++){
        if(ans[i]<minx){
            minx=ans[i];
        }
    }
        cout<<minx<<endl;
}
