# Grid Path Construction - Lời giải

**ID:** 2418 | **URL:** https://cses.fi/problemset/task/2418

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho lưới $R \times C$ và hai ô $A = (sr, sc)$, $B = (er, ec)$, xây dựng đường đi Hamilton từ $A$ đến $B$ (đi qua mỗi ô đúng một lần), hoặc kết luận không tồn tại.

### Kiểm tra khả thi (`feasible`)

Hàm `feasible` xác định sự tồn tại đường đi Hamilton trong $O(1)$ bằng các điều kiện cần và đủ. Itai et al. [1] đã chứng minh các điều kiện này đặc trưng hoàn toàn sự tồn tại đường đi Hamilton trong đồ thị lưới chữ nhật.

**Quy tắc parity (tô màu bàn cờ).** Tô ô $(r, c)$ màu trắng nếu $(r+c) \bmod 2 = 0$, đen nếu lẻ. Đường đi phải xen kẽ màu, nên:

- **$RC$ chẵn:** Hai màu có số ô bằng nhau. Đường đi Hamilton cần $A$ và $B$ **khác** màu.
- **$RC$ lẻ:** Ô trắng nhiều hơn ô đen đúng 1. Đường đi Hamilton cần cả $A$ và $B$ đều **trắng** (màu đa số).

**Các cấu hình hình học bị cấm** (giả sử $R \le C$ sau khi hoán đổi):

- **$R = 1$:** Đường đi chỉ là đường thẳng, nên $A$ và $B$ phải ở hai đầu mút (cột 1 hoặc cột $C$). Nếu $A$ ở cột giữa, hai nửa lưới bị chia cắt và không thể đi qua tất cả các ô trong một đường thẳng duy nhất.
- **$R = 2$, cùng cột, không phải biên:** Nếu $sc = ec$ và $1 < sc < C$, thì $A$ và $B$ tạo "vách ngăn" chia lưới thành hai vùng độc lập — đường đi đi qua $A$ đến $B$ không thể bao phủ cả hai vùng cùng lúc.
- **$R = 3$, $C$ chẵn, $sc \ne ec$:** Gọi $A_L = (lr, lc)$ là endpoint có cột nhỏ hơn. Nếu $A_L$ màu đen và ($A_L$ ở hàng giữa **hoặc** hai endpoint không nằm ở cột kề nhau, tức $lc + 1 < rc$), thì đường đi bị kẹt ở "góc chết". Cụ thể: khi $A_L$ ở hàng 2 (giữa), đường đi bắt đầu từ giữa bị buộc rẽ lên hoặc xuống, tạo một ô cô lập ở góc mà không thể quay lại thăm. Khi $A_L$ ở hàng 1 hoặc 3 nhưng hai endpoint ở cột không kề nhau ($lc + 1 < rc$), đường đi không thể quay lại phủ kín vùng bên trái trước khi đến $B$ — các ô ở góc bên trái bị bỏ lại.

Ngoài ra, nếu $A = B$ (cùng ô), hiển nhiên không tồn tại đường đi Hamilton (code kiểm tra `sr == er && sc == ec`).

Các điều kiện này vừa cần vừa đủ: khi `feasible` trả về true, đường đi Hamilton luôn xây dựng được.

### Chuẩn hóa hình học

Thuật toán dùng bốn phép biến đổi để quy về dạng chuẩn, giảm số trường hợp cần xử lý:

- **`rotate` (xoay 90° CW):** Ánh xạ $(r, c) \to (c, R{+}1{-}r)$, đổi $R \leftrightarrow C$, và đổi ký tự hướng theo chiều kim đồng hồ: up→right→down→left→up (tức old\_up thành new\_right, old\_right thành new\_down, v.v.).
- **`transpose` (đổi hàng/cột):** Ánh xạ $(r, c) \to (c, r)$, đổi up↔left, down↔right.
- **`flip_horizontal` (lật gương dọc):** Đổi $sc \to C{+}1{-}sc$, đổi left↔right.
- **`flip_vertical` (lật gương ngang):** Đổi $sr \to R{+}1{-}sr$, đổi up↔down.

Mỗi phép biến đổi chỉ thay đổi tọa độ và ký tự hướng, không làm thay đổi cấu trúc đường đi. Khi xây xong, dùng ký tự hướng đã biến đổi để thu được đáp án đúng. Nhờ chuẩn hóa ($R \le C$, $sc \le ec$), mọi trường hợp đối xứng được xử lý bằng một đoạn code duy nhất.

### Cấu trúc chia để trị (`build`)

**Ý tưởng trung tâm:** Chia nhỏ lưới thành các phần nhỏ hơn. Khi gọt được 2 hàng biên thì đệ quy dễ dàng; khi không (do endpoint quá sát biên), ta chia đôi theo cột. Chìa khóa là: **nếu `feasible` đúng thì ít nhất một trong hai chiến lược luôn thành công** (trừ đúng một trường hợp đặc biệt $4 \times 5$).

Hàm `build` thử các chiến lược theo thứ tự ưu tiên:

1. **Strip + Splice** (thử 4 phép xoay).
2. **Chuẩn hóa** (transpose để $R \le C$, flip để $sc \le ec$) rồi kiểm tra **base case** ($1 \times C$, $2 \times C$ nhỏ, $3 \times 3$).
3. **Split** (chia 2 cột từ bên trái).
4. **`solve_4x5`** (phương án dự phòng).

**Chiến lược 1 — Gọt biên và ghép nối (Strip + Splice).** Thử 4 phép xoay. Nếu tìm được hướng sao cho cả $A$ và $B$ đều cách mép trên ít nhất 2 hàng (tức $sr \ge 3$ và $er \ge 3$ sau xoay) **và** lưới lõi $(R{-}2) \times C$ cũng feasible (code kiểm tra `feasible(rows-2, cols, sr-2, sc, er-2, ec)`), thì gọt 2 hàng từ trên cùng và giải đệ quy lưới lõi. Sau đó `splice` mở rộng đường đi lõi để phủ kín dải 2 hàng đã gọt:

1. Duyệt dọc đường đi lõi, tìm **bước ngang đầu tiên** trên hàng 3 (biên giới giữa lõi và dải đã gọt) — tức hai ô liên tiếp trên đường đi đều nằm ở hàng 3, di chuyển từ cột $c$ sang $c'$. Code dùng cờ `spliced` để chèn đúng một lần.
2. Thay bước ngang đó bằng một "vòng vèo": đi lên 1 ô vào dải 2 hàng → duyệt Hamilton path phủ kín dải 2 hàng → đi xuống 1 ô trở lại hàng 3. Cụ thể, thay bước ngang $(3,c) \to (3,c')$ bằng: `up + build(2, C, 2, c, 2, c') + down`, tức $(3,c) \to (2,c) \to \cdots \to (2,c') \to (3,c')$.
3. **Tại sao luôn tìm được bước ngang?** Vì $C \ge 2$ (các trường hợp $C = 1$ đã là base case), đường đi Hamilton trong lõi phải thăm tất cả $C$ ô trên hàng biên. Dù đường đi có thể thăm hàng biên thành nhiều đoạn (k đoạn → $C - k$ bước ngang), luôn có ít nhất 1 bước ngang vì $C \ge 2$.
4. **Tại sao chèn luôn thành công?** Lưới 2 hàng có tính chất quan trọng: giữa hai ô bất kỳ (thỏa feasible) luôn tồn tại đường đi Hamilton. Ở điểm chèn, start và end cùng hàng 2, cột kề nhau ($c$ và $c'$), nên luôn feasible — đường đi 2 hàng có dạng zíc-zác đơn giản (đi hết một hướng, xuống, đi hết hướng ngược lại).

**Chiến lược 2 — Chia đôi (Split).** Nếu gọt biên thất bại (một trong $A, B$ quá sát mọi cạnh sau mọi phép xoay), chuẩn hóa về $R \le C$ và $sc \le ec$, rồi thử cắt 2 cột từ bên trái. Tìm hàng nối `cut_r` trong số $\{1, 2, R{-}1, R\}$ sao cho cả hai nửa đều khả thi:

$$\texttt{feasible}(R, 2, sr, sc, cut\_r, 2) \wedge \texttt{feasible}(R, C{-}2, cut\_r, 1, er, ec{-}2)$$

Nếu tìm được, giải đệ quy cả hai nửa và nối bằng một bước `R`.

**Tại sao split luôn tìm được `cut_r`?** Khi strip thất bại, ít nhất một endpoint nằm ở 2 hàng đầu hoặc 2 hàng cuối (sau mọi phép xoay). Sau chuẩn hóa ($R \le C$, $sc \le ec$), endpoint đó nằm sát biên. Lưới $R \times 2$ bên trái nhỏ nên ít forbidden configuration. Ta thử 4 hàng nối ứng với 4 góc của lưới $R \times 2$; trong số đó, ít nhất một hàng nối hoạt động vì: (i) các ô ở góc/biên thường feasible trong lưới nhỏ, và (ii) khi một hàng nối thất bại, endpoint ở gần hàng nối đó sẽ "dịch chuyển" feasible sang hàng nối khác — tổng thể không thể tất cả 4 đều thất bại nếu bài toán ban đầu feasible.

**Phương án dự phòng — `solve_4x5`.** Code bỏ qua split khi `rows == 4 && cols == 5 && !(sc <= 2 && ec >= 4)`, tức lưới $4 \times 5$ và hai endpoint không "vắt ngang" ranh giới chia đôi (cả hai cùng ở nửa trái hoặc cùng ở nửa phải). Lý do:

- **Strip thất bại:** Lưới $4 \times 5$ chỉ có 4 hàng. Sau bất kỳ phép xoay nào, ít nhất một endpoint luôn ở hàng 1–2 hoặc hàng 3–4 (không cách cả hai biên $\ge 2$ hàng).
- **Split thất bại:** Cả $A$ và $B$ ở cột 1–2, lưới con $4 \times 2$ bên trái phải chứa cả hai endpoint. Nhưng $4 \times 2$ chỉ có 8 ô và nhiều cấu hình trong đó không feasible (ví dụ cùng cột ở giữa).
- **$4 \times 5$ là lưới nhỏ nhất** mà cả hai chiến lược thất bại đồng thời. Các lưới lớn hơn luôn có đủ không gian để strip hoặc split hoạt động.

Trường hợp này được xử lý bằng hai cách:
- **$A$ ở nửa trên, $B$ ở nửa dưới** ($sr \le 2$, $er \ge 3$): chia ngang thành $2 \times C$ và $(R{-}2) \times C$, nối tại cột 4 hoặc 5 bằng bước `dn`.
- **Cả hai cùng ở nửa trên** (code lật gương để đưa $B$ từ nửa dưới lên nếu cần): dùng đường đi cố định 19 bước, được thiết kế riêng cho cấu hình $4 \times 5$ khi cả hai endpoint cùng ở hàng 1–2.

### Các trường hợp cơ sở

- **$1 \times C$:** Đường thẳng `string(C-1, 'R')`. Chỉ khả thi khi $A$ và $B$ ở hai đầu mút.
- **`solve_2xC` ($C \le 3$):** Xây đường đi cho lưới 2 hàng. Chiến lược chung: ánh xạ vị trí lên chỉ số tuyến tính quanh chu vi 2 hàng, chọn hướng đi phù hợp, rồi duyệt zíc-zác (hàng trên hết sang phải, xuống, hàng dưới hết sang trái). Với $C = 3$ và hai endpoint ở góc đối diện (ví dụ $(1,1)$ và $(2,3)$), cần đường đi đặc biệt `DRURD` thay vì chữ U đơn giản — chữ U thông thường sẽ đến $B$ quá sớm trước khi thăm hết các ô.
- **`solve_3x3`:** Có 10 cặp $(A, B)$ khả thi (5 ô trắng chọn 2). Sau khi xét 4 phép xoay, chỉ còn 5 dạng phân biệt: start ở góc $(1,1)$ với end lần lượt ở $(2,2)$, $(1,3)$, $(3,1)$, $(3,3)$; hoặc start ở tâm $(2,2)$, end ở $(1,1)$. Mỗi dạng có đường đi cố định 8 bước. Ví dụ: $A = (2,2)$, $B = (1,1)$ → code trả về `URDDLLUU`: $(2,2) \to (1,2) \to (1,3) \to (2,3) \to (3,3) \to (3,2) \to (3,1) \to (2,1) \to (1,1)$. Lưu ý: do hàm `build` thử xoay trước khi gọi `solve_3x3`, ký tự hướng trong kết quả có thể khác với UDLR mặc định — bản chất đường đi là như nhau, chỉ khác thứ tự thăm.

### Ví dụ minh họa

**Ví dụ 1 (base case):** Lưới $2 \times 3$, $A = (1,1)$, $B = (2,3)$.

- `feasible`: $R = 2$, $C = 3$, tổng 6 chẵn. $(1,1)$ trắng, $(2,3)$ đen → khác màu ✓. Không cấu hình bị cấm → feasible.
- `solve_2xC` nhận diện góc đối diện, trả về `DRURD`.
- Truy vết: $(1,1) \xrightarrow{D} (2,1) \xrightarrow{R} (2,2) \xrightarrow{U} (1,2) \xrightarrow{R} (1,3) \xrightarrow{D} (2,3)$. Đủ 6 ô ✓.

**Ví dụ 2 (chia để trị):** Lưới $4 \times 7$, $A = (1,3)$, $B = (3,6)$.

- `feasible(4, 7, 1, 3, 3, 6)`: diện tích 28 chẵn, $(1,3)$ trắng, $(3,6)$ đen → khác màu ✓. Không cấu hình bị cấm → feasible.
- `build` thử strip với 4 phép xoay. Xoay 90° được lưới $7 \times 4$, lúc này $A' = (3,4)$, $B' = (6,2)$ — cả hai đều cách biên trên $\ge 2$ hàng → strip thành công.
- Gọt 2 hàng từ trên, giải đệ quy lõi $5 \times 4$. Lõi tiếp tục được strip/split cho đến khi chạm base case.
- `splice` tìm bước ngang trên hàng biên trong đường đi lõi, chèn đường đi 2 hàng phủ kín dải đã gọt.
- Kết quả: đường đi 27 bước thăm đủ 28 ô.

**Ví dụ 3 (không khả thi):** Lưới $1 \times 3$, $A = (1,2)$, $B = (1,3)$.

$A$ không ở đầu mút (cột 2), nên `feasible` trả về false → `NO`.

## Độ phức tạp

- **Thời gian:** $O(RC \cdot \max(R, C))$ mỗi test case.
  - Mỗi lần gọi `feasible` mất $O(1)$.
  - Pha gọt biên thử 4 phép xoay mỗi lần gọi ($O(1)$). Hàm `splice` duyệt toàn bộ chuỗi đường đi lõi (độ dài $O(RC)$) để tìm điểm chèn và xây kết quả.
  - Pha chia đôi thử 4 hàng nối (ứng với 4 góc), mỗi hàng kiểm tra `feasible` trong $O(1)$. Nối hai chuỗi con mất $O(RC)$.
  - Mỗi lần gọt giảm 2 hàng; mỗi lần chia giảm 2 cột. Sâu đệ quy $O(\max(R, C))$.
  - Ở mỗi mức, thao tác chuỗi mất $O(RC)$, tổng cộng $O(RC \cdot \max(R, C))$.
- **Bộ nhớ:** $O(RC)$ cho chuỗi kết quả và $O(\max(R, C))$ độ sâu đệ quy.

## Tài liệu tham khảo

- [1] A. Itai, C. H. Papadimitriou, J. L. Szwarcfiter. [Hamilton Paths in Grid Graphs](https://www.ibr.cs.tu-bs.de/courses/ws2223/ag/papers/Ch8/1982-Itai_GridGraphs.pdf). *SIAM Journal on Computing*, 11(4):676–686, 1982. — Chứng minh điều kiện cần và đủ cho đường đi Hamilton trong đồ thị lưới.

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Path%20Construction.cpp)
