# Reversals and Sums - Lời giải

**ID:** 2074 | **URL:** https://cses.fi/problemset/task/2074

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, xử lý $m$ thao tác: (1) đảo ngược mảng con $[a, b]$, hoặc (2) tính tổng mảng con $[a, b]$.

### Ý tưởng chính

Mảng thông thường hay cây phân đoạn không thể xử lý đảo ngược hiệu quả. **Treap với lan truyền lười** hỗ trợ cả hai thao tác trong $O(\log n)$:

**Các trường nút:** `key` (giá trị), `pri` (độ ưu tiên ngẫu nhiên), `siz` (kích thước cây con), `sum` (tổng cây con), `rev` (cờ đảo lười).

**Đảo ngược lười:** Để đảo khoảng $[a, b]$, tách treap thành $T_1 [1, a{-}1]$, $T_2 [a, b]$, $T_3 [b{+}1, n]$. Bật `rev` trên gốc $T_2$, rồi nối lại. Khi gặp nút $v$ có `rev = true` trong tách/nối, lan truyền: đổi con trái/phải, bật `rev` trên cả hai con, xóa cờ của $v$. Thao tác này đảo đúng thứ tự duyệt giữa — nếu $T(v) = T(L) \circ [k] \circ T(R)$, sau khi đổi con và đẩy `rev` xuống, duyệt giữa trở thành $T^R(R) \circ [k] \circ T^R(L) = T^R(v)$. Trường `sum` không ảnh hưởng vì đảo chỉ đổi thứ tự, không thay đổi tập phần tử.

**Truy vấn tổng:** Tách tương tự; $T_2 \to \text{sum}$ cho đáp án trực tiếp.

### Thuật toán

1. Xây treap từ mảng (chèn từng phần tử).
2. Với mỗi thao tác:
   - **Loại 1 (đảo $[u, v]$):** Tách thành $T_1, T_2, T_3$. Đặt $T_2 \to \text{rev} \mathrel{\wedge}= \text{true}$. Nối lại.
   - **Loại 2 (tổng $[u, v]$):** Tách thành $T_1, T_2, T_3$. Xuất $T_2 \to \text{sum}$. Nối lại.
3. Luôn gọi `Reverse(P)` trước khi truy cập con trong tách/nối, và `Update_node` sau mỗi thay đổi cấu trúc.

### Ví dụ minh họa

Mảng: $[2, 1, 3, 4, 5, 3, 4, 4]$.

| Bước | Thao tác | Kết quả |
|------|----------|---------|
| 1 | Tổng $[2, 4]$: $1 + 3 + 4$ | **8** |
| 2 | Đảo $[3, 6]$: $[3,4,5,3] \to [3,5,4,3]$ | Mảng: $[2, 1, 3, 5, 4, 3, 4, 4]$ |
| 3 | Tổng $[2, 4]$: $1 + 3 + 5$ | **9** |

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Reversals%20and%20Sums.cpp)
