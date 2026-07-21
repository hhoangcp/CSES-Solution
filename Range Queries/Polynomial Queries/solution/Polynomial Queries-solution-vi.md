# Polynomial Queries - Lời giải

**ID:** 1736 | **URL:** https://cses.fi/problemset/task/1736

## Hướng tiếp cận

### Tóm tắt đề bài

Duy trì mảng $n$ giá trị. Xử lý $q$ truy vấn:
1. Tăng vị trí $i$ trong đoạn $[a, b]$ thêm $(i - a + 1)$.
2. Tính tổng các giá trị trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Truyền lười thông thường chỉ xử lý cập nhật cộng hằng số. Ở đây lượng tăng tuyến tính theo $i$: $\Delta_i = (i - a + 1) = i - (a - 1)$. Phân rã thành phần hằng số $-(a-1)$ và phần tuyến tính $+i$. Lưu hai tham số lười tại mỗi nút:

- **`Lazy_1`**: tích lũy hệ số hằng số. Đóng góp $\text{Lazy\_1} \times (r - l + 1)$ vào tổng đoạn $[l, r]$.
- **`Lazy_2`**: tích lũy hệ số tuyến tính. Đóng góp $\text{Lazy\_2} \times \sum_{i=l}^{r} i$ vào tổng, với $\sum_{i=l}^{r} i = \frac{r(r+1)}{2} - \frac{(l-1)l}{2}$ tính được trong $O(1)$.

Điều này đúng vì mỗi vị trí $i$ trong đoạn phải nhận thêm $\text{Lazy\_2} \cdot i + \text{Lazy\_1}$, nên tổng trên $[l', r']$ là:

$$\sum_{i=l'}^{r'} (\text{Lazy\_2} \cdot i + \text{Lazy\_1}) = \text{Lazy\_2} \cdot \sum_{i=l'}^{r'} i + \text{Lazy\_1} \cdot (r' - l' + 1)$$

Khi chia $[l, r]$ thành $[l, mid]$ và $[mid+1, r]$, cùng cặp $(\text{Lazy\_1}, \text{Lazy\_2})$ được truyền cho cả hai con — chỉ miền chỉ số thay đổi, bảo toàn tính đúng:

$$\sum_{i=l}^{r} (\text{Lazy\_2} \cdot i + \text{Lazy\_1}) = \sum_{i=l}^{mid} (\text{Lazy\_2} \cdot i + \text{Lazy\_1}) + \sum_{i=mid+1}^{r} (\text{Lazy\_2} \cdot i + \text{Lazy\_1})$$

### Thuật toán

1. **Xây dựng** cây phân đoạn, mỗi nút lưu `sum`, `Lazy_1`, `Lazy_2`.
2. **Cập nhật** $[a, b]$ với `val`: Tại nút $[l, r]$ nằm trọn trong đoạn:
   - `Lazy_1 -= val × (a - 1)`, `Lazy_2 += val`.
   - `sum += val × (cal(r) - cal(l-1)) - val × (a-1) × (r-l+1)`.
3. **Đẩy lười** xuống con $[l, mid]$ và $[mid+1, r]$:
   - Cộng `Lazy_1` và `Lazy_2` của cha vào lazy của mỗi con.
   - Cập nhật `sum` của mỗi con theo công thức trên với miền chỉ số tương ứng.
   - Đặt lại lazy của cha về 0.
4. **Truy vấn** $[a, b]$: Truy vấn tổng đoạn thông thường với truyền lười.

### Ví dụ minh họa

Đầu vào:
```
5 3
4 2 3 1 7
2 1 5
1 1 5
2 1 5
```

Mảng: $[4, 2, 3, 1, 7]$. Tổng gốc $= 17$.

- Truy vấn $[1, 5]$: trả về 17.
- Cập nhật $[1, 5]$ với val $= 1$: `Lazy_1 -= 0`, `Lazy_2 += 1`, `sum += cal(5) - cal(0) = 15`. Tổng gốc mới $= 32$. Mảng thành $[5, 4, 6, 5, 12]$.
- Truy vấn $[1, 5]$: trả về 32.

Kết quả:
```
17
32
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Polynomial%20Queries.cpp)
