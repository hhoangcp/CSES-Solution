# Tree Traversals - Lời giải

**ID:** 1702 | **URL:** https://cses.fi/problemset/task/1702

## Phương pháp

### Tóm tắt bài toán

Cho duyệt tiền thứ tự và trung thứ tự của cây nhị phân có nhãn phân biệt, xác định duyệt hậu thứ tự.

### Ý tưởng chính

Phần tử đầu tiên của tiền thứ tự luôn là gốc. Trong trung thứ tự, gốc chia dãy thành cây con trái (các phần tử trước gốc) và cây con phải (các phần tử sau gốc). Đệ quy: đọc gốc từ tiền thứ tự, chia trung thứ tự tại vị trí gốc, đệ quy trái rồi phải, cuối cùng xuất gốc — đúng thứ tự hậu thứ tự (trái → phải → gốc). Cặp (tiền thứ tự, trung thứ tự) xác định duy nhất cây nhị phân: gốc cố định bởi tiền thứ tự, cách chia trung thứ tự duy nhất cho mỗi cây con. Dùng mảng vị trí để tìm gốc trong trung thứ tự $O(1)$.

### Thuật toán

1. Tiền xử lý `pos[v]` = vị trí giá trị $v$ trong trung thứ tự.
2. Đệ quy với con trỏ `cur` vào tiền thứ tự:
   - Gốc = `preorder[cur]`, `mid = pos[gốc]`.
   - Đệ quy cây con trái (trung thứ tự `[Left, mid-1]`).
   - Đệ quy cây con phải (trung thứ tự `[mid+1, Right]`).
   - Xuất gốc.

### Ví dụ minh họa

Tiền thứ tự: [5, 3, 2, 1, 4]. Trung thứ tự: [3, 5, 1, 2, 4].

Gốc 5 → trái {3}, phải {1,2,4}. Trái: gốc 3 → xuất 3. Phải: gốc 2 → trái {1}, phải {4} → xuất 1, 4, 2. Xuất 5.

Hậu thứ tự: 3, 1, 4, 2, 5.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Traversals.cpp)
