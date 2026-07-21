# Robot Path - Lời giải

**ID:** 1742 | **URL:** https://cses.fi/problemset/task/1742

## Phương pháp

### Tóm tắt bài toán

Robot bắt đầu tại $(0,0)$, thực hiện $n$ lệnh di chuyển ngang/dọc. Robot dừng ngay khi quay lại điểm đã đi qua. Tính tổng khoảng cách đã di chuyển.

### Ý tưởng chính

Mỗi lệnh tạo thành một đoạn thẳng song song trục. Tự giao chỉ xảy ra giữa đoạn ngang và đoạn dọc (hoặc hai lệnh liên tiếp ngược chiều). Ta dùng cây phân đoạn lưu `set<long long>` tại mỗi nút để phát hiện giao đầu tiên qua hai lần duyệt.

**Lệnh ngược chiều:** Nếu hai lệnh liên tiếp ngược hướng (VD: U rồi D), robot quay lại ngay — xuất khoảng cách đến đó và dừng.

**Phát hiện giao bằng hai lần duyệt:** Lần 1 chèn đoạn ngang vào cây phân đoạn (trên tọa độ $x$ đã nén) và truy vấn mỗi đoạn dọc. Lần 2 chèn đoạn dọc (cây trên $y$ đã nén) và truy vấn mỗi đoạn ngang. Mỗi lần duyệt phát hiện một chiều giao.

**Cây phân đoạn với set:** Mỗi nút lưu `set` các giá trị. Chèn đoạn ngang tại cao độ $y$ trải $[x_1, x_2]$: thêm $y$ vào `set` tại mỗi nút bị bao phủ hoàn toàn. Truy vấn đoạn dọc tại $x$ trải $[y_1, y_2]$: duyệt gốc-lá tại vị trí $x$, dùng `upper_bound` / `lower_bound` tìm giá trị $y$ gần nhất trong $[y_1, y_2]$. `Query_min` tìm $y$ nhỏ nhất lớn hơn $y_1$ (giao từ dưới); `Query_max` tìm $y$ lớn nhất nhỏ hơn $y_1$ (giao từ trên). Giao gần đầu mút bắt đầu nhất mới quyết định robot đi bao xa trước khi dừng.

**Tìm lệnh va chạm đầu tiên:** Xử lý lệnh theo thứ tự. Mỗi lần duyệt, khi truy vấn tìm được giao, ghi nhận chỉ số lệnh và khoảng cách, dừng xử lý. Chỉ số lệnh nhỏ nhất qua hai lần duyệt cho va chạm đầu tiên. Các lệnh trước đó đóng góp toàn bộ độ dài; lệnh va chạm chỉ đóng góp khoảng cách đến điểm giao.

**Nén tọa độ:** Tọa độ có thể đạt $10^{11}$ ($10^5$ lệnh × $10^6$ mỗi lệnh), nên nén cả hai trục về chỉ số $[0, 2n]$.

### Thuật toán

1. Mô phỏng lộ trình, ghi mỗi đoạn. Kiểm tra lệnh ngược chiều.
2. Nén tọa độ $x$ và $y$.
3. **Lần 1:** Với mỗi lệnh theo thứ tự:
   - Ngang: chèn giá trị $y$ vào cây phân đoạn trên $[x_1, x_2]$.
   - Dọc: truy vấn đoạn ngang cắt qua gần nhất. Nếu tìm thấy, ghi nhận va chạm.
4. Xóa cây. **Lần 2:** Với mỗi lệnh theo thứ tự:
   - Dọc: chèn giá trị $x$ vào cây phân đoạn trên $[y_1, y_2]$.
   - Ngang: truy vấn đoạn dọc cắt qua gần nhất. Nếu tìm thấy, ghi nhận va chạm.
5. Tổng khoảng cách: toàn bộ độ dài cho lệnh trước va chạm, độ dài części cho lệnh va chạm.

### Ví dụ minh họa

5 lệnh: U2, R3, D1, L5, U2.

| # | Lệnh | Đoạn | Khoảng cách |
|---|------|------|-------------|
| 1 | U 2 | $(0,0)\to(0,2)$ | 2 |
| 2 | R 3 | $(0,2)\to(3,2)$ | 3 |
| 3 | D 1 | $(3,2)\to(3,1)$ | 1 |
| 4 | L 5 | $(3,1)\to(-2,1)$ | 3 (dừng tại $(0,1)$) |

Lệnh 4 (L5) là đoạn ngang tại $y=1$, trải $x \in [-2, 3]$. Nó cắt lệnh 1 (U2), đoạn dọc tại $x=0$, trải $y \in [0, 2]$. Giao tại $(0,1)$, cách đầu L5 là 3 đơn vị.

Tổng: $2 + 3 + 1 + 3 = 9$.

## Độ phức tạp

- **Thời gian:** $O(n \log^2 n)$
- **Không gian:** $O(n \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Robot%20Path.cpp)
