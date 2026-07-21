# Sum of Three Values - Lời giải

**ID:** 1641 | **URL:** https://cses.fi/problemset/task/1641

## Đề bài

Cho mảng gồm $n$ số nguyên $a_1, a_2, \ldots, a_n$ và giá trị mục tiêu $x$. Tìm ba chỉ số phân biệt $i, j, k$ sao cho $a_i + a_j + a_k = x$. Nếu có nhiều đáp án, xuất bất kỳ; nếu không tồn tại, xuất `IMPOSSIBLE`.

## Hướng tiếp cận

### 1. Sắp xếp mảng bảo toàn vị trí gốc

Vì đề yêu cầu trả về vị trí ban đầu, ta đính kèm chỉ số gốc vào từng phần tử thành các cặp $(\text{giá trị}, \text{vị trí gốc})$, rồi sắp xếp theo giá trị tăng dần. Gọi mảng sau sắp xếp là $A$.

### 2. Cố định một phần tử, hai con trỏ cho hai phần tử còn lại

Ý tưởng cốt lõi là đưa bài toán tổng 3 số về bài toán tổng 2 số (two pointers). Duyệt $l$ từ $1$ đến $n$ để cố định phần tử thứ nhất $A[l]$; khi đó hai phần tử còn lại phải có tổng:

$$X = x - A[l].a$$

Vì $A$ đã sắp xếp tăng, ta đặt hai con trỏ `mid = l + 1` và $r = n$ trên đoạn $[l+1, n]$ rồi thu hẹp khoảng:

- Nếu $A[mid].a + A[r].a > X$: tổng đang lớn, giảm $r$ (`--r`).
- Nếu $A[mid].a + A[r].a < X$: tổng đang nhỏ, tăng `mid` (`++mid`).
- Nếu $A[mid].a + A[r].a = X$: tìm thấy bộ ba, xuất các vị trí gốc của $A[l]$, $A[mid]$, $A[r]$ rồi dừng.
- Dừng khi `mid >= r`.

Việc luôn giới hạn `mid` và $r$ ở phía sau $l$ (bắt đầu `mid = l + 1`) đảm bảo ba phần tử nằm ở ba vị trí khác nhau trên mảng đã sắp xếp, loại trùng lặp.

## Ví dụ minh họa

Xét $n = 5$, $x = 9$, mảng $a = [2, 1, 5, 3, 7]$.

Sau khi sắp xếp tăng dần kèm vị trí gốc:

$$A = [(1, 2),\ (2, 1),\ (3, 4),\ (5, 3),\ (7, 5)]$$

*(mỗi cặp dạng $(\text{giá trị}, \text{vị trí gốc})$)*.

- **$l = 1$ ($A[1] = (1, 2)$):** cần tìm hai phần tử còn lại có tổng $X = 9 - 1 = 8$. Khởi tạo `mid = 2` (giá trị $2$), $r = 5$ (giá trị $7$).
  - $2 + 7 = 9 > 8$ $\to$ giảm $r$ xuống $4$.
  - `mid = 2` (giá trị $2$), $r = 4$ (giá trị $5$): $2 + 5 = 7 < 8$ $\to$ tăng `mid` lên $3$.
  - `mid = 3` (giá trị $3$), $r = 4$ (giá trị $5$): $3 + 5 = 8 = X$.
- **Kết quả:** tìm thấy bộ ba, các vị trí gốc là $2,\ 4,\ 3$ (tức $a_2 + a_4 + a_3 = 1 + 3 + 5 = 9$).

## Độ phức tạp

- **Thời gian:** $O(n^2)$. Sắp xếp tốn $O(n \log n)$; vòng ngoài cố định $l$ chạy $n$ lần, mỗi lần hai con trỏ chỉ dịch một chiều (`mid` tăng hoặc $r$ giảm) nên tốn tối đa $O(n)$ bước. Tổng $O(n \log n) + O(n^2) = O(n^2)$, đáp ứng $n \le 5000$.
- **Bộ nhớ:** $O(n)$ để lưu mảng các cặp (giá trị, vị trí gốc).
