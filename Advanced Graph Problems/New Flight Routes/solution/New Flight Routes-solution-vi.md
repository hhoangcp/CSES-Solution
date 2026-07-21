# New Flight Routes - Lời giải

**ID:** 1685 | **URL:** https://cses.fi/problemset/task/1685

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh, $m$ cạnh. Thêm số chuyến bay tối thiểu để từ bất kỳ thành phố nào có thể đến bất kỳ thành phố nào khác (làm đồ thị liên thông mạnh).

### Ý tưởng chính

Tìm SCC bằng Tarjan, xây DAG ngưng tụ. Nếu chỉ 1 SCC, đáp án 0. Ngược lại, gọi $a$ = số nguồn (bậc vào 0), $b$ = số hố (bậc ra 0) trong DAG. Đáp án là $\max(a, b)$: mỗi nguồn cần 1 cạnh vào, mỗi hố cần 1 cạnh ra, nhưng 1 cạnh mới giải quyết tối đa 1 nguồn và 1 hố, nên cận dưới $\max(a, b)$; ngược lại, ghép cặp hố-nguồn thành chu trình luôn đạt được cận này.

### Thuật toán

1. Tìm SCC bằng Tarjan. Xây DAG ngưng tụ, đếm nguồn và hố.
2. Nếu chỉ 1 SCC, xuất 0.
3. Thêm $\max(a, b)$ cạnh: ghép hố với nguồn thành chu trình, xử lý nguồn/hố còn lại.
4. Xuất cạnh dùng đỉnh đại diện mỗi SCC.

### Ví dụ minh họa

$n=4$, cạnh: $1\to2$, $2\to3$, $3\to1$, $1\to4$, $3\to4$. SCC: {1,2,3} (nguồn), {4} (hố). $a=1, b=1$. Thêm cạnh $4\to2$.

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/New%20Flight%20Routes.cpp)
