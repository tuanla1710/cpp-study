#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
// cao độ của các nốt nhạc
#define do1 66 #define dod1 70 #define re1 73
#define red1 78 #define mi1 82 #define fa1 86
#define fad1 91 #define sol1 96 #define sold1 102
#define la1 108 #define lad1 115 #define si1 122
#define do2 130 #define dod2 139 #define re2 148
#define re2 148 #define red2 156 #define mi2 164
#define fa2 176 #define fad2 188 #define sol2 196
#define sold2 209 #define la2 230 #define lad2 233
#define si2 247 #define do3 264 #define dod3 281
#define re3 297 #define red3 313 #define mi3 330
#define fa3 352 #define fad3 374 #define sol3 396
#define sold3 415 #define la3 440 #define lad3 468
#define si3 495 #define do4 528 #define dod4 565
#define re4 594 #define red4 625 #define mi4 660
#define fa4 704 #define fad4 748 #define sol4 792
#define sold4 836 #define la4 880 #define lad4 935
#define si4 990 #define lang 30000
void not(unsigned caodo, float truongdo)
{ sound(caodo); delay(truongdo); nosound(); }
void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
int star[20] = {320, 150, 285, 225, 200, 225, 270, 270, 240, 350,
320, 300, 390, 350, 360, 270, 430, 225, 345, 225};
setbkcolor(RED); setcolor(YELLOW); // Vẽ lá cờ đỏ sao vàng
setfillstyle(SOLID_FILL, YELLOW);
fillpoly(10, star);
// Trường độ các nốt nhạc
float d = 300; // đen
float tr = 2*d; // trắng
float tro = 4*d; // tròn
float md = d/2; // móc đen
float mk = d/4; // móc kép
float m3 = d/8; // móc 3
float m4 = d/16; // móc 4
float dc = 3*d/2; // đen chấm
float trc = 3*d; // trắng chấm
float troc = 6*d; // tròn chấm
// Choi bai TQC
not(re2, d); not(mi2, d); not(re2, d); not(sol2, tr); not(sol2, tro);
not(la2, d); not(sol2, d); not(si2, tr); not(si2, tro); not(la2, d);
not(sol2, d); not(mi2, tr); not(sol2, tr); not(sol2, d); not(mi2, tro);
not(re2, d); not(si2, d); not(re2, tro); not(sol2, d); not(la2, d);
not(si2, tr); not(si2, tr); not(si2, tr); not(la2, d); not(sol2, d);
not(re3, tro); not(si2, d); not(sol2, d); not(la2, tr); not(la2, tr);
not(si2, tr); not(fad2, d); not(re2, d); not(sol2, tro); not(si2, d);
not(do3, d); not(re3, tr); not(re3, tr); not(mi3, tro); not(re3, d);
not(si2, tro); not(si2, tr); not(la2, d); not(sol2, tr); not(re2, tr);
not(fad2, tr); not(fad2, d); not(la2, d); not(sol2, tr); not(si2, d);
not(do3, d); not(re3, tr); not(re3, tr); not(mi3, tro); not(re3, d);
not(si2, tro); not(si2, tr); not(la2, d); not(sol2, tr); not(sol2, tr);
not(re2, tro); not(re3, tro); not(si2, tr); not(sol2, tr); not(mi3, tro);
not(re3, tr); not(si2, d); not(la2, d); not(re2, d); not(la2, tr);
not(la2, tro); not(si2, tr); not(sol2, tro);
closegraph();
}
