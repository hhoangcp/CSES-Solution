# Flight Route Requests - Lời giải

**ID:** 1699 | **URL:** https://cses.fi/problemset/task/1699

## Phương pháp

### Tóm tắt bài toán

Cho $n$ thành phố và $m$ yêu cầu "phải có đường đi từ $a$ đến $b$". Tìm số cạnh hướng tối thiểu cần thêm để thỏa mãn mọi yêu cầu.

### Ý tưởng chính

Chia đồ thị yêu cầu thành các thành phần liên thông vô hướng. Với mỗi thành phần $k$ đỉnh:
- Nếu đồ thị con (chỉ dùng cạnh xuôi) là **DAG**: cần $k-1$ cạnh (đường đi Hamilton đủ để mọi đỉnh sau đạt được từ đỉnh trước; tối ưu vì ít nhất $k-1$ cạnh để nối $k$ đỉnh).
- Nếu chứa **chu trình**: cần $k$ cạnh. Xây chu trình Hamilton đi qua mọi đỉnh: trong mỗi SCC, chu trình nội bộ tốn đúng $|SCC|$ cạnh (mọi đỉnh cần bậc ra $\geq 1$ nên ít nhất $k$ cạnh tổng); nối các SCC theo thứ tự topo trong đồ thị ngưng tụ, rồi nối SCC cuối về SCC đầu (tồn tại vì liên thông vô hướng). Tổng cạnh đúng $k$.

Kết quả: bắt đầu bằng $n$, trừ 1 cho mỗi thành phần là DAG.

### Thuật toán

1. DFS duyệt cả cạnh xuôi và ngược để tìm thành phần liên thông vô hướng.
2. Với mỗi thành phần, kiểm tra đồ thị con (chỉ cạnh xuôi) có phải DAG bằng Kahn (sắp xếp topo).
3. Nếu DAG, đóng góp $k-1$ cạnh; ngược lại, đóng góp $k$ cạnh.

### Ví dụ minh họa

$n=4, m=5$, yêu cầu: $1\to2, 2\to3, 2\to4, 3\to1, 3\to4$.

Thành phần: $\{1,2,3,4\}$. Có chu trình $1\to2\to3\to1$, không phải DAG. Cần 4 cạnh.

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Flight%20Route%20Requests.cpp)
