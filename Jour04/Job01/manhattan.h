#ifndef MANHATTAN_H
#define MANHATTAN_H

#define ABS(x) ((x) < 0 ? -(x) : (x))

struct point {
    int x;
    int y;
};

int manhattan(struct point a, struct point b);

#endif
