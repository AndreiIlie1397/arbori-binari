#include<iostream>
using namespace std;
struct nod
{
    int info;
    nod *st,*dr;
};
nod *prim;
int nr, x;
void insert(nod *&t, int x)
{
    if(t)
        if(t->info==x)
            cout<<"Element deja inserat "<<endl;
        else if(t->info<x)
            insert(t->dr, x);
        else
            insert(t->st, x);
    else
    {
        t=new nod;
        t->info=x;
        t->st=t->dr=0;
    }
}
void afisare(nod *c, int k1, int k2)
{
    if(c)
    {
        if(k1<=c->info && k2>=c->info)
            cout<<c->info<<" ";
            afisare(c->st, k1, k2);
            afisare(c->dr, k1, k2);
    }
}
int main()
{
    int k1, k2;
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    for(int i=1; i<=nr; i++)
    {
        cout<<"valoarea de inserat ";
        cin>>x;
        insert(prim, x);
    }
    cout<<"Introduceti capatul din stanga al intervalului: ";
    cin>>k1;
    cout<<"Introduceti capatul din dreapta al intervalului: ";
    cin>>k2;
    afisare(prim, k1, k2);
    return 0;
}
