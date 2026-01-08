int my_sqrt(int n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Use loop to find exact sqrt
    // Note: i*i can overflow if we go too high, but sqrt(INT_MAX) ~ 46340
    // so using int for i is fine.
    
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            return i;
        }
        // Optimization: if i*i overflows (becomes negative), we stop
        if (i > 46340) break; 
    }
    return 0;
}
