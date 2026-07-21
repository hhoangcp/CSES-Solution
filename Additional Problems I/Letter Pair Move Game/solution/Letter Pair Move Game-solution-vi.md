# Letter Pair Move Game - Lời giải

**ID:** 2427 | **URL:** https://cses.fi/problemset/task/2427

## Đề bài

Có $2n$ hộp xếp thành hàng, trong đó có $2$ ô trống kề nhau (ký hiệu là `..`) và $2n-2$ hộp chứa chữ cái 'A' hoặc 'B' (mỗi loại $n-1$ hộp). Mỗi lượt, bạn chọn một cặp chữ cái kề nhau và di chuyển chúng vào vị trí trống hiện tại mà không thay đổi thứ tự của cặp đó. Mục tiêu là đưa tất cả chữ 'A' đứng trước tất cả chữ 'B' trong tối đa $1000$ lượt.

## Hướng tiếp cận

### 1. Kiểm tra trạng thái đích

Trạng thái được coi là hoàn thành khi mọi chữ cái 'A' đều nằm bên trái mọi chữ cái 'B'. Vị trí của hai ô trống có thể ở bất kỳ đâu trong mảng.

### 2. Chiến lược tham lam (Greedy)

Thuật toán tìm kiếm các cặp chữ cái để di chuyển vào vị trí trống dựa trên các quy tắc ưu tiên nhằm dồn 'A' về bên trái và 'B' về bên phải:

- **Ưu tiên 1:** Tìm cặp `BA` hoặc `BB` nằm ở bên **trái** ô trống. Di chuyển chúng vào ô trống giúp đẩy các ký tự 'B' về phía sau.
- **Ưu tiên 2:** Tìm cặp `AB` hoặc `AA` nằm ở bên **phải** ô trống. Di chuyển chúng vào ô trống giúp kéo các ký tự 'A' về phía trước.
- **Xử lý bế tắc:** Nếu không tìm thấy các cặp trên, ta tìm một cặp `BA` ở bên phải ô trống, di chuyển nó vào ô trống để làm thay đổi cấu trúc mảng, sau đó tiếp tục tìm kiếm lại từ đầu.

### 3. Chứng minh tính đúng đắn và Điều kiện bất khả thi

- **Bất biến về tính chẵn lẻ:** Gọi $P$ là số lượng chữ 'A' nằm bên trái ô trống. Khi di chuyển một cặp chữ cái kề nhau:
  - Nếu di chuyển cặp `AA`, $P$ thay đổi $2$ đơn vị (tăng hoặc giảm).
  - Nếu di chuyển cặp `BB`, $P$ không đổi.
  - Nếu di chuyển cặp `AB` hoặc `BA`, $P$ không đổi.
  
  Do đó, **độ chẵn lẻ của $P$ là không đổi** trong suốt quá trình di chuyển. Nếu trạng thái ban đầu có $P \not\equiv n-1 \pmod 2$, bài toán có thể không có lời giải.

- **Tiến độ giải thuật:** Mỗi bước di chuyển hợp lệ được thiết kế để giảm số lượng cặp nghịch thế `BA` hoặc đưa mảng dần về trạng thái hội tụ. Số lượt di chuyển thực tế thường rất nhỏ, không quá $5n$, nằm trong giới hạn $1000$ của đề bài.

## Ví dụ mô phỏng

Mảng: `AB..BA`, $n=3$.

1. **Bước 1:** Ô trống ở vị trí 3-4. Tìm bên phải thấy cặp `BA` (vị trí 5-6). Di chuyển `BA` vào 3-4.
   - Kết quả: `ABBA..`
2. **Bước 2:** Ô trống ở vị trí 5-6. Tìm bên trái thấy cặp `BB` (vị trí 3-4). Di chuyển `BB` vào 5-6.
   - Kết quả: `A..ABB`
3. **Kiểm tra:** Các chữ 'A' đứng trước 'B'. Hoàn thành trong 2 bước.

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — Vòng lặp tối đa $5n$ lần, mỗi lần quét mảng $2n$ để tìm cặp di chuyển.
- **Bộ nhớ:** $O(n)$ — Lưu trữ trạng thái mảng và các bước di chuyển.

## Mã nguồn (C++)

[Mã nguồn](../code/Letter%20Pair%20Move%20Game.cpp)
