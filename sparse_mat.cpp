#include<iostream>
using namespace std;

class Element{
    public:
    int i,j,x;
};

class sparse_mat{
    int n,m,num;
    Element *e;

    public:
    sparse_mat(int n,int m, int num){
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[num];
    }

    ~sparse_mat(){
        delete [] e;
    }
    sparse_mat operator+ (sparse_mat &s);
    friend istream & operator >> (istream &is,sparse_mat &s);
    friend ostream & operator << (ostream &os,sparse_mat &s);

};
    istream & operator >> (istream &is,sparse_mat &s){
        cout<<"enter non zero elements : ";
        for(int i =0;i<s.num;i++){
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;

        }
        return is;
    }

    ostream & operator << (ostream &os,sparse_mat &s){
        int k =0;
        for(int i =0;i<s.m;i++){
            for(int j=0;j<s.n;j++){
                if(s.e[k].i == i && s.e[k].j==j){
                    cout<<s.e[k].x<<" ";
                    k++;
                }
                else{
                    cout<<"0 ";
                }

            }
            cout<<"\n";
        }
        return os;

    }

    sparse_mat sparse_mat:: operator+ (sparse_mat &s){
        int i,j,k;
        sparse_mat *sum = new sparse_mat(m,n,num+s.num);
        if(m!=s.m || n!=s.n){
            return *sum;
        }
        
        i=j=k=0;
        while(i<num && j<s.num){
            if(e[i].i<s.e[j].i){
                sum->e[k++] = e[i++];
            }
            else if(e[i].i>s.e[j].i){
                sum->e[k++] = s.e[j++];
            }
            else{
                if(e[i].j<s.e[j].j){
                    sum->e[k++] = e[i++];
                }
                else if(e[i].j>s.e[j].j){
                    sum->e[k++] = s.e[j++];
                }
                else{
                    sum->e[k]=e[i];
                    sum->e[k++].x = e[i++].x + s.e[j++].x;


                }


            }
        }
        for(i;i<num;i++) sum->e[k++] = e[i];
        for(j;j<s.num;j++) sum->e[k++] = s.e[j];

        return *sum;


    }





int main(){
    sparse_mat s1(5,5,5);
    sparse_mat s2(5,5,5);
    cin>>s1;
    cin>>s2;


    cout<<s1<<"\n";
    cout<<s2<<"\n";
    sparse_mat sum = s1+s2;
    cout<<sum;


    return 0;
}