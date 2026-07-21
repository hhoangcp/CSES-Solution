# Missing Coin Sum Queries - Lời giải

**ID:** 2184 | **URL:** https://cses.fi/problemset/task/2184

## Hướng tiếp cận

### Tóm tắt đề bài

Cho $n$ đồng xu có giá trị nguyên dương, xử lý $q$ truy vấn: với các đồng xu trong đoạn $[a, b]$, tổng nhỏ nhất không thể tạo ra là bao nhiêu?

### Ý tưởng cốt lõi

Thuật toán tham lam cổ điển cho các đồng xu đã sắp xếp $c_1 \le c_2 \le \cdots \le c_k$: duy trì $s$ = tổng nhỏ nhất chưa biểu diễn được (ban đầu 1). Nếu $c_i \le s$, cập nhật $s \leftarrow s + c_i$; ngược lại $s$ là đáp án. Điều này đúng vì sau khi biểu diễn được mọi tổng trong $[0, s{-}1]$, thêm đồng xu $c_i \le s$ mở rộng phạm vi lên $[0, s + c_i - 1]$ (khoảng mới $[c_i, s + c_i - 1]$ giao hoặc nối với $[0, s-1]$ do $c_i \le s$). Nếu $c_i > s$, tồn tại khoảng trống tại $s$.

Để xử lý truy vấn đoạn, ta không thể sắp xếp từng mảng con. Thay vào đó, sắp xếp **toàn bộ mảng** theo giá trị và dùng BIT trên vị trí gốc. Chèn từng phần tử theo thứ tự giá trị tăng dần. Sau khi chèn $i$ phần tử nhỏ nhất, BIT lưu tổng $i$ phần tử nhỏ nhất tại vị trí gốc. Với truy vấn $[a, b]$, tính `ans = BIT.query(b) - BIT.query(a-1) + 1` — tổng các phần tử đã chèn trong đoạn cộng 1. Tìm vị trí lớn nhất $p$ trong mảng sắp xếp mà giá trị $\le$ ans. Nếu $p \le i$ (tất cả phần tử liên quan đã chèn), ans là kết quả cuối cùng. Ngược lại, lên lịch đánh giá lại tại bước $p$.

Mỗi truy vấn được đánh giá lại tối đa $O(\log \Sigma x_i)$ lần vì $s$ ít nhất gấp đôi mỗi lần (nếu tổng phần tử $\le s$ đạt $\ge s$, thì $s$ mới $\ge 2s$).

### Thuật toán

1. **Sắp xếp** mảng theo giá trị: `sorted[i]` = giá trị phần tử nhỏ thứ $i$, `pos[i]` = vị trí gốc của nó.
2. **Lên lịch** tất cả truy vấn tại bước 0.
3. **Quét** $i$ từ 0 đến $n$: chèn `sorted[i]` tại vị trí `pos[i]` vào BIT (nếu $i > 0$). Với mỗi truy vấn được lên lịch tại bước $i$:
   - Tính `ans = BIT.sum(a, b) + 1`.
   - Tìm $p$ = chỉ số lớn nhất mà `sorted[p]` $\le$ ans (tìm kiếm nhị phân).
   - Nếu $p > i$: lên lịch lại truy vấn tại bước $p$.
   - Ngược lại: `ans` là đáp án cuối cùng.

### Ví dụ

Đầu vào:
```
5 3
2 9 1 2 7
2 4
4 4
1 5
```

Đồng xu: $[2, 9, 1, 2, 7]$. Sắp xếp: giá trị $[1, 2, 2, 7, 9]$, vị trí $[3, 1, 4, 5, 2]$.

- Truy vấn $[2,4]$ (đồng xu $[9, 1, 2]$: sắp xếp $[1, 2, 9]$):
  - Sau bước 1 (chèn 1 tại pos 3): tổng$[2,4] = 1$, ans$=2$. Chưa ổn định (phần tử $\le 2$ tại bước $\le 3$).
  - Sau bước 3 (đã chèn 1, 2, 2): tổng$[2,4] = 3$, ans$=4$. Tất cả phần tử $\le 4$ đã chèn. Đáp án = **4**.
- Truy vấn $[4,4]$ (đồng xu $[2]$):
  - Sau bước 1: tổng$[4,4] = 0$, ans$=1$. Ổn định (không có phần tử $\le 1$ trong đoạn). Đáp án = **1**.
- Truy vấn $[1,5]$ (đồng xu $[2, 9, 1, 2, 7]$):
  - Sau bước 3: tổng$[1,5] = 5$, ans$=6$. Ổn định (7 > 6). Đáp án = **6**.

Kết quả:
```
4
1
6
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n \cdot \log(\sum x_i))$
- **Bộ nhớ:** $O(n + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/Missing%20Coin%20Sum%20Queries.cpp)
