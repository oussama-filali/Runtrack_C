int my_atoi(char *str) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Skip whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r') {
        i++;
    }

    // Handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Convert digits
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}
