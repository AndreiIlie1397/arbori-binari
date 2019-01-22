#include <iostream>
using namespace std;
struct nod
{
    int info;
    nod *st, *dr;
};
nod *r;
nod* creare_adaugare()
{
    int x;
    nod*c;
    cout<<"Valoarea de adaugat in arbore: ";
    cin>>x;
    if(x!=0)
    {
        c=new nod;
        c->info=x;
        c->st=creare_adaugare();
        c->dr=creare_adaugare();
        return c;
    }
    else
        return 0;
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
void SRD(nod *c)
{
    if(c)
    {
        SRD(c->st);
        cout<<c->info<<" ";
        SRD(c->dr);
    }
}
void SDR(nod *c)
{
    if(c)
    {
        SDR(c->st);
        SDR(c->dr);
        cout<<c->info<<" ";
    }
}
void adaugare(nod *c)
{
    int x;
    nod *aux;
    while(c->dr)
        c=c->dr;
     cout<<endl<<"Valoarea de adaugat in arbore: ";
    cin>>x;
        aux=new nod;
        aux->info=x;
        c->dr=aux;
        aux->dr=0;
        aux->st=0;
}
void functie()
{
    cout<<endl;
    cout<<"Parcurgere RSD: ";
    RSD(r);
    cout<<endl;
    cout<<"Parcurgere SRD: ";
    SRD(r);
    cout<<endl;
    cout<<"Parcurgere SDR: ";
    SDR(r);
    cout<<endl;
}
int main()
{
    r=creare_adaugare();
    functie();
    adaugare(r);
    functie();
    return 0;
}
