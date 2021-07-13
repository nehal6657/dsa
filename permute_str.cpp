#include<iostream>
using namespace std;
void perm(char s[],int k){
    static int a[10] = {0};
    static char res[10];
    int i;
    if(s[k]=='\0'){
        cout<<res<<"\n";
    }
    else{
        for(i=0;s[i]!='\0';i++){
            if(a[i]==0){
                res[k]=s[i];
                a[i]=1;
                perm(s,k+1);
                a[i]=0;
            }

        }
    }
}
void perm1(char s[], int l, int h){
    int i;
    if(l==h){
        cout<<s<<"\n";
    }
    else{
        for(i = l;i<=h;i++){
            swap(s[i],s[l]);
            perm1(s,l+1,h);
            swap(s[i],s[l]);

        }


    }

    
}

int main(){
    char s[]="ABCD";
    perm1(s,0,3);

    return 0;
}