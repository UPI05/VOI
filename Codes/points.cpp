int64_t ans = 0;
for (int points = 0; points <= n; points++) {
    int pos = posx - points;
    int deff = negy - pos;
    int neg = negx - deff;
    if (pos >= 0 && diff >= 0 && neg >= 0) {
        int64_t cntx = (cnk(posx, points) * cnk(negx, diff)) % MOD;
        int64_t cnty = (cnk(posy, points) * cnk(negy, diff)) % MOD;
        ans = (ans + (cntx * cnty) % MOD) % MOD;
    }
}
