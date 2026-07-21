# Removing Digits II - Lời giải

**ID:** 2174 | **URL:** https://cses.fi/problemset/task/2174

## Đề bài

Cho số nguyên $n$ (lên đến $10^{18}$), mỗi bước trừ đi một chữ số xuất hiện trong biểu diễn thập phân. Tìm số bước tối thiểu để về 0.

## Hướng tiếp cận

### Chia để trị theo khối chữ số + Ghi nhớ

Với $n \le 10^{18}$, không thể trừ từng bước. Phân tích số thành chữ số đầu $d$ và hậu tố $s$, xử lý đệ quy hai pha với ghi nhớ.

**Trạng thái:** `(upper_max, number)` — `upper_max` là chữ số lớn nhất từ các hàng cao hơn (bên ngoài khối đang xét), `number` là khối số hiện tại. Hai số có cùng `upper_max` và cùng `number` có cùng tập bước tiếp theo — trạng thái đủ thông tin.

### Hàm `compute(upper_max, number)` → `{steps, remainder}`

- **`steps`**: số bước để khối `number` bị trừ đến khi cần mượn từ hàng cao hơn.
- **`remainder`**: giá trị còn lại sau khi mượn (âm, sẽ trừ vào hàng cao hơn).

### Đệ quy hai pha

Tách `number` thành $d$ (chữ số đầu) và $s$ (hậu tố). Ví dụ: $27 \Rightarrow d = 2, s = 7$.

**Pha 1 (hậu tố):** Gọi `compute(max(upper_max, d), s)`. Xử lý hậu tố với ngữ cảnh chữ số lớn nhất bao gồm cả $d$. Đếm số bước để hậu tố bị trừ đến mức cần mượn từ $d$.

**Pha 2 (cập nhật + tiếp tục):** Cập nhật `new_number = d * power + remainder`. Lúc này $d$ đã giảm (do mượn), gọi `compute(upper_max, new_number)` để xử lý phần còn lại.

**Tại sao đúng:** Mỗi bước trừ chỉ ảnh hưởng hậu tố cho đến khi mượn xảy ra. Khi mượn, chữ số đầu giảm và hậu tố thay đổi hoàn toàn. Tách xử lý thành 2 pha — trước khi mượn (chỉ ảnh hưởng hậu tố) và sau khi mượn (cập nhật toàn bộ) — không bỏ sót hay đếm lặp.

**Cơ sở:** Khi `number < 10`, trả về `{1, number - max(upper_max, number)}` (1 bước trừ chữ số lớn nhất, phần dư có thể âm nếu cần mượn).

## Thuật toán

1. Định nghĩa `compute({upper_max, number})`:
   - Nếu `number < 10`: cơ sở.
   - Tách $d$, $s$. Pha 1: `compute({max(upper_max, d), s})`. Pha 2: `compute({upper_max, d*power + remainder})`.
   - Trả về tổng bước và phần dư cuối.
2. Đáp án = `compute({0, n}).first`.

## Ví dụ minh họa: $n = 27$

| Gọi | Pha 1 | delta | Pha 2 | Kết quả |
|:---|:---|:---|:---|:---|
| `compute({0, 27})` | `compute({2, 7})` → `{1, 0}` | 1 | `compute({0, 20})` → `{4, 0}` | `{5, 0}` |
| `compute({0, 20})` | `compute({2, 0})` → `{1, -2}` | 1 | `compute({0, 18})` → `{3, 0}` | `{4, 0}` |
| `compute({0, 18})` | `compute({1, 8})` → `{1, 0}` | 1 | `compute({0, 10})` → `{2, 0}` | `{3, 0}` |
| `compute({0, 10})` | `compute({1, 0})` → `{1, -1}` | 1 | `compute({0, 9})` → `{1, 0}` | `{2, 0}` |
| `compute({0, 9})` | cơ sở → `{1, 0}` | — | — | `{1, 0}` |

Tổng: 5 bước. Đường đi: $27 \to 20 \to 18 \to 10 \to 9 \to 0$.

## Độ phức tạp

- **Số trạng thái:** $O(\log n)$ — `upper_max` chỉ nhận giá trị 0 hoặc các chữ số của $n$ (tối đa 10 giá trị). Với mỗi `upper_max` cố định, tại mỗi tầng $10^k$:
  - Có 1 giá trị gốc (hậu tố ban đầu của $n$).
  - Khi mượn xảy ra, `new_number = d \cdot 10^k + remainder` với `remainder ∈ [-9, 0]`. Phần hậu tố (độ dài $k$) có dạng $\underbrace{99\ldots9}_{k-1}x$ (nếu $k \ge 2$) hoặc chỉ $x$ (nếu $k = 1$), với $x$ phụ thuộc `remainder`. Số biến thể hậu tố do mượn tại mỗi tầng ≤ 10.
  - Có $O(\log n)$ tầng, mỗi tầng ≤ 11 giá trị `number` → tổng `number` khác nhau = $O(\log n)$.
  - Tổng trạng thái $\le 10 \times O(\log n) = O(\log n)$.
- **Chi phí mỗi trạng thái:** $O(\log n)$ — vòng lặp `while` tìm `power` và các phép chia/lấy dư.
- **Thời gian:** $O(\log^2 n)$
- **Bộ nhớ:** $O(\log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Removing%20Digits%20II.cpp)
