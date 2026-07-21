# Truy Vấn Hành Tinh II - Lời giải

**ID:** 1160 | **URL:** https://cses.fi/problemset/task/1160

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị hàm trên $n$ đỉnh, xử lý $q$ truy vấn: tìm số bước tối thiểu để đi từ đỉnh $a$ đến đỉnh $b$, hoặc $-1$ nếu không đến được.

### Ý tưởng chính

Trong đồ thị hàm, từ bất kỳ đỉnh $a$, đường đi duy nhất đi qua một đuôi rồi vào chu trình. Vậy $b$ đến được từ $a$ chỉ khi $b$ nằm trên đường này — hoặc trên đuôi từ $a$ vào chu trình, hoặc trong chu trình.

Định nghĩa $\text{len}[u]$ sao cho nó giảm đúng 1 đơn vị theo mỗi cạnh: $\text{len}[u] = \text{len}[t_u] + 1$. Tính bằng DFS: khi DFS gặp đỉnh đã thăm (đóng chu trình), trả về giá trị cơ sở; lan truyền ngược đảm bảo $\text{len}$ giảm 1 theo chiều cạnh. Hệ quả: khi $b$ nằm xuôi dòng từ $a$, khoảng cách đơn giản là $\text{len}[a] - \text{len}[b]$.

Trả lời truy vấn $(a, b)$:
- **Trường hợp 1:** $b$ nằm trên đuôi từ $a$ vào chu trình. Kiểm tra bằng nhảy đôi: nếu $\text{Lifting}(a, \text{len}[a] - \text{len}[b]) = b$, đáp án là $\text{len}[a] - \text{len}[b]$.
- **Trường hợp 2:** $b$ nằm trong chu trình. Gọi $x = \text{Lifting}(a, \text{len}[a])$ là điểm vào chu trình của $a$. Nếu $\text{Lifting}(x, \text{len}[x] - \text{len}[b]) = b$, đáp án là $\text{len}[a] + \text{len}[x] - \text{len}[b]$.
- **Ngược lại:** $b$ không đến được từ $a$ (khác thành phần hoặc không nằm xuôi dòng).

### Thuật toán

1. Xây dựng bảng nhảy đôi $\text{up}[u][i]$ từ đầu vào.
2. DFS tính $\text{len}[u]$ cho mọi đỉnh.
3. Với mỗi truy vấn $(a, b)$:
   - Nếu $\text{Lifting}(a, \text{len}[a] - \text{len}[b]) = b$: xuất $\text{len}[a] - \text{len}[b]$.
   - Nếu $\text{Lifting}(\text{Lifting}(a, \text{len}[a]), \text{len}[\text{Lifting}(a, \text{len}[a])] - \text{len}[b]) = b$: xuất $\text{len}[a] + \text{len}[\text{Lifting}(a, \text{len}[a])] - \text{len}[b]$.
   - Ngược lại: xuất $-1$.

### Ví dụ minh họa

Input:
```
5 3
2 3 2 3 2
1 2
1 3
1 4
```

Đồ thị: chu trình $2 \to 3 \to 2$ (độ dài 2). Đuôi: $1 \to 2$, $4 \to 3$, $5 \to 2$.

$\text{len} = [3, 2, 1, 2, 3]$ (len[3] = 1 trên chu trình, len[2] = 2 trên chu trình, đuôi cộng thêm khoảng cách).

- Truy vấn $(1, 2)$: Trường hợp 1 — $\text{Lifting}(1, 3-2) = \text{Lifting}(1, 1) = 2 = b$. Đáp án: $3 - 2 = 1$.
- Truy vấn $(1, 3)$: Trường hợp 1 — $\text{Lifting}(1, 3-1) = \text{Lifting}(1, 2) = 3 = b$. Đáp án: $3 - 1 = 2$.
- Truy vấn $(1, 4)$: Trường hợp 1 — $\text{Lifting}(1, 3-2) = 2 \ne 4$. Trường hợp 2 — $x = \text{Lifting}(1, 3) = 2$, $\text{Lifting}(2, 2-2) = 2 \ne 4$. Đáp án: $-1$.

Kết quả:
```
1
2
-1
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Planets%20Queries%20II.cpp)
