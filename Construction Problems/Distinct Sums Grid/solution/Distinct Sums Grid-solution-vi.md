# Distinct Sums Grid - Lời giải

**ID:** 3424 | **URL:** https://cses.fi/problemset/task/3424

## Hướng tiếp cận

### Phát biểu lại bài toán

Xây dựng lưới $n \times n$ thỏa mãn: (1) mỗi số nguyên $1 \dots n$ xuất hiện đúng $n$ lần, và (2) tất cả $2n$ tổng hàng và cột đều phân biệt.

### Trường hợp không khả thi

Với $n \le 3$, không tồn tại lưới hợp lệ:

- **$n = 1$:** Chỉ có 1 tổng hàng và 1 tổng cột, cả hai đều bằng 1 — không thể phân biệt.
- **$n = 2$:** Tổng tất cả phần tử bằng $n \cdot n = 4$. Cần $r_1 + r_2 = c_1 + c_2 = 4$ với $r_1, r_2, c_1, c_2$ đôi một khác nhau, điều này không thể.
- **$n = 3$:** Tương tự, không có cách sắp xếp thỏa mãn cả hai điều kiện.

### Cấu trúc cho $n \ge 4$

**Khung cơ bản:** Điền khung con $(n-1) \times (n-1)$ góc trên trái bằng $a[i][j] = i$ (mỗi hàng hằng), gán cột cuối $a[i][n] = n$ với mọi $i$, và hàng cuối $a[n][j] = j$. Sau bước này, mỗi số $1 \dots n$ xuất hiện đúng $n$ lần (khung con đóng góp $n-1$ bản sao của mỗi $i < n$, cột cuối thêm một bản sao của $n$, hàng cuối thêm một bản sao của mỗi $1 \dots n$).

Các tổng hàng $i(n-1)+n$ (với $i < n$) tạo thành cấp số cộng có công sai $n-1 \ge 3$, nên đã phân biệt. Tổng hàng $n$ bằng $\frac{n(n+1)}{2}$, khác mọi tổng hàng khác khi $n \ge 4$. Tuy nhiên, một số tổng cột có thể trùng nhau, cần điều chỉnh.

**Hoán đổi để sửa xung đột cột:**

- **$n$ lẻ:** Hoán đổi $a[n][2]$ với $a[\lfloor n/2 \rfloor][n]$. Việc này dịch chuyển tổng cột 2 và tổng hàng $\lfloor n/2 \rfloor$, phá vỡ mọi sự bằng nhau. Vì chỉ trao đổi các giá trị đã có, bất biến đếm được bảo toàn.
- **$n$ chẵn:** Hoán đổi $a[n][n-1]$ với $a[n/2-1][n]$, sau đó hoán đổi $a[n][n/2-1]$ với $a[n/2][n/2-1]$. Hai lần hoán đổi điều chỉnh đủ tổng để đảm bảo tất cả $2n$ giá trị phân biệt.

### Ví dụ minh họa

$n = 5$:

Khung cơ bản:
```
1 1 1 1 5
2 2 2 2 5
3 3 3 3 5
4 4 4 4 5
1 2 3 4 5
```

$n$ lẻ, hoán đổi $a[5][2]$ (giá trị 2) với $a[2][5]$ (giá trị 5):

```
1 1 1 1 5
2 2 2 2 2
3 3 3 3 5
4 4 4 4 5
1 5 3 4 5
```

Tổng hàng: $\{9, 10, 17, 21, 18\}$, tổng cột: $\{11, 15, 13, 14, 22\}$ — cả 10 giá trị phân biệt, mỗi số $1 \dots 5$ xuất hiện đúng 5 lần.

## Độ phức tạp

- **Thời gian:** $O(n^2)$
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Sums%20Grid.cpp)
