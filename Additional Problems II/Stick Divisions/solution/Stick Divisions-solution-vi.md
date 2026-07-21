# Stick Divisions - Lời giải

**ID:** 1161 | **URL:** https://cses.fi/problemset/task/1161

## Đề bài

Bạn có một thanh gỗ độ dài $x$ và muốn chia nó thành $n$ thanh có độ dài cho trước, với tổng độ dài bằng $x$. Trên mỗi bước, bạn có thể lấy bất kỳ thanh nào và chia nó thành hai thanh. Chi phí của thao tác này bằng độ dài của thanh ban đầu. Chi phí nhỏ nhất cần thiết để tạo ra các thanh là bao nhiêu?

## Hướng tiếp cận

### Bước 1: Đảo ngược bài toán — Từ cắt thành ghép

Thay vì cắt thanh lớn thành nhỏ (chiều thuận), nghĩ theo chiều ngược: bắt đầu từ $n$ thanh nhỏ, mỗi bước ghép hai thanh thành một thanh lớn hơn, chi phí bằng tổng độ dài hai thanh. Quá trình kết thúc khi chỉ còn 1 thanh độ dài $x$. Mỗi lần cắt thanh $d$ thành $a+b$ chi phí $d$, tương ứng ghép $a$ và $b$ chi phí $a+b=d$, nên tổng chi phí hai quá trình bằng nhau.

### Bước 2: Thuật toán tham lam Huffman

Quá trình ngược chính là bài toán **mã Huffman**: luôn ghép hai thanh ngắn nhất mỗi bước.

**Thuật toán:**
1. Đưa tất cả $n$ độ dài vào min-heap.
2. Lặp lại khi heap có hơn 1 phần tử:
   - Trích hai phần tử nhỏ nhất $a$ và $b$.
   - Cộng $a + b$ vào đáp án.
   - Đẩy $a + b$ trở lại heap.
3. Xuất đáp án.

**Tính tối ưu (Luận chứng trao đổi):** Chi phí tổng viết dưới dạng $\sum d_i \times \text{depth}_i$, trong đó $\text{depth}_i$ là số lần thanh $d_i$ tham gia phép ghép. Giả sử tồn tại phương án tối ưu mà thanh nhỏ $d_{small}$ ở tầng nông, thanh lớn $d_{large}$ ở tầng sâu hơn. Hoán đổi vị trí hai thanh: $d_{small}$ xuống sâu thêm $\Delta d$, $d_{large}$ lên cao bớt $\Delta d$. Tổng thay đổi $\Delta = (d_{small} - d_{large}) \times \Delta d < 0$ vì $d_{small} < d_{large}$. Vậy chi phí giảm sau hoán đổi, mâu thuẫn với tính tối ưu. Chi phí chỉ đạt min khi các thanh nhỏ nhất luôn được ghép sớm nhất (nằm tầng sâu nhất).

**Định lý:** Thuật toán tham lam cho chi phí cắt tối thiểu. Chứng minh quy nạp: $n=1$ chi phí 0 đúng. $n>1$: hai thanh ngắn nhất phải được ghép trước (theo luận chứng trao đổi), bài toán quy về $n-1$ thanh với thanh mới $a+b$. Theo giả thiết quy nạp, thuật toán trên bài toán con tối ưu.

### Ví dụ

$x = 8$, $n = 3$, độ dài: $2, 3, 3$.

- Heap: $\{2, 3, 3\}$. Ghép $2+3=5$, chi phí 5. Heap: $\{3, 5\}$.
- Ghép $3+5=8$, chi phí 8. Heap: $\{8\}$.
- Tổng chi phí: $5 + 8 = 13$.

Phương án khác: cắt 8 thành (2,6) chi phí 8, cắt 6 thành (3,3) chi phí 6. Tổng: 14 > 13. Huffman tối ưu hơn.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Stick%20Divisions.cpp)
