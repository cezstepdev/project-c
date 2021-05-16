#include "zapisplik.h"
#include "dodwys.h"

/*!funkcja to_program, wczytuje ona dane kontaktow z pliku baza_kontaktow.txt, odtwarza zapisane struktury danych;
\param p1 adres na pierwszy kontakt(czesciej jednak na NULL)
*/
void to_program(struct osoba **wsk)
{
    char zmienna[30];
    FILE *plik=fopen("baza kontaktow.txt","r");
    if(plik)
    while(!feof(plik))
    {
        struct osoba *nowy=(struct osoba *)malloc(sizeof(struct osoba));
        if(nowy!=NULL)
        {
            fscanf(plik,"%d ",&(nowy->ID));
            fscanf(plik,"%s ",nowy->imie);
            fscanf(plik,"%s ",nowy->nazwisko);
            fscanf(plik,"%s ",nowy->miasto.miasto);
            fscanf(plik,"%s ",nowy->miasto.ulica);
            fscanf(plik,"%s ",nowy->miasto.nr_domu);
            fscanf(plik,"%s ",nowy->miasto.kod_pocztowy);
            fscanf(plik,"%s\n",nowy->miasto.poczta);
            nowy->telefon=NULL;
            nowy->email=NULL;
            while(1)
            {
                fscanf(plik,"%s",zmienna);
                if(!strcmp(zmienna,"|"))
                    break;
                add_tel(&(nowy->telefon),zmienna);
            }
            while(1)
            {
                fscanf(plik,"%s",zmienna);
                if(!strcmp(zmienna,"|"))
                    break;
                add_mail(&(nowy->email),zmienna);
            }
            nowy->next=*wsk;
            (*wsk)=nowy;
        }
        else
        printf("Blad\n");
    }
      if(*wsk!=NULL)
        *wsk=(*wsk)->next;
    fclose(plik);
}
/*!funkcja to_file zapisuje ona strukture kotnaktow do pliku baza kontaktow.txt;
\param p1 wskaznik na pierwszy kontakt
\param p2 wskaznik na plik do zapisu
*/
void to_file(struct osoba *wsk,FILE *plik)
{
        fprintf(plik,"%d %s %s %s %s %s %s %s ",wsk->ID,wsk->imie,wsk->nazwisko,wsk->miasto.miasto,
        wsk->miasto.ulica,wsk->miasto.nr_domu,wsk->miasto.kod_pocztowy,wsk->miasto.poczta);
        struct Telefon *tmp=wsk->telefon;
        while(tmp!=NULL)
        {
            fprintf(plik,"%s ",tmp->telefon);
            tmp=tmp->next;
        }
        fprintf(plik,"| ");
        struct Email *pom=wsk->email;
        while(pom!=NULL)
        {
            fprintf(plik,"%s ",pom->email);
            pom=pom->next;
        }
        fprintf(plik,"|\n");
}
/*!funkcja save_groups, funkcja zapisuje struktury grup do pliku baza kontaktow-grupy.txt;
\param p1 wskaznik na pierwsza grupe kontaktow
*/
void save_groups(struct groups *wsk)
{
    FILE *plik=fopen("baza kontaktow-grupy.txt","w");
    while(wsk!=NULL)
    {
        fprintf(plik,"; %d %s ",wsk->group_ID,wsk->group_tag);
        struct members *tmp=wsk->group;
        while(tmp!=NULL)
        {
            if(tmp!=wsk->group)
                fprintf(plik,"+ ");
            to_file(tmp->member,plik);
            tmp=tmp->next;
        }
        fprintf(plik,"\n");
        wsk=wsk->next;
    }
    fclose(plik);
}
/*!funkcja save_contacts, pozwala ona zapisac uzytkownikowi kontakty do pliku baza kontaktow.txt;
\param p1 wskaznik na pierwszy kontakt
*/
void save_contacts(struct osoba *wsk)
{
    FILE *plik=fopen("baza kontaktow.txt","w");
    while(wsk!=NULL)
    {
        to_file(wsk,plik);
        wsk=wsk->next;
    }
    fclose(plik);
}
/*!funkcja czysc_plik, usuwa ona dane zapisane w plikach txt*/
void czysc_plik()
{
FILE *plik=fopen("baza kontaktow.txt","w");
fclose(plik);
FILE *plik2=fopen("baza kontaktow-grupy.txt","w");
fclose(plik2);
}
