# Raab Game I - Lời giải

**ID:** 3399 | **URL:** https://cses.fi/problemset/task/3399

## Phương pháp

### Tóm tắt bài toán

Hai người chơi mỗi người có lá bài $1, 2, \ldots, n$. Mỗi vòng, cả hai lật bài — lá lớn hơn được 1 điểm (bằng nhau = hòa). Cho điểm cuối $a$ và $b$, xây dựng một ván đấu hợp lệ, hoặc xác định không thể.

### Ý tưởng chính

Ván đấu hợp lệ tồn tại khi và chỉ khi:
1. $a + b \leq n$ (mỗi vòng nhiều nhất 1 người thắng, tổng thắng không vượt $n$).
2. Hoặc cả $a$ và $b$ đều dương, hoặc cả hai đều bằng 0. Nếu $a = 0$ và $b > 0$, sau khi hết các vòng hòa (cả hai chơi cùng lá), phần lá còn lại của hai người giống hệt nhau — không thể có người luôn thắng mà người kia không thắng lần nào.

**Cách xây dựng** (khi hợp lệ): Gọi $h = n - a - b$ (số vòng hòa). Chia thành 3 giai đoạn:
1. **Hòa** ($h$ vòng): Cả hai chơi lá $1, 2, \ldots, h$.
2. **Người 1 thắng** ($a$ vòng): Người 1 chơi lá cao nhất ($n{-}a{+}1$ đến $n$), người 2 chơi lá trung bình ($h{+}1$ đến $h{+}a$).
3. **Người 2 thắng** ($b$ vòng): Người 2 chơi lá cao nhất ($n{-}b{+}1$ đến $n$), người 1 chơi lá trung bình ($h{+}1$ đến $h{+}b$).

Mỗi cặp lá trong phần người 1 thắng lệch nhau đúng $b > 0$ (vì $A[i] - B[i] = n - a - h = b$), nên người 1 luôn thắng. Đối xứng, người 2 luôn thắng trong giai đoạn của họ. Vì $h + a + b = n$, mọi khoảng lá rời nhau và dùng đủ mỗi lá đúng 1 lần.

### Thuật toán

1. Nếu $(a = 0 \neq b)$ hoặc $(b = 0 \neq a)$ hoặc $(a + b > n)$: xuất `NO`.
2. Ngược lại, xuất `YES` và cấu trúc 3 giai đoạn trên.

### Ví dụ minh họa

Từ đề bài:
- $n=4, a=1, b=2$: $h=1$. Hòa: N1=1, N2=1. N1 thắng: N1=4, N2=2. N2 thắng: N1=2, N2=3 và N1=3, N2=4. N1: [1,4,2,3], N2: [1,2,3,4]. ✓
- $n=2, a=0, b=1$: $a=0$ nhưng $b>0$ → `NO`.
- $n=3, a=0, b=0$: toàn hòa → `YES`.
- $n=2, a=1, b=1$: $h=0$. Người 1 thắng: (2,1). Người 2 thắng: (1,2). Người 1: [2,1], Người 2: [1,2]. ✓
- $n=4, a=4, b=1$: $a+b=5>4$ → `NO`.

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Raab%20Game%20I.cpp)
