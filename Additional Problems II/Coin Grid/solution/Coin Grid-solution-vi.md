# Coin Grid - Lời giải

**ID:** 1709 | **URL:** https://cses.fi/problemset/task/1709

## Đề bài

Cho lưới $n \times n$ có xu ở một số ô. Xóa tất cả xu bằng ít thao tác nhất, mỗi thao tác xóa toàn bộ xu trong một hàng hoặc cột. Xuất số thao tác tối thiểu và dãy thao tác.

## Hướng tiếp cận

### Mô hình hóa: Bao phủ đỉnh tối thiểu trên đồ thị hai phía

Xây đồ thị hai phía $G = (L \cup R, E)$: đỉnh trái $L$ đại diện $n$ hàng, đỉnh phải $R$ đại diện $n$ cột, xu tại $(i,j)$ tạo cạnh hàng $i$ -- cột $j$. Chọn một hàng hoặc cột tương đương chọn một đỉnh để "bao phủ" mọi cạnh kề nó. Bài toán trở thành tìm **bao phủ đỉnh tối thiểu (Minimum Vertex Cover)** trên đồ thị hai phía.

### Định lý König: MVC = Khớp tối đa

Theo **định lý König**, trong đồ thị hai phía, kích thước bao phủ đỉnh tối thiểu bằng kích thước khớp tối đa.

Từ khớp tối đa $M$, xây MVC như sau: gọi $U \subseteq L$ là tập đỉnh trái chưa khớp, $Z$ là tập tất cả đỉnh đạt được từ $U$ qua đường xen kẽ. Đặt $C = (L \setminus Z) \cup (R \cap Z)$.

**Tại sao $C$ là MVC:**

- **$|C| = |M|$:** Mỗi đường xen kẽ từ $U$ đến đỉnh phải $r \in R \cap Z$ kết thúc bằng cạnh khớp (nếu không, ta có đường tăng, mâu thuẫn $M$ tối đa). Đếm: $|L \setminus Z| + |R \cap Z| = |M|$.
- **$C$ bao phủ mọi cạnh:** Xét cạnh $(l, r)$. Nếu $l \notin Z$ thì $l \in C$. Nếu $l \in Z$ và cạnh thuộc $M$ thì $r \in Z \Rightarrow r \in C$. Nếu $l \in Z$ và cạnh không thuộc $M$ thì đường xen kẽ đến $l$ cộng cạnh này mở rộng đến $r$, nên $r \in Z \Rightarrow r \in C$.
- **Tối thiểu:** Các cạnh khớp không chung đỉnh, mỗi cạnh cần ít nhất 1 đỉnh trong bao phủ, nên mọi bao phủ phải có kích thước $\geq |M|$. Mà $|C| = |M|$, nên $C$ tối thiểu.

## Thuật toán

1. Xây mạng luồng hai phía: nguồn $\to$ hàng (c.p 1), hàng $\to$ cột (c.p 1 cho mỗi xu), cột $\to$ đích (c.p 1).
2. Tìm khớp tối đa bằng Dinic.
3. Tìm hàng chưa khớp, duyệt DFS trên đồ thị xen kẽ (vô hướng, đảo chiều cạnh khớp) để tìm tập $Z$.
4. Xuất: hàng không thuộc $Z$ (loại 1) và cột thuộc $Z$ (loại 2).

## Ví dụ minh họa

Lưới $3 \times 3$: xu tại $(1,3), (2,1), (2,3)$.

- Khớp tối đa: $\{(2,1), (1,3)\}$, kích thước 2.
- Bao phủ đỉnh tối thiểu: hàng 2, cột 3.
- Kết quả:
```
2
1 2
2 3
```

## Lưu ý cài đặt

- Dùng Dinic cho khớp tối đa.
- Sau khớp, xây đồ thị vô hướng `V2` cho duyệt đường xen kẽ: với mỗi hàng khớp, đảo cạnh khớp trong `V2`.
- Hàng chưa khớp là điểm bắt đầu DFS xen kẽ.

## Độ phức tạp

- **Thời gian:** $O(n^{5/2})$ — Dinic trên đồ thị hai phía
- **Bộ nhớ:** $O(n^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Coin%20Grid.cpp)
