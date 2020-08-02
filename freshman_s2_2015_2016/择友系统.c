#include <stdio.h>
#include <Windows.h>
#include <string.h>
struct vip
{
	long num;
	char pass[20];
	char qu1[20];
	char aw1[20];
	char name[10];
	char sex;
	char BIR[20];
	int age;
	char city[20];
	char EB[6];
	char job[12];
	char hobbies[100];
	char qq[12];
	char e_mail[20];
};
vip data[100];
FILE *fp;
int n = 0;
int readfile()
{
	int i = 0;
	if ((fp = fopen("c://vip.txt", "r")) == NULL)
	{
		printf("can not open the file");
	}
	while (!feof(fp))
	{
		fscanf(fp, "%ld %s %s %s %s %c %s %d %s %s %s %s %s %s", &data[i].num, data[i].pass, data[i].qu1, data[i].aw1, data[i].name, &data[i].sex, data[i].BIR, &data[i].age, data[i].city, data[i].EB, data[i].job, data[i].hobbies, data[i].qq, data[i].e_mail);
		i = i + 1;
	}
	return i;
}
int writefile(int i)
{
	printf("%d", i);
	fp = fopen("c:\\vip.txt", "a");
	fprintf(fp, "%ld %s %s %s %s %c %s %d %s %s %s %s %s %s\n", data[i].num, data[i].pass, data[i].qu1, data[i].aw1, data[i].name, data[i].sex, data[i].BIR, data[i].age, data[i].city, data[i].EB, data[i].job, data[i].hobbies, data[i].qq, data[i].e_mail);
	fclose(fp);
	printf("已上线的vip数%d\n", readfile() - 1);
	return 0;
}
int checknum(long num, int i)
{
	int k = 1;
	for (n = 0; n < i; n++)
		if (num == data[n].num)
		{
			k = 0;
			break;
		}
	return k;
}
int checkpass(char pass[])
{
	int k = 1;
	if (strcmp(pass, data[n].pass) == 0)
		k = 0;
	return k;
}
int show(int j)
{
	printf("*******************************************************\n");
	printf("账号:%ld 昵称:%s 性别:%c 年龄:%d\n", data[j].num, data[j].name, data[j].sex, data[j].age);
	printf("城市:%s 生日:%s 学历:%s 职业:%s\n", data[j].city, data[j].BIR, data[j].EB, data[j].job);
	printf("爱好:%s\n", data[j].hobbies);
	printf("QQ:%s\n", data[j].qq);
	printf("e_mail:%s\n", data[j].e_mail);
	printf("*******************************************************\n");
	return 0;
}
int zhuce()
{
	int i, j, count;
	char pass[20];
	i = readfile();
	printf("当前注册用户%d\n", i - 1);
	printf("请创建你的账号\n");
	scanf("%ld", &data[i].num);
	while (1)
	{
		if (checknum(data[i].num, i) == 0)
		{
			printf("你注册的账号已经存在，请重新创建！\n");
			scanf("%ld", &data[i].num);
		}
		else
			break;
	}
	printf("请输入你的密码\n");
	scanf("%s", data[i].pass);
	while (1)
	{
		printf("请确认你的密码\n");
		scanf("%s", pass);
		if (strcmp(pass, data[i].pass) == 0)
			break;
		else
		{
			printf("请重新输入你的密码\n");
			scanf("%s", data[i].pass);
		}
	}
	printf("请输入你的验证问题\n");
	scanf("%s", data[i].qu1);
	printf("请输入你的问题答案\n");
	scanf("%s", data[i].aw1);
	printf("请输入你的昵称\n");
	scanf("%s", data[i].name);
	printf("请选择你的性别:1.M 2.W\n");
	scanf("%d", &count);
	switch (count)
	{
	case 1:
		data[i].sex = 'M';
		break;
	case 2:
		data[i].sex = 'W';
		break;
	}
	printf("请输入你的生日\n");
	scanf("%s", data[i].BIR);
	printf("请输入你的年龄\n");
	scanf("%d", &data[i].age);
	printf("请选择你所在地：1.镇江 2.南京 3.常州 4.无锡 5.苏州\n");
	scanf("%d", &count);
	switch (count)
	{
	case 1:
		strcpy(data[i].city, "镇江");
		break;
	case 2:
		strcpy(data[i].city, "南京");
		break;
	case 3:
		strcpy(data[i].city, "常州");
		break;
	case 4:
		strcpy(data[i].city, "无锡");
		break;
	case 5:
		strcpy(data[i].city, "苏州");
		break;
	}
	printf("请选择你的文凭：1.中专 2.大专 3.本科 4.硕士 5.博士\n");
	scanf("%d", &count);
	switch (count)
	{
	case 1:
		strcpy(data[i].EB, "中专");
		break;
	case 2:
		strcpy(data[i].EB, "大专");
		break;
	case 3:
		strcpy(data[i].EB, "本科");
		break;
	case 4:
		strcpy(data[i].EB, "硕士");
		break;
	case 5:
		strcpy(data[i].EB, "博士");
		break;
	}
	printf("请选择你的工作领域：1.IT业 2.管理 3.金融 4.医学 5.外贸\n");
	scanf("%d", &count);
	switch (count)
	{
	case 1:
		strcpy(data[i].job, "IT业");
		break;
	case 2:
		strcpy(data[i].job, "管理");
		break;
	case 3:
		strcpy(data[i].job, "金融");
		break;
	case 4:
		strcpy(data[i].job, "医学");
		break;
	case 5:
		strcpy(data[i].job, "外贸");
		break;
	}
	printf("请输入你的兴趣\n");
	scanf("%s", data[i].hobbies);
	printf("请输入你的QQ\n");
	scanf("%s", data[i].qq);
	printf("请输入你的e-mail\n");
	scanf("%s", data[i].e_mail);
	writefile(i);
	return 0;
}
int search()
{
	int i, a[5], j, k, t = 0, ch, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
	i = readfile();
	printf("请选择查找好友的类别\n");
	printf("1.年龄 2.城市 3.学历 4.工作(可多选,以空格间隔，结束则按回车)\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:
		printf("请选择您要查找的年龄段\n");
		printf("1.0~15 2.16~22 3.23~27 4.28~50 5.51+\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			for (c1 = 0; c1 < i; c1++)
			{
				if (data[c1].age >= 0 && data[c1].age <= 15)
					show(c1);
			}
			break;
		case 2:
			for (c1 = 0; c1 < i; c1++)
			{
				if (data[c1].age >= 16 && data[c1].age <= 22)
					show(c1);
			}
			break;
		case 3:
			for (c1 = 0; c1 < i; c1++)
			{
				if (data[c1].age >= 23 && data[c1].age <= 27)
					show(c1);
			}
			break;
		case 4:
			for (c1 = 0; c1 < i; c1++)
			{
				if (data[c1].age >= 28 && data[c1].age <= 50)
					show(c1);
			}
			break;
		case 5:
			for (c1 = 0; c1 < i; c1++)
			{
				if (data[c1].age >= 51)
					show(c1);
			}
			break;
		}
		break;
	case 2:
		printf("请选择你要查找的城市\n");
		printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			for (c2 = 0; c2 < i; c2++)
			{
				if (strcmp(data[c2].city, "镇江") == 0)
					show(c2);
			}
			break;
		case 2:
			for (c2 = 0; c2 < i; c2++)
			{
				if (strcmp(data[c2].city, "南京") == 0)
					show(c2);
			}
			break;
		case 3:
			for (c2 = 0; c2 < i; c2++)
			{
				if (strcmp(data[c2].city, "常州") == 0)
					show(c2);
			}
			break;
		case 4:
			for (c2 = 0; c2 < i; c2++)
			{
				if (strcmp(data[c2].city, "无锡") == 0)
					show(c2);
			}
			break;
		case 5:
			for (c2 = 0; c2 < i; c2++)
			{
				if (strcmp(data[c2].city, "苏州") == 0)
					show(c2);
			}
			break;
		}
		break;
	case 3:
		printf("请选择您要查找的学历\n");
		printf("1.中专 2.大专 3.本科 4.硕士 5.博士\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			for (c3 = 0; c3 < i; c3++)
			{
				if (strcmp(data[c3].EB, "中专") == 0)
					show(c3);
			}
			break;
		case 2:
			for (c3 = 0; c3 < i; c3++)
			{
				if (strcmp(data[c3].EB, "大专") == 0)
					show(c3);
			}
			break;
		case 3:
			for (c3 = 0; c3 < i; c3++)
			{
				if (strcmp(data[c3].EB, "本科") == 0)
					show(c3);
			}
			break;
		case 4:
			for (c3 = 0; c3 < i; c3++)
			{
				if (strcmp(data[c3].EB, "硕士") == 0)
					show(c3);
			}
			break;
		case 5:
			for (c3 = 0; c3 < i; c3++)
			{
				if (strcmp(data[c3].EB, "博士") == 0)
					show(c3);
			}
			break;
		}
		break;
	case 5:
		printf("请选择您要查找的工作类别\n");
		printf("1.IT业 2.管理 3.金融 4.医学 5.外贸\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			for (c4 = 0; c4 < i; c4++)
			{
				if (strcmp(data[c4].EB, "IT业") == 0)
					show(c4);
			}
			break;
		case 2:
			for (c4 = 0; c4 < i; c4++)
			{
				if (strcmp(data[c4].EB, "管理") == 0)
					show(c4);
			}
			break;
		case 3:
			for (c4 = 0; c4 < i; c4++)
			{
				if (strcmp(data[c4].EB, "金融") == 0)
					show(c4);
			}
			break;
		case 4:
			for (c4 = 0; c4 < i; c4++)
			{
				if (strcmp(data[c4].EB, "医学") == 0)
					show(c4);
			}
			break;
		case 5:
			for (c4 = 0; c4 < i; c4++)
			{
				if (strcmp(data[c4].EB, "外贸") == 0)
					show(c4);
			}
			break;
		}
		break;
	}
	return 0;
}
int signin()
{
	long num;
	char pass[20], aw[20];
	int i, k = 0, t, j, flag = 0;
	i = readfile();
	printf("请输入你的的账号\n");
	scanf("%ld", &num);
	while (1)
	{
		if (checknum(num, i) == 0)
		{
			printf("请输入你的密码\n");
			break;
		}
		else
		{
			printf("账号错误，请重新输入\n");
			scanf("%ld", &num);
		}
	}
	scanf("%s", pass);
	while (1)
	{
		if (strcmp(pass, data[n].pass) == 0)
		{
			flag = 1;
			break;
		}
		else
		{
			if (k != 2)
			{
				printf("密码输入错误,请重新输入\n");
			}
			else
			{
				printf("密码错误，如果忘记密码，请重置你的密码\n");
				break;
			}
			scanf("%s", pass);
			k++;
			continue;
		}
	}
	if (k == 2)
	{
		printf("1.忘记密码 2.退出\n");
		scanf("%d", &t);
		switch (t)
		{
		case 1:
			printf("%s\n", data[n].qu1);
			scanf("%s", aw);
			if (strcmp(aw, data[n].aw1) == 0)
			{
				printf("请输入你的新密码\n");
				while (1)
				{
					scanf("%s", pass);
					printf("请确认你的密码\n");
					scanf("%s", data[n].pass);
					if (strcmp(pass, data[n].pass) == 0)
					{
						fp = fopen("c:\\vip.txt", "w");
						for (j = 0; j < i; j++)
							fprintf(fp, "%ld %s %s %s %s %c %s %d %s %s %s %s %s %s\n", data[j].num, data[j].pass, data[j].qu1, data[j].aw1, data[j].name, data[j].sex, data[j].BIR, data[j].age, data[j].city, data[j].EB, data[j].job, data[j].hobbies, data[j].qq, data[j].e_mail);
						fclose(fp);
						printf("密码重置成功\n");
						flag = 1;
						break;
					}
					else
						printf("密码错误，请重新输入\n");
				}
			}
			break;
		case 2:
			break;
		}
	}
	if (flag == 1)
	{
		printf("登录成功!\n");
		show(n);
		search();
	}
	return 0;
}
int main()
{
	int c;
	printf("1.注册2.登录\n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		zhuce();
		break;
	case 2:
		signin();
		break;
	}
	system("pause");
	return 0;
}
