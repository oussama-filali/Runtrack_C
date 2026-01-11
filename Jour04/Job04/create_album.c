#include "../album.h"
#include <stdlib.h>

static char *dup_str(const char *s) {
    if (!s) return NULL;
    size_t len = 0;
    while (s[len]) len++;
    char *p = (char *)malloc(len + 1);
    if (!p) return NULL;
    for (size_t i = 0; i < len; ++i) p[i] = s[i];
    p[len] = '\0';
    return p;
}

struct album *create_album(const char *artist, const char *title, int year) {
    struct album *a = (struct album *)malloc(sizeof(struct album));
    if (!a) return NULL;
    a->artist = dup_str(artist);
    a->title = dup_str(title);
    if ((artist && !a->artist) || (title && !a->title)) {
        if (a->artist) free(a->artist);
        if (a->title) free(a->title);
        free(a);
        return NULL;
    }
    a->year = year;
    a->next = NULL;
    return a;
}
