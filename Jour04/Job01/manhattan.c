#include "manhattan.h"

int manhattan(struct point a, struct point b) {
    int dx = ABS(a.x - b.x);
    int dy = ABS(a.y - b.y);
    return dx + dy;
}
