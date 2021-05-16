#include "dodwys.h"
/*!funkcja show_tel, wypisuje ona wszystkie nr. telefonu kontaktu;
\param p1 wskaznik na pierwszy nr. kontaktu
*/
void show_tel(struct Telefon *wsk)
{
    if(wsk!=NULL)
    {
        printf("NR TELEFONU %s ",wsk->telefon);
        show_tel(wsk->next);
    }
}
/*!funkcja show_mail, wypisuje ona wszystkie adresy e-mail kontaktu;
\param p1 wskaznik na pierwszy adres e-mail
*/
void show_mail(struct Email *wsk)
{
    if(wsk!=NULL)
    {
        printf("MAIL %s",wsk->email);
        show_mail(wsk->next);
    }
}
/*!funkcja show, wypisuje ona wszystkie kontakty;
\param p1 wskaznik na pierwszy kontakt
*/
void show(struct osoba *wsk)
{
    if(wsk!=NULL)
    {
    printf("id: %d IMIE: %s NAZWISKO: %s MIASTO: %s ULICA: %s NR DOMU: %s KOD POCZTOWY: %s POCZTA: %s  ",wsk->ID,wsk->imie,wsk->nazwisko,wsk->miasto.miasto,
        wsk->miasto.ulica,wsk->miasto.nr_domu,wsk->miasto.kod_pocztowy,wsk->miasto.poczta);
        show_tel(wsk->telefon);
        show_mail(wsk->email);
        printf("\n");
    }
}
/*!funkcja show_group, wywoluje ona funkcje show ktorej parametr to wskaznik na kolejnych czlonkow grupy;
\param p1 wskaznik na pierwszego czlonka grupy
*/
void show_group(struct members *wsk)
{
    while(wsk!=NULL)
    {
        show(wsk->member);
        wsk=wsk->next;
    }
}
/*!funkcja show_groups, wypisuje ona oznaczenie grupy, wywoluje funkcje show_group ktorej parametr to kolejne grupy kontaktow;
\param p1 wskaznik na pierwsza grupe kontaktow
*/
void show_groups(struct groups *wsk)
{
    if(wsk==NULL)
    {
        printf("Brak grup w bazie\n");
        return;
    }

    while(wsk!=NULL)
    {
        printf("Grupa: %d %s\n",wsk->group_ID,wsk->group_tag);
        show_group(wsk->group);
        wsk=wsk->next;
    }
}
/*!funkcja id, przydziela ona id kazdemu nowo dodanemu kontaktowi przez uzytkownika;
\param p1 wskaznik na pierwszy kontakt
*/
int id(struct osoba *wsk)
{
    int id=1;
    struct osoba *start=wsk;
    if(wsk==NULL)
        return id;
    while(wsk!=NULL)
    {
        if(id==wsk->ID)
        {
            wsk=start;
            id++;
        }
        else
            wsk=wsk->next;
    }
    return id;
}
/*!funkcja add_tel, dodaje ona numer telefonu do kontaktu;
\param p1 adres ostatniego nr. telefonu
\param p2 kolejny nr kontaktu
*/
void add_tel(struct Telefon **wsk,char zmienna[30])
{
    struct Telefon *nowy=(struct Telefon *)malloc(sizeof(struct Telefon));
    if(nowy!=NULL)
    {
        strcpy(nowy->telefon,zmienna);
        nowy->next=(*wsk);
        (*wsk)=nowy;
    }
}
/*!funkcja add_mail, dodaje ona adres e-mail do kontaktu;
\param p1 adres na ostatni adres e-mail
\param p2 kolejny adres e-mail
*/
void add_mail(struct Email **wsk,char zmienna[30])
{
    struct Email *nowy=(struct Email *)malloc(sizeof(struct Email));
    if(nowy!=NULL)
    {
        strcpy(nowy->email,zmienna);
        nowy->next=(*wsk);
        (*wsk)=nowy;
    }
}
/*!funkcja add, dodaje ona nowy kontakt;
\param p1 adres na pierwszy kontakt
*/
void add(struct osoba **wsk)
{
    char zmienna[30];
    int czy_to_co_trzeba=0;
    struct osoba *nowy=(struct osoba *)malloc(sizeof(struct osoba));
    if(nowy!=NULL)
    {
        printf("Podaj imie: ");
        nowy->ID=id(*wsk);
        scanf("%s",nowy->imie);
         while(czy_to_co_trzeba!=strlen(nowy->imie)) {

                    czy_to_co_trzeba=0;
            if(strlen(nowy->imie)>=3){
                for(int i=0;i<strlen(nowy->imie);i++){
            if(!isdigit(nowy->imie[i])){
                    czy_to_co_trzeba++;  }

            }
             if (czy_to_co_trzeba!=strlen(nowy->imie)){
               printf("podano liczby w imieniu\n");
            printf("Podaj imie: ");
        scanf("%s",nowy->imie);
            }
            }
            else{
             printf("podano za krotkie imie\n");
            printf("Podaj imie: ");
        scanf("%s",nowy->imie);

            }

            }

         printf("Podaj nazwisko: ");
        scanf("%s",nowy->nazwisko);
         czy_to_co_trzeba=0;
                 while(czy_to_co_trzeba!=strlen(nowy->nazwisko)) {

                    czy_to_co_trzeba=0;
            if(strlen(nowy->nazwisko)>=2){
                for(int i=0;i<strlen(nowy->nazwisko);i++){
            if(!isdigit(nowy->nazwisko[i])){
                    czy_to_co_trzeba++;  }
            }
            if (czy_to_co_trzeba!=strlen(nowy->nazwisko)){
               printf("podano liczby w  nazwisku\n");
            printf("Podaj nazwisko: ");
        scanf("%s",nowy->nazwisko);
            }
            }
            else{
             printf("podano za krotkie nazwisko\n");
            printf("Podaj nazwisko: ");
        scanf("%s",nowy->nazwisko);

            }

            }
         printf("Podaj miasto(jesli w nazwie miasta wystepuja odstepty prosze wpisac'_'): ");
        scanf("%s",nowy->miasto.miasto);
        czy_to_co_trzeba=0;
                 while(czy_to_co_trzeba!=strlen(nowy->miasto.miasto)) {

                    czy_to_co_trzeba=0;
            if(strlen(nowy->miasto.miasto)>=2){
                for(int i=0;i<strlen(nowy->miasto.miasto);i++){
            if(!isdigit(nowy->miasto.miasto[i])){
                    czy_to_co_trzeba++;  }
            }
            if (czy_to_co_trzeba!=strlen(nowy->miasto.miasto)){
               printf("podano liczby w nazwie  miasta\n");
            printf("Podaj miasto: ");
        scanf("%s",nowy->miasto.miasto);
            }
            }
            else{
             printf("podano za krotkia nazwa  miasto\n");
            printf("Podaj miasto: ");
        scanf("%s",nowy->miasto.miasto);

            }

            }
         printf("Podaj ulice(jesli nie ma wpisz 'brak'): ");
        scanf("%s",nowy->miasto.ulica);
        while(strlen(nowy->miasto.ulica)<3){
                  printf("podano za krotkia nazwa  ulicy\n");
            printf("Podaj ulice: ");
        scanf("%s",nowy->miasto.ulica);
        }
         printf("Podaj nr domu: ");
        scanf("%s",nowy->miasto.nr_domu);
        czy_to_co_trzeba=0;
         while(czy_to_co_trzeba<1){
                czy_to_co_trzeba=0;
                for(int i=0;i<strlen(nowy->miasto.nr_domu);i++)
                 if(isdigit(nowy->miasto.nr_domu[i])){
                czy_to_co_trzeba++;
            }
            if(czy_to_co_trzeba<1){
                printf("podano niewlasciwy numer domu");
                 printf("Podaj nr domu: ");
        scanf("%s",nowy->miasto.nr_domu);
            }
         }
         printf("Podaj kod pocztowy: ");
        scanf("%s",nowy->miasto.kod_pocztowy);
            czy_to_co_trzeba=0;
         while(czy_to_co_trzeba!=6){
                czy_to_co_trzeba=0;
                  for(int i=0;i<2;i++)
                 if(isdigit(nowy->miasto.kod_pocztowy[i])){
                czy_to_co_trzeba++;
            }
                for(int i=3;i<strlen(nowy->miasto.kod_pocztowy);i++)
                 if(isdigit(nowy->miasto.kod_pocztowy[i])){
                czy_to_co_trzeba++;
            }
            if(nowy->miasto.kod_pocztowy[2]==45){
                czy_to_co_trzeba++;
            }
            if(czy_to_co_trzeba!=6){
                printf("podano niewlasciwy kod pocztowy");
                 printf("Podaj  kod pocztowy: ");
        scanf("%s",nowy->miasto.kod_pocztowy);
            }
         }
         printf("Podaj poczte: ");
        scanf("%s",nowy->miasto.poczta);
        czy_to_co_trzeba=0;
                while(czy_to_co_trzeba!=strlen(nowy->miasto.poczta)) {

                    czy_to_co_trzeba=0;
            if(strlen(nowy->miasto.poczta)>=2){
                for(int i=0;i<strlen(nowy->miasto.poczta);i++){
            if(!isdigit(nowy->miasto.poczta[i])){
                    czy_to_co_trzeba++;  }
            }
            if (czy_to_co_trzeba!=strlen(nowy->miasto.poczta)){
               printf("podano liczby w nazwie  poczty\n");
            printf("Podaj miasto: ");
        scanf("%s",nowy->miasto.poczta);
            }
            }
            else{
             printf("podano za krotkia nazwa  poczta\n");
            printf("Podaj poczta: ");
        scanf("%s",nowy->miasto.poczta);

            }

            }
        nowy->telefon=NULL;
        nowy->email=NULL;
        czy_to_co_trzeba=0;
        while(getchar()!=121)
        {
            printf("Podaj numer telefonu: ");
            scanf("%s",zmienna);
            while(czy_to_co_trzeba!=9) {
                    czy_to_co_trzeba=0;
            if(strlen(zmienna)==9){
                for(int i=0;i<10;i++){
            if(isdigit(zmienna[i])){
                czy_to_co_trzeba++;
            }}
              if (czy_to_co_trzeba!=9){
                printf("podano niewlasciwy numer\n");
                printf("Podaj numer telefonu: ");
            scanf("%s",zmienna);
            }
            }
            else{
                 printf("podano niewlasciwy numer\n");
                printf("Podaj numer telefonu: ");
            scanf("%s",zmienna);

            }

            }
            add_tel(&(nowy->telefon),zmienna);
            printf("Zakonczyc Y/N: ");
            getchar();
        }

        while(getchar()!=121)
        {
            printf("Podaj email: ");
            scanf("%s",zmienna);
            czy_to_co_trzeba=0;
            while(czy_to_co_trzeba!=2){
                    czy_to_co_trzeba=0;
            for(int i=0;i<strlen(zmienna);i++)
            {
                if(zmienna[i]==64||zmienna[i]==46){
                    czy_to_co_trzeba++;
                }
            }
            if(czy_to_co_trzeba!=2){
                  printf("podano niewlasciwy email\n");
                printf("Podaj email: ");
                    scanf("%s",zmienna);

            }}


            add_mail(&(nowy->email),zmienna);
            printf("Zakonczyc Y/N: ");
            getchar();

    }
        nowy->next=*wsk;
        (*wsk)=nowy;
    }
    else
        printf("Blad w tworzeniu kontaktu\n");
}
/*!funkcja print_list, wypisuje wszystkie kontakty
\param p1 wskaznik na pierwszy kontakt
*/
void print_list(struct osoba *wsk)
{
    while(wsk!=NULL)
    {
        show(wsk);
        wsk=wsk->next;
    }
}
