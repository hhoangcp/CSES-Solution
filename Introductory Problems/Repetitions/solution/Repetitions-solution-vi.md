# Repetitions - Lời giải

**ID:** 1069 | **URL:** https://cses.fi/problemset/task/1069

## Đề bài

Cho chuỗi DNA độ dài $n$ ($1 \le n \le 10^6$) gồm các ký tự A, C, G, T. Tìm độ dài chuỗi con dài nhất gồm các ký tự giống nhau liên tiếp.

## Hướng tiếp cận

### Nhận xét quan trọng

Bài toán yêu cầu tìm đoạn liên tiếp dài nhất gồm ký tự giống nhau (run). Đây là bài toán cơ bản về xử lý xâu, có thể giải trực tiếp bằng quét tuyến tính.

### Ý tưởng: Quét tuyến tính với bộ đếm chạy

Duyệt qua chuỗi, duy trì hai biến:
- `len`: độ dài chuỗi liên tiếp hiện tại (chứa ký tự giống nhau đang xét).
- `res`: đáp án -- độ dài lớn nhất tìm được.

Khi ký tự hiện tại khác ký tự tiếp theo (hoặc là ký tự cuối cùng), chuỗi liên tiếp kết thúc -- cập nhật `res = max(res, len)` và đặt lại `len = 0`.

### Thuật toán chi tiết

1. Khởi tạo `res = 0` và `len = 0`.
2. Duyệt qua chuỗi từ vị trí 1 đến $n$:
   - Tăng `len` lên 1.
   - Nếu `i == n` hoặc `S[i] != S[i+1]`: chuỗi hiện tại kết thúc tại vị trí $i$:
     - Cập nhật `res = max(res, len)`.
     - Đặt lại `len = 0`.
3. In `res`.

### Chứng minh tính đúng

Ta chứng minh rằng sau khi xử lý vị trí $i$, biến `res` lưu đúng độ dài chuỗi liên tiếp dài nhất trong tiền tố $S[1..i]$.

**Quy nạp theo $i$:**

- **Cơ sở ($i = 1$):** Nếu $n = 1$, `len = 1`, `S[1]` là ký tự cuối $\to$ `res = 1`. Đúng vì chuỗi chỉ có 1 ký tự.
- **Bước quy nạp:** Giả sử đúng đến vị trí $i-1$. Xét vị trí $i$:
  - Nếu `S[i] == S[i+1]` (cùng chuỗi liên tiếp): `len` tăng nhưng không cập nhật `res`. Các chuỗi liên tiếp trong $S[1..i]$ không kết thúc tại $i$, nên `res` vẫn đúng.
  - Nếu `S[i] != S[i+1]` hoặc $i = n$ (chuỗi liên tiếp kết thúc tại $i$): `len` chính xác là độ dài chuỗi liên tiếp kết thúc tại $i$. Cập nhật `res = max(res, len)` đảm bảo `res` $\geq$ độ dài chuỗi mới này, và `res` không giảm. Do đó `res` là tối đa trên tất cả chuỗi trong $S[1..i]$.

### Tại sao không cần xử lý đặc biệt sau vòng lặp

Cách code so sánh `S[i]` với `S[i+1]` (nhìn trước) thay vì `S[i-1]` (nhìn lại). Khi phát hiện `S[i] != S[i+1]` hoặc `i == n`, ta biết chuỗi hiện tại kết thúc tại vị trí $i$ và cập nhật ngay. Do đó, chuỗi liên tiếp cuối cùng cũng được xử lý trong vòng lặp, không cần xử lý thêm.

### Chứng minh tối ưu

**Cận dưới:** Phải đọc mọi ký tự ít nhất một lần để xác định nó tiếp tục hay kết thúc chuỗi liên tiếp. Nếu bỏ qua bất kỳ ký tự nào, ta không thể biết chuỗi liên tiếp có kéo dài qua vị trí đó hay không. Do đó, cận dưới là $\Omega(n)$.

**Cận trên:** Thuật toán duyệt qua chuỗi đúng 1 lần, mỗi bước $O(1)$, tổng $O(n)$.

Vậy thuật toán là tối ưu: $\Theta(n)$.

### Ví dụ minh họa

S = "ATTCGGGA":

| i | S[i] | S[i+1] | len | Hành động | res |
|---|------|--------|-----|-----------|-----|
| 1 | A | T | 1 | Khác $\to$ cập nhật, len=0 | 1 |
| 2 | T | T | 1 | Giống $\to$ tiếp tục | 1 |
| 3 | T | C | 2 | Khác $\to$ cập nhật, len=0 | 2 |
| 4 | C | G | 1 | Khác $\to$ cập nhật, len=0 | 2 |
| 5 | G | G | 1 | Giống $\to$ tiếp tục | 2 |
| 6 | G | G | 2 | Giống $\to$ tiếp tục | 2 |
| 7 | G | A | 3 | Khác $\to$ cập nhật, len=0 | 3 |
| 8 | A | (hết) | 1 | Cuối $\to$ cập nhật, len=0 | 3 |

Kết quả: 3 (chuỗi "GGG")

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Bộ nhớ:** $O(n)$ cho mảng xâu (có thể tối ưu xuống $O(1)$ nếu đọc từng ký tự)

## Mã nguồn (C++)

[Mã nguồn](../code/Repetitions.cpp)
