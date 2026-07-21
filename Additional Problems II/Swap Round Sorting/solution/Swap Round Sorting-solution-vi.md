# Swap Round Sorting - Lời giải

**ID:** 1698 | **URL:** https://cses.fi/problemset/task/1698

## Hướng tiếp cận

### Bước 1: Phân tích chu trình

Phân tích hoán vị thành các chu trình rời rạc. Bắt đầu từ đỉnh $i$, đi theo $i \to a_i \to a_{a_i} \to \ldots$ cho đến khi quay lại $i$. Chu trình dài 1 đã đúng vị trí, chu trình dài 2 cần 1 lần đổi, chu trình dài $c \geq 3$ cần tối đa 2 vòng.

### Bước 2: Vòng 1 — Đảo ngược chu trình

Với mỗi chu trình $S = [v_0, v_1, \ldots, v_{m-1}]$ (với $a[v_k] = v_{k+1}$, $v_m = v_0$), hoán đổi các cặp đối xứng: `swap(a[v_l], a[v_r])` với $l < r$ và $l + r = m - 1$. Mỗi phần tử xuất hiện nhiều nhất 1 lần nên các đổi không chồng lấn, thực hiện trong 1 vòng.

**Tính chất đối xứng sau vòng 1 ($a[i]=j \Leftrightarrow a[j]=i$):** Vị trí $v_l$ sau hoán đổi nhận giá trị cũ của $a[v_r]$, tức $v_{r+1} = v_{m-l}$. Vị trí $v_{m-l}$ hoán đổi với $v_{l-1}$, nhận giá trị cũ của $a[v_{l-1}] = v_l$. Vậy $a[v_l] = v_{m-l}$ và $a[v_{m-l}] = v_l$. Chu trình dài đã biến thành các chu trình độ dài 2 (hoặc 1 nếu đúng vị trí).

### Bước 3: Vòng 2 — Đưa về đúng vị trí

Sau vòng 1, mảng chỉ còn các cặp lỗi đối xứng: $a[i] = j$ và $a[j] = i$. Duyệt qua mảng, nếu $a[i] < i$, hoán đổi vị trí $a[i]$ và $i$. Đổi này đưa cả hai phần tử về đúng vị trí cùng lúc. Vì $a[a[i]] = i$ (đối xứng), vị trí $a[i]$ đã đúng sau khi đổi, không tham gia đổi khác $\Rightarrow$ các đổi không chồng lấn, thực hiện trong 1 vòng.

### Số vòng tối thiểu

- Mảng đã sắp: 0 vòng.
- Mọi chu trình dài $\leq 2$: 1 vòng.
- Tồn tại chu trình dài $\geq 3$: cần ít nhất 2 vòng (một phần tử cần ít nhất 2 lần đổi để về đúng vị trí, mỗi vòng chỉ cho 1 lần đổi), thuật toán dùng đúng 2 vòng.

### Ví dụ

$n = 5$, hoán vị: $[5, 2, 1, 3, 4]$. Chu trình: $(1, 5, 4, 3)$.

- **Vòng 1:** Đổi vị trí $1 \leftrightarrow 3$ và $5 \leftrightarrow 4$. Mảng thành: $[1, 2, 5, 4, 3]$. Bây giờ $a[3]=5$ và $a[5]=3$ (đối xứng).
- **Vòng 2:** Thấy $a[5]=3 < 5$, đổi vị trí $3 \leftrightarrow 5$. Mảng thành: $[1, 2, 3, 4, 5]$.

Kết quả: 2 vòng.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Swap%20Round%20Sorting.cpp)
