# Convex Hull - Lời giải

**ID:** 2195 | **URL:** https://cses.fi/problemset/task/2195

## Phương pháp

### Tóm tắt bài toán

Cho $n$ điểm phân biệt trên mặt phẳng, tìm bao lồi — đa giác lồi nhỏ nhất chứa tất cả các điểm. Cần báo cáo tất cả các điểm nằm trên biên bao lồi, bao gồm cả các điểm thẳng hàng.

### Ý tưởng chính

Sử dụng thuật toán chuỗi đơn điệu Andrew, xây dựng bao dưới và bao trên riêng biệt.

Sắp xếp tất cả điểm theo thứ tự từ điển $(y, x)$. **Bao dưới** được xây dựng bằng cách quét trái sang phải: với mỗi điểm mới, trong khi hai điểm cuối bao và điểm mới tạo thành vòng quay theo chiều kim đồng hồ (CW), loại điểm cuối bao — điểm đó nằm bên trong bao vì nó nằm trong tam giác tạo bởi điểm trước nó, điểm mới và điểm tiếp theo trên bao. Sau đó thêm điểm mới. **Bao trên** được xây dựng tương tự nhưng quét theo thứ tự ngược. Hai bao chia sẻ điểm đầu cuối; gộp lại (loại trùng lặp) cho bao lồi hoàn chỉnh.

Kiểm tra CW dùng tích có hướng: ba điểm $A, B, C$ tạo vòng CW khi $(B_x - A_x)(C_y - A_y) - (B_y - A_y)(C_x - A_x) < 0$. Điểm thẳng hàng (tích có hướng $= 0$) được giữ lại, đảm bảo báo cáo đầy đủ các điểm trên biên.

### Thuật toán

1. Sắp xếp tất cả điểm theo $(y, x)$.
2. Xây bao dưới: với mỗi điểm theo thứ tự đã sắp, trong khi hai điểm cuối bao và điểm mới tạo vòng CW, loại điểm cuối bao. Thêm điểm mới.
3. Loại điểm cuối cùng của bao dưới (sẽ được thêm lại bởi bao trên).
4. Xây bao trên: với mỗi điểm theo thứ tự ngược, áp dụng cùng logic loại/thêm.
5. Loại điểm cuối cùng của bao trên (trùng với điểm đầu bao dưới).
6. Xuất kết quả bao lồi.

### Ví dụ minh họa

Điểm: $(2,1), (2,5), (3,3), (4,3), (4,4), (6,3)$.

Sắp xếp theo $(y,x)$: $(2,1), (3,3), (4,3), (6,3), (4,4), (2,5)$.

**Bao dưới:**
- $(2,1)$: bao $= [(2,1)]$
- $(3,3)$: bao $= [(2,1), (3,3)]$
- $(4,3)$: CW tại $(2,1) \to (3,3) \to (4,3)$, loại $(3,3)$. bao $= [(2,1), (4,3)]$
- $(6,3)$: CW tại $(2,1) \to (4,3) \to (6,3)$, loại $(4,3)$. bao $= [(2,1), (6,3)]$
- $(4,4)$: CCW, giữ. bao $= [(2,1), (6,3), (4,4)]$
- $(2,5)$: thẳng hàng $(6,3) \to (4,4) \to (2,5)$, giữ. bao $= [(2,1), (6,3), (4,4), (2,5)]$

**Bao trên** (thứ tự ngược: $(2,5), (4,4), (6,3), (4,3), (3,3), (2,1)$):
- $(2,5), (4,4), (6,3)$: đều thẳng hàng, giữ. bao $= [(2,5), (4,4), (6,3)]$
- $(4,3)$: CW, loại $(6,3)$; CW, loại $(4,4)$. bao $= [(2,5), (4,3)]$
- $(3,3)$: CW, loại $(4,3)$. bao $= [(2,5), (3,3)]$
- $(2,1)$: CW, loại $(3,3)$. bao $= [(2,5), (2,1)]$

**Gộp** (loại trùng lặp đầu cuối): $(2,1), (6,3), (4,4), (2,5)$ — 4 điểm.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Convex%20Hull.cpp)
