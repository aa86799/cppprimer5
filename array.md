# 数组
int ary[];

# 特性：
在很多用数组名的地方，编译器会将其转成指向首元素的指针. 
string *p = ary;

# 标准库函数 begin, end
c11 add: 
int *p = std::begin(ary); p++ ;
int *q = std::end(ary);

# 下标和指针

int a = ary[2];

<==> 

int *p = ary;

int a = *(p + 2);



int *p = &ary[2];

int a = p[1];   <==> *(p+1)

int b = p[-1];  <==> *(p-1)

> vector 、string 虽然也有下标运算，但要求下标是无符号整数类型



# 建议

尽量用 vector和iterator，而非内置数组



