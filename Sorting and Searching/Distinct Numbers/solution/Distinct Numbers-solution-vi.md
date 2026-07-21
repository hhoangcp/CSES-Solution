# Distinct Numbers - Lời giải

**ID:** 1621 | **URL:** https://cses.fi/problemset/task/1621

## Phương pháp

### Tóm tắt bài toán

Cho mảng gồm $n$ số nguyên, đếm số lượng giá trị phân biệt trong mảng.

### Ý tưởng chính

Cấu trúc `set` trong C++ là cây tìm kiếm nhị phân cân bằng với thuộc tính không chứa phần tử trùng lặp. Khi chèn toàn bộ $n$ phần tử vào `set`, các giá trị trùng sẽ bị tự động loại bỏ, nên kích thước tập hợp `S.size()` chính là số giá trị phân biệt. Tính đúng đắn bảo đảm vì: mọi giá trị phân biệt xuất hiện ít nhất một lần nên được chèn vào `set` ($V \subseteq S$), và `set` chỉ chứa giá trị từ mảng gốc ($S \subseteq V$), suy ra $S = V$.

Phương pháp thay thế: sắp xếp mảng rồi đếm số lần phần tử hiện tại khác phần tử liền trước — cũng đạt $O(n \log n)$ nhưng tận dụng tốt bộ nhớ đệm nên thực tế nhanh hơn.

### Thuật toán

1. Khởi tạo `set<int> S`.
2. Đọc từng phần tử, chèn vào `S`.
3. Xuất `S.size()`.

### Ví dụ minh họa

Mảng $[2, 3, 2, 2, 3]$.

| Bước | Phần tử | $S$ | Ghi chú |
|------|---------|-----|---------|
| 1 | 2 | $\{2\}$ | Mới |
| 2 | 3 | $\{2, 3\}$ | Mới |
| 3 | 2 | $\{2, 3\}$ | Đã tồn tại |
| 4 | 2 | $\{2, 3\}$ | Đã tồn tại |
| 5 | 3 | $\{2, 3\}$ | Đã tồn tại |

Kết quả: $|S| = \mathbf{2}$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Numbers.cpp)
