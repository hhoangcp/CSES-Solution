# Mex Grid Construction - Lời giải

**ID:** 3419 | **URL:** https://cses.fi/problemset/task/3419

## Phương pháp

### Tóm tắt bài toán

Xây dựng lưới $n \times n$ ($1 \le n \le 100$) mà mỗi ô $(i, j)$ nhận giá trị **mex** (số nguyên không âm nhỏ nhất chưa xuất hiện) của tập các giá trị đã có bên trái cùng hàng và phía trên cùng cột.

### Ý tưởng chính

Đáp án tại mỗi ô $(i, j)$ (đánh số từ 0) chính là $i \oplus j$.

**Chứng minh bằng quy nạp.** Cơ sở: ô $(0,0)$ có mex của tập rỗng = 0 = $0 \oplus 0$. Bước quy nạp: giả sử mọi ô $(i', j')$ trước $(i,j)$ theo thứ tự hàng đều có giá trị $i' \oplus j'$. Tập giá trị đã có:
- Bên trái: $\{i \oplus 0, i \oplus 1, \ldots, i \oplus (j-1)\}$
- Phía trên: $\{0 \oplus j, 1 \oplus j, \ldots, (i-1) \oplus j\}$

Ta chứng minh mex của tập này bằng $i \oplus j$:

1. **$i \oplus j$ vắng mặt:** Nếu $i \oplus k = i \oplus j$ với $k < j$ thì $k = j$, mâu thuẫn. Tương tự với $k \oplus j = i \oplus j$ và $k < i$.

2. **Mọi $v < i \oplus j$ đều xuất hiện:** Đặt $k = i \oplus v$. Nếu $k < j$ thì $v = i \oplus k$ nằm trong tập bên trái. Nếu $k \geq j$, gọi $b$ là bit cao nhất mà $i$ và $j$ khác nhau (bit cao nhất của $i \oplus j$). Vì $v < i \oplus j$, bit $b$ của $v$ bằng 0. Điều này buộc bit $b$ của $i$ = 1 và bit $b$ của $j$ = 0 (nếu không thì $k < j$, mâu thuẫn $k \geq j$). Khi đó $l = v \oplus j$ có bit $b$ = 0 trong khi bit $b$ của $i$ = 1, các bit cao hơn trùng nhau, nên $l < i$, và $v = l \oplus j$ nằm trong tập phía trên.

Vì mọi giá trị $0, \ldots, i \oplus j - 1$ đều có và $i \oplus j$ vắng mặt, mex = $i \oplus j$.

Đây chính là giá trị Sprague-Grundy cho vị trí $(i, j)$ trong trò chơi công bằng di chuyển về $(0,0)$, mỗi bước giảm $i$ hoặc $j$.

### Thuật toán

**Tính trực tiếp:** Với mỗi ô $(i, j)$, xuất $i \oplus j$.

**Nhân đôi lặp (dùng trong code):** Tính trước lưới $128 \times 128$ từ cơ sở $2 \times 2$ rồi nhân đôi liên tục. Từ lưới $k \times k$ ($k$ là lũy thừa 2), xây lưới $2k \times 2k$: góc trên-trái giữ nguyên, góc trên-phải và dưới-trái = trên-trái $+ k$, góc dưới-phải = bản sao trên-trái (vì $(i+k) \oplus (j+k) = i \oplus j$ khi $k$ là lũy thừa 2).

### Ví dụ minh họa

$n = 5$:

```
0 1 2 3 4
1 0 3 2 5
2 3 0 1 6
3 2 1 0 7
4 5 6 7 0
```

Kiểm tra ô $(1,2)$: bên trái = $\{1,0\}$, phía trên = $\{2\}$, tập = $\{0,1,2\}$, mex = 3 = $1 \oplus 2$. $\checkmark$

## Độ phức tạp

- **Thời gian:** $O(n^2)$
- **Không gian:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Mex%20Grid%20Construction.cpp)
