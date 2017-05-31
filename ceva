#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct nod
{
    string cuvant;
    nod urm, ant;
}*prim,*ultim;
int n = 0;
void adaugare(string cuvant)
{
    nod *nou = new nod;
    nou->cuvant = cuvant;
    nou->urm = NULL;
    nou->ant = NULL;
    if (prim == NULL)
    {
        prim = ultim = nou;
    }
    else
    {
        ultim->urm = nou;
        nou->ant = ultim;
        ultim = nou;
    }

}
void inseraredupa(nod *&p, string cuvant)
{
    if (p == NULL)
    {
        adaugare(cuvant);
    }
    else
    {
        if (p == ultim)
        {
            adaugare(cuvant);
        }
        else
        {
            nod *nou = new nod;
            nou->cuvant = cuvant;
            nou->ant = p;
            nou->urm = p->urm;
            p->urm->ant = nou;
            p->urm = nou;
        }

    }
}
void inserare_inainte(nod *&p, string cuvant)
{
    if (p == NULL)
    {
        adaugare(cuvant);
    }
    else
    {
        if (p == prim)
        {
            nod *nou = new nod;
            nou->cuvant = cuvant;
            nou->urm = prim;
            prim->ant = nou;
            prim = nou;
        }
        else
        {
            nod *nou = new nod;
            nou->cuvant = cuvant;
            nou->ant = p->ant;
            nou->urm = p;
            p->ant->urm = nou;
            p->ant = nou;
        }
    }
}
void cauta_insereaza(string cauta, string cuvant,int rasp)
{
    if (prim == NULL)
    {
        adaugare(cuvant);
    }
    else
    {
        nod *p = prim;
        bool gasit = false;
        while (p->urm != NULL)
        {
            if (p->cuvant == cauta)
            {
                if (rasp == 1)
                {
                    gasit = true;
                    inserare_inainte(p, cuvant);
                }
                else if (rasp == 2)
                {
                    gasit = true;
                    inseraredupa(p, cuvant);
                }
                p = p->urm;
            }
            p = p->urm;
        }
        if (!gasit)
        {
            adaugare(cuvant);
        }
    }
}

void del(nod *p)
{
    p->ant->urm = p->urm;
    p->urm->ant = p->ant;
}
void cauta_delete(string cauta)
{
    if (prim != NULL)
    {
        nod *p = prim;
        while (p != NULL)
        {
            if (p->cuvant == cauta)
            {
                if (p == ultim)
                {
                    n--;
                    if (n <= 0)
                    {
                        prim = ultim = NULL;
                        break;
                    }
                    else
                    {
                        ultim = ultim->ant;
                        ultim->urm = NULL;
                    }
                }
                else if (p==prim)
                {
                    n--;
                    if (n <= 0)
                    {
                        prim = ultim = NULL;
                        break;
                    }
                    else
                    {
                        prim = prim->urm;
                        prim->ant = NULL;
                    }
                }
                else
                {
                    n--;
                    if (n <= 0)
                    {
                        prim = ultim = NULL;
                        break;
                    }
                    else
                    {
                        del(p);
                    }
                }
            }
            p = p->urm;
        }
    }
}
void afisare1(nod *p)
{
    if (p != NULL)
    {
        cout << p->cuvant << " ";
        afisare1(p->urm);
    }
}
void afisare2(nod *p)
{
    while (p != NULL)
    {
        cout << p->cuvant<<" ";
        p = p->ant;
    }
}

int main()
{
    int rasp;
    string cuvant;
    string cauta;
    do
    {
            system("cls");
        cout << "1.Insereaza cuvant inaintea cuvantului cautat"<<endl;
         cout << "2.Insereaza cuvant dupa cuvant cautat"<<endl;
         cout << "3.Sterge cuvant cauta"<<endl;
         cout << "4.Afiseaza de la stanga la drapta"<<endl;
         cout << "5.Afiseaza de la drapta la stanga"<<endl;


        cin >> rasp;

        switch (rasp)
        {
        case 1:
            cout<<"Cuvantul cautat: ";
            cin>>cauta;
            cout<<"Cuvantul de inserat: ";
            cin >>cuvant;
            cauta_insereaza(cauta, cuvant, 1);
            n++;
            break;
        case 2:
            cout<<"Cuvantul cautat: ";
            cin>>cauta;
            cout<<"Cuvantul de inserat: ";
            cin >>cuvant;
            cauta_insereaza(cauta, cuvant, 2);
            n++;
            break;
        case 3:
            cout<<"Cuvantul de sters: ";
            cin >> cauta;
            cauta_delete(cauta);
            break;
        case 4:
            afisare1(prim);
            break;
        case 5:
            afisare2(ultim);
            break;
        } system("pause");
    }
    while (rasp<=5);
}
