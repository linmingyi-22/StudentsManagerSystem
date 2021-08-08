#include "StudentManagerSystem.h"

int main()
{
	while (1)
	{
		Welcome();
		char ch = _getch();
		switch (ch)
		{
		case '1'://录入学生信息
			InputStudent(); 
			break;
		case '2'://打印学生信息
			PrintStudent();
			break;
		case '3'://保存学生信息
			SaveStudent();
			break;
		case '4'://读取学生信息
			ReadStudent();
			break;
		case '5'://统计所有学生人数
			printf("学生总人数为: %d\n", CountStudent());
			system("pause");
			system("cls");
			break;
		case '6'://查找学生信息
		{
			Node* p = FindStudent();
			if (p != NULL)
				printf("学号:%d\t姓名:%s\t年龄:%d\t成绩:%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			else
				printf("查无此人");
			system("pause");
			system("cls");
			break;
		}
		case '7'://修改学生信息
			ModifyStudent();
			system("pause");
			system("cls");
			break;
		case '8'://删除学生信息
			DeleteStudent();
			system("pause");
			system("cls");
			break;
		case '0'://退出系统
			printf("see you");
			return 0;
		default:
			printf("输入有误，请重新输入\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
void Welcome()
{
	printf("*****************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统\t*\n");
	printf("*****************************************\n");
	printf("*\t\t请选择功能\t\t*\n");
	printf("*****************************************\n");
	printf("*\t\t1.录入学生信息\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t*\n");
	printf("*\t\t6.查找学生信息\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t*\n");
	printf("*\t\t0.退出系统\t\t*\n");
	printf("*****************************************\n");
}
void InputStudent()
{
	Node* pNewNode=(Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//头插法
	if (g_pHead == NULL)
		g_pHead = pNewNode;
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	printf("请输入学生姓名:\n");
	scanf_s("%s", &pNewNode->stu.name,20);//数组名代表地址
	printf("请输入学生年龄:\n");
	scanf_s("%d", &pNewNode->stu.age);
	printf("请输入学生学号:\n");
	scanf_s("%d", &pNewNode->stu.stuNum);
	printf("请输入学生成绩:\n");
	scanf_s("%d", &pNewNode->stu.score);
	
	printf("录入成功\n");
	system("pause");
	system("cls");
};
void PrintStudent()
{
	printf("*****************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统\t*\n");
	printf("*****************************************\n");
	printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\n");
	printf("*****************************************\n");
	//遍历列表
	Node* p = g_pHead;
	while (p!=NULL)
	{
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
		p = p->pNext;
	}
	printf("*****************************************\n");
	system("pause");
	system("cls");
}
void SaveStudent()
{
	//打开文件
	FILE* fp = fopen("E:\\stuinfo.dat", "w");

	if (fp==NULL)
	{
		printf("打开文件失败.\n");
		return;
	}
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}

	printf("数据保存成功\n");
	//关闭文件
	fclose(fp);
	system("pause");
	system("cls");
}
void ReadStudent()
{
	FILE *fp= fopen("E:\\stuinfo.dat", "r");

	if (fp==NULL)
	{
		printf("打开文件失败\n");
		return;
	}

	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp))
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));

		pNewNode->pNext = NULL;

		if (pNewNode != NULL)
			memcpy(pNewNode, &stu,sizeof(Student));

		//头插法
		if (g_pHead == NULL)
			g_pHead = pNewNode;
		else
		{
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	}
	printf("加载数据成功\n");
	fclose(fp);
	system("pause");
	system("cls");
}
int CountStudent()
{
	int nCount = 0;
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	return nCount;
}
//错误
Node* FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("请输入要查找学生的学号:\n");
	scanf_s("%d", &nStuNum);
	printf("请输入要查找学生的姓名:\n");
	scanf_s("%s", szName);
	
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum==nStuNum || 0==strcmp(p->stu.name,szName))
			return p;
		p = p->pNext;
	}
	return NULL;
}
void ModifyStudent()
{
	int nStuNum;
	printf("请输入需要修改的学生的学号:\n");
	scanf("%d", &nStuNum);
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum==nStuNum)
		{
			printf("请输入要修改的学生姓名，年龄，成绩:\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("修改成功\n");
			break;
		}
		p = p->pNext;
	}
	if (p==NULL)
		printf("查无此人\n");
}
void DeleteStudent()
{
	int nStuNum;
	printf("请输入要删除的学生的学号:\n");
	scanf("%d", &nStuNum);
	Node* p1;
	if (g_pHead->stu.stuNum== nStuNum)
	{
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		return;
	}
	Node* p = g_pHead;
	Node* p2;
	while (p->pNext!=NULL)
	{
		if (p->pNext->stu.stuNum==nStuNum)
		{
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			return;
		}
		p = p->pNext;
		if (p->pNext==NULL)
		{
			break;
		}
	}
	if (p->pNext==NULL)
	{
		printf("查无此人\n");
	}
}