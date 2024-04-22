#pragma once    // 防止重复包含，防止头文件被重复包含多次

// 引入必要的库文件
#include <stdlib.h>    // 提供动态内存分配、随机数生成等
#include <string.h>    // 提供字符串操作函数
#include <stdio.h>     // 提供输入输出函数
#include <math.h>      // 提供数学函数
#include <assert.h>    // 提供断言函数

#define M 1000         // 预设的某些操作或容量限制的宏定义，具体用途未详细说明

// 定义数据类型和顺序表结构体
typedef int SLDateType;   // 数据类型，此处定义为int，可根据实际需要调整
typedef struct Seqlist {
	SLDateType* a;        // 指向动态分配数组的指针
	int size;             // 记录存储了多少个有效数据
	int capacity;         // 空间容量大小
} SL;

// 动态顺序表的操作函数声明
void SLInit(SL* ps);                // 初始化顺序表
void SLDestory(SL* ps);             // 销毁顺序表，释放资源
void SLPushBack(SL* ps, SLDateType x);  // 尾插函数，向顺序表末尾添加元素
void SLPrint(SL* ps);               // 打印函数，输出顺序表内容
void SLPopBack(SL* ps);             // 尾删函数，删除顺序表末尾元素
void SLPushFront(SL* ps, SLDateType x); // 头插函数，向顺序表头部添加元素
void SLPopFront(SL* ps);            // 头删函数，删除顺序表头部元素
void SLCheckCapacity(SL* ps);       // 检查是否需要扩容，确保有足够空间添加元素

// 中间位置的插入和删除操作
void SLInsert(SL* ps, int pos, SLDateType x);  // 在pos位置插入数据
void SLErase(SL* ps, int pos);                 // 删除pos位置的数据

int SLFind(SL* ps, SLDateType x);              // 查找某一个数字的位置
int SLFinds(SL* ps, SLDateType x, int begin);  // 从指定位置开始查找某数字的位置

