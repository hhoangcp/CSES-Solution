# Range Updates and Sums - Lời giải

**ID:** 1735 | **URL:** https://cses.fi/problemset/task/1735

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn thuộc ba loại:
1. Tăng mỗi giá trị trong đoạn $[a, b]$ lên $x$.
2. Gán mỗi giá trị trong đoạn $[a, b]$ bằng $x$.
3. Tính tổng các phần tử trong đoạn $[a, b]$.

### Ý tưởng cốt lõi

Dùng cây phân đoạn với **hai tham số lười**: `increase` (lượng cộng đang chờ) và `Set`/`Set_All` (giá trị gán đang chờ). Thách thức là phép gán ghi đè mọi phép cộng trước đó, trong khi phép cộng tích lũy.

Mọi chuỗi thao tác trên một phần tử $v$ đều biểu diễn được dưới dạng hàm tuyến tính $f(v) = c \cdot v + d$:
- Đơn vị (chưa có thao tác): $f(v) = 1 \cdot v + 0$ (`Set_All = false`, `increase = 0`).
- Sau phép cộng thêm $x$: $g(v) = f(v) + x = c \cdot v + (d + x)$. Nên `increase += x`.
- Sau phép gán bằng $x$: $h(v) = 0 \cdot v + x$. Hệ số góc triệt về 0, nên `increase = 0`, `Set = x`, `Set_All = true`.

Góc nhìn đại số này giải thích trực tiếp quy tắc truyền lười:

**Đẩy lười** từ cha xuống con:
- Nếu cha có `Set_All = true`: phép gán ghi đè mọi trạng thái con. Đặt `con.Set = cha.Set`, `con.increase = cha.increase`, `con.Set_All = true`, `con.sum = (cha.Set + cha.increase) * độ_dài`.
- Nếu cha chỉ có `Set_All = false` (chỉ cộng): `con.increase += cha.increase`, `con.sum += cha.increase * độ_dài`. Nếu con đã có `Set_All = true`, lượng cộng chỉ cần tích vào `con.increase`.

**Áp dụng cộng** lên nút bị bao trọn: `increase += x`, `sum += x * độ_dài`.

**Áp dụng gán** lên nút bị bao trọn: `Set = x`, `Set_All = true`, `increase = 0`, `sum = x * độ_dài`.

### Thuật toán

1. **Xây dựng** cây phân đoạn, mỗi nút lưu `sum`, `increase`, `Set`, `Set_All`.
2. **Cộng đoạn** $[a, b]$ thêm $x$: tại nút bị bao trọn, `increase += x`, `sum += x * độ_dài`. Tại nút giao một phần, đẩy lười rồi đệ quy.
3. **Gán đoạn** $[a, b]$ bằng $x$: tại nút bị bao trọn, `Set = x`, `Set_All = true`, `increase = 0`, `sum = x * độ_dài`. Tại nút giao một phần, đẩy lười rồi đệ quy.
4. **Tổng đoạn** $[a, b]$: truy vấn tổng thông thường với truyền lười.

### Ví dụ minh họa

Đầu vào:
```
6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5
```

Mảng: $[2, 3, 1, 1, 5, 3]$.

- Tổng $[3, 5]$: $1 + 1 + 5 = 7$.
- Cộng $[2, 4]$ thêm 2: mảng thành $[2, 5, 3, 3, 5, 3]$.
- Tổng $[3, 5]$: $3 + 3 + 5 = 11$.
- Gán $[2, 4]$ bằng 5: mảng thành $[2, 5, 5, 5, 5, 3]$.
- Tổng $[3, 5]$: $5 + 5 + 5 = 15$.

Kết quả:
```
7
11
15
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Range%20Updates%20and%20Sums.cpp)
