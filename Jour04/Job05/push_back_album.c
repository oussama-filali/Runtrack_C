#include "../album.h"

void push_back_album(struct album **list, struct album *node) {
    if (!list || !node) return;
    node->next = NULL;
    if (!*list) {
        *list = node;
        return;
    }
    struct album *cur = *list;
    while (cur->next) cur = cur->next;
    cur->next = node;
}
