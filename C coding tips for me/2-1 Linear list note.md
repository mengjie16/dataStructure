# 多项式表示
## 线性表示
1. 数组
2. 结构数组

## 链表结构

```
typedef struct PolyNode *Polynomial;

struct PolyNode {
  int coef;
  int expon;
  Polynomial link;
}
```

### 操作

- 初始化空表
- 位置查找元素
- 元素查找位置
- 位置插入元素
- 删除位置上元素
- 表长

### 线性表的顺序存储实现
```
typedef struct LNode *List;
struct LNode{
   ElementType Data[MAXSIZE];
   int Last;
};
struct LNode L;
List PtrL;
```
