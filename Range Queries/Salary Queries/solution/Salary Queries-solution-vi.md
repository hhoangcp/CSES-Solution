# Salary Queries - Lời giải

**ID:** 1144 | **URL:** https://cses.fi/problemset/task/1144

## Hướng tiếp cận

### Tóm tắt đề bài

Công ty có $n$ nhân viên, nhân viên thứ $i$ có lương $p_i$. Xử lý $q$ truy vấn:
1. `! k x`: đổi lương nhân viên $k$ thành $x$.
2. `? a b`: đếm số nhân viên có lương thuộc đoạn $[a, b]$.

### Ý tưởng cốt lõi

Dùng **cây Fenwick (BIT)** kết hợp **nén tọa độ**. Lương có thể lên tới $10^9$, không thể dùng trực tiếp làm chỉ số mảng. Thu thập mọi giá trị có thể xuất hiện — lương ban đầu, giá trị cập nhật, và hai biên $a, b$ của truy vấn đếm — sắp xếp rồi ánh xạ mỗi giá trị thành thứ hạng. Phép nén bảo toàn thứ tự: $v_1 \le v_2 \iff f(v_1) \le f(v_2)$, nên truy vấn đoạn $[a, b]$ trong tọa độ gốc ánh xạ chính xác sang $[f(a), f(b)]$ trong tọa độ nén.

BIT duy trì tần suất tại mỗi vị trí nén. Đếm đoạn $[a, b]$ bằng `query(f(b)) - query(f(a)-1)`. Khi cập nhật, xóa lương cũ (`update(f(p_k), -1)`) và thêm lương mới (`update(f(x), +1)`).

### Thuật toán

1. **Nén tọa độ:** Thu thập mọi giá trị lương (ban đầu, cập nhật, biên truy vấn). Sắp xếp, loại trùng, ánh xạ thành thứ hạng.
2. **Khởi tạo BIT:** Với mỗi nhân viên, `update(f(p_i), +1)`.
3. **Cập nhật** `! k x`: `update(f(p_k), -1)`, `update(f(x), +1)`, đặt $p_k = x$.
4. **Truy vấn** `? a b`: Trả về `query(f(b)) - query(f(a) - 1)`.

### Ví dụ minh họa

Đầu vào:
```
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3
```

Lương: $[3, 7, 2, 2, 5]$.

- Truy vấn `? 2 3`: nhân viên có lương $\in [2, 3]$ là vị trí 1, 3, 4. Đếm $= 3$.
- Cập nhật `! 3 6`: nhân viên 3 đổi lương từ 2 sang 6. Lương thành $[3, 7, 6, 2, 5]$.
- Truy vấn `? 2 3`: nhân viên có lương $\in [2, 3]$ là vị trí 1, 4. Đếm $= 2$.

Kết quả:
```
3
2
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log(n + q))$
- **Bộ nhớ:** $O(n + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/Salary%20Queries.cpp)
