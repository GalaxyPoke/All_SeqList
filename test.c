#define  _CRT_SECURE_NO_WARNINGS 1
//  ----------- 顺序表 ----------- //
#include "SeqList.h"
// 头插测试 

void menu()
{
	printf("***********************************************************\n");
	printf("1、尾插数据             2、尾删数据\n");
	printf("\n");
	printf("3、头插数据             4、头删数据\n");
	printf("\n");
	printf("5、在任意位置插入数据（位置3插入20）\n");
	printf("\n");
	printf("6、在任意位置删除数据              \n");
	printf("\n");
	printf("7、查找某个数据的位置，并删除它     \n");
	printf("\n");
	printf("8、删除顺序表中有的 某个数据        \n");
	printf("\n");
	printf("9、打印数据                       \n");
	printf("\n");
	printf("-1、退出                          \n");
	printf("\n");
	printf("***********************************************************\n");

}

int main()
{
	printf("*************  欢迎大家使用GalaxyPokemon的动态顺序表 **************\n");
	int option = 0;
	SL s;
	SLInit(&s);
	do
	{
		menu();
		printf("请输入你的操作：>");
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
			printf("请依次输入你要尾插的数据：，以-1结束\n");
			scanf("%d", &sum);
			while (sum != -1)
			{
				SLPushBack(&s, sum);    // 1.尾插
				scanf("%d", &sum);
			}
			break;
		case 2:
			SLPopBack(&s);             // 2.尾删
			break;
		case 3:
			scanf("%d", &x);
			SLPushFront(&s, x);       // 3.头插
			break;
		case 4:
			SLPopFront(&s);           // 4.头删
			break;
		case 5:
			SLInsert(&s, 3, 20);     // 5.在任意位置插入数据
			break;
		case 6:
			SLErase(&s, 3);          // 6.在任意位置删除数据
			break;
		case 7:
			printf("请输入要删除序列的中的某个数字\n");
			scanf("%d", &z);
			y = SLFind(&s, z);        // 7.查找某个数字的位置，并且删除它
			printf("%d的位置在%d处： \n", z, y);
			if (y != -1)
			{
				SLErase(&s, y);
			}
			break;
		case 8:
			printf("请输入要删除序列的中的数字\n");  //8.删除顺序表中 所有的 某个数据 
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
				exit(0);  // 退出程序 
			}
			else
			{
				printf("输入错误，请重新输入\n");
			}
			break;

		}
	} while (option != -1);   // 退出程序
	SLDestory(&s);
	return 0;
}