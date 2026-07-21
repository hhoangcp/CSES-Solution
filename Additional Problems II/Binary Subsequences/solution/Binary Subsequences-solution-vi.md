# Binary Subsequences - Lời giải

**ID:** 2430 | **URL:** https://cses.fi/problemset/task/2430

## Đề bài

Tìm chuỗi bit ngắn nhất chứa đúng $n$ dãy con phân biệt không rỗng.

## Hướng tiếp cận

### Đếm dãy con

Gọi $a$ = số dãy con khác nhau kết thúc bằng `0`, $b$ = kết thúc bằng `1`. Tổng dãy con không rỗng $= a + b$.

Thêm ký tự vào cuối:
- **`0`:** mọi dãy con hiện có nối thêm `0`, cộng thêm `0` đơn lẻ. Trạng thái mới: $(a, b) \to (a + b + 1, b)$.
- **`1`:** tương tự, $(a, b) \to (a, a + b + 1)$.

### Thuật toán Euclid ngược

Để khôi phục xâu từ đích $n = a + b$, đảo ngược quá trình từ trạng thái $(a, b)$:

- Nếu $a \geq b$: phát `0`, đặt $a \leftarrow a - (b + 1)$.
- Nếu $a < b$: phát `1`, đặt $b \leftarrow b - (a + 1)$.

Mỗi bước giảm $a + b$ ít nhất một nửa (giống thuật toán Euclid), nên chạy trong $O(\log n)$ bước. Quá trình hợp lệ khi và chỉ khi đạt $(0, 0)$ (mỗi cách chia cho đúng 1 quá trình ngược, và mọi xâu nhị phân có $n$ dãy con tương ứng đúng 1 cách chia).

### Thử mọi cách chia

Không biết cách chia $a + b = n$ nào cho xâu ngắn nhất, nên thử mọi $a$ từ $0$ đến $\lfloor n/2 \rfloor$ (đối xứng: đổi $a \leftrightarrow b$ tương ứng đổi `0` $\leftrightarrow$ `1`). Với mỗi cách, mô phỏng quá trình ngược; chọn xâu hợp lệ ngắn nhất.

### Ví dụ

$n = 6$, thử $a = 2, b = 4$:

1. $(2, 4)$: $a < b$, phát `1`, $b = 4 - 3 = 1$ → $(2, 1)$
2. $(2, 1)$: $a \geq b$, phát `0`, $a = 2 - 2 = 0$ → $(0, 1)$
3. $(0, 1)$: $a < b$, phát `1`, $b = 1 - 1 = 0$ → $(0, 0)$ ✓

Xâu (đọc ngược): `101`. Độ dài 3.

Các cách chia khác: $a = 0, b = 6$ cho `111111` (độ dài 6); $a = 1, b = 5$ cho $a = -1$ (không hợp lệ).

Kết quả: `101`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — $O(n)$ cách chia, mỗi cách $O(\log n)$ bước
- **Bộ nhớ:** $O(\log n)$ — lưu xâu kết quả

## Mã nguồn (C++)

[Mã nguồn](../code/Binary%20Subsequences.cpp)
