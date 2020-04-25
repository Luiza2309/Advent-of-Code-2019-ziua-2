#include<bits/stdc++.h>
using namespace std;
int v[1000], w[1000], n;
void citire(int v[1000], int&n)
{
    ifstream f("numere.in");
    char l[10000];
    while(f.getline(l, 10000)){
        char*p=strtok(l, ",");
        while(p){
            int x=atoi(p);
            v[n++]=x;
            p=strtok(NULL, ",");
        }
    }
}
void fa_magia(int v[1000], int n)
{
    int i=0;
    while(v[i]!=99){
        if(v[i]==1)
            v[v[i+3]]=v[v[i+1]]+v[v[i+2]];
        else
        if(v[i]==2)
            v[v[i+3]]=v[v[i+1]]*v[v[i+2]];
        i=i+4;
    }
}
void copiaza(int a[], int b[])
{
    for(int i=0; i<n; i++)
        a[i]=b[i];
}
void afisare(int v[])
{
    for(int i=0; i<n; i++)
        cout<<v[i]<<',';
}
void cauta_manca_te_ar_mama()
{
    for(int i=0; i<=99; i++)
        for(int j=0; j<=99; j++){
            copiaza(w, v);
            w[1]=i; w[2]=j;
            fa_magia(w, n);
            if(w[0]==19690720)
                cout<<endl<<w[1]<<' '<<w[2];}
}
int main()
{
    citire(v, n);
    cauta_manca_te_ar_mama();
    afisare(w);
}
