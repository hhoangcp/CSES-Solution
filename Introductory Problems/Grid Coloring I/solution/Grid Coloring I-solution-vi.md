# Grid Coloring I - Lời giải

**ID:** 3311 | **URL:** https://cses.fi/problemset/task/3311

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times m$ trong đó mỗi ô được tô bằng một trong bốn màu (A, B, C, D). Tô lại lưới sao cho:
1. Không có hai ô kề nhau (chia sẻ cạnh) có cùng màu.
2. Màu mới của mỗi ô phải khác với màu gốc của nó.

### Ý tưởng chính

Mỗi ô $(i, j)$ có nhiều nhất **3 ràng buộc**: ô phía trên $(i-1, j)$, ô bên trái $(i, j-1)$, và màu gốc của chính nó. Theo nguyên lý chuồng bồ câu, 4 màu trừ 3 ràng buộc luôn còn ít nhất 1 màu khả dụng, nên lời giải luôn tồn tại.

Xử lý lưới theo thứ tự từ trên xuống dưới, trái sang phải, chọn màu khả dụng đầu tiên (theo A, B, C, D) luôn cho kết quả hợp lệ. Quy nạp: ô góc trên-trái có nhiều nhất 1 ràng buộc (3+ lựa chọn). Với mỗi ô tiếp theo, màu phía trên và bên trái đã cố định, nên nhiều nhất 3/4 màu bị cấm. Quyết định tại $(i, j)$ chỉ thêm ràng buộc cho ô dưới và ô phải, vốn vẫn có nhiều nhất 3 ràng buộc, nên không cần quay lui.

### Thuật toán

1. Duyệt lưới theo từng hàng, từ trái sang phải.
2. Với mỗi ô $(i, j)$:
   - Xác định các màu bị cấm: màu gốc, màu phía trên (nếu $i > 0$), màu bên trái (nếu $j > 0$).
   - Chọn màu đầu tiên từ {A, B, C, D} không nằm trong tập cấm.

### Ví dụ minh họa

Đầu vào: lưới $3 \times 4$ `AAAA / BBBB / CCDD`.

| Ô | Gốc | Trên | Trái | Cấm | Chọn |
|---|-----|------|------|-----|------|
| (0,0) | A | — | — | {A} | B |
| (0,1) | A | — | B | {A,B} | C |
| (0,2) | A | — | C | {A,C} | B |
| (0,3) | A | — | B | {A,B} | C |
| (1,0) | B | B | — | {B} | A |
| (1,1) | B | C | A | {B,C,A} | D |
| (1,2) | B | B | D | {B,D} | A |
| (1,3) | B | C | A | {B,C,A} | D |
| (2,0) | C | A | — | {C,A} | B |
| (2,1) | C | D | B | {C,D,B} | A |
| (2,2) | D | A | A | {D,A} | B |
| (2,3) | D | D | B | {D,B} | A |

Kết quả:
```
BCBC
ADAD
BABA
```

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$
- **Không gian:** $O(n \cdot m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Coloring%20I.cpp)
