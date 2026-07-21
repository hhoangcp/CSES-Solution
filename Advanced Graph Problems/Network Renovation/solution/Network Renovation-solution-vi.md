# Network Renovation - Lời giải

**ID:** 1704 | **URL:** https://cses.fi/problemset/task/1704

## Phương pháp

### Tóm tắt bài toán

Cho cây $n$ đỉnh, thêm số cạnh tối thiểu sao cho đồ thị vẫn liên thông sau khi loại bất kỳ cạnh nào (làm đồ thị 2-liên thông cạnh).

### Ý tưởng chính

Trong cây, mọi cạnh đều là cầu. Để loại bỏ mọi cầu, ta thêm cạnh tạo chu trình bao phủ tất cả cầu. Thu thập lá theo thứ tự DFS, ghép lá $i$ với lá $i + \lceil L/2 \rceil$: vì DFS thăm lá từng cây con liên tiếp, offset $L/2$ luôn vượt ranh giới cây con gốc, nên hai lá trong mỗi cặp thuộc cây con khác nhau, tạo chu trình đi qua gốc bảo vệ mọi cầu trên cả hai đường gốc-lá. Mỗi cạnh mới bảo vệ tối đa 2 cầu lá, nên $\lceil L/2 \rceil$ cạnh vừa đủ (cận dưới) vừa đủ dùng (cận trên).

### Thuật toán

1. DFS từ gốc bất kỳ, thu lá (đỉnh bậc 1, trừ gốc) theo thứ tự thăm vào danh sách `Leaf`.
2. Nếu $L$ lẻ, thêm `Leaf[0]` vào cuối.
3. Xuất $L/2$ cạnh: ghép `Leaf[i]` với `Leaf[i + L/2]`, $0 \le i < L/2$.

### Ví dụ minh họa

Cây: 1-2, 1-3, 3-4, 3-5. Lá theo DFS: [2, 4, 5]. $L=3$ (lẻ) → [2, 4, 5, 2]. Ghép: (2, 5), (4, 2). Kết quả: 2 cạnh.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Network%20Renovation.cpp)
