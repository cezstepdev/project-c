#ifndef GRUPY_H_INCLUDED
#define GRUPY_H_INCLUDED
#include "naglowki.h"
#include "struktury.h"
#include "dodwys.h"
int group_ID(struct groups *wsk);
void add_to_group(struct members **wsk,struct osoba *data);
int create_group(struct groups **wsk,struct osoba *data,char group_tag[20],int group_ID);
void add_group(struct groups **point,struct osoba *wsk);
void load_groups(struct groups **wsk,struct osoba *data);
struct members **find_group(struct groups *wsk);
void delete_from_group(struct osoba *member,struct members **front);
void del_groups(struct groups **wsk);
void del_if_empty(struct groups **wsk);
#endif // GRUPY_H_INCLUDED
