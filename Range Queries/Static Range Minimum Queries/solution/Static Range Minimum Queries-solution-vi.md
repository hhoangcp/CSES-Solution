# Static Range Minimum Queries - Lời giải

**ID:** 1647 | **URL:** https://cses.fi/problemset/task/1647

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng tĩnh $n$ số nguyên, xử lý $q$ truy vấn: tìm giá trị nhỏ nhất trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Dùng **cây phân đoạn** cho truy vấn minimum đoạn. Mỗi nút nội quản lý đoạn $[l, r]$ lưu $\min_{i \in [l,r]} x_i$. Vì $[l, r] = [l, mid] \cup [mid+1, r]$ (hợp rời nhau), cực tiểu phân rã:

$$\min_{i \in [l,r]} x_i = \min\left(\min_{i \in [l,mid]} x_i,\min_{i \in [mid+1,r]} x_i\right)$$

Nên giá trị mỗi nút bằng $\min$(con trái, con phải). Bất biến này đúng theo cấu trúc: lá lưu phần tử đơn lẻ, nút nội tổng hợp từ con.

Truy vấn $\min$ trên $[a, b]$: đệ quy từ gốc, nếu đoạn nút nằm trọn trong $[a, b]$ thì trả về giá trị lưu; nếu hoàn toàn nằm ngoài thì trả về $+\infty$ (phần tử trung hòa của min); ngược lại đệ quy vào hai con rồi lấy $\min$. Truy vấn phân hoạch $[a, b]$ thành tối đa $O(\log n)$ đoạn rời nhau, mỗi đoạn lưu đúng cực tiểu.

### Thuật toán

1. **Xây dựng** cây phân đoạn: lá lưu $x_i$, nút nội lưu $\min$(con trái, con phải).
2. **Truy vấn** $[a, b]$: đệ quy từ gốc, lấy $\min$ các đoạn con phù hợp.

### Ví dụ minh họa

Đầu vào:
```
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
```

Mảng: $[3, 2, 4, 5, 1, 1, 5, 3]$. Cây phân đoạn: gốc $[1,8] = 1$, $[1,4] = 2$, $[5,8] = 1$, $[1,2] = 2$, $[3,4] = 4$, $[5,6] = 1$, $[7,8] = 3$.

- Truy vấn $[2, 4]$: $\min(2, 4, 5) = 2$.
- Truy vấn $[5, 6]$: $\min(1, 1) = 1$.
- Truy vấn $[1, 8]$: $\min = 1$.
- Truy vấn $[3, 3]$: $x_3 = 4$.

Kết quả:
```
2
1
1
4
```

## Độ phức tạp

- **Thời gian:** $O(n + q \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Static%20Range%20Minimum%20Queries.cpp)
