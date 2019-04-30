#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

#define nil NULL


#define infok(p) (p)->infok
#define infoh(p) (p)->infoh
#define infos(p) (p)->infos
#define infor(p) (p)->infor
#define infou(p) (p)->infou
#define infob(p) (p)->infob

#define nextk(p) (p)->nextk
#define prevk(p) (p)->prevk
#define nextu(p) (p)->nextu
#define prevu(p) (p)->prevu
#define nextb(p) (p)->nextb

#define prevh(p) (p)->prevh
#define nexth(p) (p)->nexth
#define nexts(p) (p)->nexts
#define nextr(p) (p)->nextr


#define first(l) ((l).first)
#define last(l) ((l).last)

using namespace std;

typedef struct
{
    char kota[10];
    int hotels;
} infotypeK;

typedef struct
{
    char hotel[10];
    int suites;
} infotypeH;

typedef struct
{
    char suite[10];
    int rooms;
} infotypeS;

typedef struct
{
    char room[10];
    int rate;
    bool stats;
} infotypeR;

typedef struct admin
{
    char user[10];
    char pass[10];
}   infotypeAdm;

typedef struct user
{
    char user[20];
    char pass[20];
    int books;
} infotypeU;

typedef struct book
{
    char kota[10];
    char hotel[10];
    char suite[10];
    char room[10];
    int price;
} infotypeB;

typedef struct elekota *addresskota;
typedef struct elehotel *addresshotel;
typedef struct elesuite *addresssuite;
typedef struct eleroom *addressroomoom;

typedef struct eleuser *addressuser;
typedef struct elebook *addressbook;


typedef struct elekota
{
    infotypeK infok;
    addresskota nextk;
    addresskota prevk;
    addresshotel nexth;
} elementkota;

typedef struct elehotel
{
    infotypeH infoh;
    addresshotel nexth;
    addresshotel prevh;
    addresssuite nexts;
} elementhotel;

typedef struct elesuite
{
    infotypeS infos;
    addresssuite nexts;
    addressroomoom nextr;
} elementsuite;

typedef struct eleroom
{
    infotypeR infor;
    addressroomoom nextr;
} elementroom;

typedef struct eleuser
{
    infotypeU infou;
    addressuser nextu;
    addressuser prevu;
    addressbook nextb;
} elementuser;

typedef struct elebook
{
    infotypeB infob;
    addressbook nextb;
} elementbook;

typedef struct
{
    addresskota first;
    addresskota last;
} multilist;

typedef struct
{
    addressuser first;
    addressuser last;
} userlist;


addresskota alokasik(infotypeK x);
addresshotel alokasih(infotypeH x);
addresssuite alokasis(infotypeS x);
addressroomoom alokasir(infotypeR x);
addressbook alokasib(infotypeB x);


addresskota cariK(multilist l, infotypeK a);
addresshotel cariH(multilist l,addresskota k,infotypeH b);
addresssuite cariS(multilist l,addresshotel h,infotypeS c);
addressroomoom cariR(multilist l,addresssuite s,infotypeR d);


void InsertKota(multilist &l);
void InsertHotel(multilist &l);
void InsertSuite(multilist&l);
void InsertRoom(multilist&l);
void DefaultData(multilist&l);
void DefaultUser(userlist&m);

void ShowAllData(multilist l);
void ShowKota(multilist l);
void ShowHotel(multilist l,addresskota k);
void ShowSuite(multilist l,addresshotel h);
void ShowRoom(multilist l,addresssuite s);
void ShowBook(addressuser usr,userlist m);



void Login(multilist &l,userlist &m);
void LoginAdmin(multilist *l);
void UserMenu(addressuser usr,multilist &l,userlist &m);
void AdminMenu(multilist *l);
int CekAdmin(infotypeAdm a);

void Signup(userlist &m);
void ShowUser(userlist m);
addressuser cariU(userlist m,infotypeU x);
addressuser alokasiU(infotypeU x);

void dealokasik(addresskota &p);
void dealokasih(addresshotel &p);
void DeleteKota(multilist &l);
void DeleteHotel(multilist &l);
void CreateList(multilist *l,userlist *m);
addressuser CekUser(userlist m,infotypeU x);

void Booking(addressuser usr,multilist &l,userlist &m);
#endif
