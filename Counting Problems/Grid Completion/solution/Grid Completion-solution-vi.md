# Grid Completion - Lời giải

**ID:** 2429 | **URL:** https://cses.fi/problemset/task/2429

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ với một số ô đã điền A hoặc B, đếm số cách điền các ô còn lại sao cho mỗi hàng và cột có đúng một A và một B. Kết quả modulo $10^9 + 7$.

### Phân tách thành hai bài toán gán độc lập

Nếu bỏ qua ràng buộc mỗi ô chỉ chứa tối đa một ký tự, bài toán phân tách thành hai nhiệm vụ độc lập:

- **Đặt A:** Gán A vào mỗi hàng thiếu A, chọn cột cũng thiếu A. Đây là bài toán song ánh từ hàng thiếu A sang cột thiếu A — $c_4!$ cách.
- **Đặt B:** Gán B vào mỗi hàng thiếu B, chọn cột cũng thiếu B. Đây là bài toán song ánh từ hàng thiếu B sang cột thiếu B — $c_5!$ cách.

Ràng buộc duy nhất ghép hai phép gán này lại là: **A và B trong cùng hàng không được rơi vào cùng cột** (mỗi ô chỉ chứa một ký tự). Bao hàm - loại trừ sẽ loại bỏ các xung đột này.

### Phân loại hàng và cột

Với mỗi hàng $i$, gọi $A[i]$ và $B[i]$ là cột chứa A và B (hoặc $-1$ nếu thiếu). Gọi $\text{markA}[j]$, $\text{markB}[j]$ cho biết cột $j$ đã có A hay B chưa. Định nghĩa:

- $c_0$: hàng thiếu cả A và B.
- $c_1$: hàng thiếu A nhưng có B, và cột của B cũng thiếu A.
- $c_2$: hàng có A nhưng thiếu B, và cột của A cũng thiếu B.
- $c_3$: cột thiếu cả A và B.
- $c_4$: tổng hàng thiếu A ($= c_0 + c_1$).
- $c_5$: tổng hàng thiếu B ($= c_0 + c_2$).

**Tại sao $c_1$, $c_2$ có điều kiện bổ sung?** Hàng thiếu A (có B ở cột $j$) chỉ gây xung đột nếu A *có thể* được đặt vào cột $j$ — tức cột $j$ chưa có A. Nếu $\text{markA}[j]$ đã đúng, A không thể vào cột $j$ nên xung đột là bất khả. Tương tự cho $c_2$: B chỉ xung đột với cột của A nếu cột đó chưa có B.

**Tại sao chỉ cột loại $c_3$ mới nhận cả A và B từ hàng loại $c_0$?** Để cột có thể nhận cả hai ký tự, nó phải thiếu cả A lẫn B — chính là loại $c_3$. Nếu cột đã có một trong hai, ký tự kia không thể đặt vào, nên xung đột không xảy ra.

### Bao hàm - loại trừ trên xung đột cột

Ba loại xung đột có thể xảy ra:

1. **Hàng loại $c_0$ ($i$ xung đột):** Hàng thiếu cả A và B có cả hai được đặt vào cùng cột loại $c_3$. Biến $i$ đếm số hàng như vậy.
2. **Hàng loại $c_1$ ($j$ xung đột):** Hàng thiếu A (có B ở cột thiếu A) có A được đặt vào cột của B. Biến $j$ đếm số hàng như vậy.
3. **Hàng loại $c_2$ ($k$ xung đột):** Hàng thiếu B (có A ở cột thiếu B) có B được đặt vào cột của A. Biến $k$ đếm số hàng như vậy.

Đây là tất cả các xung đột có thể xảy ra. Không có loại hàng nào khác tạo xung đột cùng cột vì ràng buộc cột ngăn chặn.

Với mỗi $(i, j, k)$, đóng góp có dấu xen $(-1)^{i+j+k}$:

$$(-1)^{i+j+k} \cdot \binom{c_0}{i}\binom{c_3}{i} \cdot i! \cdot \binom{c_1}{j} \cdot \binom{c_2}{k} \cdot (c_4 - i - j)! \cdot (c_5 - i - k)!$$

- $\binom{c_0}{i}\binom{c_3}{i} \cdot i!$: chọn $i$ hàng loại $c_0$ và $i$ cột loại $c_3$, ghép song ánh — mỗi cặp $(r, c)$ ép cả A và B của hàng $r$ vào cột $c$.
- $\binom{c_1}{j}$: chọn $j$ hàng loại $c_1$ ép A vào cột của B.
- $\binom{c_2}{k}$: chọn $k$ hàng loại $c_2$ ép B vào cột của A.
- $(c_4 - i - j)!$: gán A còn lại vào cột thiếu A còn lại (song ánh). $i$ xung đột loại $c_0$ mỗi cái tiêu một cột A, $j$ xung đột loại $c_1$ mỗi cái tiêu một cột A (cột của B, vốn thiếu A).
- $(c_5 - i - k)!$: gán B còn lại vào cột thiếu B còn lại (song ánh). Tương tự với $i$ và $k$.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, lưới:
```
.....
..AB.
.....
B....
...A.
```

Phân loại: $c_0 = 2$ (hàng 1,3), $c_1 = 1$ (hàng 4: có B ở cột 1, cột 1 thiếu A), $c_2 = 0$ (hàng 5 có A ở cột 4, cột 4 đã có B), $c_3 = 2$ (cột 2,5), $c_4 = 3$, $c_5 = 3$.

| $(i,j,k)$ | dấu | công thức | giá trị |
|------------|-----|-----------|---------|
| (0,0,0) | $+$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 3! \cdot 3!$ | 36 |
| (0,1,0) | $-$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 2! \cdot 3!$ | $-12$ |
| (1,0,0) | $-$ | $\binom{2}{1}^2 \cdot 1 \cdot 1 \cdot 1! \cdot 2! \cdot 2!$ | $-16$ |
| (1,1,0) | $+$ | $\binom{2}{1}^2 \cdot 1 \cdot 1 \cdot 1! \cdot 1! \cdot 2!$ | $+8$ |
| (2,0,0) | $+$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 2! \cdot 0! \cdot 1!$ | $+2$ |
| (2,1,0) | $-$ | $1 \cdot 1 \cdot 1 \cdot 1 \cdot 2! \cdot 0! \cdot 1!$ | $-2$ |

**Tổng:** $36 - 12 - 16 + 8 + 2 - 2 = \mathbf{16}$. ✓

## Độ phức tạp

- **Thời gian:** $O(n^3)$ — ba vòng lặp lồng trên $(i, j, k)$.
- **Bộ nhớ:** $O(n)$ — cho mảng giai thừa và đánh dấu.

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Completion.cpp)
