int power(int n, int p) {
    if (p < 0) return 0;
    if (p == 0) return 1;
    
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}
