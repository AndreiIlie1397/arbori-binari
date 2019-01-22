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
void afisare(nod *c)
{
    if(c)
    {
        afisare(c->st);
        cout<<c->info<<" ";
        afisare(c->dr);
    }
}
int main()
{
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    for(int i=1; i<=nr; i++)
    {
        cout<<"valoarea de inserat ";
        cin>>x;
        insert(prim, x);
    }
    afisare(prim);
    return 0;
}
