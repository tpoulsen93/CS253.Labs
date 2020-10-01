#ifndef     CharCat_H
#define     CharCat_H

typedef struct {
    int count;
    char *name;
    char *chars;
} ChrCat;

typedef ChrCat ChrCats[];

extern ChrCats chrcats;

extern int charCount(char targetChar, ChrCat category);

#endif