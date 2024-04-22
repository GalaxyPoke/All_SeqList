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
    assert(ps); // ���ԣ�ȷ�������˳���ָ��ǿ�

    if (ps->size == ps->capacity)
    { // �����ǰԪ������������������Ҫ����
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;  // ������������ԣ������ǰ����Ϊ0�����ʼΪ4��������������

        SLDateType* temp = (SLDateType*)realloc(ps->a, newCapacity * sizeof(SLDateType)); // �������¶�̬�����ڴ�
        if (temp == NULL)
        { // ���realloc�Ƿ�ɹ���ע�������ǱȽϲ�����Ӧʹ�������Ⱥ�==
            perror("realloc failed"); // ����ڴ����ʧ�ܣ����������Ϣ
            exit(-1);  // �˳�����
        }

        ps->a = temp;  // ����˳��������ָ��
        ps->capacity = newCapacity;  // ����˳��������
    }
}


void SLPushBack(SL* ps, SLDateType x) {
    assert(ps); // ���ԣ�ȷ�������˳���ָ��ǿգ���������ÿ�ָ�뵼�³������

    SLCheckCapacity(ps); // ���˳���������Ƿ��㹻������������������

    ps->a[ps->size] = x; // ����Ԫ��x���������ĵ�ǰĩβλ�ã�ps->size��ָ����һ������λ�õ����� //����Ϊʲô��size������size-1���߱���أ���Ϊsize�Ĵ�С�������������һ����+1���±�

    ps->size++; // ����˳����Ԫ�ؼ���������1���Է�ӳ�������Ԫ��
}

void SLPopBack(SL* ps) {
    assert(ps); // ���ԣ�ȷ�������˳���ָ��ǿգ���������ÿ�ָ�뵼�³������

    //ps->a[ps->size - 1] = 0;  //�������˳������һ��Ԫ�ص����ݣ���������Ϊ 0��

    // �º͵Ĵ�����ʽ: ���˳����Ƿ�Ϊ�գ����Ϊ�����ӡ��Ϣ���˳�����
    /*if (ps->size == 0) {
        printf("˳����ѿ�\n");
        return;
    }*/

    // �����Ĵ�����ʽ: ʹ�ö���ȷ��˳���Ϊ�գ����Ϊ�ճ����ڵ���ģʽ�»��ж�ִ��
    assert(ps->size > 0); // ȷ��˳�����������һ��Ԫ�أ���ֹ����

    // ��ѡ���������: ���˳������һ��Ԫ�ص����ݣ���������Ϊ 0
    // ps->a[ps->size - 1] = 0;

    ps->size--; // ����˳���Ĵ�С���߼����Ƴ����һ��Ԫ��
}

// ��˳���Ŀ�ʼλ�ò���һ����Ԫ��
void SLPushFront(SL* ps, SLDateType x) {
    assert(ps);  // ���ԣ�ȷ�������˳���ָ��ǿ�

    SLCheckCapacity(ps);  // ���˳���������Ƿ��㹻������������������

    int end = ps->size - 1;  // ����˳������һ��Ԫ�ص�����λ��
    while (end >= 0) {
        ps->a[end + 1] = ps->a[end];  // ��Ԫ������ƶ�һ��λ��
        end--;  // ��ǰ�ƶ������������ƶ�ǰһ��Ԫ��
    }

    ps->a[0] = x;  // ��˳���ĵ�һ��λ�ò�����Ԫ��
    ps->size++;  // ����˳���Ĵ�С
}

void SLPopFront(SL* ps) {
    assert(ps);  // ���ԣ�ȷ�������˳���ָ��ǿգ���������ÿ�ָ�뵼�³������

    assert(ps->size > 0);  // ���ԣ�ȷ��˳�������Ԫ�أ������������

    int begin = 1;  // ��˳���ĵڶ���Ԫ�ؿ�ʼ
    while (begin < ps->size) {
        ps->a[begin - 1] = ps->a[begin];  // ��ÿ��Ԫ����ǰ�ƶ�һ��λ��
        begin++;  // ��������������������һ��Ԫ��
    }

    ps->size--;  // ����˳���Ĵ�С���߼����Ƴ����һ���ճ���λ�õ�Ԫ��
}

void SLInsert(SL* ps, int pos, SLDateType x)
{
    assert(ps); // ���ԣ�ȷ�������˳���ָ��ps�ǿգ���ֹ��ָ�����õ��µĳ������
    assert(ps->size > 0); // ���ԣ�ȷ��˳���Ĵ�С����Ϊ1��������Կ��ܲ����Ǳ�Ҫ���ر�����������ڿձ��в���
    assert(pos <= ps->size); // ���ԣ�ȷ������λ����Ч������λ�ÿ�������������һ��Ԫ��֮�󣨼�����size��

    SLCheckCapacity(ps); // ���˳�������������������������ݲ�������֤�пռ������Ԫ��

    int end = ps->size - 1; // ��ȡ˳��������һ��Ԫ�ص�λ��

    // ѭ���ƶ�Ԫ�أ�Ϊ��Ԫ���ڳ�λ��
    while (end >= pos)
    {
        ps->a[end + 1] = ps->a[end]; // ��Ԫ������ƶ�һ��λ��
        end--; // ���´����Ԫ��λ��
    }

    ps->a[pos] = x; // ��ָ��λ��pos������Ԫ��x
    ps->size++; // ����˳����Ԫ������
}


void SLErase(SL* ps, int pos)
{
    assert(ps); // ���ԣ�ȷ��˳����ָ��ps�ǿգ���ֹ��ָ�����õ��µĳ������
    assert(pos >= 0); // ���ԣ�ȷ��ָ����λ��pos����Ч�ģ������Ǹ���
    assert(pos < ps->size); // ���ԣ�ȷ��ָ����λ��pos��˳���ĵ�ǰԪ�ط�Χ�ڣ���С��Ԫ������size��
    assert(ps->size > 0);  // ���ԣ����˳����Ԫ��������Ϊ�㣬ȷ����Ԫ�ؿ���ɾ��

    int begin = pos + 1; // ���ÿ�ʼ�ƶ����ݵ�λ�ã���pos����һ��λ�ÿ�ʼ

    // ѭ���ƶ�Ԫ�أ�������Ҫɾ����Ԫ��
    while (begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin]; // ������Ԫ����ǰ�ƶ�һλ�����ɾ��Ԫ�ص�λ��
        begin++; // �ƶ�����һ��Ԫ��
    }

    ps->size--; // ɾ��Ԫ�غ�˳����Ԫ����������1
}

// �������壺��˳���ps�в���Ԫ��x��λ��
int SLFind(SL* ps, SLDateType x)
{
    assert(ps); // ���ԣ�ȷ��˳����ָ��ps�ǿ�

    // ����˳����е�����Ԫ��
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x) // �����ǰԪ�ص���x
        {
            return i; // ���ص�ǰԪ�ص�����
        }
    }

    return -1; // ���û���ҵ�Ԫ��x������-1��Ϊʧ�ܵı�־
}


// �������壺��˳���ps�д�����begin��ʼ����Ԫ��x��λ��
int SLFinds(SL* ps, SLDateType x, int begin)
{
    assert(ps); // ���ԣ�ȷ��˳����ָ��ps�ǿգ���ֹ��ָ�����õ��µĳ������

    // ��ָ���Ŀ�ʼλ��begin����˳���
    for (int i = begin; i < ps->size; i++)
    {
        if (ps->a[i] == x) // �����ǰԪ�ص���x
        {
            return i; // ���ص�ǰԪ�ص�����
        }
    }

    return -1; // ����������û���ҵ�Ԫ��x������-1��ʾδ�ҵ�
}

void SLPrint(SL* ps)  // ��ӡ����
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SLDestory(SL* ps)   //����
{
    assert(ps);
    if (ps->a != NULL)
    {
        free(ps->a);
        ps->a = NULL;
        ps->size = ps->capacity = 0;
    }
}