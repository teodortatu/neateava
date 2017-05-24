/**
lista dublu inlantuita cu nr mai mari ca 2
inainte is dupa fiecare nod al listei sa se insereze cate un nod nou cu informatia cel mai apropiat nr prim mai mic si respectiv mai mare decat inform din nodul selectat
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
struct lista
{
  int info;
  lista *urm,*ant;
}*prim,*ultim;
void adaugare(int x)
{
  lista *nou=new lista;
  nou->urm=nou->ant=NULL;
  nou->info=x;
  if(prim==NULL)
    prim=ultim=nou;
  else
  {
    ultim->urm=nou;
    nou->ant=ultim;
    ultim=nou;
  }
}
void afisare(lista *p)
{
  while(p!=NULL)
  {
    cout<<p->info<<' ';
    p=p->urm;
  }
  cout<<endl;
}
int fonctie_complicata(int x,int c)
{
  for(int d=2;d<=x/2;d++)
    if(x%d==0) return fonctie_complicata(x+c,c);
  return x;
}
void inserare_stanga(lista *p,int x)
{
  lista *nou=new lista;
  nou->info=x;
  if(p==prim)
  {
    prim->ant=nou;
    nou->urm=prim;
    nou->ant=NULL;
    prim=nou;
  }
  else
  {
    nou->ant=p->ant;
    p->ant->urm=nou;
    nou->urm=p;
    p->ant=nou;
  }
}
void inserare_dreapta(lista *p,int x)
{
  lista *nou=new lista;
  nou->info=x;
  if(p==ultim)
  {
    ultim->urm=nou;
    nou->ant=ultim;
    nou->urm=NULL;
    ultim=nou;
  }
  else
  {
    nou->ant=p;
    nou->urm=p->urm;
    p->urm->ant=nou;
    p->urm=nou;
  }
}
int main()
{
    int x;
  while(fin>>x)
    adaugare(x);
    afisare(prim);
    cout<<endl;
  lista *p=prim;
  while(p!=NULL)
  {
    inserare_stanga(p,fonctie_complicata(p->info-1,-1));
    inserare_dreapta(p,fonctie_complicata(p->info+1,1));
    p=p->urm->urm;
  }
  afisare (prim);
}
