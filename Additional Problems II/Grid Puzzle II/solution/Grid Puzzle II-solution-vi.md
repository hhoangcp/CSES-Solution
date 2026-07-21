# Grid Puzzle II - Lời giải

**ID:** 2131 | **URL:** https://cses.fi/problemset/task/2131

## Đề bài

Có một lưới $n \times n$ mà mỗi ô chứa một số lượng đồng xu. Bạn biết với mỗi hàng và cột có bao nhiêu ô phải chọn. Bạn nhận được tất cả đồng xu từ mỗi ô được chọn. Số đồng xu tối đa bạn có thể thu được là bao nhiêu?

## Hướng tiếp cận

### Mô hình hóa: Luồng chi phí tối thiểu trên đồ thị hai phía

Giống Grid Puzzle I, nhưng mỗi ô $(i,j)$ có giá trị $c_{ij}$ (số đồng xu). Cần **tối đa hóa** tổng đồng xu thu được. Xây mạng luồng chi phí tối thiểu:

- **Nguồn $S$** $\to$ **hàng $i$**: dung lượng $a_i$, chi phí 0.
- **Hàng $i$** $\to$ **cột $j$**: dung lượng 1, chi phí $-c_{ij}$.
- **Cột $j$** $\to$ **đích $T$**: dung lượng $b_j$, chi phí 0.

**Tại sao chi phí âm?** Thuật toán luồng tối thiểu chi phí tìm **tối thiểu** tổng chi phí. Tối thiểu hóa $\sum (-c_{ij})$ tương đương tối đa hóa $\sum c_{ij}$. Mỗi đơn vị luồng qua cạnh hàng $i$ $\to$ cột $j$ tương ứng chọn ô $(i,j)$, tổng chi phí luồng $= -\sum c_{ij}$. Luồng bão hòa cạnh nguồn $\to$ hàng (đúng $a_i$) và cột $\to$ đích (đúng $b_j$), nên ràng buộc bậc được thỏa mãn.

### Tính khả thi: Đồ thị hai phía đầy đủ luôn có luồng

Đề bài đảm bảo $\sum a_i = \sum b_j$. Vì mọi hàng đều nối với mọi cột (đồ thị hai phía đầy đủ), luồng cực đại luôn đạt $\sum a_i$ (không có cụt). Vậy luôn tồn tại cách chọn thỏa mãn mọi ràng buộc bậc.

### Tối ưu chi phí: Không còn chu trình âm trong đồ thị dư

Thuật toán lặp: tìm đường tăng chi phí tối thiểu (SPFA/D'Esopo-Pape trên đồ thị dư), tăng luồng, lặp đến khi không còn đường tăng chi phí âm từ $S$ đến $T$. Theo **điều kiện tối ưu chi phí**, một luồng khả thi là luồng tối thiểu chi phí khi và chỉ khi không tồn tại chu trình chi phí âm trong đồ thị dư. SPFA tìm đường ngắn nhất nên sau mỗi lần tăng, không tạo chu trình âm mới. Khi không còn đường chi phí âm, điều kiện tối ưu thỏa mãn.

## Thuật toán

1. Xây mạng luồng với chi phí đảo dấu.
2. Lặp cho đến khi luồng đạt $\sum a_i$:
   - Tìm đường chi phí thấp nhất từ $S$ đến $T$ bằng SPFA hoặc D'Esopo-Pape.
   - Nếu không tìm thấy, xuất $-1$.
   - Tăng luồng dọc theo đường, cộng dồn chi phí.
3. Tổng đồng xu tối đa $= -(\text{tổng chi phí})$.

## Ví dụ minh họa

$n = 5$, $a = [0, 1, 3, 2, 0]$, $b = [1, 2, 2, 0, 1]$, tổng $= 6$.

Luồng tối thiểu chi phí $= -32$, tức tổng xu tối đa $= 32$.

## Độ phức tạp

- **Thời gian:** $O(F \cdot E \cdot V)$ trường hợp xấu nhất với SPFA, rất nhanh trong thực tế với $n = 50$
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Puzzle%20II.cpp)
