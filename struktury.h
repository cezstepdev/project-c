#ifndef STRUKTURY_H_INCLUDED
#define STRUKTURY_H_INCLUDED
#include "naglowki.h"
/*!struct Miasto, struktura przechowujaca dane zamieszkania kontaktu*/
struct Miasto
{
    char miasto[20];/*!<miejscowosc*/
    char ulica[20];/*!<ulica*/
    char nr_domu[10];/*!<numer domu*/
    char kod_pocztowy[8];/*!<kod pocztowy*/
    char poczta[20];/*!<poczta*/
};
/*!struct Telefon, struktura przechowujaca wszystkie nr. telefonow kontaktu*/
struct Telefon
{
    char telefon[10];/*!<numer telefonu*/
    struct Telefon *next;/*!<wskaznik na kolejny numer telefonu*/
};
/*!struct Email, struktura przechowujaca wszystkie adresy e-mail kontaktu*/
struct Email
{
    char email[30];/*!<adres e-mail*/
    struct Email *next;/*!<wskaznik na kolejny adres e-mail*/
};
/*!struct osoba, struktura przechowujaca wszystkie dane dot. kontaktu;
posiada ona wskazniki na telefony i e-maile kontaktu*/
struct osoba
{
    int ID;/*!<unikalne id kontaktu*/
    char imie[20];/*!<imie kontaktu*/
    char nazwisko[20];/*!<nazwisko kontaktu*/
    struct Miasto miasto;/*!<strktura w ktorej przechowywane sa dane na temat zamieszkania kontaktu*/
    struct Telefon *telefon;/*!<wskaznik na pierwszy telefon kontaktu*/
    struct Email *email;/*!<wskaznik na pierwszy adres e_mail kontaktu*/
    struct osoba *next;/*!<wskaznik na kolejny kontakt*/
};
/*!struct members, struktura w ktorej sa czlonkowie grupy kontkatow*/
struct members
{
    struct osoba *member;/*!<wskaznik na czlonka grupy*/
    struct members *next;/*!<wskaznik na kolejnego czlonka*/
};
/*!struct groups, struktura w ktorej przechowywane sa wskazniki na wszystkie grupy kontaktow oraz ich oznaczenia*/
struct groups
{
    int group_ID;
    char group_tag[20];/*!<zmienna w ktorej przechowywane jest oznaczenie grupy*/
    struct members *group;/*!<wskzanik na grupe kontaktow*/
    struct groups *next;/*!<wskaznik na kolejna grupe*/
};
/*!struct sort, struktura pomocnicza w ktorej sortujemy wszystkie kontakty*/
struct sort
{
    char dane[20];/*!<zmienna po ktorej sortujemy kontakty*/
    struct osoba *data;/*!<wskaznik na osobe*/
    struct sort *next;/*!<wskaznik na kolejna osobe*/
};
/*!struct founds, structtura pomocnicza w ktorej przechowujemy znalezione przez funkcje find kontakty*/
struct founds
{
    struct osoba *data;/*!<wskaznik na dane znalazionej osoby*/
    struct founds *next;/*!<wskaznik na kolejna znaleziona osobe*/
};





#endif // STRUKTURY_H_INCLUDED
