

// Implement your logic here.
int gcdRecursive(int a, int b) {
    if (b==0) return a;
    int r=a%b;
    return gcdRecursive(b,r);
}


int gcdIterativeEuclides(int a, int b) {
    while (b>0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}


