// this function must return 2
// b is the input number, a is 0x6030f0 initially
int fun7(int *a, int b) {
    if(a == 0) {
        return 0xffffffff;
    }
    if(*a <= b) {
        if(b == *a) {
            return 0;
        } else {
            return 2 * fun7(*(a + 16), b) + 1;
        }
    } else {
        return 2 * fun7(*(a + 8), b);
    }
}

// in fun7(0x6030f0, b) (must return 2)
// fun7(*(0x6030f8), b) = 1;    (*a > b, 24 > b)
// which is fun7(0x603110, b)

// in fun7(0x603110, b) (must return 1)
// fun(*(*0x06030f8 + 16), b) = 0    (*a < b, 8 < b)
// which is fun(*0x603120, b) = 0
// which is fun(0x603150, b) = 0

// in fun7(0x603150, b) (must return 0)
// b == *0x603150 = 0x16
// ans is 0x16
