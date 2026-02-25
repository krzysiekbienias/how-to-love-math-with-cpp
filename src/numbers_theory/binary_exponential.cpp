




// Implement your logic here.
long long binExponentialWithMod(long long a,long long b, long long m){
    if (a==0 && b==0) return 1;
    if (a==0) return 0;
    if (m==1) return 0;
    a%=m; //<--- extra safety step we normalize to handle negative base.
    if (a<0) a+=m;

    long long res=1;
    while (b>0) {
        if(b&1){
            res=res*a%m; //<--- 1 on bit contribute to the result
        }
        a=a*a%m;
        b>>=1;//<---- we move right and update 🤓 not b>>1 but b>>=1
    }
    return res;
}