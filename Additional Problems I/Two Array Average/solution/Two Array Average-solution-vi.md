# Two Array Average - Lời giải

**ID:** 3361 | **URL:** https://cses.fi/problemset/task/3361

## Đề bài

Cho hai mảng $n$ số nguyên, chọn tiền tố không rỗng từ mỗi mảng sao cho trung bình tất cả số được chọn là lớn nhất.

## Hướng tiếp cận

### Chặt nhị phân trên kết quả

Trung bình khi chọn tiền tố $i$ từ $A$ và tiền tố $j$ từ $B$:

$$\frac{\text{prefA}[i] + \text{prefB}[j]}{i + j}$$

Kiểm tra trung bình max có $\geq x$ không:

$$\frac{\text{prefA}[i] + \text{prefB}[j]}{i + j} \geq x \iff (\text{prefA}[i] - xi) + (\text{prefB}[j] - xj) \geq 0$$

Với $x$ cố định, hai phần độc lập. Kiểm tra quy về:

$$\max_i(\text{prefA}[i] - xi) + \max_j(\text{prefB}[j] - xj) \geq 0$$

Hàm kiểm tra đơn điệu (nếu trung bình $\geq x$ đạt được thì $\geq x'$ với mọi $x' < x$ cũng đạt được), nên chặt nhị phân đúng. Chạy 80 lần lặp cho độ chính xác $10^{-6}$, theo dõi cặp $(i, j)$ tốt nhất.

### Ví dụ

$n = 4$, $A = [1, 5, 5, 2]$, $B = [3, 1, 3, 1]$.

$\text{prefA} = [1, 6, 11, 13]$, $\text{prefB} = [3, 4, 7, 8]$.

Tối ưu: tiền tố 3 từ $A$ và tiền tố 1 từ $B$: $\frac{11 + 3}{3 + 1} = 3.5$.

Kết quả: `3 1`.

## Độ phức tạp

- **Thời gian:** $O(n \cdot \text{số lần lặp})$ — với 80 lần lặp
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Two%20Array%20Average.cpp)
