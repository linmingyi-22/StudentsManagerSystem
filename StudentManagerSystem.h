#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


//ѧ��
typedef struct _Student
{
	char name[20];
	int age;
	int stuNum;
	int score;
}Student;

//�ڵ�
typedef struct _Node
{
	Student stu;
	struct _Node* pNext;
}Node;

//ͷ���
Node* g_pHead = NULL;

//��ӭ
void Welcome();
//¼��ѧ����Ϣ
void InputStudent();
//��ӡѧ����Ϣ
void PrintStudent();
//����ѧ����Ϣ
void SaveStudent();
//��ȡѧ����Ϣ
void ReadStudent();