#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


//学生
typedef struct _Student
{
	char name[20];
	int age;
	int stuNum;
	int score;
}Student;

//节点
typedef struct _Node
{
	Student stu;
	struct _Node* pNext;
}Node;

//头结点
Node* g_pHead = NULL;

//欢迎
void Welcome();
//录入学生信息
void InputStudent();
//打印学生信息
void PrintStudent();
//保存学生信息
void SaveStudent();
//读取学生信息
void ReadStudent();