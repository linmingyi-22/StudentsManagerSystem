#include "StudentManagerSystem.h"

int main()
{
	while (1)
	{
		Welcome();
		char ch = _getch();
		switch (ch)
		{
		case '1'://¼��ѧ����Ϣ
			InputStudent(); 
			break;
		case '2'://��ӡѧ����Ϣ
			PrintStudent();
			break;
		case '3'://����ѧ����Ϣ
			SaveStudent();
			break;
		case '4'://��ȡѧ����Ϣ
			ReadStudent();
			break;
		case '5'://ͳ������ѧ������
			printf("ѧ��������Ϊ: %d\n", CountStudent());
			system("pause");
			system("cls");
			break;
		case '6'://����ѧ����Ϣ
		{
			Node* p = FindStudent();
			if (p != NULL)
				printf("ѧ��:%d\t����:%s\t����:%d\t�ɼ�:%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			else
				printf("���޴���");
			system("pause");
			system("cls");
			break;
		}
		case '7'://�޸�ѧ����Ϣ
			ModifyStudent();
			system("pause");
			system("cls");
			break;
		case '8'://ɾ��ѧ����Ϣ
			DeleteStudent();
			system("pause");
			system("cls");
			break;
		case '0'://�˳�ϵͳ
			printf("see you");
			return 0;
		default:
			printf("������������������\n");
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
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳ\t*\n");
	printf("*****************************************\n");
	printf("*\t\t��ѡ����\t\t*\n");
	printf("*****************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t*\n");
	printf("*****************************************\n");
}
void InputStudent()
{
	Node* pNewNode=(Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//ͷ�巨
	if (g_pHead == NULL)
		g_pHead = pNewNode;
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	printf("������ѧ������:\n");
	scanf_s("%s", &pNewNode->stu.name,20);//�����������ַ
	printf("������ѧ������:\n");
	scanf_s("%d", &pNewNode->stu.age);
	printf("������ѧ��ѧ��:\n");
	scanf_s("%d", &pNewNode->stu.stuNum);
	printf("������ѧ���ɼ�:\n");
	scanf_s("%d", &pNewNode->stu.score);
	
	printf("¼��ɹ�\n");
	system("pause");
	system("cls");
};
void PrintStudent()
{
	printf("*****************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳ\t*\n");
	printf("*****************************************\n");
	printf("*\tѧ��\t*\t����\t*\t����\t*\t�ɼ�\n");
	printf("*****************************************\n");
	//�����б�
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
	//���ļ�
	FILE* fp = fopen("E:\\stuinfo.dat", "w");

	if (fp==NULL)
	{
		printf("���ļ�ʧ��.\n");
		return;
	}
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}

	printf("���ݱ���ɹ�\n");
	//�ر��ļ�
	fclose(fp);
	system("pause");
	system("cls");
}
void ReadStudent()
{
	FILE *fp= fopen("E:\\stuinfo.dat", "r");

	if (fp==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}

	Student stu;
	while (fread(&stu, 1, sizeof(Student), fp))
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));

		pNewNode->pNext = NULL;

		if (pNewNode != NULL)
			memcpy(pNewNode, &stu,sizeof(Student));

		//ͷ�巨
		if (g_pHead == NULL)
			g_pHead = pNewNode;
		else
		{
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	}
	printf("�������ݳɹ�\n");
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
//����
Node* FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("������Ҫ����ѧ����ѧ��:\n");
	scanf_s("%d", &nStuNum);
	printf("������Ҫ����ѧ��������:\n");
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
	printf("��������Ҫ�޸ĵ�ѧ����ѧ��:\n");
	scanf("%d", &nStuNum);
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum==nStuNum)
		{
			printf("������Ҫ�޸ĵ�ѧ�����������䣬�ɼ�:\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("�޸ĳɹ�\n");
			break;
		}
		p = p->pNext;
	}
	if (p==NULL)
		printf("���޴���\n");
}
void DeleteStudent()
{
	int nStuNum;
	printf("������Ҫɾ����ѧ����ѧ��:\n");
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
		printf("���޴���\n");
	}
}