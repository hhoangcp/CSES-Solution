# Substring Reversals - Lời giải

**ID:** 2073 | **URL:** https://cses.fi/problemset/task/2073

## Phương pháp

### Tóm tắt bài toán

Cho chuỗi dài $n$ và $m$ thao tác, mỗi thao tác chỉ định đoạn $[a, b]$. Đảo ngược chuỗi con từ vị trí $a$ đến $b$. Xuất chuỗi cuối cùng.

### Ý tưởng chính

Đảo ngược thông thường mất $O(n)$ mỗi thao tác, tổng $O(nm)$. **Treap với đảo lười** hỗ trợ mỗi thao tác trong $O(\log n)$:

**Đảo lười:** Để đảo chuỗi con $[a, b]$, tách treap thành $T_1 [1, a{-}1]$, $T_2 [a, b]$, $T_3 [b{+}1, n]$, bật `rev` trên $T_2$, rồi nối lại. Khi gặp nút có `rev = true` trong tách/nối/duyệt, lan truyền: đổi con trái/phải, bật `rev` trên cả hai con, xóa cờ hiện tại. Thao tác này đảo đúng thứ tự duyệt giữa của cây con $T_2$ mà không cần sửa từng nút. `Reverse` luôn được gọi trước khi truy cập con để đảm bảo nhất quán cấu trúc.

Độ ưu tiên ngẫu nhiên duy trì chiều cao cây $O(\log n)$ kỳ vọng, nên tách và nối đều $O(\log n)$.

### Thuật toán

1. Xây treap từ chuỗi (mỗi nút lưu chỉ số ký tự gốc).
2. Với mỗi thao tác $(u, v)$:
   - Tách tại $v+1$ → $T_2, T_3$. Tách $T_2$ tại $u$ → $T_1, T_2$.
   - Bật `rev` trên $T_2$.
   - Nối: `root = merge(merge(T1, T2), T3)`.
3. Duyệt thứ tự giữa (có lan truyền lười) để xuất chuỗi cuối cùng.

### Ví dụ minh họa

Chuỗi: `AYBABTU`, thao tác: $(3,4)$ rồi $(4,7)$.

| Bước | Thao tác | Chuỗi con đảo | Kết quả |
|------|----------|---------------|---------|
| 1 | Đảo $[3,4]$ | `BA` → `AB` | `AYABBTU` |
| 2 | Đảo $[4,7]$ | `BBTU` → `UTBB` | `AYAUTBB` |

Chuỗi cuối: **AYAUTBB**

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Substring%20Reversals.cpp)
