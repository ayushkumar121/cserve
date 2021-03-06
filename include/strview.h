#ifndef STRVIEW_H
#define STRVIEW_H

typedef struct {
  int count;
  char *ptr;
} strview;

strview str(char *string);
int streq(strview a, strview b);

strview strsplit(strview view, char del);
strview strslice(strview view, int start, int count);

// strview strvcat(strview a, strview b);
// strview trim(strview str);

#endif /* STRVIEW_H */
