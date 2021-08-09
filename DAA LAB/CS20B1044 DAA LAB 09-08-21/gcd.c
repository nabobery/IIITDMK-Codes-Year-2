unsigned int gcd(unsigned int u, unsigned int v)
{
    // Base cases
    //  gcd(n, n) = n
    if (u == v)
        return u;
    
    //  Identity 1: gcd(0, n) = gcd(n, 0) = n
    if (u == 0)
        return v;
    if (v == 0)
        return u;

    if (u % 2 == 0) { // u is even
        if (v % 2 == 1) // v is odd
            return gcd(u/2, v); // Identity 3
        else // both u and v are even
            return 2 * gcd(u/2, v/2); // Identity 2

    } else { // u is odd
        if (v % 2 == 0) // v is even
            return gcd(u, v/2); // Identity 3

        // Identities 4 and 3 (u and v are odd, so u-v and v-u are known to be even)
        if (u > v)
            return gcd((u - v)/2, v);
        else
            return gcd((v - u)/2, u);
    }
}