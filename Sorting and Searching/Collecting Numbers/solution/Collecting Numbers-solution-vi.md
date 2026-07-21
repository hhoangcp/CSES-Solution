# Collecting Numbers - Lời giải

**ID:** 2216 | **URL:** https://cses.fi/problemset/task/2216

## Phương pháp

### Tóm tắt bài toán

Cho mảng gồm $n$ số nguyên, mỗi số từ $1$ đến $n$ xuất hiện đúng một lần. Trong mỗi vòng, duyệt mảng từ trái sang phải và thu thập các số theo thứ tự tăng dần từ $1$. Tìm số vòng tối thiểu để thu thập hết tất cả các số.

### Ý tưởng chính

Gọi $\text{pos}[v]$ là vị trí của giá trị $v$ trong mảng. Trong một vòng duyệt, các số thu thập được phải có vị trí tăng dần (vì ta quét từ trái sang phải và nhặt theo thứ tự tăng). Do đó, nếu $\text{pos}[i] < \text{pos}[i-1]$, tức số $i$ nằm trước $i-1$ trên mảng, thì khi duyệt ta gặp $i$ trước khi có $i-1$ — không thể nhặt $i$ trong cùng vòng với $i-1$, buộc phải bắt đầu vòng mới. Ngược lại, nếu $\text{pos}[i] > \text{pos}[i-1]$, ta luôn nhặt được $i$ ngay sau $i-1$ trong cùng một vòng. Mỗi đoạn liên tiếp có vị trí tăng dần chính xác gom được vào một vòng, nên số vòng bằng đúng số lần vị trí giảm cộng thêm 1.

Công thức: $\text{Round} = 1 + \sum_{i=2}^{n} [\text{pos}[i] < \text{pos}[i-1]]$.

### Thuật toán

1. Quét mảng, lưu $\text{pos}[v]$ cho mỗi giá trị $v$.
2. Khởi tạo $\text{Round} = 1$.
3. Với $i$ từ $2$ đến $n$: nếu $\text{pos}[i] < \text{pos}[i-1]$, tăng $\text{Round}$ lên 1.

### Ví dụ minh họa

Mảng $[4, 2, 1, 5, 3]$.

| $v$ | 1 | 2 | 3 | 4 | 5 |
|-----|---|---|---|---|---|
| $\text{pos}[v]$ | 3 | 2 | 5 | 1 | 4 |

| $i$ | $\text{pos}[i]$ | $\text{pos}[i-1]$ | $\text{pos}[i] < \text{pos}[i-1]$? | Vòng |
|-----|------------------|--------------------|-------------------------------------|------|
| 2 | 2 | 3 | Có | +1 |
| 3 | 5 | 2 | Không | |
| 4 | 1 | 5 | Có | +1 |
| 5 | 4 | 1 | Không | |

Kết quả: $1 + 2 = \mathbf{3}$ vòng. Thực tế: vòng 1 nhặt $\{1\}$, vòng 2 nhặt $\{2, 3\}$, vòng 3 nhặt $\{4, 5\}$.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Collecting%20Numbers.cpp)
