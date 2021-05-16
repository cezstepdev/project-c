#ifndef USUWANIE_H_INCLUDED
#define USUWANIE_H_INCLUDED
#include "naglowki.h"
#include "struktury.h"
void freeTelefon(struct Telefon **head);
void freeEmail(struct Email **head);
void remove_by_ID(struct osoba **wsk, int ID);
void pop(struct osoba **wsk);


#endif // USUWANIE_H_INCLUDED
