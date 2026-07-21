# Cyclic Array - Lời giải

**ID:** 1191 | **URL:** https://cses.fi/problemset/task/1191

## Đề bài

Cho một mảng tuần hoàn gồm $n$ phần tử. Bạn cần chia mảng này thành số lượng mảng con ít nhất sao cho tổng các phần tử trong mỗi mảng con không vượt quá $k$.

## Hướng tiếp cận

### 1. Xử lý tính tuần hoàn bằng cách nhân đôi mảng

Vì mảng là tuần hoàn, điểm chia có thể nằm ở bất kỳ đâu. Kỹ thuật phổ biến là nhân đôi mảng thành $2n$ phần tử để chuyển bài toán tuần hoàn về bài toán trên dãy tuyến tính.

- Tạo mảng mới: $a[1], a[2], \dots, a[n], a[1], a[2], \dots, a[n]$.
- Tính mảng tổng tiền tố $sum[i]$ để truy vấn tổng đoạn nhanh trong $O(1)$.

### 2. Tính bước nhảy xa nhất (Greedy)

Với mỗi vị trí bắt đầu $i$, ta muốn biết nếu tạo một mảng con bắt đầu từ $i$, điểm kết thúc xa nhất có thể là bao nhiêu mà tổng vẫn $\leq k$.

- Gọi $next[i]$ là vị trí ngay sau phần tử cuối cùng của mảng con bắt đầu từ $i$.
- $next[i]$ được tìm bằng tìm kiếm nhị phân (`upper_bound`) trên mảng tổng tiền tố sao cho $sum[next[i]-1] - sum[i-1] \leq k$.

### 3. Tối ưu hóa bằng Nhảy nhị phân (Binary Lifting)

Nếu ta nhảy tham lam từng bước từ $i \to next[i] \to next[next[i]]$, độ phức tạp sẽ là $O(n^2)$ trong trường hợp xấu nhất. Để tối ưu, ta sử dụng bảng nhị phân nhảy:

- `jump[i][j]`: Vị trí đạt được sau khi thực hiện $2^j$ mảng con bắt đầu từ $i$.
- Công thức: $jump[i][j] = jump[jump[i][j-1]][j-1]$.

### 4. Tìm lời giải tối ưu

Với mỗi vị trí bắt đầu $i \in [1, n]$, ta tính số mảng con tối thiểu để bao phủ được quãng đường độ dài $n$ (tức là đạt đến vị trí $\geq i + n$).

- Sử dụng bảng `jump` để nhảy từ các bit cao xuống thấp nhằm tìm số bước nhảy ít nhất.
- Kết quả cuối cùng là giá trị nhỏ nhất tìm được khi thử mọi vị trí bắt đầu $i$.

### Chứng minh tính đúng đắn

- **Tính tham lam:** Trong bài toán chia đoạn này, việc luôn chọn đoạn dài nhất có thể tại mỗi bước (tham lam) sẽ không bao giờ làm tệ đi kết quả so với việc chọn đoạn ngắn hơn, vì điểm kết thúc xa hơn sẽ mở ra nhiều lựa chọn hơn cho các đoạn kế tiếp (Exchange Argument).
- **Nhảy nhị phân:** Đây chỉ là cách tăng tốc quá trình nhảy tham lam từ $O(n)$ xuống $O(\log n)$ cho mỗi vị trí bắt đầu.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — bao gồm việc xây dựng bảng nhị phân nhảy và thực hiện $n$ lần tìm kiếm mỗi lần $O(\log n)$.
- **Bộ nhớ:** $O(n \log n)$ để lưu trữ bảng `jump`.

## Ví dụ minh họa

$n=5$, $k=10$, $a = [3, 5, 2, 4, 1]$.

### Bước 1: Nhân đôi mảng và tính tổng tiền tố

Mảng sau khi nhân đôi: $[3, 5, 2, 4, 1, 3, 5, 2, 4, 1]$

Tổng tiền tố: $[3, 8, 10, 14, 15, 18, 23, 25, 29, 30]$.

### Bước 2: Tính next[i] (bắt đầu xa nhất của đoạn tiếp theo)

Tìm vị trí đầu tiên mà $sum[j] > sum[i-1] + k$:

| $i$ | $sum[i-1]+k$ | $next[i]$ | Đoạn con | Tổng |
|-----|--------------|-----------|-----------|------|
| 1   | 10           | 4         | $[3,5,2]$ | 10   |
| 2   | 13           | 4         | $[5,2]$   | 7    |
| 3   | 18           | 7         | $[2,4,1,3]$ | 10 |
| 4   | 20           | 7         | $[4,1,3]$ | 8    |
| 5   | 24           | 8         | $[1,3,5]$ | 9    |

### Bước 3: Binary Lifting

Thử vị trí bắt đầu $i=1$:
- Nhảy 1: $1 \to next[1]=4$, đoạn $[3,5,2]$.
- Nhảy 2: $4 \to next[4]=7$, đoạn $[4,1,3]$. Đã đạt $7 \ge 1+5=6$.

Chỉ cần **2 mảng con**. Thử các vị trí bắt đầu khác cũng cho kết quả tối thiểu 2.

**Kết quả: 2.**

### Ví dụ theo đề bài

$n=8$, $k=5$, $a = [2, 2, 2, 1, 3, 1, 2, 1]$.

#### Bước 1: Nhân đôi mảng và tính tổng tiền tố

Mảng sau khi nhân đôi: $[2, 2, 2, 1, 3, 1, 2, 1, 2, 2, 2, 1, 3, 1, 2, 1]$

Tổng tiền tố: $[2, 4, 6, 7, 10, 11, 13, 14, 16, 18, 20, 21, 24, 25, 27, 28]$.

#### Bước 2: Tính next[i]

| $i$ | $sum[i-1]+k$ | $next[i]$ | Đoạn con | Tổng |
|-----|--------------|-----------|-----------|------|
| 1   | 5            | 3         | $[2,2]$   | 4    |
| 2   | 7            | 5         | $[2,2,1]$ | 5    |
| 3   | 9            | 5         | $[2,1]$   | 3    |
| 4   | 11           | 7         | $[1,3,1]$ | 5    |
| 5   | 12           | 7         | $[3,1]$   | 4    |
| 6   | 15           | 9         | $[1,2,1]$ | 4    |
| 7   | 16           | 10        | $[2,1,2]$ | 5    |
| 8   | 18           | 11        | $[1,2,2]$ | 5    |

#### Bước 3: Binary Lifting

Thử vị trí bắt đầu $i=2$:
- Nhảy 1: $2 \to next[2]=5$, đoạn $[2,2,1]$.
- Nhảy 2: $5 \to next[5]=7$, đoạn $[3,1]$.
- Nhảy 3: $7 \to next[7]=10$, đoạn $[2,1,2]$. Đã đạt $10 \ge 2+8=10$.

Chỉ cần **3 mảng con**. Thử các vị trí bắt đầu khác cũng cho kết quả tối thiểu 3.

**Kết quả: 3.**

## Mã nguồn (C++)

[Mã nguồn](../code/Cyclic%20Array.cpp)
