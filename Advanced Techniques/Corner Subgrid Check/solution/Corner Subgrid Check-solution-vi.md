# Corner Subgrid Check - Lời giải

**ID:** 3360 | **URL:** https://cses.fi/problemset/task/3360

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ gồm các chữ cái ($k$ chữ cái in hoa đầu tiên). Với mỗi chữ cái, xác định có tồn tại hay không một lưới con kích thước ít nhất $2 \times 2$ mà cả bốn góc đều có chữ cái đó.

### Ý tưởng chính

Một lưới con được xác định bởi hai hàng $(r_1, r_2)$ và hai cột $(c_1, c_2)$. Bốn góc tại $(r_1, c_1)$, $(r_1, c_2)$, $(r_2, c_1)$, $(r_2, c_2)$ đều phải có cùng chữ cái $c$. Điều này tương đương với: chữ cái $c$ xuất hiện tại cả hai cột $c_1$ và $c_2$ ở cả hai hàng $r_1$ và $r_2$ — hay nói cách khác, cùng một cặp cột $(c_1, c_2)$ xuất hiện ở ít nhất hai hàng khác nhau cho chữ cái $c$.

Chiều đảo cũng đúng: nếu tồn tại lưới con hợp lệ với bốn góc đều bằng $c$, thì có cặp cột xuất hiện ở hai hàng với chữ cái $c$. Vậy việc kiểm tra cặp cột lặp lại giữa các hàng là điều kiện cần và đủ. Nếu tìm được cặp lặp $(u, v)$ tại hai hàng $r_1 \neq r_2$, thì $u \neq v$ (hai cột khác nhau) và $r_1 \neq r_2$ (hai hàng khác nhau), đảm bảo lưới con có kích thước ít nhất $2 \times 2$.

Để phát hiện cặp cột lặp hiệu quả, ta dùng mảng `last[u][v]` kiểu byte, trong đó `last[u][v]` lưu chỉ số chữ cái cuối cùng đã đánh dấu cặp cột $(u, v)$ (khởi tạo bằng 26, một giá trị nằm ngoài $0 \ldots k-1$). Các chữ cái được xử lý lần lượt theo thứ tự tăng dần của $c$. Khi xử lý hàng $r$ cho chữ cái $c$ và tạo cặp $(u, v)$: nếu `last[u][v] == c`, cặp này đã thấy ở một hàng trước trong cùng lần xử lý chữ cái $c$ → YES; ngược lại, đặt `last[u][v] = c`. Vì các chữ cái trước đó chỉ ghi các giá trị strictly nhỏ hơn $c$, nên phép kiểm tra `== c` chỉ có thể đúng khi chính chữ cái $c$ đã đánh dấu cặp này trước đó trong lần xử lý hiện tại, do đó tất cả $k$ chữ cái có thể dùng chung mảng mà không xung đột.

### Thuật toán

1. Tiền xử lý: với mỗi chữ cái $c$ và mỗi hàng $r$, thu thập danh sách các cột chứa chữ cái $c$.
2. Với mỗi chữ cái $c$ từ 0 đến $k-1$:
   - Với mỗi hàng $r$ từ 0 đến $n-1$:
     - Với mỗi cặp cột $(u, v)$ từ danh sách cột của chữ cái $c$ trong hàng $r$:
       - Nếu `last[u][v] == c` → YES cho chữ cái $c$, chuyển sang chữ cái tiếp theo.
       - Ngược lại, đặt `last[u][v] = c`.
   - Nếu không tìm thấy cặp lặp → NO.

### Ví dụ minh họa

Lưới (chỉ số từ 0):
```
Hàng 0: A A A A
Hàng 1: C B B C
Hàng 2: C B B E
Hàng 3: A A A A
```

- **A:** Hàng 0 có A tại cột $\{0,1,2,3\}$, hàng 3 có A tại cột $\{0,1,2,3\}$. Cặp cột $(0,1)$ xuất hiện ở cả hai hàng → **YES**.
- **B:** Hàng 1 có B tại cột $\{1,2\}$, hàng 2 có B tại cột $\{1,2\}$. Cặp cột $(1,2)$ xuất hiện ở cả hai hàng → **YES**.
- **C:** Hàng 1 có C tại cột $\{0,3\}$, cặp $(0,3)$ được đánh dấu. Hàng 2 chỉ có C tại cột $\{0\}$, không tạo được cặp. Không có hàng thứ hai với cặp $(0,3)$ → **NO**.
- **D:** Không xuất hiện → **NO**.
- **E:** Chỉ xuất hiện tại (hàng 2, cột 3), một vị trí duy nhất không tạo cặp → **NO**.

Kết quả: `YES YES NO NO NO`

## Độ phức tạp

- **Thời gian:** $O(k \cdot n \cdot m^2)$ với $m$ là số lần xuất hiện tối đa của một chữ cái trong một hàng. Cơ chế dừng sớm khi tìm thấy YES giúp thời gian thực tế hiệu quả.
- **Không gian:** $O(n^2)$ — mảng `last` (byte, $\approx 9$MB) cộng với danh sách cột theo từng chữ cái/hàng lưu tổng cộng $\approx n^2$ phần tử int.

## Mã nguồn (C++)

[Mã nguồn](../code/Corner%20Subgrid%20Check.cpp)
