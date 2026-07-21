# Two Stacks Sorting - Lời giải

**ID:** 2402 | **URL:** https://cses.fi/problemset/task/2402

## Đề bài

Bạn được cho một danh sách đầu vào gồm $n$ số (hoán vị của $1 \ldots n$). Nhiệm vụ của bạn là tạo ra danh sách đầu ra đã sắp xếp bằng cách sử dụng hai ngăn xếp. Mỗi số được đẩy vào một ngăn xếp (chọn ngăn xếp 1 hoặc 2), rồi bật từ ngăn xếp đó theo thứ tự LIFO để tạo đầu ra. Gán mỗi số vào ngăn xếp 1 hoặc 2. Nếu không thể, xuất `IMPOSSIBLE`.

## Hướng tiếp cận

### Bước 1: Mô phỏng, xác định khoảng thời gian

Mô phỏng quá trình bắt buộc khi đầu ra phải là $1, 2, \ldots, n$. Xác định **khoảng thời gian sống** của mỗi phần tử: $In[i]$ là thời điểm đẩy vào, $Out[i]$ là thời điểm bật ra. Mỗi phần tử tạo khoảng $[In[i], Out[i]]$.

### Bước 2: Phân loại tương quan giữa các khoảng

Duyệt phần tử theo giá trị tăng dần ($y = 1 \to n$), so sánh với phần tử $x$ đã duyệt ($x < y$). Ba vị trí tương đối:

1. **Rời rạc:** Không mâu thuẫn, có thể cùng stack.
2. **Lồng nhau** ($In[y] < In[x] < Out[x] < Out[y]$): $x$ vào sau và ra trước $y$, hợp lệ với LIFO.
3. **Chồng lấn** ($In[x] < In[y] < Out[x] < Out[y]$): $y$ đè lên $x$ nhưng $x$ phải ra trước. Mâu thuẫn LIFO — $x$ và $y$ **bắt buộc khác stack**.

### Bước 3: Tối ưu phát hiện xung đột bằng set và BIT

Duy trì tập các phần tử đang hoạt động, sắp theo thời gian $In$.

**Set:** Dùng để tìm nhanh các khoảng có khả năng chồng lấn với $y$. Tìm phần tử đầu tiên có $In > In[y]$, lùi 1 bước — đó là phần tử duy nhất có thể chồng lấn trường hợp 3. Các phần tử phía sau đều là trường hợp 2 (lồng nhau). Vì $y$ bao trọn các phần tử này, $y$ sẽ thay gánh các mâu thuẫn về sau, nên ta xóa chúng khỏi set.

**BIT:** Kiểm tra có phần tử $z$ nào xen vào giữa khoảng giao nhau $[L, R]$ của $x$ và $y$ hay không:
- Trường hợp 3 (chồng lấn): $x, y$ đã phải khác stack. Nếu có $z$ xen giữa $\to$ cần 3 stack $\to$ `IMPOSSIBLE`.
- Trường hợp 2 (lồng nhau): Nếu có $z$ xen giữa, để nhường chỗ cho $z$, $x$ và $y$ **bắt buộc cùng stack**.

**Độ phức tạp khấu hao:** Mỗi phần tử chỉ bị lùi iterator tối đa 1 lần mỗi vòng ($n$ tổng) và chỉ bị tiến qua rồi xóa khỏi set đúng 1 lần ($n$ tổng). Nếu có $>1$ phần tử cùng chồng lấn với $y$, mâu thuẫn 3 stack đã bị BIT phát hiện từ trước.

### Bước 4: Mô hình 2-SAT bằng DSU

Mỗi phần tử $i$ có hai biến: $i$ (stack 1) và $i+n$ (stack 2). Ràng buộc được gộp bằng DSU:
- **Khác stack:** Gộp $x$ với $y+n$ và $y$ với $x+n$.
- **Cùng stack:** Gộp $x$ với $y$ và $x+n$ với $y+n$.

Nếu tồn tại $i$ mà $Find(i) = Find(i+n)$, tức $i$ vừa phải ở stack 1 vừa phải ở stack 2 $\to$ `IMPOSSIBLE`. Ngược lại, tô màu 2 phía trên DSU cho phép gán stack cho mọi phần tử.

### Ví dụ

$n = 5$, hoán vị: $[2, 3, 1, 5, 4]$.

Khoảng: $In[1]=3, Out[1]=4$; $In[2]=1, Out[2]=5$; $In[3]=2, Out[3]=6$; $In[4]=8, Out[4]=9$; $In[5]=7, Out[5]=10$.

Phần tử 2 và 3 chồng lấn ($In[2]=1 < In[3]=2 < Out[2]=5 < Out[3]=6$). Kết quả khả thi: 2, 4 vào stack 1; 1, 3, 5 vào stack 2.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — set $O(\log n)$ mỗi thao tác, BIT $O(\log n)$ mỗi truy vấn, khấu hao tuyến tính.
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Two%20Stacks%20Sorting.cpp)
