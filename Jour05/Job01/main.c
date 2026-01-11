#include "../../Jour04/album.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void write_str(const char *s) {
    if (!s) return;
    const char *p = s;
    while (*p) p++;
    write(1, s, (size_t)(p - s));
}

static void write_line(const char *s) {
    write_str(s);
    write(1, "\n", 1);
}

static int str_cmp(const char *a, const char *b) {
    size_t i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return (int)((unsigned char)a[i] - (unsigned char)b[i]);
        i++;
    }
    return (int)((unsigned char)a[i] - (unsigned char)b[i]);
}

static int parse_int(const char *s, int *out) {
    if (!s || !*s) return 0;
    int sign = 1;
    int i = 0;
    if (s[0] == '-') { sign = -1; i = 1; }
    int val = 0;
    for (; s[i]; ++i) {
        if (s[i] < '0' || s[i] > '9') return 0;
        val = val * 10 + (s[i] - '0');
    }
    *out = val * sign;
    return 1;
}

static char *alloc_substr(const char *start, size_t len) {
    char *s = (char *)malloc(len + 1);
    if (!s) return NULL;
    for (size_t i = 0; i < len; ++i) s[i] = start[i];
    s[len] = '\0';
    return s;
}

static int cmp_artist(const struct album *a, const struct album *b) {
    return str_cmp(a->artist, b->artist);
}
static int cmp_title(const struct album *a, const struct album *b) {
    return str_cmp(a->title, b->title);
}
static int cmp_year(const struct album *a, const struct album *b) {
    return (a->year < b->year) ? -1 : (a->year > b->year);
}

static int parse_line_to_album(const char *line, struct album **out) {
    // find commas
    int c1 = -1, c2 = -1;
    int i = 0;
    while (line[i]) {
        if (line[i] == ',') { if (c1 < 0) c1 = i; else { c2 = i; break; } }
        i++;
    }
    if (c1 < 0 || c2 < 0) return 0;
    int len = 0; while (line[len]) len++;
    char *artist = alloc_substr(line, (size_t)c1);
    char *title = alloc_substr(line + c1 + 1, (size_t)(c2 - c1 - 1));
    if (!artist || !title) { if (artist) free(artist); if (title) free(title); return 0; }
    int year = 0;
    if (!parse_int(line + c2 + 1, &year)) { free(artist); free(title); return 0; }
    struct album *a = create_album(artist, title, year);
    free(artist);
    free(title);
    if (!a) return 0;
    *out = a;
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        write_line("Incorrect format.");
        return 1;
    }
    const char *path = argv[1];
    const char *method = argv[2];
    int (*cmp)(const struct album *, const struct album *) = 0;
    if (str_cmp(method, "artist") == 0) cmp = cmp_artist;
    else if (str_cmp(method, "title") == 0) cmp = cmp_title;
    else if (str_cmp(method, "year") == 0) cmp = cmp_year;
    else {
        write_line("Sort method does not exist.");
        return 1;
    }

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        write_line("File not found.");
        return 1;
    }

    struct album *list = NULL;
    char buf[1024];
    char *line = NULL;
    size_t cap = 0, len = 0;

    ssize_t r;
    while ((r = read(fd, buf, sizeof(buf))) > 0) {
        for (ssize_t k = 0; k < r; ++k) {
            char ch = buf[k];
            if (ch == '\r') continue;
            if (ch == '\n') {
                if (len > 0) {
                    line[len] = '\0';
                    struct album *a = NULL;
                    if (!parse_line_to_album(line, &a)) {
                        write_line("Incorrect format.");
                        if (line) free(line);
                        close(fd);
                        // free list
                        while (list) album_del_one(&list, list);
                        return 1;
                    }
                    push_back_album(&list, a);
                    len = 0;
                }
            } else {
                if (len + 1 >= cap) {
                    size_t new_cap = cap ? cap * 2 : 64;
                    char *nl = (char *)malloc(new_cap);
                    if (!nl) {
                        write_line("Incorrect format.");
                        if (line) free(line);
                        close(fd);
                        while (list) album_del_one(&list, list);
                        return 1;
                    }
                    for (size_t i = 0; i < len; ++i) nl[i] = line ? line[i] : '\0';
                    if (line) free(line);
                    line = nl;
                    cap = new_cap;
                }
                line[len++] = ch;
            }
        }
    }
    if (r < 0) {
        write_line("File not found.");
        if (line) free(line);
        close(fd);
        while (list) album_del_one(&list, list);
        return 1;
    }
    // process last line if any
    if (len > 0) {
        line[len] = '\0';
        struct album *a = NULL;
        if (!parse_line_to_album(line, &a)) {
            write_line("Incorrect format.");
            if (line) free(line);
            close(fd);
            while (list) album_del_one(&list, list);
            return 1;
        }
        push_back_album(&list, a);
        len = 0;
    }
    if (line) free(line);
    close(fd);

    sort_album_by(&list, cmp);

    for (struct album *p = list; p; p = p->next) {
        print_album(p);
    }

    while (list) album_del_one(&list, list);
    return 0;
}
