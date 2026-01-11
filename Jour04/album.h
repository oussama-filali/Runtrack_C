#ifndef ALBUM_H
#define ALBUM_H

#include <stddef.h>

struct album {
    char *artist;
    char *title;
    int year;
    struct album *next;
};

void print_album(struct album *a);
struct album *realloc_album(struct album *arr, size_t current_size, size_t new_size);
struct album *create_album(const char *artist, const char *title, int year);
void push_back_album(struct album **list, struct album *node);
void push_front_album(struct album **list, struct album *node);
void album_del_one(struct album **list, struct album *node);
void sort_album_by(struct album **list, int (*cmp)(const struct album *, const struct album *));

#endif
