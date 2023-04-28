# ifndef ARRAY_DEF
# define ARRAY_DEF
struct array
{
    int *data;
    int len;
};
typedef struct array Array;
// 初始化一个空的Array指针，并作为返回值，需要在周期结尾free
extern Array* initArr();
// 释放Array类型指针指向的空间，注意需要先释放成员data的空间
extern void delArr(Array* p_arr);
// 给成员data分配指向的空间，长度len
extern void setLenArr(int len, Array* p_arr);
// print array
extern void printArr(Array arr);
# endif