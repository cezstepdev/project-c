#include "usuwanie.h"
#include "dodwys.h"
 void freeTelefon(struct Telefon **head)
{
    while(NULL != *head){
        struct Telefon *tmp=*head;
        *head=(*head)->next;
        free(tmp);
    }
}

void freeEmail(struct Email **head)
{
    while(NULL != *head){
        struct Email *tmp=*head;
        *head=(*head)->next;
        free(tmp);
    }
}

 void remove_by_ID(struct osoba **wsk, int ID)
{
    int wybor=1;
    if(NULL==*wsk) return;
    struct osoba * tmp= *wsk; // zapamiêtujemy pocz¹tek

    if(tmp->ID == ID){
         printf("wybrany kontakt\n");
         show(tmp);
            printf("czy naperno chcesz usunac ta kontakt\n 1. tak \n 0. nie ");
                  scanf("%d",&wybor);

do
{
    if(wybor!=1&&wybor!=0){
            printf("nieprawidlowy wybor\n ");
        printf("czy naperno chcesz usunac ten kontakt\n 1. tak \n 0. nie ");
    scanf("%d",&wybor);
    }
    if(wybor==1){
        //usuwanie z poczatku | OK?
            *wsk=(*wsk)->next;
            //(*wsk)->tmp=NULL;remove_by_ID
            freeEmail(&tmp->email);
            freeTelefon(&tmp->telefon);
            free(tmp);}

            return;
    }while(wybor!=1||wybor!=0);
}


    struct osoba *previous=tmp;
    tmp=tmp->next;

    while(tmp!= NULL && tmp->next != NULL){//usuwanie ze srodka
        if(tmp->ID == ID){
                printf("wybrany kontakt\n");
                 show(tmp);
                printf("czy naperno chcesz usunac ta kontakt\n 1. tak \n 0. nie ");
                  scanf("%d",&wybor);
do
{
    if(wybor!=1&&wybor!=0){
            printf("nieprawidlowy wybor2");
        printf("czy naperno chcesz usunac ten kontakt\n 1. tak \n 0. nie ");
    scanf("%d",&wybor);
    }
          if(wybor==1){
            //tmp->tmp->next=tmp->next;
            //tmp->next->tmp=tmp->tmp;
            previous->next=tmp->next;
            freeEmail(&tmp->email);
            freeTelefon(&tmp->telefon);
            free(tmp);}
            return;
            }while(wybor!=1||wybor!=0);
        }
        previous=tmp;
        tmp=tmp->next;
    }
    if(tmp->ID == ID){
            printf("wybrany kontakt\n");
            show(tmp);
            printf("czy naperno chcesz usunac ta kontakt\n 1. tak \n 0. nie ");
              scanf("%d",&wybor);
              do
{
    if(wybor!=1&&wybor!=0){
            printf("nieprawidlowy wybor3");
        printf("czy naperno chcesz usunac ten kontakt\n 1. tak \n 0. nie ");
    scanf("%d",&wybor);
    }
          if(wybor==1){
        //tmp->prev->next=NULL;
        previous->next=NULL;
        freeEmail(&tmp->email);
            freeTelefon(&tmp->telefon);
            free(tmp);}
            return;
            }while(wybor!=1||wybor!=0);
    }
}
/*!funckja pop usuwa i dealokuje pamiec po kontakcie
\param p1 adres na osobe
*/
void pop(struct osoba **wsk)
{
    while(*wsk!=NULL)
    {
        struct osoba *tmp=(*wsk)->next;
        while((*wsk)->telefon!=NULL)
        {
           struct Telefon *pomoc=(*wsk)->telefon->next;
           free((*wsk)->telefon);
           (*wsk)->telefon=pomoc;
        }
        while((*wsk)->email!=NULL)
        {
           struct Email *pom=(*wsk)->email->next;
           free((*wsk)->email);
           (*wsk)->email=pom;
        }
        free(*wsk);
        *wsk=tmp;
    }
}
