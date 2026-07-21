# Border Subgrid Count II - Lời giải

**ID:** 3418 | **URL:** https://cses.fi/problemset/task/3418

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ trong đó mỗi ô chứa một trong $k$ chữ cái in hoa đầu tiên, đếm — với mỗi chữ cái $c$ — số lượng lưới con **hình chữ nhật** có toàn bộ 4 đường viền là chữ cái $c$.

### Duyệt cặp hàng kết hợp theo dõi tính đồng nhất cột

Hình chữ nhật với hàng $[u, v]$ và cột $[L, R]$ có viền chữ $c$ khi và chỉ khi:
- Hàng trên $u$, cột $L$ đến $R$: toàn $c$.
- Hàng dưới $v$, cột $L$ đến $R$: toàn $c$.
- Cột trái $L$, hàng $u$ đến $v$: toàn $c$.
- Cột phải $R$, hàng $u$ đến $v$: toàn $c$.

Duyệt tất cả $O(n^2)$ cặp hàng $(u, v)$. Với mỗi cặp, duy trì `colS[i]` theo dõi xem cột $i$ có **đồng nhất** từ hàng $u$ đến $v$ hay không:

- Nếu tất cả ô trong cột $i$ từ hàng $u$ đến $v$ cùng chữ $c$, thì `colS[i] = c`.
- Ngược lại, `colS[i] = -1` (không đồng nhất, nên cột $i$ không thể làm viền trái/phải).

Khi mở rộng biên dưới từ $v-1$ sang $v$, cập nhật `colS[i]` trong $O(n)$: nếu `colS[i] != -1` và `a[v][i]` khác chữ cái lưu, đặt `colS[i] = -1`. Với $u = v$, khởi tạo `colS[i] = a[u][i]`.

### Đếm hình chữ nhật bằng quét cột

Với cặp hàng cố định $(u, v)$, quét cột từ trái sang phải. Cột $i$ có thể làm viền trái/phải khi và chỉ khi:
1. `a[u][i] == a[v][i]` — ô trên và ô dưới cùng chữ (cùng chữ trên cả hai cạnh ngang).
2. `colS[i] == a[u][i]` — toàn bộ cột từ $u$ đến $v$ đồng nhất với chữ đó (cả hai cạnh dọc cùng chữ).

Hai điều kiện này cùng đảm bảo mọi bốn viền của hình chữ nhật dùng cột $i$ làm cạnh là cùng một chữ cái. Phần trong hình chữ nhật (giữa viền trái và phải) không ảnh hưởng viền, nên chỉ các ô viền cần kiểm tra.

**Kỹ thuật đếm:** Theo dõi các cột liên tiếp thỏa mãn điều kiện cho cùng một chữ cái. Duy trì `num` = số cột viền hợp lệ trong đoạn chạy hiện tại. Khi chữ cái thay đổi hoặc điều kiện bị vi phạm, đặt `num = 0`. Với mỗi cột hợp lệ, `ans[c] += ++num`. Điều này đếm tất cả hình chữ nhật có viền phải tại cột $i$: viền trái có thể là bất kỳ trong số `num` cột hợp lệ trong đoạn.

Quan sát chính: nếu cột $p$ và $i$ (với $p \le i$) cùng thỏa điều kiện cho chữ $c$, thì hình chữ nhật cột $[p, i]$, hàng $[u, v]$ có cả bốn viền toàn chữ $c$. Hàng trên và dưới toàn $c$ giữa cột $p$ và $i$ (vì mọi cột trong đoạn đều có $c$ trên cả hai hàng), và cột trái/phải toàn $c$ từ hàng $u$ đến $v$ (do điều kiện `colS`).

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 3$, lưới:

```
A B B B C
A B A B C
A B B B C
A B B B C
C C C C C
```

**Cặp hàng $(u, v) = (0, 2)$:**

Tính đồng nhất cột sau khi mở rộng đến hàng 2: `colS = [A, B, -1, B, C]` (cột 2 không đồng nhất: A tại hàng 1 khác B tại hàng 0, 2).

| $i$ | `a[0][i]` | `a[2][i]` | Khớp? | `colS[i]` | Hợp lệ? | `num` | `ans[c] +=` |
|-----|-----------|-----------|-------|-----------|---------|-------|-------------|
| 0 | A | A | ✓ | A | ✓ | 1 | A += 1 |
| 1 | B | B | ✓ | B | ✓ | 1 | B += 1 |
| 2 | B | B | ✓ | -1 | ✗ | 1 | — |
| 3 | B | B | ✓ | B | ✓ | 2 | B += 2 |
| 4 | C | C | ✓ | C | ✓ | 1 | C += 1 |

Tại $i = 3$ với `num = 2`: hai hình chữ nhật viền B kết thúc tại cột 3 là (cột 1–3 và cột 3–3). Cột 2 không thể làm viền trái vì `colS[2] = -1`.

**Cặp hàng $(u, v) = (4, 4)$:** `colS = [C, C, C, C, C]`, tất cả hợp lệ. `num` đạt 5 → $C += 1 + 2 + 3 + 4 + 5 = 15$.

**Kết quả:** Tổng trên tất cả 15 cặp hàng: **11, 38, 29**. ✓

## Độ phức tạp

- **Thời gian:** $O(n^3)$ — $O(n^2)$ cặp hàng, mỗi cặp quét $O(n)$ cột.
- **Bộ nhớ:** $O(n)$ — cho mảng `colS` và tích lũy kết quả.

## Mã nguồn (C++)

[Mã nguồn](../code/Border%20Subgrid%20Count%20II.cpp)
