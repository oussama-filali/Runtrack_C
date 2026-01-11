#include "../album.h"

void push_front_album(struct album **list, struct album *node) {
    if (!list || !node) return;
    node->next = *list;
    *list = node;
}
