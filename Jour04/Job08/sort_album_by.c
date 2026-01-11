#include "../album.h"

void sort_album_by(struct album **list, int (*cmp)(const struct album *, const struct album *)) {
    if (!list || !cmp) return;
    struct album *sorted = NULL;
    struct album *cur = *list;
    while (cur) {
        struct album *next = cur->next;
        if (!sorted || cmp(cur, sorted) < 0) {
            cur->next = sorted;
            sorted = cur;
        } else {
            struct album *s = sorted;
            while (s->next && cmp(cur, s->next) >= 0) {
                s = s->next;
            }
            cur->next = s->next;
            s->next = cur;
        }
        cur = next;
    }
    *list = sorted;
}
