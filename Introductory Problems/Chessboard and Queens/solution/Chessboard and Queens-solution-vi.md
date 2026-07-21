# Chessboard and Queens - Lời giải

**ID:** 1624 | **URL:** https://cses.fi/problemset/task/1624

## Phương pháp

### Tóm tắt bài toán

Đếm số cách đặt 8 hậu trên bàn cờ $8 \times 8$ có một số ô bị giữ (`*`), sao cho không hai hậu tấn công lẫn nhau và không có hậu nào đặt trên ô bị giữ.

### Ý tưởng chính

Vì mỗi hàng phải chứa đúng một hậu, ta đặt hậu theo từng hàng. Tại mỗi hàng, thử tất cả các cột và kiểm tra xem cột và hai đường chéo có còn trống không, đồng thời ô đó không bị giữ. Quay lui khám phá mọi cấu hình hợp lệ.

**Chỉ số đường chéo:** Hai ô $(r_1, c_1)$ và $(r_2, c_2)$ chung đường chéo khi và chỉ khi:
- Đường chéo trái (từ trái-trên xuống phải-dưới): $r_1 - c_1 = r_2 - c_2$ (mỗi bước xuống-phải tăng cả $r$ và $c$ lên 1).
- Đường chéo phải (từ phải-trên xuống trái-dưới): $r_1 + c_1 = r_2 + c_2$ (mỗi bước xuống-trái tăng $r$ lên 1 và giảm $c$ xuống 1).

Dùng mảng boolean lập chỉ số theo các giá trị này cho phép kiểm tra xung đột trong $O(1)$, thay vì phải duyệt tất cả hậu đã đặt trong $O(n)$.

**Tính đúng đắn:** Đệ quy thử tất cả 8 cột cho mỗi hàng, khám phá mọi cách đặt hợp lệ. Ba mảng `col`, `ld`, `rd` đảm bảo không hai hậu chung cột hay đường chéo; `board[r][c] == '.'` đảm bảo không đặt trên ô bị giữ. Mỗi cách đặt được xác định duy nhất bởi cột của hậu ở mỗi hàng, nên không đếm trùng.

### Thuật toán

1. Đọc bàn cờ $8 \times 8$. Khởi tạo `col[1..8]`, `ld[1..15]`, `rd[2..16]` bằng `false`, `count = 0`.
2. Đệ quy tại hàng $r$:
   - Nếu $r > 8$: tăng `count`.
   - Với mỗi cột $c$ từ 1 đến 8: nếu `col[c]`, `ld[r-c+8]`, `rd[r+c]` đều `false` và `board[r][c] == '.'`:
     - Đánh dấu `true`, đệ quy hàng $r+1$, rồi đánh dấu lại `false` (quay lui).
3. Xuất `count`.

### Ví dụ minh họa

Bàn cờ mẫu có 4 ô bị giữ (tại vị trí (3,3), (6,6), (6,7), (7,4)). Nếu không có ô bị giữ, có 92 cách đặt 8 hậu. Với các ô bị chặn, đáp án là 65.

Ví dụ, đặt hậu tại $(1,4)$: chỉ số đường chéo trái $= 1-4+8 = 5$, đường chéo phải $= 1+4 = 5$. Các mảng này được đánh dấu, nên không hậu nào sau đó có thể chung đường chéo.

## Độ phức tạp

- **Thời gian:** $O(n!)$ trường hợp xấu nhất, nhưng cắt tỉa giảm đáng kể — với $n=8$, số nút khám phá ít hơn 40320
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Chessboard%20and%20Queens.cpp)
