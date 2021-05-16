#ifndef SORTOWANIE_H_INCLUDED
#define SORTOWANIE_H_INCLUDED
#include "naglowki.h"
#include "struktury.h"
void add_sort(struct sort **head,struct osoba *wsk,char data[20]);
void add_sort_dsc(struct sort **head,struct osoba *wsk,char data[20]);
void sort_del(struct sort **wsk);
void sort(struct osoba *wsk,int kolejnosc,int opcja);

#endif // SORTOWANIE_H_INCLUDED
