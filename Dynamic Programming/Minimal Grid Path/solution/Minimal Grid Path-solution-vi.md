# Minimal Grid Path - Lời giải

**ID:** 3359 | **URL:** https://cses.fi/problemset/task/3359

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho lưới $n \times n$ gồm các chữ cái hoa, tìm chuỗi có thứ tự từ điển nhỏ nhất trên đường đi từ $(0,0)$ đến $(n-1, n-1)$, chỉ được đi sang phải hoặc xuống dưới.

### Ý tưởng cốt lõi

Mọi đường đi đều có đúng $2n - 1$ ô. Vì mỗi bước (sang phải hoặc xuống dưới) tăng $i + j$ lên đúng 1, ký tự thứ $k$ (đánh số từ 0) luôn đến từ ô trên đường chéo phụ $i + j = k$. Vậy ta có thể quyết định từng ký tự, theo từng đường chéo.

**Chiến lược tham lam:** Tại mỗi đường chéo $k$, chọn ký tự nhỏ nhất trong các ô **có thể đạt được**. Ô $(i, j)$ có thể đạt được nếu là $(0,0)$, hoặc có ô kề phía trên $(i-1, j)$ hoặc bên trái $(i, j-1)$ đã được đánh dấu. Sau khi chọn ký tự nhỏ nhất $c^*$, chỉ đánh dấu các ô có ký tự $c^*$ và có ô kề đã đánh dấu — đảm bảo tính liên tục của đường đi.

**Tính đúng của tham lam:** Giả sử hai đường đi khác nhau đầu tiên tại đường chéo $k$. Đường đi chọn ký tự nhỏ hơn tại $k$ có thứ tự từ điển nhỏ hơn, bất kể các ký tự phía sau. Vậy tại mỗi đường chéo, ta phải chọn ký tự nhỏ nhất có thể. Lưu ý: không phải mọi ô có ký tự $c^*$ đều có thể đạt được — chỉ những ô có ô kề đã đánh dấu mới hợp lệ.

### Thuật toán

1. Nhóm các ô theo đường chéo phụ: `P[i+j]` chứa tất cả ô $(i,j)$ với $i+j = k$.
2. Với mỗi đường chéo $k = 0, 1, \ldots, 2n-2$:
   - Tìm ký tự nhỏ nhất $c^*$ trong các ô có thể đạt được trên `P[k]`.
   - Xuất $c^*$.
   - Đánh dấu ô $(i,j) \in P[k]$ là có thể đạt được nếu $a[i][j] = c^*$ và (used$(i-1,j)$ hoặc used$(i,j-1)$).

### Ví dụ

Lưới đầu vào:

```
A A C A
B A B C
A B D A
A A C A
```

| $k$ | Các ô có thể đạt được | Ký tự nhỏ nhất | Các ô được đánh dấu |
|-----|------------------------|-----------------|---------------------|
| 0 | $(0,0)$: A | **A** | $(0,0)$ |
| 1 | $(0,1)$: A, $(1,0)$: B | **A** | $(0,1)$ |
| 2 | $(1,1)$: A | **A** | $(1,1)$ |
| 3 | $(1,2)$: B, $(2,1)$: B | **B** | $(1,2)$, $(2,1)$ |
| 4 | $(3,1)$: A | **A** | $(3,1)$ |
| 5 | $(3,2)$: C | **C** | $(3,2)$ |
| 6 | $(3,3)$: A | **A** | $(3,3)$ |

Kết quả: `AAABACA`.

Chú ý: tại $k=2$, ô $(2,0)$ cũng có 'A' nhưng không thể đạt được (không có ô kề đã đánh dấu). Tại $k=3$, ô $(0,3)$ và $(3,0)$ đều có 'A' nhưng cũng không thể đạt được — nên ký tự nhỏ nhất có thể đạt được là 'B'.

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — mỗi ô được xử lý đúng một lần theo đường chéo phụ, $O(1)$ cho mỗi ô
- **Bộ nhớ:** $O(n^2)$ — cho lưới và mảng đánh dấu

## Mã nguồn (C++)

[Mã nguồn](../code/Minimal%20Grid%20Path.cpp)
