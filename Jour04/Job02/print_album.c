#include "../album.h"
#include <unistd.h>

static void write_str(const char *s) {
    if (!s) return;
    const char *p = s;
    while (*p) p++;
    write(1, s, (size_t)(p - s));
}

static void write_int(int n) {
    char buf[12];
    int i = 0;
    if (n == 0) {
        write(1, "0", 1);
        return;
    }
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    while (n > 0 && i < 11) {
        buf[i++] = (char)('0' + (n % 10));
        n /= 10;
    }
    while (i > 0) {
        i--;
        write(1, &buf[i], 1);
    }
}

void print_album(struct album *a) {
    if (!a || !a->title || !a->artist) return;
    write(1, "\"", 1);
    write_str(a->title);
    write(1, "\" by \"", 6);
    write_str(a->artist);
    write(1, "\" released in ", 14);
    write_int(a->year);
    write(1, ".\n", 2);
}
