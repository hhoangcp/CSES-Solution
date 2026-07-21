# Mê Cung - Lời giải

**ID:** 1193 | **URL:** https://cses.fi/problemset/task/1193

## Phương pháp

### Tóm tắt bài toán

Cho mê cung kích thước $n \times m$ với điểm xuất phát `A` và điểm kết thúc `B`, tìm đường đi ngắn nhất từ `A` đến `B` di chuyển theo 4 hướng qua các ô sàn (`.`). Xuất độ dài và chuỗi hướng di chuyển, hoặc "NO" nếu không tồn tại đường đi.

### Ý tưởng chính

Mô hình hóa mê cung thành đồ thị lưới không trọng số: mỗi ô sàn là một đỉnh, hai ô kề nhau theo 4 hướng có cạnh nối. BFS trên đồ thị không trọng số luôn tìm đường đi ngắn nhất — khi một đỉnh lần đầu được phát hiện, nó được tiếp cận qua số cạnh ít nhất từ nguồn. Nếu `A` không được thăm, `A` và `B` không liên thông.

BFS chạy **từ `B` về `A`**. Mảng `trace` lưu ô cha (gần `B` hơn) trên cây BFS, nên khi truy vết từ `A` về `B` theo `trace`, các hướng được sinh ra đúng thứ tự từ `A` đến `B` mà không cần đảo ngược chuỗi.

### Thuật toán

1. Đọc mê cung. Xác định vị trí `A` và `B`.
2. Chạy BFS từ `B`. Với mỗi ô được phát hiện, lưu ô cha (`trace`) và khoảng cách từ `B` (`depth`).
3. Nếu `A` không được thăm, in "NO".
4. Ngược lại, in "YES" và `depth[A]`. Truy vết từ `A` về `B` qua `trace`: tại mỗi bước từ ô hiện tại $t$ sang ô cha $p$, xuất hướng dựa trên vị trí tương đối ($t.y > p.y \to$ `L`, $t.y < p.y \to$ `R`, $t.x > p.x \to$ `U`, $t.x < p.x \to$ `D`).

### Ví dụ minh họa

```
5 8
########
#.A#...#
#.##.#B#
#......#
########
```

BFS từ $B = (3,7)$ phát hiện $A = (2,3)$ ở khoảng cách 9. Truy vết từ $A$ về $B$:

$(2,3) \xrightarrow{L} (2,2) \xrightarrow{D} (3,2) \xrightarrow{D} (4,2) \xrightarrow{R} (4,3) \xrightarrow{R} (4,4) \xrightarrow{R} (4,5) \xrightarrow{R} (4,6) \xrightarrow{R} (4,7) \xrightarrow{U} (3,7)$

Kết quả:
```
YES
9
LDDRRRRRU
```

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$
- **Không gian:** $O(n \cdot m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Labyrinth.cpp)
