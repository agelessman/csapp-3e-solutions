
long cread(long *xp) {
    return (xp ? *xp : 0);
}

long cread_alt(long *xp) {
    return (!xp ? 0 : *xp);
}