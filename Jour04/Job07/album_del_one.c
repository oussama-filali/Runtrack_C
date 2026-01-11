#include "../album.h"
#include <stdlib.h>

void album_del_one(struct album **list, struct album *node) {
    if (!list || !*list || !node) return;
    struct album *cur = *list;
    if (cur == node) {
        *list = cur->next;
        if (cur->artist) free(cur->artist);
        if (cur->title) free(cur->title);
        free(cur);
        return;
    }
    while (cur->next && cur->next != node) {
        cur = cur->next;
    }
    if (cur->next == node) {
        cur->next = node->next;
        if (node->artist) free(node->artist);
        if (node->title) free(node->title);
        free(node);
    }
}
