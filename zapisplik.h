#ifndef ZAPISPLIK_H_INCLUDED
#define ZAPISPLIK_H_INCLUDED
#include "naglowki.h"
#include "struktury.h"
void to_program(struct osoba **wsk);
void to_file(struct osoba *wsk,FILE *plik);
void save_groups(struct groups *wsk);
void save_contacts(struct osoba *wsk);
void czysc_plik();

#endif // ZAPISPLIK_H_INCLUDED
