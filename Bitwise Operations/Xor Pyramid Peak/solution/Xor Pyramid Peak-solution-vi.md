# Xor Pyramid Peak - Lời giải

**ID:** 2419 | **URL:** https://cses.fi/problemset/task/2419

## Phương pháp

### Tóm tắt bài toán

Cho kim tự tháp XOR với hàng đáy $a_0, a_1, \ldots, a_{n-1}$ (mỗi phần tử là XOR của hai phần tử bên dưới), tìm phần tử trên cùng (đỉnh).

### Ý tưởng chính

Kim tự tháp XOR có cấu trúc tương tự tam giác Pascal. Đỉnh bằng $\bigoplus_{i:\ \binom{n-1}{i}\ \text{lẻ}} a_i$. Cả **định lý Lucas** và **định lý Kummer** đều đặc tả hệ số tổ hợp nào là số lẻ, dẫn đến hai cách cài đặt.

### Phần chung: Hệ số tổ hợp trong kim tự tháp XOR

Phần tử thứ $i$ của hàng thứ $k$ từ đáy là $b_k[i] = \bigoplus_{j=0}^{k} a_{i+j} \cdot [\binom{k}{j} \bmod 2 = 1]$. Đỉnh (hàng $n-1$, phần tử duy nhất) là:

$$\text{đỉnh} = \bigoplus_{i:\ \binom{n-1}{i}\ \text{lẻ}} a_i$$

### Phương pháp 1: Định lý Lucas

**Định lý Lucas** trên GF(2): $\binom{m}{k} \bmod 2 = 1$ khi và chỉ khi $k$ là **mặt con** của $m$ ($k \subseteq m$, tức mọi bit 1 của $k$ đều nằm trong $m$). Chứng minh: viết $m = \sum m_i 2^i$, $k = \sum k_i 2^i$; khi đó $\binom{m}{k} \equiv \prod_i \binom{m_i}{k_i} \pmod{2}$. Mỗi thừa số bằng 0 khi $k_i=1, m_i=0$, nên tích bằng 1 iff $k_i \le m_i$ với mọi $i$, tức $k \subseteq m$.

**Cài đặt:** Với mỗi $i$, kiểm tra $(i \wedge (n{-}1)) = i$. Nếu đúng, XOR $a_i$ vào kết quả. Thời gian $O(n)$, bộ nhớ phụ $O(1)$.

### Phương pháp 2: Định lý Kummer

**Định lý Kummer:** Lũy thừa lớn nhất của số nguyên tố $p$ chia $\binom{n}{k}$ bằng số lần nhớ khi cộng $k$ và $n{-}k$ trong hệ cơ số $p$. Với $p = 2$, $\binom{n}{k}$ lẻ iff không có nhớ khi cộng $k$ và $n{-}k$ trong nhị phân.

**Cài đặt:** Tiền tính `bit[i]` sao cho `bit[n-1] - bit[i] - bit[n-1-i]` cho số lần nhớ khi cộng $i$ và $(n{-}1){-}i$. Nếu bằng 0, $\binom{n-1}{i}$ lẻ và ta XOR $a_i$ vào kết quả.

Công thức tiền tính: `power[h] = power[h/2] + 1` với $h$ là lũy thừa 2, và `bit[i] = bit[i-1] + power[lowbit(i)]`. Thời gian $O(n)$, bộ nhớ $O(n)$.

### Ví dụ minh họa

Đầu vào: $n = 8$, hàng đáy $[2, 10, 5, 12, 9, 5, 1, 5]$.

$n - 1 = 7 = 111_2$. Vì $7$ có tất cả bit đặt, mọi $i \le 7$ đều là mặt con của $7$. Vậy tất cả $\binom{7}{i}$ đều lẻ.

$$\text{đỉnh} = 2 \oplus 10 \oplus 5 \oplus 12 \oplus 9 \oplus 5 \oplus 1 \oplus 5 = 9$$

Để đối chiếu, nếu $n = 6$ ($n{-}1 = 5 = 101_2$): mặt con của 5 là $\{0, 1, 4, 5\}$, nên chỉ $a_0, a_1, a_4, a_5$ đóng góp vào đỉnh.

## Độ phức tạp

| Phương pháp | Thời gian | Bộ nhớ |
|---|---|---|
| Lucas | $O(n)$ | $O(1)$ |
| Kummer | $O(n)$ | $O(n)$ |

## Mã nguồn (C++)

- [Phương pháp Lucas](../code/Xor%20Pyramid%20Peak%20-%20Lucas.cpp) — kiểm tra mặt con bằng AND bit
- [Phương pháp Kummer](../code/Xor%20Pyramid%20Peak%20-%20Kummer.cpp) — kiểm tra nhớ bằng mảng `bit[]` tiền tính
