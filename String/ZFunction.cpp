vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, r = 0; i<n; i++) {
        if (i <= r) {
            z[i] = min(r-i+1, z[i-1]);
        }
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        r = i+z[i]-1;
    }
    return z;
}
