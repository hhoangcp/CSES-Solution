# Grid Coloring II - Lời giải

**ID:** 3312 | **URL:** https://cses.fi/problemset/task/3312

## Đề bài

Bạn được cho một lưới $n \times m$ mà mỗi ô chứa một ký tự `A`, `B` hoặc `C`. Với mỗi ô, bạn phải thay đổi ký tự thành `A`, `B` hoặc `C` (khác ký tự cũ) sao cho không có hai ô kề nhau (4 hướng) cùng ký tự.

## Hướng tiếp cận

### Mỗi ô có đúng 2 lựa chọn → Biến nhị phân

Mỗi ô phải đổi sang ký tự khác ký tự hiện tại. Từ 3 ký tự, loại bỏ ký tự hiện tại, còn đúng 2 lựa chọn. Gọi chúng là **option 0** và **option 1**. Đặt biến nhị phân $x_{i,j}$: chọn option 0 ($x = \text{false}$) hoặc option 1 ($x = \text{true}$). Mọi phép gán biến tương ứng 1-1 với một cách tô màu.

### Ràng buộc kề nhau → Mệnh đề 2-SAT

Với mỗi cặp ô kề $(u, v)$, kiểm tra 4 tổ hợp lựa chọn. Nếu option $i$ của $u$ và option $k$ của $v$ cho cùng ký tự, tổ hợp bị cấm bởi mệnh đề: $\neg(u = i \land v = k)$, tức $(u \neq i) \lor (v \neq k)$. Đây là mệnh đề OR trên hai biến bị phủ định — đúng dạng 2-SAT.

Trong đồ thị suy luận, thêm hai cạnh: $u_i \to v_{\neg k}$ (nếu $u$ chọn $i$ thì $v$ không được chọn $k$) và $v_k \to u_{\neg i}$ (chiều ngược).

### Giải bằng Tarjan SCC

1. Tìm tất cả SCC bằng Tarjan.
2. Nếu biến $x$ và $\neg x$ cùng SCC $\to$ tồn tại đường suy luận $x \Rightarrow \neg x \Rightarrow x$, tức mâu thuẫn logic $\to$ vô nghiệm.
3. Ngược lại, gán theo thứ tự tô-pô: SCC có số thứ tự lớn hơn (được xử lý trước) quyết định giá trị. Vì $x$ và $\neg x$ khác SCC, và không có cạnh từ SCC($\neg x$) đến SCC($x$) khi SCC($x$) > SCC($\neg x$), phép gán này nhất quán.

## Ví dụ minh họa

Lưới:
```
AAAA
CCBB
ABCA
```

Ô $(1,1)$ là `A` (options: `B`, `C`), ô $(1,2)$ cũng `A` (options: `B`, `C`). Nếu cả hai cùng chọn `B` $\to$ cấm $\to$ thêm mệnh đề: chọn `B` ở $(1,1)$ thì $(1,2)$ phải chọn `C`, và ngược lại.

Kết quả sau giải 2-SAT:
```
BCBC
ABCA
CABC
```

## Độ phức tạp

- **Thời gian:** $O(nm)$ — $nm$ biến, $O(nm)$ mệnh đề, Tarjan tuyến tính
- **Bộ nhớ:** $O(nm)$

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Coloring%20II.cpp)
