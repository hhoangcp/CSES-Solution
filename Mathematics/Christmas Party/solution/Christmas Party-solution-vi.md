# Christmas Party - Lời giải

**ID:** 1717 | **URL:** https://cses.fi/problemset/task/1717

## Phương pháp

### Tóm tắt bài toán

Có $n$ đứa trẻ dự tiệc Giáng sinh, mỗi người mang một món quà. Đếm số cách phân phối lại quà sao cho không ai nhận đúng quà của mình, kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

Đây là bài toán **hoán vị bất tương đẳng** (derangement): đếm số hoán vị $\sigma$ của $\{1, 2, \ldots, n\}$ sao cho $\sigma(i) \neq i$ với mọi $i$. Ký hiệu $D_n$.

**Hệ thức truy hồi.** Xét phần tử 1, phải đến một trong $n-1$ vị trí, giả sử vị trí $k$. Khi đó phần tử $k$ có hai khả năng:

- **Trường hợp A:** Phần tử $k$ đi đến vị trí 1. Cặp $(1, k)$ trao đổi khép kín, $n-2$ phần tử còn lại cần hoán vị bất tương đẳng: $D_{n-2}$ cách.
- **Trường hợp B:** Phần tử $k$ không đi đến vị trí 1. Khi đó $n-1$ phần tử còn lại cần hoán vị bất tương đẳng (phần tử $k$ bị cấm ở vị trí 1 thay vì vị trí của chính nó): $D_{n-1}$ cách.

Có $n-1$ cách chọn $k$ và hai trường hợp phân hoạch đầy đủ:

$$D_n = (n-1)(D_{n-1} + D_{n-2})$$

Cơ sở: $D_0 = 1$ (hoán vị rỗng), $D_1 = 0$.

**Công thức đóng (nguyên lý bao hàm-loại trừ):** $D_n = n! \sum_{i=0}^{n} \frac{(-1)^i}{i!}$. Hệ thức truy hồi đơn giản hơn cho tính toán $O(n)$.

### Thuật toán

1. Khởi tạo $D_0 = 1$, $D_1 = 0$.
2. Với $i = 2$ đến $n$: $D_i = (i-1)(D_{i-1} + D_{i-2}) \bmod (10^9+7)$.
3. Xuất $D_n$.

### Ví dụ minh họa

$n = 4$: $D_0 = 1$, $D_1 = 0$, $D_2 = 1 \cdot (0+1) = 1$, $D_3 = 2 \cdot (1+0) = 2$, $D_4 = 3 \cdot (2+1) = 9$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(1)$ — chỉ cần hai giá trị liền trước
