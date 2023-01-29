

bool isPalindrome (int x){
    if (x < 0) {
            return false;
    }
    long n=x;
    long rev=0;
    while (n>0){
        rev=rev * 10 + n % 10;
            n= n/10;
    }
    return x == rev;
    return 0;
}
