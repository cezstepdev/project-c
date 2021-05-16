#include "edycja.h"
#include "dodwys.h"
/*!funkcja add_found, funkcja ta dodaje elementy znalezione przez funkcje find do struktury;
\param p1 adres na ostatni znaleziony element
\param p2 wskaznik na dane kontaktu
*/
void add_found(struct founds **point,struct osoba *wsk)
{
    struct founds *nowy=(struct founds *)malloc(sizeof(struct founds));
    if(nowy!=NULL)
    {
        nowy->data=wsk;
        nowy->next=*point;
        *point=nowy;
    }
}
/*!funkcja del_found, usuwa strukture znalezionych kontaktow;
\param p1 adres na ostatni znaleziony kontakt w strukturze
*/
void del_found(struct founds **point)
{
    while(*point!=NULL)
    {
        struct founds *tmp=(*point)->next;
        free(*point);
        *point=tmp;
    }
}
/*!funkcja find znajduje i wypisuje wszytkie kontakty z atrybutem podanym przez uzytkownika po polu wybranym przez uzytkownika na poczatku uzywa funkcji del_found w razie ponownego wyszukiwania;
\param p1 wskaznik na pierwszy kontakt
\param p2 wskaznik na strukture znalezonych kontaktow
\return wskaznik na strukture kontaktow znalezionych;
*/
struct founds *find(struct osoba *wsk,struct founds *point)
{
    del_found(&point);
    int wybor;
    char atrybut[30];

    printf("0. id\n1.Imie\n2.Nazwisko\n3.miasto\n4.ulica\n5.nr domu\n6.kod pocztowy\n7.poczta\n8.telefon\n9.email\n");

    printf("Po czym znalezc uzytkownika: ");
    scanf("%d",&wybor);
    printf("Jakiego atrybutu szukac: ");

    if(wybor==0)
    {
        scanf("%d",&wybor);
        while(wsk!=NULL)
        {
            if(wsk->ID==wybor)
            {
                show(wsk);
                add_found(&point,wsk);
                return point;
            }
                wsk=wsk->next;
        }
        return NULL;
     }

    scanf("%s",atrybut);
    switch(wybor)
    {
        case 1:
            while(wsk!=NULL)
            {
                if(strstr(wsk->imie,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 2:
            while(wsk!=NULL)
            {
                if(strstr(wsk->nazwisko,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 3:
            while(wsk!=NULL)
            {
                if(strstr(wsk->miasto.miasto,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 4:
            while(wsk!=NULL)
            {
                if(strstr(wsk->miasto.ulica,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 5:
            while(wsk!=NULL)
            {
                if(strstr(wsk->miasto.nr_domu,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 6:
            while(wsk!=NULL)
            {
                if(strstr(wsk->miasto.kod_pocztowy,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 7:
            while(wsk!=NULL)
            {
                if(strstr(wsk->miasto.poczta,atrybut)!=0)
                {
                    show(wsk);
                    add_found(&point,wsk);
                }
                wsk=wsk->next;
            }
            return point;
        case 8:
            while(wsk!=NULL)
            {
                while(wsk->telefon!=NULL)
                {
                    if(strstr(wsk->telefon->telefon,atrybut)!=0)
                    {
                        show(wsk);
                        add_found(&point,wsk);
                    }
                    wsk->telefon=wsk->telefon->next;
                }
                wsk=wsk->next;
            }
            return point;
        case 9:
            while(wsk!=NULL)
            {
                while(wsk->email!=NULL)
                {
                    if(strstr(wsk->email->email,atrybut)!=0)
                    {
                        show(wsk);
                        add_found(&point,wsk);
                    }
                    wsk->email=wsk->email->next;
                }
                wsk=wsk->next;
            }
            return point;
         default: printf("niepoprawny wybor\n");
     }
     return NULL;
}
/*!funkcja to_edit, okresla ona ktory kontakt ma byc edytowany
\param p1 wskaznik na pierwszy kontakt
\param p2 wskaznik na strukture znalezionych kontaktow
\return wskaznik na kontakt spelniajacy wszystkie kryteria podeane przez uzytkownika
*/
struct osoba *to_edit(struct osoba *wsk,struct founds *point)
{
    int id;
    do
    {
        point=find(wsk,point);
    }while(point==NULL && printf("Nie ma takiej osoby\n")!=0);

    struct founds *tmp=point;
    if(point->next==NULL)
        return point->data;

    do
    {
        point=tmp;
        printf("Podaj id kontaktu: ");
        scanf("%d",&id);

        while(point!=NULL && point->data->ID!=id)
            point=point->next;

    }while(point==NULL && printf("Podales nieprawidlowe id\n")!=0);

    return point->data;
};
/*!funkcja edit, edytuje wybrany dane kontaktu;
\param p1 wskaznik na edytowany kontakt
\param p2 wskaznik na strukture znalezionych kontaktow(argument dla funkcji to_edit)
*/
void edit(struct osoba *wskaznik,struct founds *point)
{
     struct osoba *wsk=to_edit(wskaznik,point);
     do
     {
        system("cls");
        printf("EDYTUJESZ!\n");
        show(wsk);
        char zmienna[20];
        int wybor;
        printf("wczytaj nowe dane:\n");
        printf("1. Imie\n");
        printf("2. Nazwisko\n");
        printf("3. Miasto\n");
        printf("4. Ulica\n");
        printf("5. Nr. domu\n");
        printf("6. Kod pocztowy\n");
        printf("7. Poczta\n");
        printf("8. Telefon\n");
        printf("9. Email\n");
        printf("10. Zakoncz edycje uzytkownika\n");
        printf("Co chcesz edytowac: ");
        scanf("%d",&wybor);

        if(wybor<8)
        {
            printf("podaj nowa dana: ");
            scanf("%s",zmienna);
        }
        switch(wybor)
        {
            case 10: return;
            case 1: strcpy(wsk->imie,zmienna);                  break;
            case 2: strcpy(wsk->nazwisko,zmienna);              break;
            case 3: strcpy(wsk->miasto.miasto,zmienna);         break;
            case 4: strcpy(wsk->miasto.ulica,zmienna);          break;
            case 5: strcpy(wsk->miasto.nr_domu,zmienna);        break;
            case 6: strcpy(wsk->miasto.kod_pocztowy,zmienna);   break;
            case 7: strcpy(wsk->miasto.poczta,zmienna);         break;
            case 8:
            {
                printf("ktory telefon edytowac\n");
                show(wsk);
                scanf("%s",zmienna);
                struct Telefon *tmp=wsk->telefon;
                while(tmp!=NULL && strcmp(tmp->telefon,zmienna))
                    tmp=tmp->next;
                if(tmp==NULL)
                {
                    printf("Uzytkownik nie ma takiego telefonu.\n");
                    break;
                }
                printf("podaj inny numer:\n");
                scanf("%s",zmienna);
                strcpy(tmp->telefon,zmienna);
            }                                      break;
            case 9:
            {
                printf("ktory email edytowac\n");
                show(wsk);
                scanf("%s",zmienna);
                struct Email *tmp=wsk->email;
                while(tmp!=NULL && strcmp(tmp->email,zmienna))
                    tmp=tmp->next;
                if(tmp==NULL)
                {
                    printf("Uzytkownik nie ma takiego emailu.\n");
                    break;
                }
                printf("podaj inny numer:\n");
                scanf("%s",zmienna);
                strcpy(tmp->email,zmienna);
            }                                      break;
            default: printf("niepoprawny wybor\n");
        }
        printf("Czy chcesz dalej edytowac tego uzytkownika?\n");
        printf("0. NIE      1. TAK\n");
        printf("Wybor: ");
        getchar();
     }while(getchar()!='0');
     del_found(&point);
 }
