vector<int> manacherOdd(string s) {
    int n = s.size();
    s = '$' + s + '^';
    vector<int> p(n+2);
    for (int i = 1, l = 1, r = 1; i<=n; i++) {
        p[i] = max(0ll, min(r-i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(p.begin()+1, p.end()-1);
}

vector<int> manacher(string s) {
    string t;
    for (auto c : s) {
        t += string(1, '#') + c;
    }
    auto res = manacherOdd(t + '#');
    return vector<int>(res.begin()+1, res.end()-1);
}
