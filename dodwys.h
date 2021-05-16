#ifndef DODWYS_H_INCLUDED
#define DODWYS_H_INCLUDED
#include "naglowki.h"
#include "struktury.h"
void show_tel(struct Telefon *wsk);
void show_mail(struct Email *wsk);
void show(struct osoba *wsk);
void show_group(struct members *wsk);
void show_groups(struct groups *wsk);
int id(struct osoba *wsk);
void add_tel(struct Telefon **wsk,char zmienna[30]);
void add_mail(struct Email **wsk,char zmienna[30]);
void add(struct osoba **wsk);
void print_list(struct osoba *wsk);

#endif // DODWYS_H_INCLUDED
