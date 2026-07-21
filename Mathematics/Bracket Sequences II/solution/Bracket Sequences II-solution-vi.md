# Bracket Sequences II - Lời giải

**ID:** 2187 | **URL:** https://cses.fi/problemset/task/2187

## Phương pháp

### Tóm tắt bài toán

Cho độ dài $n$ và một tiền tố gồm các ngoặc mở `(` và đóng `)`. Đếm số cách hoàn thành dãy ngoặc hợp lệ có độ dài đúng $n$ bắt đầu bằng tiền tố đó, kết quả lấy modulo $10^9+7$.

### Ý tưởng chính

**Bước 1: Phân tích tiền tố.** Gọi tiền tố có độ dài $L$. Tính **độ cân bằng** $k$ (số ngoặc mở trừ số ngoặc đóng) bằng cách duyệt tiền tố. Nếu tại bất kỳ thời điểm nào $k < 0$, tiền tố không hợp lệ và đáp án bằng $0$. Nếu $n$ lẻ, đáp án bằng $0$.

**Bước 2: Quy về bài toán đếm.** Sau tiền tố, còn $m = n - L$ vị trí cần điền với độ cân bằng hiện tại là $k$. Cần bổ sung $a$ ngoặc mở và $b$ ngoặc đóng:

$$a = \frac{m - k}{2}, \quad b = \frac{m + k}{2}$$

Nếu $m - k$ lẻ hoặc $a < 0$ hoặc $b < 0$, đáp án bằng $0$.

**Bước 3: Công thức Ballot tổng quát.** Bài toán quy về đếm đường đi lưới từ $(0, k)$ đến $(m, 0)$ bằng các bước $+1$ (mở) và $-1$ (đóng), không bao giờ chạm $y < 0$. Theo nguyên lý phản xạ André:

$$f(m, k) = \binom{m}{a} - \binom{m}{a-1} = \frac{k+1}{m+1}\binom{m+1}{a}$$

*Chứng minh.* Số đường đi tự do từ $(0, k)$ đến $(m, 0)$ là $\binom{m}{a}$. Với mỗi đường đi vi phạm (chạm $y = -1$), tìm vị trí chạm đầu tiên rồi phản xạ phần còn lại (đổi mở $\leftrightarrow$ đóng). Đường phản xạ đi đến $(m, -2)$ với $a-1$ bước lên, tức có $\binom{m}{a-1}$ đường. Phản xạ là song ánh, nên $f(m,k) = \binom{m}{a} - \binom{m}{a-1}$.

**Bước 4: Tính truy hồi.** Thay vì tính trực tiếp công thức Ballot, dùng hệ thức truy hồi. Gọi $C[i]$ là đáp án khi cần thêm $i$ ngoặc mở, với độ cân bằng hiện tại $k$:

$$C[i] = C[i-1] \cdot \frac{(2i+k-1)(2i+k)}{i \cdot (i+k+1)}$$

suy ra từ tỷ số liên tiếp của công thức Ballot. Cơ sở: $C[0] = 1$.

### Thuật toán

1. Duyệt tiền tố: tính độ cân bằng $k$. Nếu $k < 0$ tại bất kỳ thời điểm, xuất $0$.
2. Nếu $n$ lẻ, xuất $0$.
3. Tính $m = n - L$, $a = (m-k)/2$. Nếu không khả thi, xuất $0$.
4. Tính nghịch đảo modulo tới $a + k + 1$.
5. Tính $C[0], C[1], \ldots, C[a]$ bằng hệ thức truy hồi. Xuất $C[a]$.

### Ví dụ minh họa

$n = 6$, tiền tố `(()`. $L = 3$, $k = 1$. $m = 3$, $a = 1$.

$$C[1] = C[0] \cdot \frac{(2+1-1)(2+1)}{1 \cdot (1+1+1)} = \frac{2 \cdot 3}{3} = 2$$

2 cách hoàn thành: `(())()` và `(()())`.

## Độ phức tạp

- **Thời gian:** $O(n)$ — duyệt tiền tố + tính truy hồi
- **Bộ nhớ:** $O(n)$
