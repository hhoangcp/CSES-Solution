# List of Sums - Lời giải

**ID:** 2414 | **URL:** https://cses.fi/problemset/task/2414

## Đề bài

Cho danh sách $B$ gồm $m = \frac{n(n-1)}{2}$ số nguyên là tổng của mọi cặp phần tử từ danh sách $A$ (gồm $n$ số nguyên dương). Nhiệm vụ là tái tạo lại danh sách $A$ ban đầu.

## Hướng tiếp cận

### 1. Quan sát và Giả định

Giả sử danh sách $A$ được sắp xếp tăng dần: $a_1 \le a_2 \le \dots \le a_n$.

Khi đó, danh sách $B$ sau khi sắp xếp tăng dần sẽ có:

- **$b[1] = a_1 + a_2$**: Đây chắc chắn là tổng nhỏ nhất.
- **$b[2] = a_1 + a_3$**: Đây chắc chắn là tổng nhỏ thứ hai.
- **$b[p] = a_2 + a_3$**: Giá trị này sẽ nằm đâu đó trong $n$ phần tử đầu tiên của $B$ (thường là $p \in [3, n]$).

### 2. Hệ phương trình tìm 3 số đầu tiên

Nếu ta biết $a_1+a_2$, $a_1+a_3$ và $a_2+a_3$, ta có thể giải hệ phương trình để tìm $a_1, a_2, a_3$:

$$a_2 = \frac{(a_1+a_2) + (a_2+a_3) - (a_1+a_3)}{2}$$

Tương ứng với mã nguồn: `a[2] = (b[1] + b[p] - b[2]) / 2`.

### 3. Giải thuật Duyệt và Khớp (Matching)

Vì không biết chắc chắn $b[p]$ nào là $a_2 + a_3$, ta thử mọi $p$ từ $3$ đến $n$:

1. **Tính $a_1, a_2, a_3$** từ $b[1], b[2], b[p]$. Nếu không nguyên hoặc không dương thì loại $p$ này.
2. **Sử dụng cơ chế tham khớp**: Duy trì các tổng đã biết từ các phần tử $a$ đã tìm được.
3. Duyệt qua các phần tử $b[i]$ còn lại trong $B$:
   - Nếu $b[i]$ khớp với một tổng của các cặp $(a_j, a_k)$ đã tìm được trước đó, ta bỏ qua (đã khớp).
   - Nếu $b[i]$ không khớp với bất kỳ cặp nào hiện có, thì $b[i]$ phải là tổng của phần tử nhỏ nhất $a_1$ với một phần tử mới $a_{next}$.
   - Tính $a_{next} = b[i] - a_1$, sau đó cập nhật danh sách các tổng cần khớp mới.
4. Nếu khớp được hết toàn bộ $m$ phần tử của $B$ và tìm đủ $n$ phần tử của $A$, ta có đáp án.

### Chứng minh tính đúng đắn

- **Tính duy nhất**: Tại mỗi bước, nếu ta đã xác định được $k$ phần tử đầu tiên của $A$, thì tổng chưa khớp nhỏ nhất trong $B$ bắt buộc phải là $a_1 + a_{k+1}$. Điều này cho phép ta xác định chính xác phần tử tiếp theo của $A$ mà không cần đoán mò thêm.
- **Giới hạn tìm kiếm**: Việc chỉ thử $p$ trong khoảng $[3, n]$ là đủ vì $a_2 + a_3$ không thể lớn hơn các tổng có dạng $a_1 + a_x$ với $x > n$.

## Độ phức tạp

- **Thời gian**: $O(n^3)$ — Vòng lặp thử $p$ ($O(n)$) kết hợp với quá trình khớp mảng ($O(n^2)$). Với $n=100$, độ phức tạp này hoàn toàn nằm trong giới hạn cho phép.
- **Bộ nhớ**: $O(n^2)$ để lưu trữ danh sách $B$ và $O(n)$ cho danh sách $A$.

## Ví dụ minh họa

$n=4$, danh sách $B = [3, 6, 7, 8, 9, 12]$ (đã sắp xếp). $m = 6$.

### Bước 1: Xác định 3 tổng nhỏ nhất

$b[1]=3 = a_1+a_2$, $b[2]=6 = a_1+a_3$.

### Bước 2: Thử $p=3$

$b[3]=7 = a_2+a_3$. Giải hệ:
- $a_2 = (3 + 7 - 6)/2 = 2$
- $a_1 = 3 - 2 = 1$
- $a_3 = 6 - 1 = 5$

### Bước 3: Khớp các tổng còn lại

Đã biết $A = [1, 2, 5]$, tổng đã khớp: $\{1+2=3, 1+5=6, 2+5=7\}$.

- $b[4]=8$: không khớp tổng nào $\Rightarrow$ phần tử mới $a_4 = 8-1 = 7$. Thêm tổng: $\{1+7=8, 2+7=9, 5+7=12\}$.
- $b[5]=9$: khớp $2+7=9$ ✓
- $b[6]=12$: khớp $5+7=12$ ✓

**Kết quả: $A = [1, 2, 5, 7]$.**

### Ví dụ theo đề bài

$n=4$, danh sách $B = [4, 4, 4, 6, 6, 6]$ (đã sắp xếp). $m = 6$.

#### Bước 1: Xác định 3 tổng nhỏ nhất

$b[1]=4 = a_1+a_2$, $b[2]=4 = a_1+a_3$.

#### Bước 2: Thử $p=3$

$b[3]=4 = a_2+a_3$. Giải hệ:
- $a_2 = (4 + 4 - 4)/2 = 2$
- $a_1 = 4 - 2 = 2$
- $a_3 = 4 - 2 = 2$

#### Bước 3: Khớp các tổng còn lại

Đã biết $A = [2, 2, 2]$, tổng đã khớp: $\{2+2=4, 2+2=4, 2+2=4\}$.

- $b[4]=6$: không khớp tổng nào $\Rightarrow$ phần tử mới $a_4 = 6-2 = 4$. Thêm tổng: $\{2+4=6, 2+4=6, 2+4=6\}$.
- $b[5]=6$: khớp $2+4=6$ ✓
- $b[6]=6$: khớp $2+4=6$ ✓

**Kết quả: $A = [2, 2, 2, 4]$.** (Lời giải khác $[1,3,3,3]$ cũng hợp lệ và được chấp nhận.)

## Mã nguồn (C++)

[Mã nguồn](../code/List%20of%20Sums.cpp)
