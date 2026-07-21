# String Transform - Lời giải

**ID:** 1113 | **URL:** https://cses.fi/problemset/task/1113

## Đề bài

Phép biến đổi Burrows-Wheeler (BWT): thêm ký tự `#` vào cuối chuỗi (`#` nhỏ hơn mọi ký tự 'a'–'z'), tạo tất cả phép xoay, sắp xếp theo thứ tự từ điển, và ghép ký tự cuối cùng của mỗi phép xoay thành chuỗi kết quả. Cho chuỗi kết quả (cột cuối, độ dài $n+1$), hãy khôi phục chuỗi gốc độ dài $n$.

## Hướng tiếp cận

### Bước 1: Tính chất LF và mảng Next

Gọi $L$ là cột cuối (chuỗi BWT cho trước), $F$ là cột đầu (chính là $L$ sắp xếp tăng dần). Hai cột cùng có $n+1$ hàng (đánh số $1..n{+}1$).

**Tính chất LF (Last-First):** trong ma trận các phép xoay đã sắp xếp, lần xuất hiện thứ $i$ của một ký tự $c$ ở cột cuối $L$ ứng với lần xuất hiện thứ $i$ của $c$ ở cột đầu $F$. Thật vậy, các phép xoay kết thúc bằng cùng $c$ được sắp xếp theo phần đứng ngay sau $c$; phần đó chính là tiền tố của phép xoay bắt đầu bằng $c$ tiếp theo, nên thứ tự tương đối giữa các lần xuất hiện $c$ được bảo toàn giữa $L$ và $F$.

Từ đó xây dựng mảng $\text{Next}$: $\text{Next}[k]$ = vị trí (hàng) trong $L$ ứng với phần tử thứ $k$ của $F$ (tức $L[\text{Next}[k]] = F[k]$, cùng lần xuất hiện). Đây là ánh xạ ngược của LF (từ cột đầu sang cột cuối).

### Bước 2: Xây dựng mảng Next bằng ngăn xếp

1. **Phân loại:** duyệt $L$ từ phải sang trái, đẩy mỗi vị trí $i$ vào ngăn xếp theo ký tự $L[i]$ (riêng `#` vào ngăn xếp 0). Đẩy ngược nên các vị trí nhỏ hơn nằm trên đỉnh — đúng với thứ tự xuất hiện tăng dần trong $L$.
2. **Gán Next:** duyệt các ngăn xếp theo thứ tự ký tự tăng dần (`#`, `a`, `b`, …, `z`) — đúng thứ tự cột đầu $F$ — và lần lượt lấy đỉnh ra; phần tử lấy ra ở bước thứ $k$ chính là $\text{Next}[k]$.

### Bước 3: Tái tạo chuỗi gốc

Phép xoay bắt đầu bằng `#` là nhỏ nhất nên đứng đầu $F$ (hàng 1); phép xoay kết thúc bằng `#` chính là chuỗi gốc cộng `#`. Đặt $\text{start}$ = vị trí của `#` trong $L$. Theo vòng $\text{Next}$:

$$\text{start} \to \text{Next}[\text{start}] \to \text{Next}[\text{Next}[\text{start}]] \to \cdots$$

mỗi bước nhảy sang hàng của phép xoay được dịch trái một ký tự so với hàng trước; ký tự $L[\text{cur}]$ đọc được chính là ký tự dẫn đầu của phép xoay trước đó, tức ký tự tiếp theo của chuỗi gốc theo chiều thuận. Lặp đến khi quay về $\text{start}$ (bỏ qua ký tự `#`), ta thu được toàn bộ chuỗi gốc theo đúng thứ tự.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: BWT (cột cuối $L$) $= \text{"cb\#ab"}$ ($n{+}1 = 5$, chuỗi gốc có $n = 4$).

Cột đầu $F = L$ sắp xếp tăng dần $= \text{"\#abbc"}$.

Phân loại ngăn xếp (đỉnh = vị trí nhỏ, do duyệt phải sang trái):

| ký tự | `#` | `a` | `b` | `c` |
|---|---|---|---|---|
| các hàng trong $L$ | 3 | 4 | 2, 5 | 1 |

Gán $\text{Next}$ theo thứ tự $F$ (`#`, `a`, `b`, `b`, `c`):

| $k$ (hàng $F$) | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| $F[k]$ | # | a | b | b | c |
| $\text{Next}[k]$ (hàng trong $L$) | 3 | 4 | 2 | 5 | 1 |
| $L[\text{Next}[k]]$ | # | a | b | b | c |

(Hàng $L[\text{Next}[k]]$ khớp với $F[k]$, biểu diễn tính chất LF.)

$\text{start} = 3$ (vị trí `#` trong $L$). Theo vòng $\text{Next}$, đọc $L[\text{cur}]$ (bỏ `#`):

$$3 \xrightarrow{\text{Next}} 2 \xrightarrow{\text{Next}} 4 \xrightarrow{\text{Next}} 5 \xrightarrow{\text{Next}} 1 \xrightarrow{\text{Next}} 3$$

Ký tự đọc: $L[2]=\text{b}, L[4]=\text{a}, L[5]=\text{b}, L[1]=\text{c}$ $\to$ `"babc"`.

Kết quả:
```
babc
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ phân loại ngăn xếp, gán $\text{Next}$, và nhảy vòng tái tạo đều là các bước tuyến tính.
- **Bộ nhớ:** $O(n)$ $\textemdash$ mảng $\text{Next}$, chuỗi đầu vào, và 27 ngăn xếp phân loại.

## Mã nguồn (C++)

[Mã nguồn](../code/String%20Transform.cpp)
