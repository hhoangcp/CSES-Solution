# Stick Lengths - Lời giải

**ID:** 1074 | **URL:** https://cses.fi/problemset/task/1074

## Hướng tiếp cận

### Tóm tắt đề bài

Có $n$ que gỗ với các chiều dài $a_1, a_2, \ldots, a_n$. Kéo dài hay cắt ngắn một que đi $x$ đơn vị thì tốn chi phí $x$. Cần chọn một chiều dài mục tiêu chung $t$ sao cho tổng chi phí sửa đổi là nhỏ nhất.

### Ý tưởng cốt lõi

Khi chọn chiều dài mục tiêu $t$, tổng chi phí là
$$f(t) = \sum_{i=1}^{n} |a_i - t|.$$
Giá trị $t$ tối thiểu hóa tổng các độ lệch tuyệt đối chính là **trung vị** của các chiều dài. Chứng minh: sắp xếp mảng theo thứ tự không giảm $a_1 \le a_2 \le \cdots \le a_n$. Giữa các điểm dữ liệu, $f$ là tuyến tính và có độ dốc bằng số que có chiều dài $\le t$ trừ số que $> t$:
$$f'(t) = |\{i : a_i \le t\}| - |\{i : a_i > t\}| = 2\cdot|\{i : a_i \le t\}| - n.$$
Độ dốc này khởi đầu bằng $-n$ khi $t$ nằm dưới mọi que và tăng thêm $2$ mỗi khi $t$ vượt qua một que, cuối cùng đạt $+n$ khi nằm trên mọi que. Vì độ dốc không giảm, $f$ là hàm lồi và đạt cực tiểu nơi độ dốc vừa đủ $0$:
- **$n$ lẻ:** độ dốc nhảy từ $-1$ sang $+1$ tại phần tử chính giữa $a_{(n+1)/2}$, đây là điểm tối ưu duy nhất.
- **$n$ chẵn:** độ dốc bằng $0$ trên cả đoạn $[a_{n/2}, a_{n/2+1}]$, nên mọi giá trị trong đoạn này đều tối ưu; chọn $a_{n/2}$ là tiện lợi.

Trong cả hai trường hợp, phần tử ở vị trí $\lfloor (n+1)/2 \rfloor$ của mảng đã sắp xếp (đánh chỉ số từ $1$) là một trung vị hợp lệ.

### Thuật toán

1. Sắp xếp các chiều dài theo thứ tự không giảm.
2. Lấy $t = a_{\lfloor (n+1)/2 \rfloor}$ làm chiều dài mục tiêu chung (trung vị).
3. Đưa ra $\sum_{i=1}^{n} |a_i - t|$.

### Ví dụ minh họa

Ví dụ của đề bài là $n = 5$ với $a = [2, 3, 1, 5, 2]$.

1. Sắp xếp: $[1, 2, 2, 3, 5]$.
2. Trung vị (vị trí $\lfloor 6/2 \rfloor = 3$): $t = 2$.
3. Chi phí: $|1-2| + |2-2| + |2-2| + |3-2| + |5-2| = 1 + 0 + 0 + 1 + 3 = 5$.

Đáp án: $5$, khớp với kết quả mong đợi.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — chủ yếu do bước sắp xếp; phép quét chỉ tốn $O(n)$.
- **Bộ nhớ:** $O(n)$ — lưu mảng các chiều dài.
