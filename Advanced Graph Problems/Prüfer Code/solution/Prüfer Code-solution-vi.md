# Prüfer Code - Lời giải

**ID:** 1134 | **URL:** https://cses.fi/problemset/task/1134

## Phương pháp

### Tóm tắt bài toán

Cho mã Prüfer độ dài $n-2$ của cây đánh nhãn $n$ đỉnh, tái tạo và xuất các cạnh của cây.

### Ý tưởng chính

Đảo ngược cấu trúc Prüfer: bậc đỉnh bằng 1 + số lần xuất hiện trong mã. Mỗi bước, đỉnh bậc 1 nhỏ nhất là lá tiếp theo cần nối với phần tử mã hiện tại. Sau khi nối, giảm bậc phần tử mã — nếu thành bậc 1 và nhỏ hơn con trỏ hiện tại thì dùng ngay, ngược lại tăng con trỏ tìm lá tiếp theo. Do song ánh của mã Prüfer, tái tạo đúng và duy nhất. Con trỏ chỉ tiến nên tổng $O(n)$ thay vì dùng hàng đợi ưu tiên.

### Thuật toán

1. Tính `deg[i]` = số lần xuất hiện + 1.
2. `cur` = đỉnh nhỏ nhất có `deg == 1`, `leaf = cur`.
3. Với mỗi phần tử mã $x$:
   - Xuất cạnh `leaf -- x`.
   - Giảm `deg[x]`. Nếu `deg[x] == 1` và `x < cur`, `leaf = x`.
   - Ngược lại, tăng `cur` đến `deg[cur] == 1`, `leaf = cur`.
4. Xuất cạnh cuối `leaf -- n`.

### Ví dụ minh họa

$n=5$, mã: 2 2 4. deg: [1,3,1,2,1].

- leaf=1: xuất 1-2, deg[2]=2. cur→3, leaf=3.
- leaf=3: xuất 3-2, deg[2]=1, 2<3 → leaf=2.
- leaf=2: xuất 2-4, deg[4]=1. cur→4, leaf=4.
- Cuối: 4-5.

Kết quả: 1-2, 3-2, 2-4, 4-5.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Pr%C3%BCfer%20Code.cpp)
