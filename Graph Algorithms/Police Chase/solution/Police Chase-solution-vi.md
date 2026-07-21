# Truy Bắt - Lời giải

**ID:** 1695 | **URL:** https://cses.fi/problemset/task/1695

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ đỉnh và $m$ cạnh, tìm số cạnh tối thiểu cần xóa để đỉnh 1 và đỉnh $n$ không còn liên thông, và liệt kê các cạnh đó.

### Ý tưởng chính

Theo **định lý luồng cực đại - lát cắt cực tiểu**, giá trị lát cắt nhỏ nhất bằng luồng cực đại. Mô hình hóa mỗi cạnh vô hướng thành hai cạnh có hướng sức chứa 1, rồi tính luồng cực đại từ 1 đến $n$ bằng thuật toán Dinic. Giá trị luồng chính là đáp án.

Để tìm các cạnh cụ thể: sau khi luồng cực đại, chạy BFS trên đồ thị dư (chỉ theo cạnh có sức chứa dư > 0) từ đỉnh 1. Gọi $S$ là tập đỉnh đến được, $T$ là phần còn lại. Theo định lý, các cạnh gốc bão hòa đi từ $S$ sang $T$ tạo thành lát cắt cực tiểu — chúng bắt buộc bão hòa (nếu không BFS sẽ mở rộng sang $T$), và tổng số cạnh bằng luồng cực đại. Xóa các cạnh này cắt đứt $S$ khỏi $T$, tức đỉnh 1 khỏi đỉnh $n$.

### Thuật toán

1. Với mỗi cạnh vô hướng $(u, v)$, thêm 4 cạnh có hướng: $u \to v$ (sức chứa 1), $v \to u$ (sức chứa 0), $v \to u$ (sức chứa 1), $u \to v$ (sức chứa 0). Mô hình đúng luồng trên đồ thị vô hướng.
2. Chạy thuật toán Dinic từ nguồn 1 đến đích $n$.
3. Chạy BFS lần cuối trên đồ thị dư để phân vùng đỉnh thành $S$ (đến được từ 1) và $T$ (không đến được).
4. Xuất mọi cạnh gốc $(u, v)$ với $u \in S$, $v \in T$, và cạnh bão hòa ($c = f$).

### Ví dụ minh họa

Input:
```
4 5
1 2
1 3
2 3
3 4
1 4
```

Luồng cực đại = 2 (ví dụ: 1 đơn vị theo $1 \to 4$, 1 đơn vị theo $1 \to 3 \to 4$). BFS trên đồ thị dư: $S = \{1, 2, 3\}$, $T = \{4\}$. Cạnh bão hòa từ $S$ sang $T$: $(3, 4)$ và $(1, 4)$.

Kết quả:
```
2
3 4
1 4
```

(Bất kỳ lát cắt cực tiểu nào đều được chấp nhận.)

## Độ phức tạp

- **Thời gian:** $O(n^2 \cdot m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Police%20Chase.cpp)
