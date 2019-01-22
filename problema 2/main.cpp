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
void RSD(nod *c)
{
    if(c)
    {
        cout<<c->info<<" ";
        RSD(c->st);
        RSD(c->dr);
    }
}
int search(nod *t, int x)
{
    if(t)
        if(t->info==x)
            return 1;
        else if(t->info<x)
            search(t->dr,x);
        else
            search(t->st,x);
    else
        return 0;
}
int findMax(nod *t)
{
    while(t->dr)
        t=t->dr;
    x=t->info;
    return x;
}
void cmd(nod *&t,nod *&f)
{
    nod *aux;
    if(f->dr)
        cmd(t,f->dr);
    else
    {
        t->info=f->info;
        aux=f;
        f=f->st;
        delete aux;
    }
}
void Delete(nod *&t,int x)
{
    nod *aux;
    if(t)
        if(t->info==x)
            if(t->st==0 && t->dr==0)
            {
                delete t;
                t=0;
            }
            else if(t->st==0)
            {
                aux=t->dr;
                delete t;
                t=aux;
            }
            else if(t->dr==0)
            {
                aux=t->st;
                delete t;
                t=aux;
            }
            else
                cmd(t,t->st);

        else if(t->info<x)
            Delete(t->dr,x);
        else
            Delete(t->st,x);

    else
        cout<<"valoarea de sters nu se gaseste in arbore "<<endl;
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
    RSD(prim);
    cout<<endl<<"Introduceti valoarea pe care doriti sa o adaugati in arbore: ";
    cin>>x;
    insert(prim, x);
    RSD(prim);
    cout<<endl<<"Introduceti elementul pe care doriti sa il cautati in arbore: ";
    cin>>x;
    cout<<search(prim, x);
    cout<<endl<<findMax(prim)<<endl;
    RSD(prim);
    cout<<endl<<"Introduceti elementul pe care doriti sa il stergeti din arbore: ";
    cin>>x;
    Delete(prim, x);
    RSD(prim);
    return 0;
}
