# Distinct Values Sum - Lời giải

**ID:** 3150 | **URL:** https://cses.fi/problemset/task/3150

## Đề bài

Cho mảng $x_1, x_2, \dots, x_n$. Gọi $d(a,b)$ là số lượng giá trị phân biệt trong mảng con từ chỉ số $a$ đến $b$. Nhiệm vụ của bạn là tính tổng của tất cả $d(a,b)$ cho mọi cặp $1 \le a \le b \le n$.

## Hướng tiếp cận

### 1. Thay đổi góc nhìn: Đếm theo giá trị

Thay vì xét từng mảng con và đếm số giá trị phân biệt, ta xét từng giá trị phân biệt $v$ và đếm xem có bao nhiêu mảng con chứa giá trị $v$ này.

- Nếu giá trị $v$ xuất hiện ít nhất một lần trong mảng con $[a, b]$, nó sẽ đóng góp $1$ đơn vị vào tổng $d(a, b)$.
- Tổng cần tìm: $S = \sum_{v \in \text{distinct values}} (\text{số mảng con chứa ít nhất một số } v)$.

### 2. Phương pháp đếm ngược (Complementary Counting)

Để đếm số mảng con chứa ít nhất một số $v$, ta lấy tổng số mảng con trừ đi số mảng con **không chứa** $v$.

- Tổng số mảng con của mảng độ dài $n$ là: $\frac{n(n+1)}{2}$.
- Một mảng con **không chứa** $v$ nếu nó nằm hoàn toàn trong các "khoảng trống" giữa các lần xuất hiện liên tiếp của $v$.

### 3. Các bước thực hiện

1. Lưu trữ vị trí của từng giá trị $v$ vào một danh sách (sử dụng `std::map<int, std::vector<int>>`).
2. Với mỗi giá trị $v$, xác định các khoảng trống:
   - Khoảng trống đầu tiên: từ đầu mảng đến vị trí đầu tiên của $v$.
   - Các khoảng trống ở giữa: giữa hai vị trí liên tiếp $p_i$ và $p_{i+1}$ của $v$.
   - Khoảng trống cuối cùng: từ vị trí cuối cùng của $v$ đến hết mảng.
3. Nếu một khoảng trống có độ dài $g$, số mảng con nằm gọn trong đó là $\frac{g(g+1)}{2}$.
4. Cộng dồn kết quả cho tất cả các giá trị phân biệt.

## Ví dụ mô phỏng

Mảng: `1 2 3 1 1`, $n=5$. Tổng số mảng con: $\frac{5 \times 6}{2} = 15$.

- **Giá trị 1:** Vị trí $\{1, 4, 5\}$.
  - Khoảng trống: trước $1$ (dài $0$), giữa $1$ và $4$ (dài $2$, là số $\{2, 3\}$), giữa $4$ và $5$ (dài $0$), sau $5$ (dài $0$).
  - Số mảng con không chứa $1$: $\frac{2 \times 3}{2} = 3$.
  - Số mảng con chứa $1$: $15 - 3 = 12$.
- **Giá trị 2:** Vị trí $\{2\}$.
  - Khoảng trống: trước $2$ (dài $1$), sau $2$ (dài $3$).
  - Số mảng con không chứa $2$: $\frac{1 \times 2}{2} + \frac{3 \times 4}{2} = 1 + 6 = 7$.
  - Số mảng con chứa $2$: $15 - 7 = 8$.
- **Giá trị 3:** Vị trí $\{3\}$.
  - Khoảng trống: trước $3$ (dài $2$), sau $3$ (dài $2$).
  - Số mảng con không chứa $3$: $\frac{2 \times 3}{2} + \frac{2 \times 3}{2} = 3 + 3 = 6$.
  - Số mảng con chứa $3$: $15 - 6 = 9$.

**Tổng cộng:** $12 + 8 + 9 = 29$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — tốn thời gian để phân loại vị trí các phần tử bằng `map` hoặc sắp xếp.
- **Bộ nhớ:** $O(n)$ — lưu trữ danh sách vị trí cho từng phần tử.

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Sum.cpp)
