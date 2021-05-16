#include "struktury.h"
#include "dodwys.h"
#include "grupy.h"
#include "zapisplik.h"
#include "edycja.h"
#include "sortowanie.h"
#include "usuwanie.h"
int main()
{
    struct osoba *wsk=NULL;
    struct groups *point=NULL;
    struct founds *pointer=NULL;
    int wybor,idd;

    FILE *plik=fopen("baza kontaktow.txt","r");
    if(isdigit(getc(plik)))
    {
        fclose(plik);
        to_program(&wsk);
        load_groups(&point,wsk);
    }
    fclose(plik);
    printf("\nWITAJ W BAZIE KONTAKTOW!\n\n");
    do
    {
        if(wsk==NULL)
        {
            printf("plik pusty\n");
            printf("Mozesz dodac kontakt lub zakonczyc!\n");
            printf("0. Wyjdz\n");
            printf("1. Dodaj\n");
            printf("Wybierz opcje: ");
            scanf("%d",&wybor);
            if(wybor==1)
            {
                add(&wsk);
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
            }
            else
            {
                system("cls");
                printf("dowidzenia\n");
                return 1;
            }
        }

        ////////////////////
        printf("1.  dodaj kontakt\n2.  usun wybrany kontakt\n3.  wyswietl kontakty\n4.  wyswietl grupy \n5.  wyswietl posortowane \n6.  stworz grupe\n7.  dodaj do grupy\n8.  usun z grupy\n9.  edytuj kontakt\n10. czysc plik  \n0.  zamkinij program\n");
        ///////////////////
        printf("Wybierz opcje: ");
        scanf("%d",&wybor);
        system("cls");
        switch(wybor)
        {
            case 1: add(&wsk);
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 2:
            {
                printf("Podaj id do usuniecia: ");
                scanf("%d",&idd);
                remove_by_ID(&wsk,idd);
            }
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 3: print_list(wsk);
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 4: show_groups(point);
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 5:
            {
                system("cls");
                int kolejnosc,opcja;
                printf("1. Rosnaco\n");
                printf("2. Malejaco\n");
                printf("Jak sortowac: ");
                scanf("%d",&kolejnosc);
                printf("0. ID\n");
                printf("1. Imie\n");
                printf("2. Nazwisko\n");
                printf("3. Miejscowosc\n");
                printf("4. Ulica\n");
                printf("5. Nr. Mieszkania\n");
                printf("6. Kod pocztowy\n");
                printf("7. Poczta\n");
                printf("8. Telefon\n");
                printf("9. E-mail\n");
                printf("Po jakim polu sortowac: ");
                scanf("%d",&opcja);
                system("cls");
                sort(wsk,kolejnosc,opcja);
            }
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 6: printf("kogo dodac do nowej grupy?\n");
                add_group(&point,to_edit(wsk,pointer));
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 7:
            {
                if(point!=NULL)
                {
                    struct members **find=find_group(point);
                    if(find!=NULL)
                        add_to_group(find,to_edit(wsk,pointer));
                    else
                        printf("nie ma takiej grupy\n");
                }
                else
                    printf("Nie istnieja zadne grupy!\n");
            }
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 8:
            {
                if(point!=NULL)
                {
                    struct members **find=find_group(point);
                    if(find!=NULL)
                    {
                        delete_from_group(to_edit(wsk,pointer),find);
                        del_if_empty(&point);
                    }

                    else
                        printf("nie ma takiej grupy\n");
                }
                else
                    printf("Brak grup w bazie!\n");
            }
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 9: edit(wsk,pointer);
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");
                break;
            case 10:
            {
                while(wsk!=NULL)
                pop(&wsk);
                czysc_plik();
            }
                printf("Wcisnij dowolny klawisz aby przejsc do menu");
                getchar();getchar();
                system("cls");  break;
            case 0: system("cls");  printf("dowidzenia!\n");
                break;
            default: printf("niewlasciwy numer!\n"); break;
        }
    }while(wybor!=0);
    save_contacts(wsk);
    save_groups(point);
    del_groups(&point);
    while(wsk!=NULL)
        pop(&wsk);

    return 0;
}
