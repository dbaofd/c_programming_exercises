#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
struct talents
{
	long num;				//账号
	long passw;				//密码
	char name[10];			//姓名
	int adress_num;			//区域代号
	char adress[50];		//区域
	char adress2[50];		//家庭住址
	int speciality_num;		//特长代号
	char speciality[50];	//特长
	int edubackground_num;	//学历代号
	char edubackground[50]; //学历
	int sex_num;			//性别代号
	char sex[10];			//性别
	int age;				//年龄
	char ps[50];			//其他说明
	char tel[12];			//联系方式
};							//人才结构体
struct companies
{
	long num;			 //账号
	long passw;			 //密码
	char company[50];	 //公司名称
	int adress_num;		 //区域代号
	char adress[50];	 //区域
	char adress2[50];	 //具体地址
	int property_num;	 //公司性质代号
	char property[50];	 //公司性质
	int background_num;	 //学历代号
	char background[50]; //要求的学历背景
	char sex[10];		 //性别限定
	char age_limit[50];	 //年龄限定
	char ps[50];		 //其他说明
	char person[50];	 //联系人
	char tel[10];		 //联系方式
};						 //公司结构体
talents guide1[200];	 //数据库容量200
companies guide2[200];
int n;
FILE *TAL;	//人才数据库
FILE *COM;	//公司数据库
int title() //主菜单
{
	printf("*******赶集网，啥都有*******\n");
	printf("*****1.上传人才数据*********\n");
	printf("*****2.上传公司数据*********\n");
	printf("*****3.修改人才数据*********\n");
	printf("*****4.修改公司数据*********\n");
	printf("*****5.搜索人才*************\n");
	printf("*****6.搜索公司*************\n");
	printf("*****7.其他*****************\n");
	printf("*****8.离开*****************\n");
	printf("请输入选项:");
	return 0;
}
int contactUs()
{
	int i;
	i = 0;
	printf("1.法律申明\n2.联系我们\n3.软件版本\n4.关于我们\n5.离开此页\n");
	while (i != 5)
	{
		scanf("%d", &i);
		if (i > 5 || i < 1)
		{
			printf("请输入1~4，重新输入:");
			scanf("%d", &i);
		}
		switch (i)
		{
		case 1:
			printf("*******************************************\n");
			printf("这是一个公司与人才的双方平台\n");
			printf("我们会不定期提供软件更新以及信息维护\n");
			printf("我们致力于提供最好的服务\n");
			printf("这是一个神奇的软件\n");
			printf("本法律申明最终解释权归鲍东\n");
			printf("*******************************************\n");
			break;
		case 2:
			printf("*******************************\n");
			printf("开发者热线:1865285206\n普通客服  :0511-84464806\n客服QQ    :1039952593\n");
			printf("企业邮箱  :bd1039952593@163.com\n");
			printf("*******************************\n");
			break;
		case 3:
			printf("**************************************************************\n");
			printf("Software:Ganji5.1.2\n");
			printf("Designed by Baodong in Jiangsu written in Ningbo.Model A1429\n");
			printf("FCCID:BCG-E2599A IC:579C-E2610A IMEI:013346005424405\n");
			printf("**************************************************************\n");
			break;
		case 4:
			printf("*******************************************************\n");
			printf("地址:江苏省镇江市京口区黄山西路万达广场A座写字楼1707号\n");
			printf("本产品由一杆清(鲍东)工作室提供技术支持\n");
			printf("*******************************************************\n");
			break;
		}
	}
	system("pause");
	system("CLS");
	title();
	return 0;
}
int readfileTAL(talents guide1[]) //读取人才信息函数
{
	int i = 0;
	int fileend = 0;
	if ((TAL = fopen("c://Talents.txt", "r")) == NULL)
	{
		printf("can not open the file");
	}
	while (fileend == feof(TAL))
	{
		i = i + 1;
		fscanf(TAL, "%ld%ld%s%d%s%s%d%s%d%s%d%s%d%s%s", &guide1[i].num, &guide1[i].passw, guide1[i].name,
			   &guide1[i].adress_num, guide1[i].adress, guide1[i].adress2, &guide1[i].speciality_num, guide1[i].speciality,
			   &guide1[i].edubackground_num, &guide1[i].edubackground, &guide1[i].sex_num, guide1[i].sex, &guide1[i].age,
			   guide1[i].ps, guide1[i].tel);
	}
	return i;
}
int writefileTAL(talents guide1[], int j) //将注册的人才数据写入数据库函数
{
	TAL = fopen("c:\\Talents.txt", "a");
	fprintf(TAL, "%ld %ld %s %d %s %s %d %s %d %s %d %s %d %s %s\n", guide1[j - 1].num, guide1[j - 1].passw, guide1[j - 1].name,
			guide1[j - 1].adress_num, guide1[j - 1].adress, guide1[j - 1].adress2, guide1[j - 1].speciality_num, guide1[j - 1].speciality,
			guide1[j - 1].edubackground_num, guide1[j - 1].edubackground, guide1[j - 1].sex_num, guide1[j - 1].sex, guide1[j - 1].age,
			guide1[j - 1].ps, guide1[j - 1].tel);
	fclose(TAL);
	printf("已上线的人才数%d\n", readfileTAL(guide1) - 1); //输出上线的人才数据的个数
	return 0;
}
int readfileCOM(companies guide2[]) //读取公司信息函数
{
	int i = 0;
	int fileend = 0;
	if ((COM = fopen("c://Companies.txt", "r")) == NULL)
	{
		printf("can not open the file");
	}
	while (fileend == feof(COM))
	{
		i = i + 1;
		fscanf(COM, "%ld%ld%s%d%s%s%d%s%d%s%s%s%s%s%s", &guide2[i].num, &guide2[i].passw, guide2[i].company,
			   &guide2[i].adress_num, guide2[i].adress, guide2[i].adress2, &guide2[i].property_num, guide2[i].property,
			   &guide2[i].background_num,
			   guide2[i].background, guide2[i].sex, guide2[i].age_limit, guide2[i].ps, guide2[i].person, guide2[i].tel);
	}
	return i;
}
int writefileCOM(companies guide2[], int j) //将注册的公司信息写入数据库
{
	COM = fopen("c:\\Companies.txt", "a");
	fprintf(COM, "%ld %ld %s %d %s %s %d %s %d %s %s %s %s %s %s\n", guide2[j - 1].num, guide2[j - 1].passw, guide2[j - 1].company,
			guide2[j - 1].adress_num, guide2[j - 1].adress, guide2[j - 1].adress2, guide2[j - 1].property_num, guide2[j - 1].property,
			guide2[j - 1].background_num, guide2[j - 1].background, guide2[j - 1].sex, guide2[j - 1].age_limit, guide2[j - 1].ps, guide2[j - 1].person, guide2[j - 1].tel);
	fclose(COM);
	printf("当前上线的公司数%d\n", readfileCOM(guide2) - 1);
	return 0;
}
int uploadTAL() //上传人才数据
{
	int m, i, k;
	long mima1, mima2;
	i = readfileTAL(guide1);
	printf("已有人才%d个\n", i - 1);
	k = 0;
	printf("要上传，首先先创建账号吧!\n输入账号:");
	scanf("%ld", &guide1[i - 1].num);
	printf("输入密码:");
	while (k == 0)
	{
		scanf("%ld", &mima1);
		printf("请核对你的密码:");
		scanf("%ld", &mima2);
		if (mima1 == mima2)
		{
			guide1[i - 1].passw = mima1;
			k = 1;
		}
		else
			printf("请重新输入密码");
	}
	printf("输入姓名:");
	scanf("%s", guide1[i - 1].name);
	printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州\n");
	printf("输入区域代号:");
	scanf("%d", &guide1[i - 1].adress_num);
	if (guide1[i - 1].adress_num > 5 || guide1[i - 1].adress_num < 1)
	{
		printf("输入错误，请输入1~5之间的数字:");
		scanf("%d", &guide1[i - 1].adress_num);
	}
	switch (guide1[i - 1].adress_num)
	{
	case 1:
		strcpy(guide1[i - 1].adress, "镇江");
		break;
	case 2:
		strcpy(guide1[i - 1].adress, "南京");
		break;
	case 3:
		strcpy(guide1[i - 1].adress, "常州");
		break;
	case 4:
		strcpy(guide1[i - 1].adress, "无锡");
		break;
	case 5:
		strcpy(guide1[i - 1].adress, "苏州");
		break;
	}
	printf("输入家庭住址:");
	scanf("%s", guide1[i - 1].adress2);
	printf("1.金融 2.管理 3.计算机 4.工程 5.其他\n");
	printf("输入特长代号:");
	scanf("%d", &guide1[i - 1].speciality_num);
	if (guide1[i - 1].speciality_num > 5 || guide1[i - 1].speciality_num < 1)
	{
		printf("输入错误，请输入1~5之间的数字:");
		scanf("%d", &guide1[i - 1].speciality_num);
	}
	switch (guide1[i - 1].speciality_num)
	{
	case 1:
		strcpy(guide1[i - 1].speciality, "金融");
		break;
	case 2:
		strcpy(guide1[i - 1].speciality, "管理");
		break;
	case 3:
		strcpy(guide1[i - 1].speciality, "计算机");
		break;
	case 4:
		strcpy(guide1[i - 1].speciality, "工程");
		break;
	case 5:
		strcpy(guide1[i - 1].speciality, "其他");
		break;
	}
	printf("1.中专 2.大专 3.本科 4.硕士 5.博士\n");
	printf("输入学历代号:");
	scanf("%d", &guide1[i - 1].edubackground_num);
	if (guide1[i - 1].edubackground_num > 5 || guide1[i - 1].edubackground_num < 1)
	{
		printf("输入错误，请输入1~5之间的数字:");
		scanf("%d", &guide1[i - 1].edubackground_num);
	}
	switch (guide1[i - 1].edubackground_num)
	{
	case 1:
		strcpy(guide1[i - 1].edubackground, "中专");
		break;
	case 2:
		strcpy(guide1[i - 1].edubackground, "大专");
		break;
	case 3:
		strcpy(guide1[i - 1].edubackground, "本科");
		break;
	case 4:
		strcpy(guide1[i - 1].edubackground, "硕士");
		break;
	case 5:
		strcpy(guide1[i - 1].edubackground, "博士");
		break;
	}
	printf("1.男 2.女 3.其他\n");
	printf("请输入性别代号:");
	scanf("%d", &guide1[i - 1].sex_num);
	if (guide1[i - 1].sex_num > 3 || guide1[i - 1].sex_num < 1)
	{
		printf("输入错误，请输入1~3之间的数字:");
		scanf("%d", &guide1[i - 1].sex_num);
	}
	switch (guide1[i - 1].sex_num)
	{
	case 1:
		strcpy(guide1[i - 1].sex, "男");
		break;
	case 2:
		strcpy(guide1[i - 1].sex, "女");
		break;
	case 3:
		strcpy(guide1[i - 1].sex, "其他");
		break;
	}
	printf("请输入年龄:");
	scanf("%d", &guide1[i - 1].age);
	printf("请输入其他备注信息:");
	scanf("%s", guide1[i - 1].ps);
	printf("请输入联系方式:");
	scanf("%s", guide1[i - 1].tel);
	writefileTAL(guide1, i);
	printf("上传成功！\n");
	system("pause");
	system("CLS");
	title();
	return 0;
}
int uploadCOM() //上传公司数据
{
	int m, i, j, k, s, t;
	long mima1, mima2;
	i = readfileCOM(guide2);
	printf("%d", i);
	k = 0;
	printf("要上传，首先先创建账号吧!\n输入账号:");
	scanf("%ld", &guide2[i - 1].num);
	printf("输入密码:");
	while (k == 0)
	{
		scanf("%ld", &mima1);
		printf("请核对你的密码:");
		scanf("%ld", &mima2);
		if (mima1 == mima2)
		{
			guide2[i - 1].passw = mima1;
			k = 1;
		}
		else
			printf("请重新输入密码");
	}
	printf("输入公司名称:");
	scanf("%s", guide2[i - 1].company);
	printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州\n");
	printf("输入公司区域代号:");
	scanf("%d", &guide2[i - 1].adress_num);
	if (guide2[i - 1].adress_num > 5 || guide2[i - 1].adress_num < 1)
	{
		printf("输入错误，请输入1~5之间的数字:");
		scanf("%d", &guide2[i - 1].adress_num);
	}
	switch (guide2[i - 1].adress_num)
	{
	case 1:
		strcpy(guide2[i - 1].adress, "镇江");
		break;
	case 2:
		strcpy(guide2[i - 1].adress, "南京");
		break;
	case 3:
		strcpy(guide2[i - 1].adress, "常州");
		break;
	case 4:
		strcpy(guide2[i - 1].adress, "无锡");
		break;
	case 5:
		strcpy(guide2[i - 1].adress, "苏州");
		break;
	}
	printf("输入公司地址:");
	scanf("%s", guide2[i - 1].adress2);
	printf("1.金融证券 2.风险投资 3.互联网 4.软件外包 5.其他\n");
	printf("输入公司性质代号:");
	scanf("%d", &guide2[i - 1].property_num);
	if (guide2[i - 1].property_num > 5 || guide2[i - 1].property_num < 1)
	{
		printf("输入错误，请输入1~5之间的数字:");
		scanf("%d", &guide2[i - 1].property_num);
	}
	switch (guide2[i - 1].property_num)
	{
	case 1:
		strcpy(guide2[i - 1].property, "金融证券");
		break;
	case 2:
		strcpy(guide2[i - 1].property, "风险投资");
		break;
	case 3:
		strcpy(guide2[i - 1].property, "互联网");
		break;
	case 4:
		strcpy(guide2[i - 1].property, "软件外包");
		break;
	case 5:
		strcpy(guide2[i - 1].property, "其他");
		break;
	}
	printf("1.中专 2.大专 3.本科 4.硕士 5.博士\n");
	printf("请输入对于学历的要求(输入代号):");
	scanf("%d", &guide2[i - 1].background_num);
	if (guide2[i - 1].property_num > 5 || guide2[i - 1].property_num < 1)
	{
		printf("输入错误，请输入1~5之间的数字:");
		scanf("%d", &guide2[i - 1].background_num);
	}
	switch (guide2[i - 1].background_num)
	{
	case 1:
		strcpy(guide2[i - 1].background, "中专");
		break;
	case 2:
		strcpy(guide2[i - 1].background, "大专");
		break;
	case 3:
		strcpy(guide2[i - 1].background, "本科");
		break;
	case 4:
		strcpy(guide2[i - 1].background, "硕士");
		break;
	case 5:
		strcpy(guide2[i - 1].background, "博士");
		break;
	}
	printf("请输入对于性别的要求:");
	scanf("%s", guide2[i - 1].sex);
	printf("请输入对于年龄的要求:");
	scanf("%s", guide2[i - 1].age_limit);
	printf("请输入其他备注信息:");
	scanf("%s", guide2[i - 1].ps);
	printf("请输入联系人:");
	scanf("%s", guide2[i - 1].person);
	printf("请输入联系方式:");
	scanf("%s", guide2[i - 1].tel);
	writefileCOM(guide2, i);
	printf("上传成功！\n");
	system("pause");
	system("CLS");
	title();
	return 0;
}
int checkTALnum(long num) //验证账号的正确性函数
{
	int i;
	i = readfileTAL(guide1);
	for (n = 1; n < i; n++)
	{
		if (num == guide1[n].num)
			return 1;
	}
	return 0;
}
int checkTALpassw(long passw) //验证密码的正确性函数
{
	if (passw == guide1[n].passw)
		return 1;
	return 0;
}
int checkCOMnum(long num) //验证企业账号
{
	int i;
	i = readfileCOM(guide2);
	for (n = 1; n < i; n++)
	{
		if (num == guide2[n].num)
			return 1;
	}
	return 0;
}
int checkCOMpassw(long passw) //验证企业账号密码
{
	if (passw == guide2[n].passw)
		return 1;
	return 0;
}
int printTAL(int i) //打印出搜索结果的函数（人才）
{
	printf("++++++++++++++++++++++++<-京口瓜洲一水间->++++++++++++++++++++++++++++++\n");
	printf("账号:%ld    姓名:%s    性别:%s    年龄:%d\n", guide1[i].num, guide1[i].name, guide1[i].sex, guide1[i].age);
	printf("特长:%s    学历:%s    所在地:%s\n", guide1[i].speciality, guide1[i].edubackground, guide1[i].adress);
	printf("家庭地址:%s    联系方式:%s\n", guide1[i].adress2, guide1[i].tel);
	printf("PS:%s\n", guide1[i].ps);
	printf("++++++++++++++++++++++++<-钟山只隔数重山->++++++++++++++++++++++++++++++\n");
	return 0;
}
int printCOM(int i) //打印出搜索结果的函数（公司）
{
	printf("++++++++++++++++++++++++++<-何处望神州->++++++++++++++++++++++++++++++\n");
	printf("账号:%ld    公司:%s    属性:%s    所在地:%s\n", guide2[i].num, guide2[i].company, guide2[i].property, guide2[i].adress);
	printf("性别要求:%s    学历要求:%s    年龄要求:%s\n", guide2[i].sex, guide2[i].background, guide2[i].age_limit);
	printf("联系人:%s    联系方式:%s\n", guide2[i].person, guide2[i].tel);
	printf("地址:%s    PS:%s\n", guide2[i].adress2, guide2[i].ps);
	printf("++++++++++++++++++++++++<-满眼风光北固楼->++++++++++++++++++++++++++++++\n");
	return 0;
}
int changeTALdata() //更改人才数据函数
{
	long num, passw;
	int i, k = 0, j = 0, t;
	printf("请输入个人账号:");
	for (i = 0; i < 3; i++)
	{
		scanf("%ld", &num);
		if (checkTALnum(num) == 1)
		{
			break;
			k++;
		}
		else
		{
			if (i != 2)
				printf("您输入的的账号不存在，请重新输入,您还有%d次机会输入\n", 2 - i);
			else
				printf("看来你是忘记了你的账号了，重新相互侧一个吧!\n");
		}
	}
	printf("请输入密码（您有三次输入机会）:");
	for (i = 0; i < 3; i++)
	{
		scanf("%ld", &passw);
		if (checkTALpassw(passw) == 1)
		{
			break;
			k++;
		}
		else
		{
			if (i != 2)
				printf("密码输入错误，请再次输入，您还有%d次输入机会", 2 - i);
			else if (i == 2)
				printf("您的账号存在问题，请一个小时之后在重新登录\n");
		}
	}
	t = readfileTAL(guide1);
	if (k == 2)
		printf("登录成功!\n");
	printTAL(n);
	printf("1.姓名 2.性别 3.年龄 4.特长 5.学历 6.所在地 7.家庭地址 8.联系方式 9.PS 10.修改完毕\n");
	while (j != 10)
	{
		scanf("%d", &j);
		if (j > 10 || j < 1)
			printf("%d", &j);
		switch (j)
		{
		case 1:
			scanf("%s", guide1[n].name);
			break;
		case 2:
			scanf("%s", guide1[n].sex);
			break;
		case 3:
			scanf("%d", &guide1[n].age);
			break;
		case 4:
			scanf("%s", guide1[n].speciality);
			break;
		case 5:
			scanf("%s", guide1[n].edubackground);
			break;
		case 6:
			scanf("%s", guide1[n].adress);
			break;
		case 7:
			scanf("%s", guide1[n].adress2);
			break;
		case 8:
			scanf("%s", guide1[n].tel);
			break;
		case 9:
			scanf("%s", guide1[n].ps);
			break;
		}
	}
	TAL = fopen("c:\\Talents.txt", "w");
	for (i = 1; i < t; i++)
	{
		fprintf(TAL, "%ld %ld %s %d %s %s %d %s %d %s %d %s %d %s %s\n", guide1[i].num, guide1[i].passw, guide1[i].name,
				guide1[i].adress_num, guide1[i].adress, guide1[i].adress2, guide1[i].speciality_num, guide1[i].speciality,
				guide1[i].edubackground_num, guide1[i].edubackground, guide1[i].sex_num, guide1[i].sex, guide1[i].age,
				guide1[i].ps, guide1[i].tel);
	}
	fclose(TAL);
	printf("修改成功!\n");
	system("pause");
	system("CLS");
	title();
	return 0;
}
int changeCOMdata() //更改公司数据的函数
{
	long num, passw;
	int i, k = 0, j = 0, t;
	printf("请输入企业账号:");
	for (i = 0; i < 3; i++)
	{
		scanf("%ld", &num);
		if (checkCOMnum(num) == 1)
		{
			break;
			k++;
		}
		else
		{
			if (i != 2)
				printf("您输入的的账号不存在，请重新输入,您还有%d次机会输入\n", 2 - i);
			else
				printf("看来你是忘记了你的账号了，重新相互侧一个吧!\n");
		}
	}
	printf("请输入密码（您有三次输入机会）:");
	for (i = 0; i < 3; i++)
	{
		scanf("%ld", &passw);
		if (checkCOMpassw(passw) == 1)
		{
			break;
			k++;
		}
		else
		{
			if (i != 2)
				printf("密码输入错误，请再次输入，您还有%d次输入机会", 2 - i);
			else if (i == 2)
				printf("您的账号存在问题，请一个小时之后在重新登录\n");
		}
	}
	t = readfileCOM(guide2);
	if (k == 2)
		printf("登录成功!\n");
	printCOM(n);
	printf("1.公司名称 2.性别限制 3.年龄限制 4.公司性质 5.学历要求 6.所在地 7.公司地址 8.联系方式 9.PS 10.联系人 11.修改完毕\n");
	while (j != 11)
	{
		scanf("%d", &j);
		if (j > 11 || j < 1)
			printf("%d", &j);
		switch (j)
		{
		case 1:
			scanf("%s", guide2[n].company);
			break;
		case 2:
			scanf("%s", guide2[n].sex);
			break;
		case 3:
			scanf("%d", &guide2[n].age_limit);
			break;
		case 4:
			scanf("%s", guide2[n].property);
			break;
		case 5:
			scanf("%s", guide2[n].background);
			break;
		case 6:
			scanf("%s", guide2[n].adress);
			break;
		case 7:
			scanf("%s", guide2[n].adress2);
			break;
		case 8:
			scanf("%s", guide2[n].tel);
			break;
		case 9:
			scanf("%s", guide2[n].ps);
			break;
		case 10:
			scanf("%s", guide2[n].person);
			break;
		}
	}
	COM = fopen("c:\\Companies.txt", "w");
	for (i = 1; i < t; i++)
	{
		fprintf(COM, "%ld %ld %s %d %s %s %d %s %d %s %s %s %s %s %s\n", guide2[i].num, guide2[i].passw, guide2[i].company,
				guide2[i].adress_num, guide2[i].adress, guide2[i].adress2, guide2[i].property_num, guide2[i].property,
				guide2[i].background_num, guide2[i].background, guide2[i].sex, guide2[i].age_limit, guide2[i].ps,
				guide2[i].person, guide2[i].tel);
	}
	fclose(COM);
	printf("修改成功!\n");
	system("pause");
	system("CLS");
	title();
	return 0;
}
int searchTAL() //搜索人才的函数
{
	int i, j, t, k, count;
	char place[10];
	k = readfileTAL(guide1);
	count = 0;
	j = 0;
	i = 0;
	printf("1.地区 2.特长 3.学历 4.离开\n");
	printf("需要那种类型的人才:");
	while (i != 4)
	{
		scanf("%d", &i);
		if (i > 4 || i < 1)
		{
			printf("请输入1~4:");
			scanf("%d", &i);
		}
		switch (i)
		{
		case 1:
			printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州 6.离开\n");
			printf("输入区域代号:");
			j = 0;
			while (j != 6)
			{
				count = 0;
				j = 0;
				scanf("%d", &j);
				if (j > 6 || j < 1)
				{
					printf("请输入1~6:");
					scanf("%d", &j);
				}
				switch (j)
				{
				case 1:
					strcpy(place, "镇江");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].adress) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 2:
					strcpy(place, "南京");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].adress) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 3:
					strcpy(place, "常州");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].adress) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 4:
					strcpy(place, "无锡");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].adress) == 0)
						{
							printTAL(t);
							count++;
						};
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 5:
					strcpy(place, "苏州");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].adress) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 6:
					break;
				}
			}
			system("pause");
			system("CLS");
			printf("1.地区 2.特长 3.学历 4.离开\n");
			printf("需要那种类型的人才:");
			break;
		case 2:
			printf("1.金融 2.管理 3.计算机 4.工程 5.其他 6.离开\n");
			printf("请输入特长代号:");
			j = 0;
			while (j != 6)
			{
				j = 0;
				count = 0;
				scanf("%d", &j);
				if (j > 6 || j < 1)
				{
					printf("请输入1~6:");
					scanf("%d", &j);
				}
				switch (j)
				{
				case 1:
					strcpy(place, "金融");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].speciality) == 0)
						{
							printTAL(t);
							count++;
						};
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 2:
					strcpy(place, "管理");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].speciality) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 3:
					strcpy(place, "计算机");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].speciality) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 4:
					strcpy(place, "工程");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].speciality) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 5:
					strcpy(place, "其他");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].speciality) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 6:
					break;
				}
			}
			system("pause");
			system("CLS");
			printf("1.地区 2.特长 3.学历 4.离开\n");
			printf("需要那种类型的人才:");
			break;
		case 3:
			printf("1.中专 2.大专 3.本科 4.硕士 5.博士 6.离开\n");
			printf("请输入学历代号:");
			j = 0;
			while (j != 6)
			{
				j = 0;
				count = 0;
				scanf("%d", &j);
				if (j > 6 || j < 1)
				{
					printf("请输入1~6:");
					scanf("%d", &j);
				}
				switch (j)
				{
				case 1:
					strcpy(place, "中专");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].edubackground) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 2:
					strcpy(place, "大专");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].edubackground) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 3:
					strcpy(place, "本科");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].edubackground) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 4:
					strcpy(place, "硕士");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].edubackground) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				case 5:
					strcpy(place, "博士");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide1[t].edubackground) == 0)
						{
							printTAL(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的人才->_->\n");
					else
						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
					break;
				}
			}
			system("pause");
			system("CLS");
			printf("1.地区 2.特长 3.学历 4.离开\n");
			printf("需要那种类型的人才:");
			break;
		case 4:
			break;
		}
	}
	system("pause");
	system("CLS");
	title();
	return 0;
}
int searchCOM() //搜索公司的函数
{
	int i, j, t, k, count;
	char place[10];
	k = readfileCOM(guide2);
	count = 0;
	j = 0;
	i = 0;
	printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
	printf("输入需要检索的公司的第一关键词代号:");
	while (i != 4)
	{
		scanf("%d", &i);
		if (i > 4 || i < 1)
		{
			printf("请输入1~4:");
			scanf("%d", &i);
		}
		switch (i)
		{
		case 1:
			printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州 6.离开\n");
			printf("输入公司区域代号:");
			j = 0;
			while (j != 6)
			{
				count = 0;
				j = 0;
				scanf("%d", &j);
				if (j > 6 || j < 1)
				{
					printf("请输入1~6:");
					scanf("%d", &j);
				}
				switch (j)
				{
				case 1:
					strcpy(place, "镇江");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].adress) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 2:
					strcpy(place, "南京");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].adress) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 3:
					strcpy(place, "常州");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].adress) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 4:
					strcpy(place, "无锡");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].adress) == 0)
						{
							printCOM(t);
							count++;
						};
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 5:
					strcpy(place, "苏州");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].adress) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 6:
					break;
				}
			}
			system("pause");
			system("CLS");
			printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
			printf("输入需要检索的公司的第一关键词代号:");
			break;
		case 2:
			printf("1.金融证券 2.风险投资 3.互联网 4.软件外包 5.其他 6.离开\n");
			printf("请输入公司性质代号:");
			j = 0;
			while (j != 6)
			{
				j = 0;
				count = 0;
				scanf("%d", &j);
				if (j > 6 || j < 1)
				{
					printf("请输入1~6:");
					scanf("%d", &j);
				}
				switch (j)
				{
				case 1:
					strcpy(place, "金融证券");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].property) == 0)
						{
							printCOM(t);
							count++;
						};
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 2:
					strcpy(place, "风险投资");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].property) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 3:
					strcpy(place, "互联网");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].property) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 4:
					strcpy(place, "软件外包");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].property) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 5:
					strcpy(place, "其他");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].property) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 6:
					break;
				}
			}
			system("pause");
			system("CLS");
			printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
			printf("输入需要检索的公司的第一关键词代号:");
			break;
		case 3:
			printf("1.中专 2.大专 3.本科 4.硕士 5.博士 6.离开\n");
			printf("请输入学历代号:");
			j = 0;
			while (j != 6)
			{
				j = 0;
				count = 0;
				scanf("%d", &j);
				if (j > 6 || j < 1)
				{
					printf("请输入1~6:");
					scanf("%d", &j);
				}
				switch (j)
				{
				case 1:
					strcpy(place, "中专");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].background) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 2:
					strcpy(place, "大专");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].background) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 3:
					strcpy(place, "本科");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].background) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 4:
					strcpy(place, "硕士");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].background) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				case 5:
					strcpy(place, "博士");
					for (t = 1; t < k; t++)
					{
						if (strcmp(place, guide2[t].background) == 0)
						{
							printCOM(t);
							count++;
						}
					}
					if (count == 0)
						printf("没有检索到您需要的公司->_->\n");
					else
						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
					break;
				}
			}
			system("pause");
			system("CLS");
			printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
			printf("输入需要检索的公司的第一关键词代号:");
			break;
		case 4:
			break;
		}
	}
	system("pause");
	system("CLS");
	title();
	return 0;
}
int main()
{
	int m = 0;
	title();
	while (m != 8)
	{
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			uploadTAL();
			break;
		case 2:
			uploadCOM();
			break;
		case 3:
			changeTALdata();
			break;
		case 4:
			changeCOMdata();
			break;
		case 6:
			searchCOM();
			break;
		case 5:
			searchTAL();
			break;
		case 7:
			contactUs();
			break;
		case 8:
			break;
		}
	}
	system("pause");
	return 0;
}