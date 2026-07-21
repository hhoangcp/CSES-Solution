#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

namespace GridPath {
    bool feasible(int rows, int cols, int sr, int sc, int er, int ec) {
        if (rows > cols) return feasible(cols, rows, sc, sr, ec, er);
        if (sr == er && sc == ec) return false;

        if (rows == 1 && ((sc != 1 && sc != cols) || (ec != 1 && ec != cols))) return false;
        if (rows == 2 && sc == ec && sc != 1 && sc != cols) return false;
        if (rows == 3 && cols % 2 == 0 && sc != ec) {
            int lr = sr, lc = sc, rr = er, rc = ec;
            if (lc > rc) { swap(lr, rr); swap(lc, rc); }
            if ((lr + lc) % 2 != 0 && (lc + 1 < rc || lr == 2)) return false;
        }

        if (rows % 2 != 0 && cols % 2 != 0) return (sr + sc) % 2 == 0 && (er + ec) % 2 == 0;
        return (sr + sc) % 2 != (er + ec) % 2;
    }

    void rotate(int& rows, int& cols, int& sr, int& sc, int& er, int& ec, char& up, char& dn, char& lt, char& rt) {
        int nsr = sc, nsc = rows + 1 - sr;
        int ner = ec, nec = rows + 1 - er;
        sr = nsr; sc = nsc; er = ner; ec = nec;
        swap(rows, cols);
        char old_up = up; up = lt; lt = dn; dn = rt; rt = old_up;
    }

    void transpose(int& rows, int& cols, int& sr, int& sc, int& er, int& ec, char& up, char& dn, char& lt, char& rt) {
        swap(rows, cols); swap(sr, sc); swap(er, ec);
        swap(up, lt); swap(dn, rt);
    }

    void flip_horizontal(int cols, int& sc, int& ec, char& lt, char& rt) {
        sc = cols + 1 - sc; ec = cols + 1 - ec;
        swap(lt, rt);
    }

    void flip_vertical(int rows, int& sr, int& er, char& up, char& dn) {
        sr = rows + 1 - sr; er = rows + 1 - er;
        swap(up, dn);
    }

    string solve_2xC(int cols, int sr, int sc, int er, int ec, char up, char dn, char lt, char rt) {
        if (cols == 3 && ((sc == 1 && ec == 3) || (sc == 3 && ec == 1))) {
            if (sc > ec) { sc = 4 - sc; ec = 4 - ec; swap(lt, rt); }
            if (sr > er) { sr = 3 - sr; er = 3 - er; swap(up, dn); }
            return string("") + dn + rt + up + rt + dn;
        }

        int pos1 = (sr == 1) ? sc : cols * 2 + 1 - sc;
        int pos2 = (er == 1) ? ec : cols * 2 + 1 - ec;
        if (pos1 % (cols * 2) + 1 == pos2) {
            sr = 3 - sr; er = 3 - er; swap(up, dn);
        }

        string res = "";
        while (sr != er || sc != ec) {
            if (sr == 1) {
                if (sc < cols) { res += rt; sc++; } else { res += dn; sr++; }
            } else {
                if (sc > 1) { res += lt; sc--; } else { res += up; sr--; }
            }
        }
        return res;
    }

    string solve_3x3(int rows, int cols, int sr, int sc, int er, int ec, char up, char dn, char lt, char rt) {
        for (int rot = 0; rot < 4; rot++) {
            if ((sr == 1 && sc == 1) || (sr == 2 && sc == 2 && er == 1 && ec == 1)) {
                if (sr == 2 && sc == 2)  return string("") + lt + dn + rt + rt + up + up + lt + lt;
                if (er == 2 && ec == 2)  return string("") + rt + rt + dn + dn + lt + lt + up + rt;
                if (er == 1 && ec == 3)  return string("") + dn + dn + rt + rt + up + lt + up + rt;
                if (er == 3 && ec == 1)  return string("") + rt + rt + dn + dn + lt + up + lt + dn;
                return string("") + rt + rt + dn + lt + lt + dn + rt + rt;
            }
            rotate(rows, cols, sr, sc, er, ec, up, dn, lt, rt);
        }
        return "";
    }

    string build(int rows, int cols, int sr, int sc, int er, int ec, char up = 'U', char dn = 'D', char lt = 'L', char rt = 'R');

    string solve_4x5(int rows, int cols, int sr, int sc, int er, int ec, char up, char dn, char lt, char rt) {
        if (sc >= 4 || ec >= 4) flip_horizontal(cols, sc, ec, lt, rt);
        if (sr > er) flip_vertical(rows, sr, er, up, dn);

        if (sr <= 2 && er >= 3) {
            if (feasible(2, 5, sr, sc, 2, 4) && feasible(rows - 2, cols, 1, 4, er - 2, ec)) {
                return build(2, cols, sr, sc, 2, 4, up, dn, lt, rt) + dn +
                       build(rows - 2, cols, 1, 4, er - 2, ec, up, dn, lt, rt);
            }
            return build(2, cols, sr, sc, 2, 5, up, dn, lt, rt) + dn +
                   build(rows - 2, cols, 1, 5, er - 2, ec, up, dn, lt, rt);
        }

        if (sr >= 3) flip_vertical(rows, sr, er, up, dn);
        bool reversed = false;
        if (sr == 2) { swap(up, dn); swap(lt, rt); reversed = true; }

        string p = string("") + lt + dn + dn + dn + rt + up + rt + dn + rt + rt + up + lt + up + rt + up + lt + lt + dn + lt;
        if (reversed) reverse(p.begin(), p.end());
        return p;
    }

    string splice(const string& core_path, int cols, int sr, int sc, char up, char dn, char lt, char rt) {
        string res = "";
        int curr_r = sr, curr_c = sc;
        bool spliced = false;
        for (char step : core_path) {
            int next_r = curr_r - (step == up) + (step == dn);
            int next_c = curr_c - (step == lt) + (step == rt);
            if (!spliced && curr_r == 3 && next_r == 3) {
                res += up;
                res += build(2, cols, 2, curr_c, 2, next_c, up, dn, lt, rt);
                res += dn;
                spliced = true;
            } else res += step;

            curr_r = next_r; curr_c = next_c;
        }
        return res;
    }

    string build(int rows, int cols, int sr, int sc, int er, int ec, char up, char dn, char lt, char rt) {
        for (int rot = 0; rot < 4; rot++) {
            if (sr >= 3 && er >= 3 && feasible(rows - 2, cols, sr - 2, sc, er - 2, ec)) {
                string core = build(rows - 2, cols, sr - 2, sc, er - 2, ec, up, dn, lt, rt);
                return splice(core, cols, sr, sc, up, dn, lt, rt);
            }
            rotate(rows, cols, sr, sc, er, ec, up, dn, lt, rt);
        }

        if (rows > cols) transpose(rows, cols, sr, sc, er, ec, up, dn, lt, rt);
        if (sc > ec) flip_horizontal(cols, sc, ec, lt, rt);

        if (rows == 1) return string(cols - 1, rt);
        if (rows == 2 && cols <= 3) return solve_2xC(cols, sr, sc, er, ec, up, dn, lt, rt);
        if (rows == 3 && cols == 3) return solve_3x3(rows, cols, sr, sc, er, ec, up, dn, lt, rt);

        if (rows != 4 || cols != 5 || (sc <= 2 && ec >= 4)) {
            int cands[] = {1, 2, rows - 1, rows};
            for (int cut_r : cands) {
                if (cut_r < 1 || cut_r > rows) continue;
                if (feasible(rows, 2, sr, sc, cut_r, 2) && feasible(rows, cols - 2, cut_r, 1, er, ec - 2)) {
                    return build(rows, 2, sr, sc, cut_r, 2, up, dn, lt, rt) + rt +
                           build(rows, cols - 2, cut_r, 1, er, ec - 2, up, dn, lt, rt);
                }
            }
        }

        return solve_4x5(rows, cols, sr, sc, er, ec, up, dn, lt, rt);
    }
}

void solve() {
    int rows, cols, sr, sc, er, ec;
    cin >> rows >> cols >> sr >> sc >> er >> ec;
    if (!GridPath::feasible(rows, cols, sr, sc, er, ec)) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << GridPath::build(rows, cols, sr, sc, er, ec) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests = 1; cin >> tests;
    for (int i = 0; i < tests; i++) {
        solve();
    }

    return 0;
}