# Range Interval Queries - Lời giải

**ID:** 3163 | **URL:** https://cses.fi/problemset/task/3163

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $x$ gồm $n$ số nguyên, xử lý $q$ truy vấn: có bao nhiêu số nguyên $i$ thỏa mãn $a \le i \le b$ và $c \le x_i \le d$?

### Ý tưởng cốt lõi

Mỗi phần tử tại vị trí $i$ mang giá trị $x_i$ được xem như điểm $(i, x_i)$ trên mặt phẳng 2D. Truy vấn yêu cầu đếm số điểm trong hình chữ nhật $[a, b] \times [c, d]$ — bài toán **đếm vùng 2D** kinh điển.

Xây cây phân đoạn trên miền giá trị $[1, 10^9]$. **Phiên bản $k$** lưu số lượng giá trị thuộc mỗi khoảng, chỉ xét phần tử từ vị trí 1 đến $k$. Theo cấu trúc, phiên bản $k$ = phiên bản $k-1$ cộng thêm 1 tại giá trị $x_k$, nên quy nạp theo $k$, phiên bản $k$ lưu đúng số lượng phần tử trong $[1, k]$.

Số phần tử trong $[a, b]$ có giá trị thuộc $[c, d]$ bằng:

$$\text{query}(\text{root}[b], c, d) - \text{query}(\text{root}[a-1], c, d)$$

Phép trừ loại bỏ hoàn toàn các phần tử từ vị trí 1 đến $a-1$, chỉ giữ lại đúng các phần tử trong $[a, b]$.

Khi chèn $x_i$ vào phiên bản $i$, dùng **sao chép đường đi** (path copying): chỉ tạo nút mới trên đường từ gốc đến lá của $x_i$ ($O(\log V)$ nút), các cây con không thay đổi được chia sẻ với phiên bản $i-1$. Vì các phiên bản cũ không bao giờ bị sửa đổi, các nút chia sẻ luôn giữ nguyên tính đúng.

### Thuật toán

1. **Xây dựng** cây phân đoạn bền vững: với mỗi vị trí $i$ từ 1 đến $n$, tạo phiên bản $i$ bằng cách chèn $x_i$ vào phiên bản $i-1$.
2. **Truy vấn** $(a, b, c, d)$: duyệt song song `root[b]` và `root[a-1]` trên miền giá trị $[1, V]$:
   - Nếu đoạn $[l, r]$ nằm trọn trong $[c, d]$: trả về $\text{seg}[\text{now}] - \text{seg}[\text{old}]$.
   - Nếu hoàn toàn nằm ngoài: trả về 0.
   - Ngược lại: đệ quy vào hai con và cộng kết quả.

### Ví dụ minh họa

Đầu vào:
```
8 4
3 2 4 5 1 1 5 3
2 4 2 4
5 6 2 9
1 8 1 5
3 3 4 4
```

Mảng: $[3, 2, 4, 5, 1, 1, 5, 3]$.

- Truy vấn $(2, 4, 2, 4)$: phần tử $\{2, 4, 5\}$, giá trị thuộc $[2,4]$: $\{2, 4\}$. Đáp án $= 2$.
- Truy vấn $(5, 6, 2, 9)$: phần tử $\{1, 1\}$, giá trị thuộc $[2,9]$: không có. Đáp án $= 0$.
- Truy vấn $(1, 8, 1, 5)$: cả 8 phần tử đều $\in [1,5]$. Đáp án $= 8$.
- Truy vấn $(3, 3, 4, 4)$: phần tử $\{4\}$, $4 \in [4,4]$. Đáp án $= 1$.

Kết quả:
```
2
0
8
1
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log V)$ với $V = 10^9$
- **Bộ nhớ:** $O(n \log V)$

## Mã nguồn (C++)

[Mã nguồn](../code/Range%20Interval%20Queries.cpp)
