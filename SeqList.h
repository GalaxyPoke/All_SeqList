#pragma once    // ��ֹ�ظ���������ֹͷ�ļ����ظ��������

// �����Ҫ�Ŀ��ļ�
#include <stdlib.h>    // �ṩ��̬�ڴ���䡢��������ɵ�
#include <string.h>    // �ṩ�ַ�����������
#include <stdio.h>     // �ṩ�����������
#include <math.h>      // �ṩ��ѧ����
#include <assert.h>    // �ṩ���Ժ���

#define M 1000         // Ԥ���ĳЩ�������������Ƶĺ궨�壬������;δ��ϸ˵��

// �����������ͺ�˳���ṹ��
typedef int SLDateType;   // �������ͣ��˴�����Ϊint���ɸ���ʵ����Ҫ����
typedef struct Seqlist {
	SLDateType* a;        // ָ��̬���������ָ��
	int size;             // ��¼�洢�˶��ٸ���Ч����
	int capacity;         // �ռ�������С
} SL;

// ��̬˳���Ĳ�����������
void SLInit(SL* ps);                // ��ʼ��˳���
void SLDestory(SL* ps);             // ����˳����ͷ���Դ
void SLPushBack(SL* ps, SLDateType x);  // β�庯������˳���ĩβ���Ԫ��
void SLPrint(SL* ps);               // ��ӡ���������˳�������
void SLPopBack(SL* ps);             // βɾ������ɾ��˳���ĩβԪ��
void SLPushFront(SL* ps, SLDateType x); // ͷ�庯������˳���ͷ�����Ԫ��
void SLPopFront(SL* ps);            // ͷɾ������ɾ��˳���ͷ��Ԫ��
void SLCheckCapacity(SL* ps);       // ����Ƿ���Ҫ���ݣ�ȷ�����㹻�ռ����Ԫ��

// �м�λ�õĲ����ɾ������
void SLInsert(SL* ps, int pos, SLDateType x);  // ��posλ�ò�������
void SLErase(SL* ps, int pos);                 // ɾ��posλ�õ�����

int SLFind(SL* ps, SLDateType x);              // ����ĳһ�����ֵ�λ��
int SLFinds(SL* ps, SLDateType x, int begin);  // ��ָ��λ�ÿ�ʼ����ĳ���ֵ�λ��

