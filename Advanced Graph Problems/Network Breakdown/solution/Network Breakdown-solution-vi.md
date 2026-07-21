# Network Breakdown - Lời giải

**ID:** 1677 | **URL:** https://cses.fi/problemset/task/1677

## Phương pháp

### Tóm tắt bài toán

Cho mạng $n$ máy tính và $m$ kết nối. $k$ kết nối đứt lần lượt. Sau mỗi lần đứt, báo số thành phần liên thông.

### Ý tưởng chính

Xóa cạnh trong DSU rất khó, nhưng thêm cạnh thì đơn giản. Đảo ngược quá trình: bắt đầu với trạng thái sau tất cả sự cố (chỉ còn cạnh không đứt), rồi thêm lại các cạnh đứt theo thứ tự ngược ($e_k, e_{k-1}, \ldots, e_1$). Bất biến: sau khi thêm lại $\{e_k, \ldots, e_{i+1}\}$, tập cạnh đang có chính là $E \setminus \{e_1, \ldots, e_i\}$, tức đúng trạng thái sau sự cố thứ $i$. Vì số thành phần chỉ phụ thuộc tập cạnh (không phụ thuộc thứ tự thêm), số thành phần ghi nhận trước khi thêm $e_i$ chính là đáp án cho sự cố thứ $i$.

### Thuật toán

1. Đọc $m$ cạnh, lưu vào tập `Start`. Đọc $k$ cạnh đứt, xóa khỏi `Start`, lưu vào `Q`.
2. Khởi tạo DSU $n$ thành phần. Union tất cả cạnh trong `Start`.
3. Duyệt sự cố từ $k$ về $1$:
   - Ghi `ans[i] = comps` (số thành phần hiện tại).
   - Union cạnh sự cố thứ $i$. Nếu hai đầu khác thành phần, `comps--`.
4. Xuất `ans[1], ans[2], ..., ans[k]`.

### Ví dụ minh họa

Mạng: 1-2, 1-3, 2-3, 3-4, 4-5. Sự cố: (3,4), (2,3), (4,5).

Sau khi loại 3 cạnh đứt: Start = {1-2, 1-3, 2-3}. comps = 3.

Thêm ngược: ans[3]=3, thêm 4-5 → comps=2. ans[2]=2. ans[1]=2.

Kết quả: `2 2 3`

## Độ phức tạp

- **Thời gian:** $O((n + m) \cdot \alpha(n))$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Network%20Breakdown.cpp)
