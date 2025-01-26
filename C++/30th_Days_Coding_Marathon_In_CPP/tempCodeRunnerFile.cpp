if (j == 0)
    {
        return i;
    }
    return gcd(j, i % j);