#include<bits/stdc++.h>
using namespace std;
int anss[2000];
int aactr=0;
int bnss[2000];
int bbctr=0;
class info{
public:
    int key;
    int value;
};
class user{
public:
    int DN;
    info myinfo[510];
    int infon;
    user(){
        infon=0;
    }
};
int cifang(int a){
    int ans=1;
    for(int i=0;i<a;i++){
        ans=ans*10;
    }
    return ans;
}

void info_find(user* arr, int n, int key, int value,bool is_yes){
    bool is_printed=false;
    if(is_yes){
        for(int i=0;i<n;i++){
            int infon=arr[i].infon;
            for(int ii=0;ii<infon;ii++){
                if(arr[i].myinfo[ii].key==key&&arr[i].myinfo[ii].value==value){
                    anss[aactr++]=arr[i].DN;
                    if(is_printed){
                        cout<<" "<<arr[i].DN;
                    }
                    else{
                        cout<<arr[i].DN;
                        is_printed=true;
                    }
                    break;
                }
            }
        }
        cout<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            int infon=arr[i].infon;
            for(int ii=0;ii<infon;ii++){
                if(arr[i].myinfo[ii].key==key&&arr[i].myinfo[ii].value!=value){
                        bnss[bbctr++]=arr[i].DN;
                    if(is_printed){
                        cout<<" "<<arr[i].DN;
                    }
                    else{
                        cout<<arr[i].DN;
                        is_printed=true;
                    }
                    break;
                }
            }
        }
        cout<<endl;
    }

}

void singlesolve(char *so, user* arr, int n){
    char s[2010];
    int sctr=0;

    for(int i=strlen(so)-1;i>=0;i--){
        s[sctr++]=so[i];
    }
    s[sctr]=0;

    bool to_b=true;
    int aans=0,ai=0;
    int bans=0,bi=0;
    bool is_yes;

    for(int i=0;i<strlen(s);i++){
        if(s[i]==':'||s[i]=='~'){
            to_b=false;
            if(s[i]==':'){
                is_yes=true;
            }
            else{
                is_yes=false;
            }
        }
        else if(to_b){
            bans+=((s[i]-'0')*cifang(bi++));
        }
        else{
            aans+=((s[i]-'0')*cifang(ai++));
        }
    }
    info_find(arr,n,aans,bans,is_yes);
}
void mulsolve(char *s, user* arr, int n){
    char newa[2500],newb[2500];
    int actr=0,bctr=0,ctr=2;
    for(;s[ctr]!=')';ctr++){
        newa[actr++]=s[ctr];
    }
    newa[actr]=0;

    ctr=ctr+2;
    for(;s[ctr]!=')';ctr++){
        newb[bctr++]=s[ctr];
    }
    newb[bctr]=0;
    singlesolve(newa,arr,n);
    singlesolve(newb,arr,n);

}
void solve(user* arr, int n){
    char s[2050];
    cin>>s;
    int ok=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='&'||s[i]=='|'){
            //mulsolve(s,arr,n);
            ok=1;
            break;
        }
    }
    if(ok==0){
        singlesolve(s,arr,n);
    }
}
int main(){
    int usern,requestn;
    user userarr[250];
    cin>>usern;
    for(int i=0;i<usern;i++){
        int tmpdn;
        cin>>tmpdn;
        userarr[i].DN=tmpdn;
        int infonum;
        cin>>infonum;
        for(int ii=0;ii<infonum;ii++){
            cin>>userarr[i].myinfo[ii].key;
            cin>>userarr[i].myinfo[ii].value;
            userarr[i].infon=userarr[i].infon+1;
        }
    }
    cin>>requestn;
    for(int i=0;i<requestn;i++){
        solve(userarr,usern);
    }
}
