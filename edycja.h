#ifndef EDYCJA_H_INCLUDED
#define EDYCJA_H_INCLUDED
#include "naglowki.h"
#include "struktury.h"
void add_found(struct founds **point,struct osoba *wsk);
void del_found(struct founds **point);
struct founds *find(struct osoba *wsk,struct founds *point);
struct osoba *to_edit(struct osoba *wsk,struct founds *point);
void edit(struct osoba *wskaznik,struct founds *point);

#endif // EDYCJA_H_INCLUDED
