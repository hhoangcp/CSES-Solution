# Tasks and Deadlines - Lời giải

**ID:** 1630 | **URL:** https://cses.fi/problemset/task/1630

## Đề bài

Cho $n$ công việc, công việc thứ $i$ có thời lượng thực hiện $a_i$ và hạn chót $d_i$. Bạn phải thực hiện tất cả $n$ công việc theo một thứ tự nào đó (mỗi thời điểm chỉ xử lý một công việc), bắt đầu từ thời điểm $0$. Nếu hoàn thành công việc $i$ tại thời điểm $f_i$, phần thưởng thu được là $d_i - f_i$ (có thể âm). Tìm tổng phần thưởng lớn nhất.

## Hướng tiếp cận

### 1. Phân tích hàm mục tiêu

Giả sử các công việc được thực hiện theo thứ tự $\pi(1), \pi(2), \ldots, \pi(n)$. Thời điểm hoàn thành công việc ở vị trí thứ $k$ là:

$$f_{\pi(k)} = \sum_{j=1}^{k} a_{\pi(j)}$$

Tổng phần thưởng:

$$\sum_{k=1}^{n} (d_{\pi(k)} - f_{\pi(k)}) = \sum_{k=1}^{n} d_{\pi(k)} - \sum_{k=1}^{n} f_{\pi(k)}$$

Vì $\sum_{k=1}^{n} d_{\pi(k)} = \sum_{i=1}^{n} d_i$ là hằng số không phụ thuộc thứ tự, **tối đa hóa tổng phần thưởng tương đương với tối thiểu hóa tổng thời điểm hoàn thành** $\sum_{k=1}^{n} f_{\pi(k)}$.

### 2. Chiến lược tham lam: quy tắc SPT (Shortest Processing Time first)

Bài toán tối thiểu hóa tổng thời điểm hoàn thành (với chung thời điểm bắt đầu) có lời giải cổ điển: luôn làm công việc có thời lượng ngắn nhất trước. Đây là bài toán lập lịch $1 \| \| \sum C_j$, giải bằng cách sắp xếp các công việc theo thời lượng $a_i$ tăng dần.

### 3. Chứng minh bằng phương pháp đổi chỗ (exchange argument)

Giả sử một thứ tự tối ưu nhưng chưa tuân theo SPT. Khi đó tồn tại hai công việc liền kề mà công việc trước có thời lượng $a$ lớn hơn công việc sau có thời lượng $b$ ($a > b$). Gọi $T$ là thời điểm bắt đầu cặp này:

- **Thứ tự hiện tại $(a, b)$:** thời điểm hoàn thành là $T + a$ và $T + a + b$. Đóng góp vào tổng thời gian hoàn thành: $(T + a) + (T + a + b) = 2T + 2a + b$.
- **Nếu đổi chỗ thành $(b, a)$:** thời điểm hoàn thành là $T + b$ và $T + b + a$. Đóng góp: $(T + b) + (T + b + a) = 2T + a + 2b$.

Hiệu: $(2T + 2a + b) - (2T + a + 2b) = a - b > 0$, nên thứ tự $(b, a)$ cho tổng nhỏ hơn. Việc đổi chỗ không ảnh hưởng đến các công việc phía sau vì tổng thời gian xử lý của cặp vẫn là $a + b$ (thời điểm kết thúc cặp không đổi). Do đó ta luôn cải thiện được kết quả bằng cách đảo các cặp nghịch thế cho đến khi mảng được sắp xếp tăng dần theo thời lượng. Vậy SPT là tối ưu.

## Ví dụ minh họa

Xét $n = 3$ công việc với $(a_i, d_i)$ lần lượt là $(6, 10)$, $(8, 15)$, $(5, 12)$.

Sắp xếp theo thời lượng tăng dần: công việc 3 ($5, 12$), công việc 1 ($6, 10$), công việc 2 ($8, 15$).

- **Công việc 3:** hoàn thành tại $t = 5$, phần thưởng $= 12 - 5 = 7$.
- **Công việc 1:** hoàn thành tại $t = 5 + 6 = 11$, phần thưởng $= 10 - 11 = -1$.
- **Công việc 2:** hoàn thành tại $t = 11 + 8 = 19$, phần thưởng $= 15 - 19 = -4$.

Tổng phần thưởng tối đa: $7 + (-1) + (-4) = 2$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — chủ yếu do sắp xếp $n$ công việc; vòng lặp tính kết quả chỉ tốn $O(n)$.
- **Bộ nhớ:** $O(n)$ để lưu danh sách các cặp (thời lượng, hạn chót).
