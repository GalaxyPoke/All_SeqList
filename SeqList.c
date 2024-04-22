#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* ps)
{
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SLCheckCapacity(SL* ps)
{
    assert(ps); // 断言，确保传入的顺序表指针非空

    if (ps->size == ps->capacity)
    { // 如果当前元素数量等于容量，需要扩容
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;  // 新容量计算策略：如果当前容量为0，则初始为4；否则容量翻倍

        SLDateType* temp = (SLDateType*)realloc(ps->a, newCapacity * sizeof(SLDateType)); // 尝试重新动态分配内存
        if (temp == NULL)
        { // 检查realloc是否成功，注意这里是比较操作，应使用两个等号==
            perror("realloc failed"); // 如果内存分配失败，输出错误消息
            exit(-1);  // 退出程序
        }

        ps->a = temp;  // 更新顺序表的数据指针
        ps->capacity = newCapacity;  // 更新顺序表的容量
    }
}


void SLPushBack(SL* ps, SLDateType x) {
    assert(ps); // 断言，确保传入的顺序表指针非空，避免解引用空指针导致程序崩溃

    SLCheckCapacity(ps); // 检查顺序表的容量是否足够，如果不足则进行扩容

    ps->a[ps->size] = x; // 将新元素x存放在数组的当前末尾位置，ps->size是指向下一个空闲位置的索引 //这里为什么用size而不用size-1或者别的呢，因为size的大小，就是数组最后一个数+1的下标

    ps->size++; // 更新顺序表的元素计数，增加1，以反映添加了新元素
}

void SLPopBack(SL* ps) {
    assert(ps); // 断言，确保传入的顺序表指针非空，避免解引用空指针导致程序崩溃

    //ps->a[ps->size - 1] = 0;  //用于清除顺序表最后一个元素的数据，将其设置为 0。

    // 温和的错误处理方式: 检查顺序表是否为空，如果为空则打印信息并退出函数
    /*if (ps->size == 0) {
        printf("顺序表已空\n");
        return;
    }*/

    // 暴力的错误处理方式: 使用断言确保顺序表不为空，如果为空程序在调试模式下会中断执行
    assert(ps->size > 0); // 确保顺序表中至少有一个元素，防止下溢

    // 可选的清除操作: 清除顺序表最后一个元素的数据，将其设置为 0
    // ps->a[ps->size - 1] = 0;

    ps->size--; // 减少顺序表的大小，逻辑上移除最后一个元素
}

// 在顺序表的开始位置插入一个新元素
void SLPushFront(SL* ps, SLDateType x) {
    assert(ps);  // 断言，确保传入的顺序表指针非空

    SLCheckCapacity(ps);  // 检查顺序表的容量是否足够，如果不足则进行扩容

    int end = ps->size - 1;  // 计算顺序表最后一个元素的索引位置
    while (end >= 0) {
        ps->a[end + 1] = ps->a[end];  // 将元素向后移动一个位置
        end--;  // 向前移动索引，继续移动前一个元素
    }

    ps->a[0] = x;  // 在顺序表的第一个位置插入新元素
    ps->size++;  // 更新顺序表的大小
}

void SLPopFront(SL* ps) {
    assert(ps);  // 断言，确保传入的顺序表指针非空，避免解引用空指针导致程序崩溃

    assert(ps->size > 0);  // 断言，确保顺序表中有元素，避免下溢错误

    int begin = 1;  // 从顺序表的第二个元素开始
    while (begin < ps->size) {
        ps->a[begin - 1] = ps->a[begin];  // 将每个元素向前移动一个位置
        begin++;  // 递增索引，继续处理下一个元素
    }

    ps->size--;  // 减少顺序表的大小，逻辑上移除最后一个空出的位置的元素
}

void SLInsert(SL* ps, int pos, SLDateType x)
{
    assert(ps); // 断言：确保传入的顺序表指针ps非空，防止空指针引用导致的程序崩溃
    assert(ps->size > 0); // 断言：确保顺序表的大小至少为1，这个断言可能不总是必要，特别是如果允许在空表中插入
    assert(pos <= ps->size); // 断言：确保插入位置有效，插入位置可以在数组的最后一个元素之后（即等于size）

    SLCheckCapacity(ps); // 检查顺序表的容量，如果不够则进行扩容操作，保证有空间插入新元素

    int end = ps->size - 1; // 获取顺序表中最后一个元素的位置

    // 循环移动元素，为新元素腾出位置
    while (end >= pos)
    {
        ps->a[end + 1] = ps->a[end]; // 将元素向后移动一个位置
        end--; // 更新处理的元素位置
    }

    ps->a[pos] = x; // 在指定位置pos放入新元素x
    ps->size++; // 更新顺序表的元素数量
}


void SLErase(SL* ps, int pos)
{
    assert(ps); // 断言：确保顺序表的指针ps非空，防止空指针引用导致的程序崩溃
    assert(pos >= 0); // 断言：确保指定的位置pos是有效的，不能是负数
    assert(pos < ps->size); // 断言：确保指定的位置pos在顺序表的当前元素范围内（即小于元素数量size）
    assert(ps->size > 0);  // 断言：检查顺序表的元素数量不为零，确保有元素可以删除

    int begin = pos + 1; // 设置开始移动数据的位置，从pos的下一个位置开始

    // 循环移动元素，覆盖需要删除的元素
    while (begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin]; // 将后续元素向前移动一位，填补被删除元素的位置
        begin++; // 移动到下一个元素
    }

    ps->size--; // 删除元素后，顺序表的元素总数减少1
}

// 函数定义：在顺序表ps中查找元素x的位置
int SLFind(SL* ps, SLDateType x)
{
    assert(ps); // 断言：确保顺序表的指针ps非空

    // 遍历顺序表中的所有元素
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x) // 如果当前元素等于x
        {
            return i; // 返回当前元素的索引
        }
    }

    return -1; // 如果没有找到元素x，返回-1作为失败的标志
}


// 函数定义：在顺序表ps中从索引begin开始查找元素x的位置
int SLFinds(SL* ps, SLDateType x, int begin)
{
    assert(ps); // 断言：确保顺序表的指针ps非空，防止空指针引用导致的程序崩溃

    // 从指定的开始位置begin遍历顺序表
    for (int i = begin; i < ps->size; i++)
    {
        if (ps->a[i] == x) // 如果当前元素等于x
        {
            return i; // 返回当前元素的索引
        }
    }

    return -1; // 如果遍历完毕没有找到元素x，返回-1表示未找到
}

void SLPrint(SL* ps)  // 打印函数
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SLDestory(SL* ps)   //销毁
{
    assert(ps);
    if (ps->a != NULL)
    {
        free(ps->a);
        ps->a = NULL;
        ps->size = ps->capacity = 0;
    }
}