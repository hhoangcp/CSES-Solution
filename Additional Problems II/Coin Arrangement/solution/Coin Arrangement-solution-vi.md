# Coin Arrangement - Lời giải

**ID:** 2180 | **URL:** https://cses.fi/problemset/task/2180

## Tóm tắt bài toán
Lưới $2 \times n$ có số xu mỗi ô tùy ý, tổng $2n$ đồng. Mỗi ô phải có đúng 1 đồng. Mỗi bước di chuyển 1 đồng 1 ô (trái, phải, lên, xuống). Tìm tổng số bước tối thiểu.

## Hướng tiếp cận

Xử lý tham lam từng cột từ trái sang phải. Tại mỗi cột thực hiện hai bước, mỗi bước đều là bắt buộc và tối ưu:

1. **Cân bằng dọc trước (tối ưu vì giảm chi phí ngang):** Nếu ô trên thừa và ô dưới thiếu (hoặc ngược lại), chuyển trực tiếp dọc tại chỗ. Bất kỳ phương án nào chuyển ngang rồi mới dọc/chéo đều tốn chi phí $\geq$ chuyển dọc trực tiếp $(1,i) \to (2,i)$, vì mỗi bước ngang thêm vào là thừa. Cân bằng dọc trước giảm số đồng thực tế phải chuyển ngang, từ đó giảm tổng chi phí toàn cục.

2. **Đẩy phần dư sang phải (bắt buộc vì không còn chỗ nhận trong cột):** Sau cân bằng dọc, phần dư/thiếu còn lại bắt buộc phải chuyển sang cột kế. Vì tổng xu đúng $2n$, mọi đồng thừa bên trái cột $i$ phải đi qua $i$ để sang phải, và ngược lại cho phần thiếu. Chi phí ngang là 1 bước/ô, nên chuyển ngay sang cột kế không bao giờ làm tăng tổng chi phí. Cột cuối tự động đúng nhờ tổng $2n$.

$\Rightarrow$ Mỗi bước đều bắt buộc, không có hành động thừa, nên tổng chi phí là tối thiểu.

## Thuật toán
Với mỗi cột $i$ từ 1 đến $n$:
1. **Cân bằng dọc:** Nếu $a[i] < 1$ và $b[i] > 1$: chuyển $\Delta = \min(1-a[i], b[i]-1)$ từ dưới lên trên, cộng $\Delta$ vào đáp án. Nếu $a[i] > 1$ và $b[i] < 1$: chuyển $\Delta = \min(a[i]-1, 1-b[i])$ từ trên xuống dưới, cộng $\Delta$ vào đáp án.
2. **Chi phí ngang:** Cộng $|a[i]-1| + |b[i]-1|$ vào đáp án.
3. **Cập nhật cột kế:** $a[i+1] \mathrel{+}= (a[i]-1)$, $b[i+1] \mathrel{+}= (b[i]-1)$.

## Ví dụ minh họa
$n = 4$, trên $[0,1,0,1]$, dưới $[2,0,1,3]$.
- **Cột 1:** Dưới (2) chuyển 1 lên Trên (0). Chi phí +1. Cột 1: `[1,1]`.
- **Cột 2:** Trên 1, Dưới 0. Dưới thiếu 1, chuyển sang cột 3. Chi phí +1.
- **Cột 3:** Trên 0, Dưới 0 (đã cho cột 2). Cả hai thiếu 2 xu, lấy từ cột 4. Chi phí +2.
- **Cột 4:** Dưới còn 2, Trên 0. Chuyển 1 từ dưới lên. Chi phí +1.
- **Tổng:** $1 + 1 + 2 + 1 = 5$.

## Lưu ý cài đặt
- Dùng `long long` vì số xu có thể tích lũy lớn.
- Thứ tự: cân bằng dọc trước, mới tính dư chuyển sang phải.

## Độ phức tạp
- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Coin%20Arrangement.cpp)
