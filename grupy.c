#include "grupy.h"
/*!funkcja group_ID, wyznacza ona id dla towrzonej grupy
\param p1 wskaznik na pierwsza grupe
\return pierwsze wolne id
*/
int group_ID(struct groups *wsk)
{
    int id=1;
    struct groups *start=wsk;
    if(wsk==NULL)
        return id;
    while(wsk!=NULL)
    {
        if(id==wsk->group_ID)
        {
            wsk=start;
            id++;
        }
        else
            wsk=wsk->next;
    }
    return id;
}
/*!funkcja add_to_group, dodaje ona kontakt do grupy kontaktow;
\param p1 adres na pierwszego czlonka grupy
\param p2 wskaznik na dane kontaktu
*/
void add_to_group(struct members **wsk,struct osoba *data)
{
    struct members *nowy=(struct members *)malloc(sizeof(struct members));
    if(nowy!=NULL)
    {
        nowy->member=data;
        nowy->next=(*wsk);
        (*wsk)=nowy;
    }
}
/*!funkcja create_group, tworzy ona nowa grupe kontaktow, nadaje im oznaczenie oraz sprawdza jego unikalnosc
\param p1 adres na pierwsza grupe
\param p2 wskaznik na dane kontaktu
\param p3 oznaczenie grupy
\param p4 id grupy
\return flaga powodzenia
*/
int create_group(struct groups **wsk,struct osoba *data,char group_tag[20],int group_ID)
{
    struct groups *nowy=(struct groups *)malloc(sizeof(struct groups));
    struct groups *tmp=*wsk;
    if(nowy!=NULL)
    {
        nowy->group=NULL;
        while(tmp!=NULL)
        {
            if(!strcmp(group_tag,tmp->group_tag))
            {
                printf("Istnieje juz taka grupa\n");
                return -1;
            }
            tmp=tmp->next;
        }
        nowy->group_ID=group_ID;
        strcpy(nowy->group_tag,group_tag);
        add_to_group(&(nowy->group),data);
        nowy->next=(*wsk);
        (*wsk)=nowy;
    }
    return 1;
}
/*!funkcja add_group, pobiera ona od uzytkowanika oznaczenie grupy dopoki to sie powtarza;
\param p1 adres na pierwsza grupe
\param p2 wskaznik na dane kontaktu
*/
void add_group(struct groups **point,struct osoba *wsk)
{
    char group_tag[20];
    do
    {
            printf("podaj nazwe grupy: ");
            scanf("%s",group_tag);
    }while(create_group(point,wsk,group_tag,group_ID(*point))<0);
}
/*!funkcja load_groups, wczytuje ona strktury grup do progrmau z pliku baza kontaktow-grupy.txt;
\param p1 adres na pierwsza grupe(najczesciej na NULL)
\param p2 wskaznik na pierwszy kontakt
*/
void load_groups(struct groups **wsk,struct osoba *data)
{

    if(data==NULL)
        return;
    char zmienna[30];
    char group_tag[20];
    int id;
    int group_ID;
    FILE *plik=fopen("baza kontaktow-grupy.txt","r");
    if(plik!=NULL)
    {
        while(!feof(plik))
        {
            struct osoba *point=data;
            fscanf(plik,"%s",zmienna);

            if(!strcmp(zmienna,"+") || !strcmp(zmienna,";"))
            {
                if(!strcmp(zmienna,";"))
                {
                    fscanf(plik,"%d",&group_ID);
                    fscanf(plik,"%s",group_tag);
                }
                fscanf(plik,"%d",&id);
                while(point!=NULL)
                {
                    if(point->ID!=id)
                        point=point->next;
                    else
                        break;
                }
            }
            if(!strcmp(zmienna,";"))
                create_group(wsk,point,group_tag,group_ID);
            else if(!strcmp(zmienna,"+"))
                add_to_group(&((*wsk)->group),point);
        }
    }
    fclose(plik);
}

/*!funkcja find,
\param p1 wskaznik na pierwsza grupe
\param p2 znacznik grupy
\return adres grupy z podanym w parametrze znacznikiem grupy
*/
struct members **find_group(struct groups *wsk)
{
    int wybor,group_ID;
    char group_tag[20];
    printf("Po czym znalezc grupe\n");
    printf("1. ID\n");
    printf("2. Group Tag\n");
    printf("Wybor: ");
    scanf("%d",&wybor);
    if(wybor==1)
    {
        printf("Podaj ID grupy: ");
        scanf("%d",&group_ID);
        while(wsk!=NULL)
        {
            if(wsk->group_ID==group_ID)
            {
                system("cls");
                printf("W grupie:\n");
            show_group(wsk->group);
                return &(wsk->group);
            }
            wsk=wsk->next;
        }
        return NULL;
    }
    else if(wybor==2)
    {
        printf("Podaj oznaczenie grupy: ");
        scanf("%s",group_tag);
        while(wsk!=NULL)
        {
            if(strcmp(wsk->group_tag,group_tag)==0)
            {
                system("cls");
                printf("W grupie:\n");
                show_group(wsk->group);
                return &(wsk->group);
            }
            else
                wsk=wsk->next;
        }
        return NULL;
    }
    else
    {
        printf("Niepoprawny wybor!\n");
        return NULL;
    }
}
/*!funkcja delete_from_group, usuwa ona czlonka z grupy
\param p1
\param p2 adres pierwszego czlonka z grupy
*/
void delete_from_group(struct osoba *member,struct members **front)
{
    if(*front==NULL)
    {
        printf("Brak grup w bazie!\n");
        return;
    }
    struct members *toFree = NULL;//Pomocniczy wskaznik na strukture

    if((*front)->member == member) {
        toFree = *front;
        if((*front)->next != NULL){
        *front = (*front)->next;}
        else
            *front = NULL;
        free(toFree);
    }
    else {
        struct members *prev = *front;
        toFree = (*front)->next;
        while(toFree->member != member) {
            prev = toFree;
            toFree = toFree->next;
        }
        if(toFree) {
            prev->next = toFree->next;
            free(toFree);
        }
    }
}
/*!funkcja del_groups dealokuje pamiec po strukturach grup
\param p1 adres na pierwsza grupe kontaktow
*/
void del_groups(struct groups **wsk)
{
    while(*wsk!=NULL)
    {
        while((*wsk)->group!=NULL)
        {
            struct members *tmp=(*wsk)->group->next;
            free((*wsk)->group);
            (*wsk)->group=tmp;
        }
        struct groups *tmp=(*wsk)->next;
        free(*wsk);
        *wsk=tmp;
    }
}

void del_if_empty(struct groups **wsk)
{
    if(*wsk==NULL)
        return;
    struct groups *tmp=*wsk;
    if(tmp->group==NULL)
    {
        (*wsk)=tmp->next;
    }
    else
    {
        struct groups *prev=NULL;
        while(tmp!=NULL && tmp->group!=NULL)
        {
            prev=tmp;
            tmp=tmp->next;
        }

        if(tmp!=NULL)
        {
            prev->next=tmp->next;
            free(tmp);
        }
    }
}
