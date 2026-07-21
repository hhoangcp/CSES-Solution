# Increasing Array Queries - Lời giải

**ID:** 2416 | **URL:** https://cses.fi/problemset/task/2416

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn: số thao tác tối thiểu (mỗi lần tăng 1 phần tử lên 1) để mảng con $[a, b]$ trở thành mảng không giảm?

### Ý tưởng cốt lõi

Để biến mảng con $[l, r]$ thành mảng không giảm, duyệt trái sang phải duy trì maximum chạy $\text{cur}_i = \max_{j=l}^{i} x_j$. Chi phí bằng:

$$\sum_{i=l}^{r} (\text{cur}_i - x_i) = \sum_{i=l}^{r} \text{cur}_i - \sum_{i=l}^{r} x_i$$

Tổng thứ hai tính được bằng mảng tổng tiền tố. Thách thức nằm ở việc tính $\sum_{i=l}^{r} \text{cur}_i$ hiệu quả.

Ta xử lý **offline**, quét biên trái $l$ từ $n$ về $1$, duy trì **ngăn xếp đơn điệu** chứa các vị trí có giá trị giảm nghiêm ngặt. Khi thêm vị trí $i$:

1. Loại tất cả vị trí $j$ khỏi ngăn xếp mà $x_j \le x_i$ (vì $x_i$ chi phối chúng), xóa đóng góp của chúng khỏi BIT.
2. Gọi $\text{next}[i]$ là vị trí tiếp theo trên ngăn xếp có giá trị $> x_i$. Vị trí $i$ làm maximum chạy cho mọi vị trí trong $[i, \text{next}[i] - 1]$. Đóng góp là:
   $$\text{delta}[i] = (\text{next}[i] - i - 1) \cdot x_i - \sum_{j=i+1}^{\text{next}[i]-1} x_j$$
   Đây chính là tổng số thao tác để nâng tất cả phần tử giữa $i$ và $\text{next}[i]$ lên ít nhất $x_i$.
3. Đẩy $i$ vào ngăn xếp và nạp $\text{delta}[i]$ vào BIT tại vị trí $i$.

Với truy vấn $(l, r)$ khi $l$ là biên trái hiện tại: tìm trên ngăn xếp vị trí $p$ bao phủ $r$ (phần tử cuối cùng $\le r$). Đáp án bằng tổng BIT trên các khối nguyên vẹn trước $p$, cộng đóng góp phần từ $p$ đến $r$:

$$(r - p) \cdot x_p - \sum_{j=p+1}^{r} x_j$$

### Thuật toán

1. **Tiền xử lý:** Tính mảng tổng tiền tố. Nhóm truy vấn theo biên trái $l$. Khởi tạo lính canh $x_{n+1} = \infty$ trên ngăn xếp.
2. **Quét** $i$ từ $n$ về $1$: duy trì ngăn xếp đơn điệu và BIT như trên. Với mỗi truy vấn $(l, r)$ có $l = i$, tính đáp án dùng tìm kiếm nhị phân trên ngăn xếp cho đóng góp phần và BIT cho khối nguyên vẹn.
3. **Xuất** kết quả theo thứ tự truy vấn ban đầu.

### Ví dụ

Đầu vào:
```
5 3
2 10 4 2 5
3 5
2 2
1 4
```

Mảng: $[2, 10, 4, 2, 5]$.

- Truy vấn $[3, 5]$: mảng con $[4, 2, 5]$. Maximum chạy: $4, 4, 5$. Chi phí: $(4-4) + (4-2) + (5-5) = 2$.
- Truy vấn $[2, 2]$: mảng con $[10]$. Đã không giảm. Chi phí: 0.
- Truy vấn $[1, 4]$: mảng con $[2, 10, 4, 2]$. Maximum chạy: $2, 10, 10, 10$. Chi phí: $0 + 0 + 6 + 8 = 14$.

Kết quả:
```
2
0
14
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/Increasing%20Array%20Queries.cpp)
