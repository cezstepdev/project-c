#include "sortowanie.h"
#include "dodwys.h"
/*!funkcja add_sort, dodaje ona kontakty w porzatku rosnacym
\param p1 adres na pierwszy element listy
\param p2 wskanik na dane kontaktu
\param p3 zmienna przechowujaca informacje o danym polu kontaktu
*/
void add_sort(struct sort **head,struct osoba *wsk,char data[20])
{
    struct sort *nowy=(struct sort *)malloc(sizeof(struct sort));
    struct sort *tmp=*head;
    if(nowy!=NULL)
    {
        nowy->data=wsk;
        nowy->next=NULL;
        strcpy(nowy->dane,data);
        if(tmp==NULL)
        {
            nowy->next=NULL;
            *head=nowy;
            return;
        }
        //insert front
        if(strcmp(data,tmp->dane)<=0)
        {
            nowy->next=tmp;
            *head=nowy;
        }
        else
        {
            struct sort *prev=NULL;
            //findspot
            while(tmp!=NULL && strcmp(data,tmp->dane)>=0)
            {
                prev=tmp;
                tmp=tmp->next;
            }
            //after
            if(prev->next!=NULL)
            {
                nowy->next=prev->next;
                prev->next=nowy;
            }
            //back
            else
                prev->next=nowy;
        }
    }
}
/*!funkcja add_sort, dodaje ona kontakty w porzatku malejacym
\param p1 adres na pierwszy element listy
\param p2 wskanik na dane kontaktu
\param p3 zmienna przechowujaca informacje o danym polu kontaktu
*/
void add_sort_dsc(struct sort **head,struct osoba *wsk,char data[20])
{
    struct sort *nowy=(struct sort *)malloc(sizeof(struct sort));
    struct sort *tmp=*head;
    if(nowy!=NULL)
    {
        nowy->data=wsk;
        nowy->next=NULL;
        strcpy(nowy->dane,data);
        if(tmp==NULL)
        {
            nowy->next=NULL;
            *head=nowy;
            return;
        }
        //insert front
        if(strcmp(data,tmp->dane)>=0)
        {
            nowy->next=tmp;
            *head=nowy;
        }
        else
        {
            struct sort *prev=NULL;
            //findspot
            while(tmp!=NULL && strcmp(data,tmp->dane)<=0)
            {
                prev=tmp;
                tmp=tmp->next;
            }
            //after
            if(prev->next!=NULL)
            {
                nowy->next=prev->next;
                prev->next=nowy;
            }
            //back
            else
                prev->next=nowy;
        }
    }
}
/*!funkcja sort_del, usuwa strukture posortowanych kontaktow
\param p1 adres na pierwszy element listy
*/
void sort_del(struct sort **wsk)
{
    while(*wsk!=NULL)
    {
        struct sort *tmp=(*wsk)->next;
        free(tmp);
        *wsk=tmp;
    }
}
/*!funkcja sort, wybiera ona pole oraz kolejnosc sortowania
\param p1 wskanik na pierwszy kontakt
\param p2 kolejnosc sortowania
\param p3 pole po ktorym maja byc sortowane kontakty
*/
void sort(struct osoba *wsk,int kolejnosc,int opcja)
{
    struct sort *pointer=NULL;
    if(wsk==NULL)
        return;
    if(kolejnosc==1)
    {
        while(wsk!=NULL)
        {
            switch(opcja)
            {
                case 0:
                {
                    char data[2];
                    sprintf(data,"%d",wsk->ID);
                    add_sort(&pointer,wsk,data);
                }break;
                case 1: add_sort(&pointer,wsk,wsk->imie); break;
                case 2: add_sort(&pointer,wsk,wsk->nazwisko); break;
                case 3: add_sort(&pointer,wsk,wsk->miasto.miasto); break;
                case 4: add_sort(&pointer,wsk,wsk->miasto.ulica); break;
                case 5: add_sort(&pointer,wsk,wsk->miasto.nr_domu); break;
                case 6: add_sort(&pointer,wsk,wsk->miasto.kod_pocztowy); break;
                case 7: add_sort(&pointer,wsk,wsk->miasto.poczta); break;
                case 8: add_sort(&pointer,wsk,wsk->telefon->telefon); break;
                case 9: add_sort(&pointer,wsk,wsk->email->email); break;
                default: printf("blad\n"); return;
            }
            wsk=wsk->next;
        }
    }
    else if(kolejnosc==2)
    {
        while(wsk!=NULL)
        {
            switch(opcja)
            {
                case 0:
                {
                    char data[2];
                    sprintf(data,"%d",wsk->ID);
                    add_sort(&pointer,wsk,data);
                }break;
                case 1: add_sort_dsc(&pointer,wsk,wsk->imie); break;
                case 2: add_sort_dsc(&pointer,wsk,wsk->nazwisko); break;
                case 3: add_sort_dsc(&pointer,wsk,wsk->miasto.miasto); break;
                case 4: add_sort_dsc(&pointer,wsk,wsk->miasto.ulica); break;
                case 5: add_sort_dsc(&pointer,wsk,wsk->miasto.nr_domu); break;
                case 6: add_sort_dsc(&pointer,wsk,wsk->miasto.kod_pocztowy); break;
                case 7: add_sort_dsc(&pointer,wsk,wsk->miasto.poczta); break;
                case 8: add_sort_dsc(&pointer,wsk,wsk->telefon->telefon); break;
                case 9: add_sort_dsc(&pointer,wsk,wsk->email->email); break;
                default: printf("blad\n"); return;
            }
            wsk=wsk->next;
        }
    }
    printf("posortowani:\n");
    while(pointer!=NULL)
    {
        show(pointer->data);
        struct sort *tmp=pointer->next;
        free(pointer);
        pointer=tmp;
    }
    sort_del(&pointer);
}
