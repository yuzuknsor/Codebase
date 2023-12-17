#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // 最大联系人数

// 联系人结构体
typedef struct
{
	char name[20];	   // 姓名
	char phone[12];	   // 电话号码
	char email[30];	   // 电子邮件
	char academic[30]; // 院系
	char major[20];	   // 专业
	char province[10]; // 籍贯
	struct student *next;
} Contact;
Contact *head, *tail;

// 全局变量

// 函数声明
void addContact();		// 增加
void displayContacts(); // 显示
void deleteContact();	// 删除
void searchContacts();	// 查询
void modifyContact();	// 修改

// 增加联系人
void addContact()
{
	Contact *p = (Contact *)malloc(sizeof(Contact));
	if (p == NULL)
	{
		printf("内存分配失败！\n");
		exit(1); // 如果内存分配失败，则退出程序
	}
	while (1)
	{
		printf("请输入联系人的姓名：");
		scanf("%19s", p->name);
		printf("请输入联系人的电话号码：");
		scanf("%11s", p->phone);
		printf("请输入联系人的电子邮件：");
		scanf("%29s", p->email);
		printf("请输入联系人的院系：");
		scanf("%29s", p->academic);
		printf("请输入联系人的专业：");
		scanf("%19s", p->major);
		printf("请输入联系人的籍贯：");
		scanf("%9s", p->province);
		printf("联系人添加成功！\n");
		tail = p;
		p->next = NULL;
		int flag; // 无需在结束数字输入，上面一系列运行到这里时判读输出是否符合定义条件
		printf("是否继续（0 或 1）");
		scanf("%d", &flag);
		if (flag == 0)
		{ // 符合时运行if-break不符合时继续循环
			break;
		}
	}
	return;
	// 显示所有联系人
	void displayContacts()
	{
		Contact *p = head->next;
		if (p == NULL)
		{
			printf("通讯录为空。\n");
			return;
		}
		printf("所有联系人：\n");
		printf("姓名\t电话号码\t电子邮件\t\t院系\t专业\t籍贯\n"); // 修改了格式，使其更整齐
		while (p != NULL)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%s\n", p->name, p->phone, p->email, p->academic, p->major, p->province); // 添加了其他字段的显示
			p = p->next;
		}
		system("pause");
		return;
	}

	// 删除联系人
	void deleteContact()
	{
		if (head == tail)
		{
			printf("还未录入联系人信息，请先录入");
			system("pause");
			return;
		}
		while (1)
		{
			char name[20];
			printf("请输入需要删除的联系人姓名：");
			scanf("%s", name);
			Contact *p = head->next;
			Contact *p2 = head;
			while (p != NULL)
			{
				if (strcmp(name, p->name) == 0)
				{
					printf("姓名\t电话号码\t电子邮件\t\t院系\t专业\t籍贯\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\n", p->name, p->phone, p->email, p->academic, p->major, p->province);
					if (tail == p)
					{
						tail = p2;
					}
					p2->next = p->next;
					free(p);
					printf("删除后");
					displayContacts();
					break;
				}
				p = p->next;
				p2 = p2->next;
			}
			if (p == NULL)
			{
				printf("未找到该联系人信息\n");
			}
			int flag;
			printf("是否继续（0 或 1）\n");
			scanf("%d", &flag);
			if (flag == 0)
			{
				break;
			}
			system("pause");
		}
		return;
	}

	// 查询联系人
	void searchContacts()
	{
		if (head == tail)
		{
			printf("还未录入联系人信息，请先录入");
			system("pause");
			return;
		}
		while (1)
		{
			char name[20];
			printf("请输入需要查询的联系人姓名");
			scanf("%s", name);
			Contact *p = head->next;
			while (p != NULL)
			{
				if (strcmp(name, p->name) == 0)
				{
					printf("* * * * * * * * * * * * * * * * * *\n");
					printf("学号\t姓名\t性别\t成绩\n");
					printf("* * * * * * * * * * * * * * * * * *\n");
					printf("%-8d%-8s%-8c%4.2f\n", p->id, p->name, p->sex, p->grade);
					printf("* * * * * * * * * * * * * * * * * *\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)
			{
				printf("未找到该联系人信息\n");
			}
			int flag;
			printf("是否继续（0 或 1）");
			scanf("%d", &flag);
			if (flag == 0)
			{
				break;
			}
			system("pause");
		}
		return;
	}
	void modifyContact()
	{
		if (head == tail)
		{
			printf("还未录入学生信息，请先录入");
			system("pause");
			return;
		}
		while (1)
		{
			int name;
			printf("请输入需要修改的学生学号");
			scanf("%d", &int name);
			contact *p = head->next;
			while (p != NULL)
			{
				if (int name == p->name)
				{
					printf("学号\t姓名\t性别\t成绩\n");
					printf("%-8d%-8s%-8c%4.2f\n", p->id, p->name, p->sex, p->grade);
					printf("请输入新的学生学号\n");
					scanf("%d", &p->id);
					printf("修改后");
					displayContacts();
					break;
				}
				p = p->next;
			}
			if (p == NULL)
			{
				printf("未找到该联系人信息\n");
			}
			int flag;
			printf("是否继续（0 或 1）");
			scanf("%d", &flag);
			if (flag == 0)
			{
				break;
			}
			system("pause");
		}
		return;
	}
	int main()
	{
		Contact *p = (Contact *)malloc(sizeof(Contact));
		head = p;
		tail = p;
		head->next = NULL;
		int choose = 1;
		int choice;
		while (1)
		{
			// 显示菜单
			printf("\n通讯录管理系统\n");
			printf("1. 增加联系人\n");
			printf("2. 显示所有联系人\n");
			printf("3. 删除联系人\n");
			printf("4. 查询联系人\n");
			printf("5. 修改联系人\n");
			printf("6. 退出\n");
			printf("请选择操作：");
			scanf("%d", &choice);

			// 根据用户选择执行相应操作
			switch (choice)
			{
			case 1:
				addContact();
				break;
			case 2:
				displayContacts();
				break;
			case 3:
				deleteContact();
				break;
			case 4:
				searchContacts();
				break;
			case 5:
				modifyContact();
				break;
			case 6:
				exit(0);
			default:
				printf("无效的选择，请重新输入。\n");
			}
		}
		return 0;
	}