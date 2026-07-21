# Permutations - Lời giải

**ID:** 1070 | **URL:** https://cses.fi/problemset/task/1070

## Phương pháp

### Tóm tắt bài toán

Xây dựng hoán vị của $\{1, 2, \ldots, n\}$ ($1 \le n \le 10^6$) sao cho $|p_i - p_{i+1}| \neq 1$ với mọi cặp liên tiếp. Nếu không thể, in "NO SOLUTION".

### Ý tưởng chính

Hai số lẻ liên tiếp hơn kém nhau đúng 2, tương tự hai số chẵn liên tiếp. Bằng cách gom tất cả số lẻ và tất cả số chẵn lại với nhau, không có hiệu 1 nào xuất hiện *trong* mỗi nhóm. Chỉ cần kiểm tra ranh giới giữa hai nhóm.

**Cấu trúc:** In tất cả số lẻ theo thứ tự giảm dần, sau đó tất cả số chẵn theo thứ tự giảm dần.

*Tính đúng đắn với $n \ge 4$:*
- Trong phần lẻ: hai số lẻ liên tiếp hơn kém nhau đúng 2. $\checkmark$
- Trong phần chẵn: hai số chẵn liên tiếp hơn kém nhau đúng 2. $\checkmark$
- Tại ranh giới: số lẻ cuối cùng luôn là 1. Nếu $n$ chẵn, số chẵn đầu tiên là $n$, cho $|1 - n| = n - 1 \ge 3$. Nếu $n$ lẻ, số chẵn đầu tiên là $n - 1$, cho $|1 - (n-1)| = n - 2 \ge 3$. $\checkmark$

*Không có lời giải khi $n = 2, 3$:* Với $n = 2$, cả hai hoán vị đều có hiệu liên tiếp bằng 1. Với $n = 3$, số 2 phải đứng ở đâu đó — dù ở giữa hay ở đầu/cuối, ít nhất một hàng xóm hơn/kém 2 đúng 1.

### Thuật toán

- Nếu $n = 1$: xuất `1`.
- Nếu $n = 2$ hoặc $n = 3$: xuất `NO SOLUTION`.
- Nếu $n \ge 4$: xuất số lẻ từ lớn nhất xuống 1, rồi số chẵn từ lớn nhất xuống 2.

### Ví dụ minh họa

Từ đề bài:
- $n = 5$: xuất `5 3 1 4 2`. Kiểm tra: $|5-3|=2$, $|3-1|=2$, $|1-4|=3$, $|4-2|=2$. Tất cả $\neq 1$. $\checkmark$
- $n = 3$: `NO SOLUTION`.

## Độ phức tắt

- **Thời gian:** $O(n)$
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Permutations.cpp)
