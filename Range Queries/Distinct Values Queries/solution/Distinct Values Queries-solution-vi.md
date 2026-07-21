# Distinct Values Queries - Lời giải

**ID:** 1734 | **URL:** https://cses.fi/problemset/task/1734

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn: có bao nhiêu giá trị phân biệt trong đoạn $[a, b]$?

### Ý tưởng cốt lõi

Một giá trị tại vị trí $i$ là "lần xuất hiện đầu tiên trong đoạn $[l, r]$" khi và chỉ khi không có giá trị nào bằng nó ở vị trí $\ge l$ và $< i$. Số giá trị phân biệt trong $[l, r]$ chính bằng số lần xuất hiện đầu tiên như vậy.

Định nghĩa $\text{Next}[i]$ = vị trí gần nhất bên phải $i$ có cùng giá trị $a[i]$ (0 nếu không có). Ta xử lý các truy vấn offline, sắp xếp theo biên trái $l$ tăng dần. Duy trì BIT tại đó vị trí $j$ lưu giá trị 1 nếu $j$ là "đại diện" cho giá trị $a[j]$ (lần xuất hiện đầu tiên tính từ $l$), và 0 nếu không. Khi đó `query(r)` trên BIT trả về đúng số giá trị phân biệt trong $[l, r]$.

Khi biên trái dịch từ $l$ sang $l+1$, vị trí $l$ không còn thuộc các đoạn tương lai. Ta tắt $l$ (cộng $-1$). Nếu $\text{Next}[l] > 0$, vị trí $\text{Next}[l]$ trở thành đại diện mới cho $a[l]$ (vì không có giá trị nào bằng $a[l]$ trong $[l+1, \text{Next}[l]-1]$), ta bật nó lên (cộng $1$). Nếu $\text{Next}[l] = 0$, giá trị $a[l]$ không còn xuất hiện nữa, không cần bật đại diện mới. Bất biến BIT luôn phản ánh đúng tập đại diện cho biên trái hiện tại được duy trì.

### Thuật toán

1. **Nén tọa độ:** Nén giá trị mảng từ $[1, 10^9]$ về $[1, n]$.
2. **Tính Next[]:** Duyệt từ phải sang trái, theo dõi vị trí gần nhất bên phải của mỗi giá trị.
3. **Khởi tạo BIT:** Duyệt trái sang phải, cộng 1 tại vị trí lần đầu xuất hiện của mỗi giá trị.
4. **Xử lý truy vấn:** Nhóm truy vấn theo $l$ tăng dần. Duyệt $i$ từ 1 đến $n$: trả lời tất cả truy vấn có $l = i$ bằng `query(r)`, sau đó tắt $i$ (cộng $-1$) và bật $\text{Next}[i]$ nếu khác 0 (cộng $1$).

### Ví dụ

Đầu vào:
```
5 3
3 2 3 1 2
1 3
2 4
1 5
```

Mảng: $[3, 2, 3, 1, 2]$, Next: $[3, 5, 0, 0, 0]$.

- **$l = 1$:** BIT = $[1, 1, 0, 1, 0]$ (các vị trí 1, 2, 4 được bật là lần đầu của 3, 2, 1).
  - Truy vấn $[1, 3]$: `query(3) = 2`. Đúng: $\{3, 2\}$.
  - Truy vấn $[1, 5]$: `query(5) = 3`. Đúng: $\{3, 2, 1\}$.
  - Tắt 1, bật $\text{Next}[1] = 3$. BIT = $[0, 1, 1, 1, 0]$.
- **$l = 2$:**
  - Truy vấn $[2, 4]$: `query(4) = 3`. Đúng: $\{2, 3, 1\}$.
  - Tắt 2, bật $\text{Next}[2] = 5$. BIT = $[0, 0, 1, 1, 1]$.

Kết quả:
```
2
3
3
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Queries.cpp)
