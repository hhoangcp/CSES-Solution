# Creating Offices - Lời giải

**ID:** 1752 | **URL:** https://cses.fi/problemset/task/1752

## Phương pháp

### Tóm tắt bài toán

Cho cây $n$ đỉnh và khoảng cách tối thiểu $d$, chọn số đỉnh lớn nhất sao cho khoảng cách giữa bất kỳ hai đỉnh được chọn đều ít nhất $d$.

### Ý tưởng chính

Dùng DFS tham lam xử lý từ dưới lên (hậu thứ tự). Tại mỗi cây con, ưu tiên giữ lại các đỉnh có độ sâu lớn nhất vì chúng nằm ở "rìa" cây, ít gây xung đột với các nhánh khác so với đỉnh gần gốc. Nếu hai đỉnh $i$ và $j$ trong cây con của $u$ xung đột (khoảng cách qua $u$ nhỏ hơn $d$), việc loại đỉnh nông hơn luôn tối ưu: đỉnh sâu hơn có khả năng xung đột nhiều hơn với tổ tiên, nên giữ lại nó không thể làm giảm tổng số đỉnh được chọn.

### Thuật toán

1. Gốc hóa cây tại đỉnh 1. Chạy DFS.
2. Tại mỗi đỉnh $u$, mặc định đánh dấu chọn, thu thập các đỉnh được chọn sâu nhất từ các cây con của các đỉnh con.
3. Sắp xếp danh sách theo độ sâu giảm dần.
4. Chừng nào hai đỉnh nông nhất còn vi phạm khoảng cách $d$ (công thức: $depth[i] + depth[j] - 2 \cdot depth[u] < d$), loại đỉnh nông nhất.
5. Trả về đỉnh sâu nhất còn lại cho tầng DFS phía trên.

### Ví dụ minh họa

$n=5$, $d=3$, cây: 1-2, 2-3, 3-4, 3-5.

- Tại đỉnh 3: thu thập đỉnh 4 (độ sâu 3) và đỉnh 5 (độ sâu 3). Đỉnh 3 có độ sâu 2.
- Xung đột 4-5: $3+3-2\cdot2=2<3$, loại đỉnh 5.
- Xung đột 4-3: $3+2-2\cdot2=1<3$, loại đỉnh 3.
- Tiếp tục lên gốc. Cuối cùng giữ đỉnh 1 và 4, khoảng cách = 3.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Creating%20Offices.cpp)
