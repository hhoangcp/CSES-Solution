# Sum of Two Values - Lời giải

**ID:** 1640 | **URL:** https://cses.fi/problemset/task/1640

## Đề bài

Cho mảng gồm $n$ số nguyên $a_1, a_2, \ldots, a_n$ và một số nguyên $x$. Tìm hai chỉ số ở hai vị trí khác nhau có tổng bằng $x$. Nếu có nhiều đáp án, xuất bất kỳ; nếu không tồn tại, xuất `IMPOSSIBLE`.

## Hướng tiếp cận

### 1. Sắp xếp mảng bảo toàn vị trí gốc

Để giảm tìm kiếm từ $O(n^2)$ xuống gần tuyến tính, ta cần mảng đã sắp xếp. Vì đề yêu cầu in vị trí gốc, ta gắn chỉ số gốc vào từng phần tử thành cặp $(\text{giá trị}, \text{vị trí gốc})$, rồi sắp xếp theo giá trị tăng dần. Gọi mảng sau sắp xếp là $A$.

### 2. Kỹ thuật hai con trỏ

Nhờ mảng đã tăng dần, ta dùng hai con trỏ dịch ngược chiều để tìm cặp có tổng bằng $x$:

- **Khởi tạo:** con trỏ trái $i = 1$, con trỏ phải $j = n$.
- Tại mỗi bước, xét tổng $A[i].val + A[j].val$:
  - Nếu $> x$: tổng quá lớn, giảm $j$ (`--j`).
  - Nếu $< x$: tổng quá nhỏ, tăng $i$ (`++i`).
  - Nếu $= x$ và $i \neq j$: tìm thấy cặp, xuất hai vị trí gốc $A[i].pos$ và $A[j].pos$ rồi dừng.
- **Dừng** khi $i > n$ hoặc $j < 1$ (trong code, điều kiện lặp là $i \le n$ và $j \ge 1$).

Do mảng đã sắp xếp, mỗi bước chỉ dịch một con trỏ theo một chiều, nên không cặp nào bị bỏ qua; điều kiện $i \neq j$ đảm bảo hai vị trí khác nhau.

## Ví dụ minh họa

Xét $n = 4$, $x = 8$, mảng $a = [2, 7, 5, 1]$.

Sau khi gắn chỉ số và sắp xếp tăng dần:

$$A = [(1, 4),\ (2, 1),\ (5, 3),\ (7, 2)]$$

*(mỗi cặp dạng $(\text{giá trị}, \text{vị trí gốc})$)*.

- $i = 1$ (giá trị $1$), $j = 4$ (giá trị $7$): $1 + 7 = 8 = x$ và $i \neq j$.
- **Kết quả:** tìm thấy cặp, hai vị trí gốc là $4$ và $2$ (tức $a_4 + a_2 = 1 + 7 = 8$).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$. Phần tốn nhất là sắp xếp $O(n \log n)$; quá trình hai con trỏ chỉ tốn $O(n)$ vì mỗi con trỏ dịch một chiều và không quay lại.
- **Bộ nhớ:** $O(n)$ để lưu mảng các cặp (giá trị, vị trí gốc).
