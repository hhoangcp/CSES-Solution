# Split into Two Paths

**CSES ID:** 3358  
**Đề bài gốc:** https://cses.fi/problemset/task/3358  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đồ thị có hướng không chu trình trên $n$ đỉnh, quyết định xem có thể chia các đỉnh thành hai đường đi có hướng (có thể rỗng) sao cho hai đỉnh liên tiếp trong mỗi đường đi phải được nối bởi một cạnh trong đồ thị hay không. Không cần dùng hết các cạnh. Nếu khả thi, in ra hai đường đi; ngược lại báo không khả thi.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng một cạnh có hướng $a \to b$.

## Kết quả
Đầu tiên in `YES` hoặc `NO`. Nếu `YES`, in thêm hai dòng, mỗi dòng bắt đầu bằng độ dài đường đi rồi các đỉnh theo thứ tự; một đường đi có thể rỗng.

## Ràng buộc
- $2 \le n \le 2 \cdot 10^5$
- $0 \le m \le 5 \cdot 10^5$
