# Subarray Sum Queries II - Lời giải

**ID:** 3226 | **URL:** https://cses.fi/problemset/task/3226

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng tĩnh $n$ số nguyên, xử lý $q$ truy vấn: tính tổng mảng con lớn nhất trong đoạn $[a, b]$. Mảng con rỗng (tổng 0) được phép.

### Ý tưởng cốt lõi

Bài toán mở rộng từ *Subarray Sum Queries* — thay vì chỉ truy vấn toàn mảng, giờ cần truy vấn đoạn bất kỳ $[a, b]$. Dùng cùng cấu trúc cây phân đoạn với 4 đại lượng mỗi nút (Sum, Left, Right, Max) và cùng công thức gộp:

$$\text{Sum} = L.\text{Sum} + R.\text{Sum}$$
$$\text{Left} = \max(L.\text{Left}, L.\text{Sum} + R.\text{Left})$$
$$\text{Right} = \max(R.\text{Right}, R.\text{Sum} + L.\text{Right})$$
$$\text{Max} = \max(L.\text{Max}, R.\text{Max}, L.\text{Right} + R.\text{Left})$$

Điểm khác biệt then chốt: hàm `query` phải trả về struct Data (không phải số đơn lẻ) để có thể gộp kết quả từ nhiều đoạn. Điều này cần thiết vì mảng con tối ưu có thể cắt ranh giới giữa hai đoạn — không thể chỉ lấy $\max$ riêng từng nửa.

Phép gộp **không giao hoán** ($\text{merge}(L, R) \neq \text{merge}(R, L)$), nên kết quả phải gộp theo thứ tự trái sang phải. Hàm `query` phân hoạch $[a, b]$ thành tối đa $O(\log n)$ đoạn rời nhau theo thứ tự, rồi gộp tuần tự. Cách này đúng nhờ tính chất kết hợp của merge: gộp các đoạn $D_1, D_2, \ldots, D_k$ trái sang phải cho kết quả đồng nhất với tính toán trên toàn đoạn $[a, b]$.

Xuất kết quả: $\max(0, \text{result.Max})$ để xử lý mảng con rỗng.

### Thuật toán

1. **Xây dựng** cây phân đoạn với 4 đại lượng mỗi nút. Lá: Sum = Max = Left = Right = $x_i$.
2. **Truy vấn** $[a, b]$: đệ quy từ gốc, thu thập Data từ các nút bị bao trọn, gộp theo thứ tự trái sang phải. Trả về $\max(0, \text{result.Max})$.

### Ví dụ minh họa

Đầu vào:
```
8 4
2 5 1 -2 3 -1 -7 1
2 4
2 5
6 7
4 8
```

Mảng: $[2, 5, 1, -2, 3, -1, -7, 1]$.

- Truy vấn $[2, 4]$: phần tử $\{5, 1, -2\}$. Mảng con lớn nhất $= [5, 1] = 6$. Đáp án $= 6$.
- Truy vấn $[2, 5]$: phần tử $\{5, 1, -2, 3\}$. Mảng con lớn nhất $= [5, 1, -2, 3] = 7$. Đáp án $= 7$.
- Truy vấn $[6, 7]$: phần tử $\{-1, -7\}$. Max $= -1$, nhưng mảng con rỗng được phép. Đáp án $= 0$.
- Truy vấn $[4, 8]$: phần tử $\{-2, 3, -1, -7, 1\}$. Mảng con lớn nhất $= [3] = 3$. Đáp án $= 3$.

Kết quả:
```
6
7
0
3
```

## Độ phức tạp

- **Thời gian:** $O(n + q \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Subarray%20Sum%20Queries%20II.cpp)
