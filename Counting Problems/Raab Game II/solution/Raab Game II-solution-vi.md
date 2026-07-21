# Raab Game II - Lời giải

**ID:** 3400 | **URL:** https://cses.fi/problemset/task/3400

## Phương pháp

### Tóm tắt bài toán

Hai người chơi mỗi người có bài $\{1, \ldots, n\}$. Mỗi lượt cả hai đánh một bài; bài cao hơn ghi điểm, bài bằng nhau không ai ghi. Với mỗi truy vấn $(n, a, b)$, đếm số ván kết thúc với người 1 thắng $a$ lần và người 2 thắng $b$ lần. Kết quả modulo $10^9 + 7$.

### QHD trên số lần thắng

Định nghĩa $\text{dp}[i][j]$ = số cách xây dựng dãy ván quyết định (không hòa) mà người 1 thắng $i$ lần và người 2 thắng $j$ lần. Điểm mấu chốt là theo dõi cách các ván quyết định mới tương tác với các ván cũ.

Sau $i + j$ ván quyết định, mỗi ván có một người thắng. Để thêm một ván quyết định mới, ta chèn nó vào giữa các ván hiện có. Các hệ số nhân xuất phát từ việc đếm số "khe" khả dụng:

- **P1 thắng ván mới ($\text{dp}[i{+}1][j] \mathrel{+}= \text{dp}[i][j] \cdot j$):** Bài mới của P1 phải thắng bài của P2. Ta ghép bài mới của P1 với một bài P2 đã thua trước đó — tức bài P2 từ ván mà P2 đã thắng (có $j$ ván như vậy). Vậy có $j$ lựa chọn.

- **P2 thắng ván mới ($\text{dp}[i][j{+}1] \mathrel{+}= \text{dp}[i][j] \cdot i$):** Đối xứng, bài mới của P2 thắng một trong $i$ bài P1 đã thua trước đó.

- **Cả hai cùng thắng ($\text{dp}[i{+}1][j{+}1] \mathrel{+}= \text{dp}[i][j] \cdot (i{+}j{+}1)$):** Chèn một ván quyết định mới mà cả P1 và P2 dùng bài mới. Ván mới có thể đặt vào bất kỳ $i + j + 1$ khe nào (trước ván 1, giữa hai ván liên tiếp, hoặc sau ván cuối).

### Trường hợp vô hiệu

- **$a + b > n$:** Nhiều ván quyết định hơn số bài. Kết quả = 0.
- **$\min(a, b) = 0$ và $\max(a, b) > 0$:** Nếu một người thắng ít nhất một lần, người thua trong ván đó cũng phải thắng ở ván khác (để duy trì cấu trúc chu trình của giá trị bài — mỗi ván quyết định ghép bài cao hơn và thấp hơn, các ghép này phải cân bằng). Tương đương, mỗi lần thắng của P1 tiêu một "khe" do lần thắng của P2 tạo ra và ngược lại. Kết quả = 0.

### Công thức kết quả

$$\text{ans}(a, b) = \text{dp}[a][b] \cdot \binom{n}{a+b} \cdot n!$$

- **$\text{dp}[a][b]$:** Số cách thiết lập quan hệ thắng/thua giữa các ván quyết định.
- **$\binom{n}{a+b}$:** Chọn $a + b$ trong $n$ ván là quyết định (không hòa). $n - a - b$ ván còn lại là hòa.
- **$n!$:** Gán giá trị bài thực tế. Khi bộ bài của P1 đã cố định (một hoán vị của $\{1, \ldots, n\}$), bộ bài của P2 bị **xác định duy nhất** bởi cấu trúc thắng/thua — mỗi bài của P2 phải cao hơn hoặc thấp hơn bài tương ứng của P1, theo đúng cấu trúc mà DP đã thiết lập.

### Ví dụ minh họa

**Ví dụ đề bài:**

$n = 3$, $a = 1$, $b = 2$: $\text{dp}[1][2] = 1$. Kết quả: $1 \cdot \binom{3}{3} \cdot 6 = 6$. ✓

$n = 2$, $a = 0$, $b = 1$: $\min = 0$, $\max > 0$ → **0**. ✓

$n = 5$, $a = 2$, $b = 2$: $\text{dp}[2][2] = 7$. Kết quả: $7 \cdot \binom{5}{4} \cdot 120 = 7 \cdot 5 \cdot 120 = 4200$. ✓

$n = 4$, $a = 4$, $b = 1$: $a + b = 5 > 4 = n$ → **0**. ✓

**Bảng QHD** cho giá trị nhỏ (từ $\text{dp}[0][0] = 1$):

| $(i,j)$ | giá trị | chuyển |
|---------|---------|--------|
| (0,0) | 1 | → (1,1): $1 \cdot 1 = 1$ |
| (1,1) | 1 | → (2,1): $1$, (1,2): $1$, (2,2): $3$ |
| (2,1) | 1 | → (3,1): $1$, (2,2): $+2$, (3,2): $4$ |
| (1,2) | 1 | → (2,2): $+2$, (1,3): $1$, (2,3): $4$ |

$\text{dp}[2][2] = 3 + 2 + 2 = 7$. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2)$ tiền tính, $O(1)$ mỗi truy vấn.
- **Bộ nhớ:** $O(n^2)$ cho bảng QHD.

## Mã nguồn (C++)

[Mã nguồn](../code/Raab%20Game%20II.cpp)
