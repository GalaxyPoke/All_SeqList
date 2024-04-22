#define  _CRT_SECURE_NO_WARNINGS 1
//  ----------- ˳��� ----------- //
#include "SeqList.h"
// ͷ����� 

void menu()
{
	printf("***********************************************************\n");
	printf("1��β������             2��βɾ����\n");
	printf("\n");
	printf("3��ͷ������             4��ͷɾ����\n");
	printf("\n");
	printf("5��������λ�ò������ݣ�λ��3����20��\n");
	printf("\n");
	printf("6��������λ��ɾ������              \n");
	printf("\n");
	printf("7������ĳ�����ݵ�λ�ã���ɾ����     \n");
	printf("\n");
	printf("8��ɾ��˳������е� ĳ������        \n");
	printf("\n");
	printf("9����ӡ����                       \n");
	printf("\n");
	printf("-1���˳�                          \n");
	printf("\n");
	printf("***********************************************************\n");

}

int main()
{
	printf("*************  ��ӭ���ʹ��GalaxyPokemon�Ķ�̬˳��� **************\n");
	int option = 0;
	SL s;
	SLInit(&s);
	do
	{
		menu();
		printf("��������Ĳ�����>");
		scanf("%d", &option);
		int sum = 0;
		int x = 0;
		int y = 0;
		int z = 0;
		int pos = 0;
		int w = 0;
		switch (option)
		{
		case 1:
			printf("������������Ҫβ������ݣ�����-1����\n");
			scanf("%d", &sum);
			while (sum != -1)
			{
				SLPushBack(&s, sum);    // 1.β��
				scanf("%d", &sum);
			}
			break;
		case 2:
			SLPopBack(&s);             // 2.βɾ
			break;
		case 3:
			scanf("%d", &x);
			SLPushFront(&s, x);       // 3.ͷ��
			break;
		case 4:
			SLPopFront(&s);           // 4.ͷɾ
			break;
		case 5:
			SLInsert(&s, 3, 20);     // 5.������λ�ò�������
			break;
		case 6:
			SLErase(&s, 3);          // 6.������λ��ɾ������
			break;
		case 7:
			printf("������Ҫɾ�����е��е�ĳ������\n");
			scanf("%d", &z);
			y = SLFind(&s, z);        // 7.����ĳ�����ֵ�λ�ã�����ɾ����
			printf("%d��λ����%d���� \n", z, y);
			if (y != -1)
			{
				SLErase(&s, y);
			}
			break;
		case 8:
			printf("������Ҫɾ�����е��е�����\n");  //8.ɾ��˳����� ���е� ĳ������ 
			scanf("%d", &w);
			pos = SLFinds(&s, w, 0);
			while (pos != -1)
			{
				SLErase(&s, pos);
				pos = SLFinds(&s, w, pos);
			}
			break;
		case 9:
			SLPrint(&s);
			break;
		default:
			if (option == -1)
			{
				exit(0);  // �˳����� 
			}
			else
			{
				printf("�����������������\n");
			}
			break;

		}
	} while (option != -1);   // �˳�����
	SLDestory(&s);
	return 0;
}