# Nearest Smaller Values - Lời giải

**ID:** 1645 | **URL:** https://cses.fi/problemset/task/1645

## Hướng tiếp cận

Xét vị trí $i$ và hai vị trí trước đó $j < k < i$. Nếu $x_j \geq x_k$, thì $x_j$ không bao giờ là đáp án cho vị trí nào bên phải $k$: nếu $x_k < x_i$ thì $x_k$ gần hơn và nhỏ hơn; nếu $x_k \geq x_i$ thì cả hai đều quá lớn. Điều này có nghĩa là tập ứng cử viên luôn có giá trị **tăng nghiêm ngặt** từ trái sang phải — ngăn xếp đơn điệu là cấu trúc dữ liệu tự nhiên.

Duyệt mảng từ trái sang phải, duy trì ngăn xếp chứa các chỉ số có giá trị tăng nghiêm ngặt từ đáy đến đỉnh. Với mỗi vị trí $i$:

1. **Loại bỏ:** Trong khi ngăn xếp không rỗng và $x_{S.\text{top}()} \geq x_i$, loại phần tử đỉnh.
2. **Truy vấn:** Nếu ngăn xếp rỗng, xuất $0$; ngược lại xuất $S.\text{top}()$.
3. **Thêm mới:** Đẩy $i$ vào ngăn xếp.

**Tính đúng:** Sau bước loại bỏ, mọi phần tử có giá trị $\geq x_i$ đã bị xóa khỏi đỉnh. Phần tử trên đỉnh (nếu có) có giá trị $< x_i$ và là vị trí gần nhất thỏa mãn — mọi vị trí giữa nó và $i$ hoặc đã bị loại (giá trị $\geq x_i$) hoặc có giá trị $\geq x_i$. Nếu ngăn xếp rỗng, không tồn tại vị trí nào bên trái có giá trị nhỏ hơn.

### Ví dụ minh họa

Xét $n = 8$, mảng $x = [2, 5, 1, 4, 8, 3, 2, 5]$ (chỉ số từ 1).

| $i$ | $x_i$ | Thao tác trên ngăn xếp | Đáp án | Ngăn xếp sau khi thêm |
|-----|-------|------------------------|--------|----------------------|
| 1 | $2$ | Rỗng → không loại | $0$ | $\{1\}$ |
| 2 | $5$ | Đỉnh $x_1=2 < 5$ → không loại | $1$ | $\{1, 2\}$ |
| 3 | $1$ | Loại 2 ($x_2=5 \geq 1$), loại 1 ($x_1=2 \geq 1$) | $0$ | $\{3\}$ |
| 4 | $4$ | Đỉnh $x_3=1 < 4$ → không loại | $3$ | $\{3, 4\}$ |
| 5 | $8$ | Đỉnh $x_4=4 < 8$ → không loại | $4$ | $\{3, 4, 5\}$ |
| 6 | $3$ | Loại 5 ($x_5=8 \geq 3$), loại 4 ($x_4=4 \geq 3$) | $3$ | $\{3, 6\}$ |
| 7 | $2$ | Loại 6 ($x_6=3 \geq 2$) | $3$ | $\{3, 7\}$ |
| 8 | $5$ | Đỉnh $x_7=2 < 5$ → không loại | $7$ | $\{3, 7, 8\}$ |

Kết quả: `0 1 0 3 4 3 3 7`

## Độ phức tạp

- **Thời gian:** $O(n)$ — mỗi phần tử được đẩy và loại khỏi ngăn xếp nhiều nhất 1 lần.
- **Bộ nhớ:** $O(n)$ — ngăn xếp chứa nhiều nhất $n$ phần tử.

## Mã nguồn (C++)

[Mã nguồn](../code/Nearest%20Smaller%20Values.cpp)
