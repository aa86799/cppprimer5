# 什么是vector？

向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。支持泛型。
类似java的 List

# 构造函数
 - vector():创建一个空vector
 - vector(int nSize):创建一个vector,元素个数为nSize
 - vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
 - vector(const vector&):复制构造函数
 - assign 分配

```
auto two = vector<int>(one) ; //
two.assign(one.begin(), one.end()); //迭代器分配  深复制
two.assign(5, 0); //重新分配5个0元素。
```



# 常用函数

1. push_back 在数组的最后添加一个数据
2. pop_back 去掉数组的最后一个数据
3. at 得到编号位置的数据
4. begin 得到数组头的指针, iterator
5. end 得到数组的最后一个单元+1的指针; iterator
6. rbegin 指向该容器的最后一个元素的指针； reverse 反向
7. rend 批向第一个
8. front 得到数组头的引用
9. back 得到数组的最后一个单元的引用
10. max_size 得到vector最大可以是多大
11. capacity 当前vector分配的大小, 会受reserve 影响，可能比size大。
12. size 真实数据的大小，会受 resize影响
13. resize 改变当前使用数据的大小，如果它比当前使用的大，则填充默认值
14. reserve 改变当前vecotr所分配空间的大小
15. erase 删除指针指向的数据项

14. clear 清空当前的vector

15. rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)

16. rend 将vector反转构的结束指针返回(其实就是原来的begin-1)

17. empty 判断vector是否为空

18. swap 与另一个vector交换数据
19. cbegin 返回 const_iterator
20. cend 返回 const_iterator
21. crbegin 返回 该函数返回一个具有const属性的reverse_iterator, 指向该容器的最后一个元素。
22. crend 指向第一个 reverse_iterator

