# Shortest Subsequence - Lời giải

**ID:** 1087 | **URL:** https://cses.fi/problemset/task/1087

## Đề bài

Cho một chuỗi DNA gồm các ký tự `A`, `C`, `G`, `T`. Hãy tìm chuỗi DNA ngắn nhất **không** phải là dãy con của chuỗi đã cho. Một chuỗi $t$ được gọi là dãy con của $s$ nếu có thể thu được $t$ bằng cách xóa một số ký tự từ $s$.

## Hướng tiếp cận

### 1. Ý tưởng: Phủ đầy 4 ký tự (Complete Cover)

Ta duyệt chuỗi DNA từ trái sang phải và chia nó thành các đoạn sao cho mỗi đoạn chứa ít nhất một lần xuất hiện của cả 4 ký tự `A`, `C`, `G`, `T`.

- Mỗi khi thu thập đủ cả 4 ký tự, ta gọi đó là một **"phủ hoàn chỉnh"**.
- Sau khi kết thúc một phủ, ta bắt đầu đếm lại từ đầu cho phủ tiếp theo.

### 2. Xây dựng chuỗi thiếu

Giả sử ta tìm được $k$ phủ hoàn chỉnh.

- **Độ dài:** Mọi chuỗi có độ dài $\le k$ đều chắc chắn là dãy con của chuỗi ban đầu. Do đó, chuỗi ngắn nhất không phải dãy con phải có độ dài **$k + 1$**.
- **Cách chọn ký tự:**
  1. Với mỗi phủ hoàn chỉnh, ta lấy ký tự **cuối cùng** (ký tự giúp hoàn thành bộ 4 chữ cái của phủ đó) để đưa vào chuỗi kết quả.
  2. Sau khi đi hết các phủ hoàn chỉnh, ta sẽ còn lại một đoạn cuối cùng không đủ 4 ký tự. Ta chọn một ký tự **còn thiếu** trong đoạn này để thêm vào cuối chuỗi kết quả.

### 3. Chứng minh tính đúng đắn

- **Tại sao chuỗi độ dài $k$ luôn là dãy con?** Vì mỗi phủ chứa đủ 4 ký tự, nên với bất kỳ ký tự nào trong chuỗi độ dài $k$, ta luôn có thể tìm thấy nó trong phủ tương ứng.
- **Tại sao chuỗi độ dài $k+1$ ta vừa tạo không là dãy con?** Bằng cách chọn ký tự cuối cùng của mỗi phủ, ta đã "ép" việc tìm kiếm phải đi qua hết một phủ mới tìm được ký tự tiếp theo. Sau $k$ phủ, ta chọn một ký tự không hề xuất hiện ở phần còn lại của chuỗi, khiến việc tìm kiếm thất bại.

## Ví dụ minh họa

Chuỗi: `ACGTACGT`, $n=8$.

1. **Phủ 1:** `A`, `C`, `G`, `T` (hoàn thành tại vị trí 4 với ký tự `T`).
2. **Phủ 2:** `A`, `C`, `G`, `T` (hoàn thành tại vị trí 8 với ký tự `T`).
3. **Đoạn dư:** Sau vị trí 8 là rỗng, thiếu cả 4 ký tự. Ta chọn `A`.

- **Kết quả:** `TTA` (hoặc `AAA`, `CCG`,... tùy vào ký tự thiếu bạn chọn).

## Độ phức tạp

- **Thời gian:** $O(n)$ — Chỉ cần một lần duyệt chuỗi duy nhất.
- **Bộ nhớ:** $O(n)$ — Để lưu trữ chuỗi DNA đầu vào.

## Mã nguồn (C++)

[Mã nguồn](../code/Shortest%20Subsequence.cpp)
