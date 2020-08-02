//搜索树的操作
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//#define null 0
//using namespace std;
//struct treenode
//{
//	int data;
//	treenode *lchild;
//	treenode *rchild;
//};
//treenode *creat()//先序创建树
//{
//	int ch;
//	treenode *t = null;
//	scanf("%d", &ch);
//	if (ch == -1)
//	{
//		t = null;
//	}
//	else
//	{
//		t = (treenode *)malloc(sizeof(treenode));
//		t->data = ch;
//		t->lchild = creat();
//		t->rchild = creat();
//	}
//	return t;
//}
//treenode *findd(int x, treenode *bt)//递归查找元素
//{
//	if (!bt)
//		return null;
//	if (x > bt->data)
//		return findd(x, bt->rchild);
//	else
//		if (x < bt->data)
//			return findd(x, bt->lchild);
//		else
//			return bt;
//}
//treenode *findf(int x, treenode *bt)//非递归查找元素
//{
//	while (bt)
//	{
//		if (x>bt->data)
//			bt = bt->rchild;
//		else
//			if (x < bt->data)
//				bt = bt->lchild;
//			else
//				return bt;
//	}
//	return null;
//}
//treenode *findmind(treenode *bt)
//{
//	if (!bt)
//		return null;
//	else
//		if (!bt->lchild)
//			return  bt;
//		else
//			return findmind(bt->lchild);
//}
//treenode *findmaxd(treenode *bt)
//{
//	if (!bt)
//		return null;
//	else
//		if (!bt->rchild)
//			return  bt;
//		else
//			return findmaxd(bt->rchild);
//}
//treenode *findminf(treenode *bt)
//{
//	if (!bt)
//		return null;
//	while (bt->lchild)
//		bt = bt->lchild;
//	return bt;
//}
//treenode *findmaxf(treenode *bt)
//{
//	if (!bt)
//		return null;
//	while (bt->rchild)
//		bt = bt->rchild;
//	return bt;
//}
//treenode *insert(treenode *bt, int x)//插入元素
//{
//	if (!bt)
//	{
//		bt = (treenode*)malloc(sizeof(treenode));
//		bt->data = x;
//		bt->lchild = bt->rchild = null;
//	}
//	else
//	{
//		if (x < bt->data)
//			bt->lchild = insert(bt->lchild, x);
//		else if (x > bt->data)
//			bt->rchild = insert(bt->rchild, x);
//		else
//			cout << "x元素已经存在" << endl;
//	}
//	return bt;
//}
//int DeleteQ(treenode *bt, int x)//删除节点
//{
//	treenode *t1, *T, *tmp, *pre;
//	if (bt == null)
//		cout << "空的搜索树!" << endl;
//	while (bt)
//	{
//		if (x > bt->data)
//		{
//			pre = bt;
//			bt = bt->rchild;
//		}
//		else
//			if (x < bt->data)
//			{
//			pre = bt;
//			bt = bt->lchild;
//			}
//			else
//			{
//				T = bt;//找到要删除的对象
//				break;
//			}
//	}
//	if (bt == null)
//		cout << "没有找到要删除的对象!" << endl;
//	else if (T->lchild&&T->rchild)//两个孩子都有
//	{
//
//		t1 = T->lchild;//被删除节点两个孩子都有，在他左子树中挑一个最大的或者在右子树中挑最小的，我选择了第一个方案
//		if (!t1->lchild&&!t1->rchild)//左子树只有根节点
//		{
//			T->data = t1->data;
//			T->lchild = null;
//			free(t1);
//		}
//		else if (!t1->rchild)//左子树根节点没有右孩子
//		{
//			T->data = t1->data;
//			T->lchild = t1->lchild;
//			free(t1);
//		}
//		else
//		{
//			while (t1->rchild)//t就是左子树的根节点
//			{
//				pre = t1;//记录最大左孩子的parent,在寻找对象时，pre已经被赋值，当此时的左子树只有一个根节点时，这个
//				t1 = t1->rchild;//while循环没有执行
//			}
//			T->data = t1->data;//找到左子树最大值，将其覆盖要删除的节点
//			if (t1->lchild)//判断左子树中最大的孩子是否有左孩子（它一定没有右孩子，有的话他就不是最大的了）
//				pre->rchild = t1->lchild;
//			else
//				pre->rchild = null;
//			free(t1);
//		}
//	}
//	else if (T->lchild || T->rchild)//要删除的节点只有一个孩子,这个“或“的条件范围比较广，要放在&&后面，不然总是执行这一步
//	{
//		if (T->lchild)//存在左子树
//		{
//			if (T->data>pre->data)//判断被删除的节点是左孩子还是右
//				pre->rchild = T->lchild;
//			else
//				pre->lchild = T->lchild;
//		}
//		else//存在右子树
//		{
//			if (T->data > pre->data)
//				pre->rchild = T->rchild;
//			else
//				pre->lchild = T->rchild;
//		}
//		free(T);
//	}
//	else//一个孩子都没有
//	{
//		if (T->data > pre->data)//pre是被删除节点的parent
//			pre->rchild = null;
//		else
//			pre->lchild = null;
//		free(T);
//	}
//	return 0;
//}
//int inorder(treenode *t)//中序遍历
//{
//	if (t)
//	{
//		inorder(t->lchild);
//		printf("%d ", t->data);
//		inorder(t->rchild);
//	}
//	return 0;
//}
//void title()//菜单
//{
//	cout << "1.递归查找元素" << endl << "2.非递归查找元素" << endl << "3.查找最大元素(非递归)" << endl;
//	cout << "4.查找最小元素（非递归）" << endl << "5.查找最大元素（递归）" << endl << "6.查找最小元素（递归）" << endl;
//	cout << "7.插入元素" << endl << "8.删除元素" << endl << "9.退出" << endl;;
//}
//int main()
//{
//	treenode *t1, *T, *t2;
//	int element, i, x;
//	cout << "请创建树:" << endl;
//	t1 = T = creat();
//	title();
//	while (cin >> i&&i != 9)
//	{
//		switch (i)
//		{
//		case 1:cout << "请输入要查找的元素:";
//			cin >> element;
//			t2 = findd(element, T);
//			if (t2 == null)
//				cout << "没有找到" << endl;
//			else
//				cout << t2->data << endl;
//			break;
//		case 2:cout << "请输入要查找的元素:";
//			cin >> element;
//			t2 = findf(element, T);
//			if (t2 == null)
//				cout << "没有找到" << endl;
//			else
//				cout << t2->data << endl;
//			break;
//		case 3:t2 = findmaxf(T);
//			if (t2 == null)
//				cout << "搜索树为空" << endl;
//			else
//				cout << t2->data << endl;
//			break;
//		case 4:t2 = findminf(T);
//			if (t2 == null)
//				cout << "搜索树为空" << endl;
//			else
//				cout << t2->data << endl;
//			break;
//		case 5:t2 = findmaxd(T);
//			if (t2 == null)
//				cout << "搜索树为空" << endl;
//			else
//				cout << t2->data << endl;
//			break;
//		case 6:t2 = findmind(T);
//			if (t2 == null)
//				cout << "搜索树为空" << endl;
//			else
//				cout << t2->data << endl;
//			break;
//		case 7:cout << "请输入要插入的数:";
//			cin >> x;
//			insert(T, x);
//			cout << "中序遍历:";
//			inorder(T);
//			cout << endl;
//			break;
//		case 8:cout << "请输入要删除的元素:";
//			cin >> x;
//			DeleteQ(T, x);
//			cout << "中序遍历:";
//			inorder(t1);
//			cout << endl;
//		default: break;
//		}
//		system("pause");
//		system("cls");
//
//		title();
//	}
//	system("pause");
//	return 0;
//}
//搜索树的操作
//have fun with number
//#include<iostream>
//#include<windows.h>
//#include<stdlib.h>
//#include<malloc.h>
//#define NULL 0
//using namespace std;
//struct result//双向链表
//{
//	int data;
//	result *next;
//	result *previous;
//};
//result  *cal(char A[], char B[])//调用大数相加函数
//{
//	int flag = 0;
//	result *p1, *p2;
//	p1 = p2 = NULL;//初始化
//	int  i, j, z, Z, cha, k, jin;//Z是最大的字符串长度
//	jin = 0;//进位专用存储
//		Z = strlen(A);//将最长字符串的大小赋值Z
//		for (i = Z - 1; i >= 0; i--)//大数相加要从各位开始相加，字符数组最末尾的就是个位数
//		{
//			if (i == Z - 1)//个位数的时候
//			{
//				p1 = (result *)malloc(sizeof(result));//开拓空间
//				p1->data = ((A[i] - '0') + (B[i] - '0') + jin) % 10;//同位相加除余10的到的数留在该位
//				jin = ((A[i] - '0') + (B[i] - '0')) / 10;//进位的大小，加法运算最大就是1
//				p2 = p1;
//				p1->previous = NULL;//双向链表的头结点的previous要赋值NULL
//			}
//			else
//			{
//				p1 = (result *)malloc(sizeof(result));
//				p1->data = ((A[i] - '0') + (B[i] - '0') + jin) % 10;
//				jin = ((A[i] - '0') + (B[i] - '0')) / 10;
//				p2->next = p1;//构造双向链表的过程
//				p1->previous = p2;
//				p2 = p1;
//			}
//		}
//		if (jin != 0)//最大位最后的相加可能需要进位，因为加法结果最多比最大被加数多一位
//		{
//			p1 = (result *)malloc(sizeof(result));
//			p1->data = jin;
//			p1->previous = p2;
//			p2->next = p1;
//			p1->next = NULL;//结束后双向链表的尾节点指向NULL
//		}
//		else
//		{
//			p1->next = NULL;//没有进位直接赋值NULL
//		}
//	return p1;
//}
//int main()
//{
//	char a[20];
//	int b[20];
//	int count[10] = { 0 },count1[10] = { 0 };
//	int i, j, k, t, flag = 0;
//	result *T;
//	cin >> a;
//	T = cal(a, a);
//	i = 0;
//	while (T != NULL)
//	{
//		b[i] = T->data;
//		T = T->previous;
//		i++;
//	}
//	t = i;//b数组的长度
//	for (k = 0; k < strlen(a); k++)//求起始数组里面的不同的数
//	{
//		for (j = 0; j <= 9; j++)
//			if (a[k] - '0' == j)
//				count[j]++ ;//标记原有数组中的数,自然数j被标记1
//	}	
//	for (j = 0; j < t; j++)//标记double之后的数组数字出现的次数
//	{
//		for (k = 0; k <=9; k++)
//		{
//			if (b[j] == k)
//			{
//				count1[k]++;
//			}
//		}
//	}
//	for (i = 0; i <= 9; i++)
//	{
//		if (count[i] != count1[i])//如果a与b对应的数字出现的频率不一致，那就是NO
//		{
//			cout << "No" << endl;
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//		cout << "Yes" << endl;
//	for (i = 0; i < t; i++)
//		cout << b[i];
//	cout << endl;
//	system("pause");
//	return 0;
//}
//have fun with number
//层序创建树
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//#define null 0
//#define maxsize 100
//using namespace std;
//struct treenode
//{
//	char data;
//	treenode *lchild;
//	treenode *rchild;
//};
//struct queue
//{
//	int rear;
//	int front;
//	treenode *data[maxsize];
//};
//int addq(treenode *bt, queue &q)
//{
//	if ((q.rear + 1) % maxsize == q.front)
//	{
//		cout << "队列已满" << endl;
//		return error;
//	}
//	q.data[q.rear] = bt;
//	q.rear = (q.rear + 1) % maxsize;
//	return 0;
//}
//treenode *deleteq(queue &q)
//{
//	if (q.front == q.rear)
//	{
//		cout << "队列为空" << endl;
//		return 0;
//	}
//	treenode *t;
//	t = q.data[q.front];
//	q.front = (q.front + 1) % maxsize;
//	return t;
//}
//treenode *levelcreatetree()
//{
//	treenode *bt,*t;
//	queue q;
//	char ch;
//	q.rear = q.front = 0;
//	bt = (treenode *)malloc(sizeof(treenode));
//	cin >> bt->data;
//	addq(bt, q);
//	while (q.rear != q.front)
//	{
//		t = deleteq(q);
//		cin >> ch;
//		if (ch != '#')
//		{
//			t->lchild = (treenode *)malloc(sizeof(treenode));
//			t->lchild->data = ch;
//			addq(t->lchild, q);
//		}
//		else
//			t->lchild = null;
//		
//		cin >> ch;
//		if (ch != '#')
//		{
//			t->rchild = (treenode *)malloc(sizeof(treenode));
//			t->rchild->data = ch;
//			addq(t->rchild, q);
//		}
//		else
//			t->rchild = null;
//		
//	}
//	return bt;
//}
//int preorder(treenode *t)//先序遍历
//{
//	if (t)
//	{
//		cout << t->data;
//		preorder(t->lchild);
//		preorder(t->rchild);
//	}
//	return 0;
//}
//int main()
//{
//	treenode *bt;
//	bt = levelcreatetree();
//	preorder(bt);
//	cout << endl;
//	system("pause");
//	return 0;
//}
//层序创建树
//树的高度和叶节点输出
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//#define null 0
//using namespace std;
//struct treenode
//{
//	char data;
//	treenode *lchild;
//	treenode *rchild;
//};
//treenode *createtree()
//{
//	treenode *t=null;
//	char t;
//	cin >> t;
//	if (t == '#')
//		t = null;
//	else
//	{
//		t = (treenode *)malloc(sizeof(treenode));
//		t->data = t;
//		t->lchild = createtree();
//		t->rchild = createtree();
//	}
//	return t;
//}
//void pfleaves(treenode *t)//打印叶节点
//{
//	if (t)
//	{
//		if (t->lchild == null&&t->rchild == null)
//			cout << t->data;
//		pfleaves(t->lchild);
//		pfleaves(t->rchild);
//	}
//}
//int getheight(treenode *t)
//{
//	int hl, hr, maxh;
//	if (t)
//	{
//		hl = getheight(t->lchild);
//		hr = getheight(t->rchild);
//		maxh = hl > hr ? hl : hr;
//		return maxh + 1;
//	}
//	else return 0;
//}
//int main()
//{
//	treenode *bt=null;
//	bt = createtree();
//	pfleaves(bt);
//	cout << endl;
//	cout << getheight(bt);
//	cout << endl;
//	system("pause");
//	return 0;
//}
//树的高度和叶节点输出
//队列的链式存储
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//#define null 0
//using namespace std;
//struct qnode//链表节点
//{
//	int data;
//	qnode *next;
//};
//struct queue//队列
//{
//	qnode *rear;
//	qnode *front;
//};
//void addq(queue &q)//增加数据的函数
//{
//	qnode *d=null;
//	d = (qnode*)malloc(sizeof(qnode));
//	cout << "请输入数据:";
//	cin >> d->data;
//	if (q.front==null)//如果队列空
//		q.rear = q.front = d;//队头队尾的地址都等于第一个值的地址，也就是让队头当链式队列的头指针
//	else
//	{
//		q.rear->next = d;//作为队尾节点，需要增加节点从队尾插入
//		q.rear = q.rear->next;
//	}
//	q.rear->next = null;//将队尾节点的next置null
//}
//int deleteq(queue&q)//删除数据的函数
//{
//	qnode *p;
//	int z;
//	if (q.front==null)
//	{
//		cout << "链队列为空!" << endl;
//		return error;
//	}
//	if (q.front == q.rear)
//	{
//		q.front = q.rear = null;
//		cout << "链队列为空!" << endl;
//	}
//	else 
//	{
//		p = q.front;
//		z = p->data;
//		q.front = q.front->next;
//		free(p);//释放被删除节点的内存
//		return z;//返回被删除节点的数据，有需要就调用
//	}
//	return 0;
//}
//int printq(qnode *p)//打印队列的函数
//{
//	qnode *e;
//	e = p;
//	if (e == null)//队列为空停止打印
//		return error;
//	cout << "队列为:";
//	while (e != null)
//	{
//		cout << e->data << " ";
//		e = e->next;
//	}
//	cout << endl;
//}
//void initialize(queue &q)//初始化对头队尾节点
//{
//	q.front = q.rear=null;
//}
//int main()
//{
//	queue q;
//	int i;
//	initialize(q);
//	cout << "1.增加数据" << endl << "2.删除数据" << endl << "3.退出" << endl;
//	while (cin >> i)
//	{
//		switch (i)
//		{
//		case 1:addq(q);
//			printq(q.front);
//			break;
//		case 2:deleteq(q);
//			printq(q.front);
//			break;
//		default:cout << "请输入1~3" << endl;
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}
//队列的链式存储
//队列的创建与操作
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//#define maxsize 10
//#define null 0
//using namespace std;
//struct queue
//{
//	int rear;
//	int front;
//	int data[maxsize];
//};
//int isempty(queue *q)//判空
//{
//	if (q->front == q->rear)
//		return 1;
//	return 0;
//}
//int isfull(queue *q)//判满
//{
//	if ((q->rear + 1) % maxsize == q->front)
//		return 1;
//	return 0;
//}
//void addq(queue *q,int item)
//{
//	if (isfull(q) == 1)
//	{
//		cout << "队列空间已满!\n" << endl;
//		return;
//	}
//	q->data[q->rear] = item;
//	q->rear = (q->rear + 1) % maxsize;
//}
//int deleteq(queue *q)
//{	
//	if (isempty(q) == 1)
//	{
//		cout << "队列为空" << endl;
//		return error;
//	}
//	q->front = (q->front + 1) % maxsize;
//	return q->data[q->front];
//}
//void printq(queue *q)
//{
//	int i;
//	
//	if (q->rear > q->front)
//	{
//		cout << "队列元素:";
//		for (i = q->front; i < q->rear; i++)
//			cout << q->data[i] << " ";
//	}
//	else if (q->rear == q->front)
//		cout << "队列为空";
//	else
//	{
//		cout << "队列元素:";
//		for (i = q->front; i < maxsize; i++)
//			cout << q->data[i]<<" ";
//		for (i = 0; i < q->rear; i++)
//			cout << q->data[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	queue *q=null;
//	int item,i,j;
//	q = (queue*)malloc(sizeof(queue));
//	q->rear = q->front =0;
//	cout << "1.增加数据" << endl << "2.删除数据" << endl << "3.退出" << endl;
//	while (cin >> i&&i!=3)
//	{
//		switch (i)
//		{
//		case 1:cin >> item;
//			addq(q, item);
//			printq(q);
//			break;
//		case 2:
//			deleteq(q);//该函数返回了队列的头数据，必要时可以调用
//			printq(q);
//			break;
//		default:cout << "请输入1~3!" << endl;
//			break;
//
//		}
//	}
//	system("pause");
//	return 0;
//}
//队列的创建与操作
//树的非递归遍历
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//using namespace std;
//#define null 0
//#define maxsize 100
//struct treenode//树的节点
//{
//	int data;
//	treenode *lchild;
//	treenode *rchild;
//};
//struct stack//用来存储结点指针地址的堆栈
//{
//	treenode *data[maxsize];
//	int top;
//};
//treenode *createtree()//先序创建树
//{
//	int ch;
//	treenode *t = null;
//	scanf("%d", &ch);
//	if (ch == -1)
//	{
//		t = null;
//	}
//	else
//	{
//		t = (treenode *)malloc(sizeof(treenode));
//		t->data = ch;
//		t->lchild = createtree();
//		t->rchild = createtree();
//	}
//	return t;
//}
//int isempty(stack *s)//判空栈
//{
//	if (s->top == -1)
//		return 1;
//	return 0;
//}
//void push(stack *s, treenode *t)//推入栈
//{
//	if (s->top == maxsize-1)
//		printf("堆栈已满\n");
//	else
//		s->data[++(s->top)] = t;
//}
//treenode *pop(stack *s)//出栈
//{
//	if (s->top == -1)
//	{
//		printf("堆栈为空\n");
//		system("pause");
//		exit(0);
//	}
//	return (s->data[s->top--]);
//}
//void inorder(treenode *bt)//中序遍历
//{
//	treenode *t;
//	struct stack *s;
//	s = (stack *)malloc(sizeof(stack));
//	s->top = -1;
//	t = null;
//	t = bt;
//	while (t || !isempty(s))
//	{
//		while (t)
//		{
//			push(s, t);
//			t = t->lchild;
//		}
//		t = null;
//		if (!isempty(s))
//		{
//			t = pop(s);
//			printf("%d", t->data);
//			t = t->rchild;
//		}
//		
//	}
//}
//void preorder(treenode *bt)//先序遍历
//{
//	treenode *t;
//	struct stack *s;
//	s = (stack *)malloc(sizeof(stack));
//	s->top = -1;
//	t = null;
//	t = bt;
//	while (t || !isempty(s))
//	{
//		while (t)
//		{
//			push(s, t);
//			printf("%d", t->data);
//			t = t->lchild;
//		}
//		t = null;
//		if (!isempty(s))
//		{
//			t = pop(s);
//			t = t->rchild;
//		}
//
//	}
//}
//void postorder(treenode *bt)//后序遍历
//{
//	treenode *t;
//	struct stack *s;
//	s = (stack *)malloc(sizeof(stack));
//	s->top = -1;
//	t = null;
//	int flag[20] ;
//	t = bt;
//	while (t || !isempty(s))
//	{
//		while (t)
//		{
//			push(s, t);
//			t = t->lchild;
//			flag[s->top] = 0;
//		}
//		while (!isempty(s) && flag[s->top] == 1)//从右孩子回来才能进行输出操作
//		{
//			t = pop(s);
//			printf("%d", t->data);
//		}
//	    if(!isempty(s))
//		{
//			flag[s->top] = 1;
//			t = s->data[s->top];
//			t = t->rchild;
//			
//		}
//		else break;
//	}
//}
//struct queue//队列
//{
//	int rear;
//	int front;
//	treenode *data[maxsize];
//};
//int addq(treenode *bt, queue &q)//入队
//{
//	q.data[q.rear] = bt;
//	q.rear = (q.rear + 1) % maxsize;
//	if (q.rear == q.front)
//	{
//		cout << "队列已满" << endl;
//		return error;
//	}
//	return 0;
//}
//treenode *deleteq(queue &q)//出队，并返回出队的元素
//{
//	treenode *t;
//	if (q.front == q.rear)
//	{
//		cout << "队列为空" << endl;
//		return error;
//	}
//	t = q.data[q.front];
//	q.front = (q.front + 1) % maxsize;
//	return t;
//}
//void levelorder(treenode *bt)//层序遍历
//{
//	queue q;
//	treenode *t;
//	if (!bt)
//		return;
//	q.rear = q.front = 0;
//	addq(bt, q);
//	while (q.rear != q.front)
//	{
//		t = deleteq(q);
//		cout << t->data;
//		if (t->lchild)addq(t->lchild, q);
//		if (t->rchild)addq(t->rchild, q);
//	}
//	cout << endl;
//}
//int main()
//{
//	stack s;
//	treenode *bt=null;
//	bt = createtree();
//	printf("中序遍历:");
//	inorder(bt);
//	printf("\n先序遍历:");
//	preorder(bt);
//	printf("\n后序遍历");
//	postorder(bt);
//	printf("\n层序遍历");
//	levelorder(bt);
//	system("pause");
//	return 0;
//}
//树的非递归遍历
//递归创建树以及递归遍历
//#include<stdio.h>
//#include<windows.h>
//#include<malloc.h>
//#define null 0
//struct treenode
//{
//	int data;
//	treenode *lchild;
//	treenode *rchild;
//};
//treenode *createtree(treenode *t)
//{
//	int ch;
//	scanf("%d", &ch);
//	if (ch == -1)
//		t = null;
//	else
//	{
//		t = (treenode *)malloc(sizeof(treenode));
//		t->data = ch;
//		t->lchild = createtree(t->lchild);
//		t->rchild = createtree(t->rchild);
//	}
//	return t;
//}
//int preorder(treenode *t)//先序遍历
//{
//	if (t)
//	{
//		printf("%d ", t->data);
//		preorder(t->lchild);
//		preorder(t->rchild);
//	}
//	return 0;
//}
//int postorder(treenode *t)//后序遍历
//{
//	if (t)
//	{
//		postorder(t->lchild);
//		postorder(t->rchild);
//		printf("%d ", t->data);
//	}
//	return 0;
//}
//int inorder(treenode *t)//中序遍历
//{
//	if (t)
//	{
//		inorder(t->lchild);
//		printf("%d ", t->data);
//		inorder(t->rchild);
//	}
//	return 0;
//}
//int main()
//{
//	treenode *t = null;
//	t = createtree(t);
//	printf("先序遍历:");
//	preorder(t);
//	printf("\n");
//	printf("后序遍历:");
//	postorder(t);
//	printf("\n");
//	printf("中序遍历:");
//	inorder(t);
//	system("pause");
//	return 0;
//}
//递归创建树以及递归遍历
//迷宫
//#include<stdio.h>
//#include<malloc.h>
//#include<windows.h>
//struct location//定义迷宫结构体 
//{
//	int row;
//	int column;
//};
//struct stack//定义堆栈 
//{
//	location data[100];//可以记录100个位置 
//	int top;
//};
//int h, l, r, c, r, c;//分别代表迷宫行、列、出口坐标、入口坐标 
//int **a, **mark;//定义二维数组，分别代表迷宫数组，标记数组，轨迹数组 
//char **k;
//stack road;// 定义一个迷宫堆栈，用来记录走过的位置信息 
//int creatmaze()//创建迷宫函数 
//{
//	int i, j;
//	printf("请输入迷宫个的行数与列数:");
//	scanf("%d%d", &h, &l);
//	a = (int **)malloc(sizeof(int *)*h);//使用malloc申请二维数组空间 
//	for (i = 0; i < h; i++)
//		a[i] = (int *)malloc(sizeof(int)*l);
//	mark = (int **)malloc(sizeof(int *)*h);
//	for (i = 0; i < h; i++)
//		mark[i] = (int *)malloc(sizeof(int)*l);
//	k = (char **)malloc(sizeof(char *)*h);
//	for (i = 0; i < h; i++)
//		k[i] = (char *)malloc(sizeof(char)*l);
//	for (i = 0; i < h; i++)//标记数组和轨迹数组赋值0 
//	{
//		for (j = 0; j < l; j++)
//		{
//			mark[i][j] = 0;
//			k[i][j] = '.';
//		}
//	}
//	printf("请设置迷宫的入口坐标:");
//	scanf("%d%d", &r, &c);
//	printf("请输入迷宫的出口坐标:");
//	scanf("%d%d", &r, &c);
//	printf("开始创建迷宫:\n");
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < l; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	return 0;
//}
//int judge()//判断所处位置的下一个位置是否可以走 
//{
//	int count;
//	count = 0;
//	if (a[r][c + 1] == 0 && mark[r][c + 1] == 0)//判断东方向是否可走 
//	{
//		road.top++;//堆栈进入下一个内存空间，用来记录位置 
//		c++;//往东走一格，c加1即可 
//		road.data[road.top].row = r;//堆栈记录行信息 
//		road.data[road.top].column = c;//堆栈记录列信息 
//		mark[r][c] = 1;//标记这个位置的信息为1，为1说明这个位置到达过 
//	}
//	else if (a[r + 1][c] == 0 && mark[r + 1][c] == 0)//判断南方向是否可走  
//	{
//		road.top++;
//		r++;
//		road.data[road.top].row = r;
//		road.data[road.top].column = c;
//		mark[r][c] = 1;
//	}
//	else if (a[r][c - 1] == 0 && mark[r][c - 1] == 0)//判断西方向是否可走 
//	{
//		road.top++;
//		c--;
//		road.data[road.top].row = r;
//		road.data[road.top].column = c;
//		mark[r][c] = 1;
//	}
//	else if (a[r - 1][c] == 0 && mark[r - 1][c] == 0)//判断北方向是否可走 
//	{
//		road.top++;
//		r--;
//		road.data[road.top].row = r;
//		road.data[road.top].column = c;
//		mark[r][c] = 1;
//	}
//	else
//		count = 1;//count=1用来判别该位置东南西北均不可走，不是1说明有方向可走 
//	return count;
//}
//int main()
//{
//	int i, j, y, x, y;
//	creatmaze();
//	road.top = 0; //初始化堆栈，存入迷宫入口信息 
//	road.data[road.top].row = r;
//	road.data[road.top].column = c;
//	while (1)
//	{
//		y = judge();
//		if (y != 1 && (r != r || c != c))//四个方向有方向可走，并且现处位置满足行或列不等于出口数值 
//			continue;//满足条件继续执行如上步骤 
//		else if ((r != r || c != c) && y == 1)
//		{
//			road.top--;//四个方向均不可走，堆栈就删除该 位置信息，退回到上一个位置 
//			r = road.data[road.top].row;//用堆栈上一个位置信息给现处位置赋值 
//			c = road.data[road.top].column;
//		}
//		else //剩下的条件就是现处位置等于出口位置，则跳出循环 
//			break;
//	}
//	printf("路线如图:\n");
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < l; j++)
//		{
//			for (x = 0; x <= road.top; x++)
//				if (i == road.data[x].row&&j == road.data[x].column)// 利用堆栈记录的位置信息，来给轨迹数组赋值 
//					k[i][j] = '*';
//		}
//	}
//	for (i = 0; i < h; i++)
//	{
//		for (j = 0; j < l; j++)
//		{
//			printf("%c ", k[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//迷宫
//计算器
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<windows.h>
//typedef struct
//{
//	char data[100];
//	int top;
//}stack;
//int judge(char a[])//判断表达式是否正确
//{
//	int k = 0, t = 0, j = 0, i;
//	for (i = 0; i < strlen(a); i++)
//	{
//		if (a[i] == ')')
//			k++;
//		else if (a[i] == '(')
//			t++;
//		else if (a[i] == '/'&&a[i + 1] == '0'&&a[i + 2] != '.')
//			j = 1;
//	}
//	if (k == t&&j == 0)return 1;
//	else return 0;
//}
//char precede(char a, char b)//判断运算符的优先级，a为操作符栈中的运算符，b为将要进入操作符栈中的运算符
//{
//	int i = 0, j = 0;
//	char pre[][5] = {
//		/*运算符之间的优先级制作成一张表格*/
//			{ '>', '>', '>', '>', '>' },
//			{ '<', '<', '>', '>', '>' },
//			{ '<', '<', '>', '>', '>' },
//			{ '<', '<', '<', '<', '>' },
//			{ '>', '>', '>', '>', '<' },
//	};
//	switch (a){
//	case '+': i = 0; break;
//	case '-': i = 1; break;
//	case '*': i = 2; break;
//	case '/': i = 3; break;
//	case '(': i = 4; break;
//	}
//	switch (b){
//	case '+': j = 0; break;
//	case '-': j = 1; break;
//	case '*': j = 2; break;
//	case '/': j = 3; break;
//	case '(': j = 4; break;
//	}
//	return pre[i][j];
//}
//stack transform(char zz[])//将中缀表达式转换成后缀表达式
//{
//	stack ex, fu;//ex是用来存放后缀值的堆栈，fu是用来存放操作符的堆栈
//	int i;
//	//int flag;
//	ex.top = -1;//初始化这些堆栈
//	fu.top = -1;
//	//flag = 0;
//	for (i = 0; i<strlen(zz); i++)
//	{
//		if (zz[i] >= '0'&&zz[i] <= '9' || zz[i] == '.')//是数字直接入后缀值栈
//		{
//			ex.data[++ex.top] = zz[i];
//			if ((zz[i + 1]>'9' || zz[i + 1]<'0') && zz[i + 1] != '.')//如果数字后面就是运算符，就在后缀值栈中加一个空格，排除数字后面是小数点的情况
//				ex.data[++ex.top] = ' ';
//		}
//		else if (zz[i] == '=')//是‘#’号就将操作符栈中的剩余运算符弹到后缀值栈中
//		{
//			while (fu.top != -1)//直到将操作符栈中的操作符弹光
//			{
//				ex.data[++ex.top] = fu.data[fu.top--];
//				//fu.top--;
//			}
//			ex.data[++ex.top] = zz[i];//'#'号弹入后缀值栈
//			ex.data[++ex.top] = '\0';//后缀值栈录结束要在字符串末尾加结束字符'\0'
//		}
//		else if (zz[i] == '-' && (zz[i - 1] == '-' || zz[i - 1] == '+' || zz[i - 1] == '*' || zz[i - 1] == '/' || i - 1 == -1 || zz[i - 1] == '('))//判断运算符是负号还是减号，减号如果是第一个，在或条件中会有i-1=-1即可通过此条件判断负号，如果不是首个，则看其前一个是否是运算符
//		{
//			ex.data[++ex.top] = '0';//满足条件就将0和空格加入后缀值栈
//			ex.data[++ex.top] = ' ';
//			fu.data[++fu.top] = zz[i];//无需经过与操作符栈中的运算符比较优先级，直接入运算符栈
//			//flag = 1;//标记存在负数
//		}
//		else if (fu.top == -1)//当操作符栈里面是空栈，就将第一个运算符弹进去
//			fu.data[++fu.top] = zz[i];
//		else if (zz[i] == '(')//遇到左括号就让其直接入操作符栈
//			fu.data[++fu.top] = zz[i];
//		else if (zz[i] == ')')//遇到右括号就把操作符栈中的截止到左括号的运算符弹到后缀值栈
//		{
//			while (fu.data[fu.top] != '(')
//			{
//				ex.data[++ex.top] = fu.data[fu.top];
//				fu.top--;
//			}
//			fu.top--;//删除左括号
//		}
//		else if (precede(fu.data[fu.top], zz[i]) == '<')//字符串中的运算符优先级小于操作符栈顶的运算符，小于则将操作符栈顶运算符弹入后缀值栈
//		{
//			ex.data[++ex.top] = fu.data[fu.top];//先将操作符栈顶运算符弹入后缀值栈
//			while (precede(fu.data[--fu.top], zz[i]) == '<')//直到发现字符串中的那个运算符的优先级大于操作符栈中的，就停止向后缀值栈弹入优先级高的运算符
//				ex.data[++ex.top] = fu.data[fu.top];
//			fu.data[++fu.top] = zz[i];//停止后就将这个字符串中的那个字符弹入操作符栈中
//			//flag = 0;
//		}
//		else if (precede(fu.data[fu.top], zz[i]) == '>')//字符串中的那个运算符的优先级大于操作符栈中的，大于则直接将这个字符串中的运算符弹入操作符栈
//			fu.data[++fu.top] = zz[i];
//	}
//	return ex;//将最后得到的后缀值栈返回
//}//ps:之所以将遇到'#','(',')'三种情况放在调用precede之前，是因为避免这三个运算符和其他运算符进行优先级比较
//double readnumber(char f[], int *i)//将后缀值栈中的数由字符型转化成double型
//{
//	double x = 0;
//	int k = 0;
//	while (f[*i] >= '0'&&f[*i] <= '9')
//	{
//		x = x * 10 + (f[*i] - '0');
//		(*i)++;
//	}
//	if (f[*i] == '.')
//	{
//		(*i)++;
//		while (f[*i] >= '0'&&f[*i] <= '9')
//		{
//			x = x * 10 + (f[*i] - '0');
//			(*i)++;
//			k++;//小数点后位数统计
//		}
//	}
//	while (k != 0)
//	{
//		x = x / 10.0;
//		k = k - 1;//小数点后有多少位就要除几次10
//	}
//	return x;
//}
//double evalpost(char f[])//求解后缀表达式
//{
//	double obst[100];//存放double型的数，进行运算
//	int top = 0;
//	int i = 0;
//	double x1, x2;
//	while (f[i] != '=')
//	{
//		if (f[i] >= '0'&&f[i] <= '9')
//		{
//			obst[top] = readnumber(f, &i); top++;
//		}
//		else if (f[i] == ' ')
//			i++;
//		else if (f[i] == '+')
//		{
//			x2 = obst[--top];
//			x1 = obst[--top];
//			obst[top] = x1 + x2;
//			top++;
//			i++;
//		}
//		else if (f[i] == '-')
//		{
//			x2 = obst[--top];
//			x1 = obst[--top];
//			obst[top] = x1 - x2;
//			top++;
//			i++;
//		}
//		else if (f[i] == '*')
//		{
//			x2 = obst[--top];
//			x1 = obst[--top];
//			obst[top] = x1 * x2;
//			top++;
//			i++;
//		}
//		else if (f[i] == '/')
//		{
//			x2 = obst[--top];
//			x1 = obst[--top];
//			obst[top] = x1 / x2;
//			top++;
//			i++;
//		}
//	}
//	return obst[0];
//}
//int main()
//{
//	char zz[100];
//	int k = 0;
//	stack *ex;
//	printf("请输入表达式(按ctrl+z终止程序)\n");
//	while (gets(zz))
//	{
//		ex = &transform(zz);
//		if (judge(zz) == 1)
//		{
//			printf("后缀表达式如下:\n");
//			puts((*ex).data);
//			k = 1;
//		}
//		else
//			printf("表达式错误！\n");
//		if (k == 1)
//			printf("值=%.2lf\n", evalpost((*ex).data));
//		system("pause");
//		system("cls");
//		printf("请输入表达式(每个数结束后跟一个空格,按ctrl+z终止程序)\n");
//	}
//	system("pause");
//	return 0;
//}
//计算器
//动态链表
//#include<stdio.h>
//#include<malloc.h>
//#include<windows.h>
//#define null 0
//#define len sizeof(struct student)
//int n, n;
//struct student
//{
//	long num;
//	char name[10];
//	int score;
//	struct student *next;
//};
//struct student *creat(int n)
//{
//	n = 0;
//	int i;
//	struct student *p1, *p2, *head;
//	for (i = 0; i<n - 1; i++)
//	{
//		n++;
//		if (n == 1)
//		{
//			p1 = p2 = (struct student*)malloc(len);
//			scanf("%ld%s%d", &p1->num, &p1->name, &p1->score);
//			head = p1;
//		}
//		else
//			p2->next = p1;
//		p2 = p1;
//		p1 = (struct student*)malloc(len);
//		scanf("%ld%s%d", &p1->num, &p1->name, &p1->score);
//	}
//	p2->next = p1;
//	p2 = p1;
//	p1->next = null;
//	return head;
//}
//struct student *del(long num, struct student *head)
//{
//	struct student *p1, *p2;
//	p1 = head;
//	while (num != p1->num&&p1->next != null)
//	{
//		p2 = p1;
//		p1 = p1->next;
//	}
//	if (num == p1->num)
//	{
//		if (p1 == head)
//			head = p1->next;
//		else
//			p2->next = p1->next;
//		n = n - 1;
//		printf("delete:%ld\n", num);
//	}
//	else
//		printf("%ld can not be found!\n", num);
//	return head;
//}
//struct student *insert(struct student *stud, struct student *head)
//{
//	struct student *p0, *p1, *p2;
//	p1 = head;
//	p0 = stud;
//	while (p0->num>p1->num&&p1->next != null)
//	{
//		p2 = p1;
//		p1 = p1->next;
//	}
//	if (p0->num>p1->num)
//	{
//		p1->next = p0;
//		p0->next = null;
//		printf("insert:%ld\n", p0->num);
//	}
//	else if (p0->num<p1->num)
//	{
//		if (p1 == head)
//			head = p0;
//		else
//			p2->next = p0;
//		p0->next = p1;
//		printf("insert:%ld\n", p0->num);
//	}
//
//	n = n + 1;
//	return head;
//}
//int main()
//{
//	struct student *p, *p0, *p00, *p000, *p0000, *head, *stud;
//	int num, i;
//	printf("请输入学生的数量:");
//	scanf("%d", &n);
//	head = null;
//	p = p0 = creat(n);
//	while (p != null)
//	{
//		printf("%ld %s %d\n", p->num, p->name, p->score);
//		p = p->next;
//	}
//	printf("请输入需要删除的学生的学号:");
//	scanf("%ld", &num);
//	p00 = p000 = del(num, p0);
//	while (p00 != null)
//	{
//		printf("%ld %s %d\n", p00->num, p00->name, p00->score);
//		p00 = p00->next;
//	}
//	printf("请输入要插入的学生的信息:");
//	stud = (struct student*)malloc(len);
//	scanf("%ld%s%d", &stud->num, &stud->name, &stud->score);
//	p0000 = insert(stud, p000);
//	while (p0000 != null)
//	{
//		printf("%ld %s %d\n", p0000->num, p0000->name, p0000->score);
//		p0000 = p0000->next;
//	}
//	system("pause");
//	return 0;
//}
//动态链表
//成绩系统
//#include<stdio.h>
//#include<malloc.h>
//#include<windows.h>
//#define len sizeof(struct student)
//#define null 0
//struct score
//{
//	int a;
//	int b;
//	int c;
//};
//struct student
//{
//	long num;
//	char name[10];
//	struct score fen;
//};
//int n;
//struct student *e;
//int *a, *b, *c, *y;
//int formax(int a[], int n)
//{
//	int i, j, temp;
//	for (i = 0; i<n - 1; i++)
//		for (j = 0; j<n - 1 - i; j++)
//			if (*(a + j)>*(a + j + 1))
//			{
//		temp = *(a + j);
//		*(a + j) = *(a + j + 1);
//		*(a + j + 1) = temp;
//			}
//	return *(a + n - 1);
//}
//int forifa(int x, int n)
//{
//	int i;
//	for (i = 0; i<n; i++)
//		if (x == e[i].fen.a)
//			printf("%ld %s %d\n", e[i].num, e[i].name, e[i].fen.a);
//	return 0;
//}
//int forifb(int x, int n)
//{
//	int i;
//	for (i = 0; i<n; i++)
//		if (x == e[i].fen.b)
//			printf("%ld %s %d\n", e[i].num, e[i].name, e[i].fen.b);
//	return 0;
//}
//int forifc(int x, int n)
//{
//	int i;
//	for (i = 0; i<n; i++)
//		if (x == e[i].fen.c)
//			printf("%ld %s %d\n", e[i].num, e[i].name, e[i].fen.c);
//	return 0;
//}
//int forifabc(int x, int n)
//{
//	int i;
//	for (i = 0; i<n; i++)
//	{
//		if (x == (e[i].fen.a + e[i].fen.b + e[i].fen.c))
//			printf("%ld %s %d %d %d %d\n", e[i].num, e[i].name, e[i].fen.a,
//			e[i].fen.b, e[i].fen.c, e[i].fen.a + e[i].fen.b + e[i].fen.c);
//	}
//	return 0;
//}
//int main()
//{
//	int i;
//	float suma = 0, sumb = 0, sumc = 0, sumy = 0;
//	printf("请输入学生人数:");
//	scanf("%d", &n);
//	a = (int *)calloc(n, sizeof(int));
//	b = (int *)calloc(n, sizeof(int));
//	c = (int *)calloc(n, sizeof(int));
//	y = (int *)calloc(n, sizeof(int));
//	e = (struct student*)calloc(n, sizeof(struct student));
//	for (i = 0; i<n; i++)
//	{
//		scanf("%ld%s%d%d%d", &e[i].num, &e[i].name, &e[i].fen.a, &e[i].fen.b, &e[i].fen.c);
//		a[i] = e[i].fen.a;
//		b[i] = e[i].fen.b;
//		c[i] = e[i].fen.c;
//		y[i] = a[i] + b[i] + c[i];
//		suma += a[i];
//		sumb += b[i];
//		sumc += c[i];
//		sumy += y[i];
//	}
//	printf("a课程:average %.2f分数最高的同学信息\n", suma / n);
//	forifa(formax(a, n), n);
//	printf("b课程:average %.2f分数最高的同学信息\n", sumb / n);
//	forifb(formax(b, n), n);
//	printf("c课程:average %.2f分数最高的同学信息\n", sumc / n);
//	forifc(formax(c, n), n);
//	printf("总分:average %.2f最高的同学信息\n", sumy / n);
//	forifabc(formax(y, n), n);
//	system("pause");
//	return 0;
//}
//成绩系统
//超级售卖机
//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//	int i, n=0, m = 1, t1 = 0, t2 = 0, t3 = 0, t4 = 0, a = 1, b=0;//定义变量 系统选择码  查询时的商品种类 查询次数控制量 薯片、爆米花、巧克力、可乐的数量 购买次数控制量 售卖时商品种类
//	float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum = 0, k, j, p, r;//薯片，爆米花，巧克力，可乐的各自总价 所有购买的商品的总价 付款金额 找零金额 补付金额 二次付款金额
//	while (1)//该无限循环终止的条件就是结束售卖服务按下case5所决定的
//	{
//		printf("**************************************\n");
//		printf("1.价格查询系统         2.自动售卖系统 \n ");
//		printf("**************************************\n");
//		printf("请选择您要进行的操作\n");
//		scanf("%d", &i);
//		switch (i)//主switch，选择系统
//		{
//		case 1:
//			printf("欢迎使用价格查询系统！\n");
//			printf("**************************\n");
//			printf("1.薯片\n");
//			printf("2.爆米花\n");
//			printf("3.巧克力\n");
//			printf("4.可乐\n");
//			printf("5.退出\n");
//			printf("**************************\n");
//			for (; m <= 5; m++)//控制查询次数上限 
//			{
//				if (n == 5)//在没有达到查询上限就想要结束服务就选case5
//					break;
//				printf("请输入您要查询的食品的编号或者退出（查询5次后自动退出）\n");
//				scanf("%d", &n);
//				switch (n)//分switch,选择查询商品种类
//				{
//				case 1:
//					printf("薯片的价格为3.0元\n"); break;
//				case 2:
//					printf("爆米花的价格为2.0元\n"); break;
//				case 3:
//					printf("巧克力的价格为4.0元\n"); break;
//				case 4:
//					printf("可乐的价格为3.5元\n"); break;
//				case 5:
//					printf("thanks for using the system!\n");
//					break;
//				}
//			}
//			break;//跳出主switch,重新进入系统选择界面； 
//		case 2:
//			printf("欢迎使用自动售卖系统！\n");
//			printf("**************************\n");
//			printf("1.薯片\n");
//			printf("2.爆米花\n");
//			printf("3.巧克力\n");
//			printf("4.可乐\n");
//			printf("5.结束购买\n");
//			printf("**************************\n");
//			for (; a <= 5; a++)
//			{
//				if (b == 5)
//					break;
//				printf("请输入你要购买的食品或退出\n");
//				scanf("%d", &b);
//				switch (b)
//				{
//				case 1:
//					printf("薯片的价格为3.0元\n");
//					printf("请输入你要购买的数量:");
//					scanf("%d", &t1);
//					sum1 = 3 * t1;
//					break;
//				case 2:
//					printf("爆米花的价格为2.0元\n");
//					printf("请输入你要购买的数量:");
//					scanf("%d", &t2);
//					sum2 = 2 * t2;
//					break;
//				case 3:
//					printf("巧克力的价格为4.0元\n");
//					printf("请输入你要购买的数量:");
//					scanf("%d", &t3);
//					sum3 = 4 * t3;
//					break;
//				case 4:
//					printf("可乐的价格为3.5元\n");
//					printf("请输入你要购买的数量:");
//					scanf("%d", &t4);
//					sum4 = 3.5*t4;
//					break;
//				case 5:
//					printf("谢谢购买！\n");
//					break;
//				}
//			}
//			sum = sum1 + sum2 + sum3 + sum4;
//			printf("请付款%.2f元\n", sum);
//			scanf("%f", &k);
//			if (k>sum)
//			{
//				j = k - sum;
//				printf("***************************************\n");
//				printf("您的账单如下:\n");
//				if (t1 != 0)
//					printf("薯  片:3.0元 数量:%d,总计%.2f元\n", t1, sum1);
//				if (t2 != 0)
//					printf("爆米花:2.0元 数量:%d,总计%.2f元\n", t2, sum2);
//				if (t3 != 0)
//					printf("巧克力:4.0元 数量:%d,总计%.2f元\n", t3, sum3);
//				if (t4 != 0)
//					printf("可  乐:3.5元 数量:%d,总计%.2f元\n", t4, sum4);
//				printf("***************************************\n");
//				printf("找零%.2f元，欢迎下次光临！\n", j);
//			}
//			else if (k == sum)
//			{
//				printf("***************************************\n");
//				printf("您的账单如下:\n");
//				if (t1 != 0)
//					printf("薯  片:3.0元 数量:%d,总计%.2f元\n", t1, sum1);
//				if (t2 != 0)
//					printf("爆米花:2.0元 数量:%d,总计%.2f元\n", t2, sum2);
//				if (t3 != 0)
//					printf("巧克力:4.0元 数量:%d,总计%.2f元\n", t3, sum3);
//				if (t4 != 0)
//					printf("可  乐:3.5元 数量:%d,总计%.2f元\n", t4, sum4);
//				printf("***************************************\n");;
//				printf("交易完成，欢迎下次光临！\n");
//			}
//			else
//			{
//				p = sum - k;
//				printf("支付的现金不足，请再付%.2f元\n", p);
//				scanf("%f", &r);
//				if (r == p)
//				{
//					printf("***************************************\n");
//					printf("您的账单如下:\n");
//					if (t1 != 0)
//						printf("薯  片:3.0元 数量:%d,总计%.2f元\n", t1, sum1);
//					if (t2 != 0)
//						printf("爆米花:2.0元 数量:%d,总计%.2f元\n", t2, sum2);
//					if (t3 != 0)
//						printf("巧克力:4.0元 数量:%d,总计%.2f元\n", t3, sum3);
//					if (t4 != 0)
//						printf("可  乐:3.5元 数量:%d,总计%.2f元\n", t4, sum4);
//					printf("***************************************\n");
//					printf("交易完成，欢迎下次光临！\n");
//				}
//			}
//		}
//		if (b == 5)//这里对于m，n的不作要求，查询过价格按5退出查询系统或者查询满5次退出查询系统，为了实用，真正要关闭系统，结束
//			//服务，则在售卖系统操作完成后方可结束，而售卖系统结束时必定会按5键结束购买，所以最后将b的值作为系统结束服务的指令。
//			break;
//	}
//	system("pause");
//	return 0;
//}
//超级售卖机
//人才管理
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//#include<string.h>
//struct talents
//{
//	long num;//账号
//	long passw;//密码
//	char name[10];//姓名
//	int adress_num;//区域代号
//	char adress[50];//区域
//	char adress2[50];//家庭住址
//	int speciality_num;//特长代号
//	char speciality[50];//特长
//	int edubackground_num;//学历代号
//	char edubackground[50];//学历
//	int sex_num;//性别代号
//	char sex[10];//性别
//	int age;//年龄
//	char ps[50];//其他说明
//	char tel[12];//联系方式
//};//人才结构体
//struct companies
//{
//	long num;//账号
//	long passw;//密码
//	char company[50];//公司名称
//	int adress_num;//区域代号
//	char adress[50];//区域
//	char adress2[50];//具体地址
//	int property_num;//公司性质代号
//	char property[50];//公司性质
//	int background_num;//学历代号
//	char background[50];//要求的学历背景
//	char sex[10];//性别限定
//	char age_limit[50];//年龄限定
//	char ps[50];//其他说明
//	char person[50];//联系人
//	char tel[10];//联系方式
//};//公司结构体
//talents guide1[200];//数据库容量200
//companies guide2[200];
//int n;
//file *tal;//人才数据库
//file *com;//公司数据库
//int title()//主菜单
//{
//	printf("*******赶集网，啥都有*******\n");
//	printf("*****1.上传人才数据*********\n");
//	printf("*****2.上传公司数据*********\n");
//	printf("*****3.修改人才数据*********\n");
//	printf("*****4.修改公司数据*********\n");
//	printf("*****5.搜索人才*************\n");
//	printf("*****6.搜索公司*************\n");
//	printf("*****7.其他*****************\n");
//	printf("*****8.离开*****************\n");
//	printf("请输入选项:");
//	return 0;
//}
//int contactus()
//{
//	int i;
//	i = 0;
//	printf("1.法律申明\n2.联系我们\n3.软件版本\n4.关于我们\n5.离开此页\n");
//	while (i != 5)
//	{
//		scanf("%d", &i);
//		if (i>5 || i<1)
//		{
//			printf("请输入1~4，重新输入:");
//			scanf("%d", &i);
//		}
//		switch (i)
//		{
//		case 1:
//			printf("*******************************************\n");
//			printf("这是一个公司与人才的双方平台\n");
//			printf("我们会不定期提供软件更新以及信息维护\n");
//			printf("我们致力于提供最好的服务\n");
//			printf("这是一个神奇的软件\n");
//			printf("本法律申明最终解释权归鲍东\n");
//			printf("*******************************************\n");
//			break;
//		case 2:
//			printf("*******************************\n");
//			printf("开发者热线:1865285206\n普通客服  :0511-84464806\n客服qq    :1039952593\n");
//			printf("企业邮箱  :bd1039952593@163.com\n");
//			printf("*******************************\n");
//			break;
//		case 3:
//			printf("**************************************************************\n");
//			printf("software:ganji5.1.2\n");
//			printf("designed by baodong in jiangsu written in ningbo.model a1429\n");
//			printf("fccid:bcg-e2599a ic:579c-e2610a imei:013346005424405\n");
//			printf("**************************************************************\n");
//			break;
//		case 4:
//			printf("*******************************************************\n");
//			printf("地址:江苏省镇江市京口区黄山西路万达广场a座写字楼1707号\n");
//			printf("本产品由一杆清(鲍东)工作室提供技术支持\n");
//			printf("*******************************************************\n");
//			break;
//		}
//	}
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int readfiletal(talents guide1[])//读取人才信息函数
//{
//	int i = 0;
//	int fileend = 0;
//	if ((tal = fopen("c://talents.txt", "r")) == null)
//	{
//		printf("can not open the file");
//	}
//	while (fileend == feof(tal))
//	{
//		i = i + 1;
//		fscanf(tal, "%ld%ld%s%d%s%s%d%s%d%s%d%s%d%s%s", &guide1[i].num, &guide1[i].passw, guide1[i].name,
//			&guide1[i].adress_num, guide1[i].adress, guide1[i].adress2, &guide1[i].speciality_num, guide1[i].speciality,
//			&guide1[i].edubackground_num, &guide1[i].edubackground, &guide1[i].sex_num, guide1[i].sex, &guide1[i].age,
//			guide1[i].ps, guide1[i].tel);
//	}
//	return i;
//}
//int writefiletal(talents guide1[], int j)//将注册的人才数据写入数据库函数
//{
//	tal = fopen("c:\\talents.txt", "a");
//	fprintf(tal, "%ld %ld %s %d %s %s %d %s %d %s %d %s %d %s %s\n", guide1[j - 1].num, guide1[j - 1].passw, guide1[j - 1].name,
//		guide1[j - 1].adress_num, guide1[j - 1].adress, guide1[j - 1].adress2, guide1[j - 1].speciality_num, guide1[j - 1].speciality,
//		guide1[j - 1].edubackground_num, guide1[j - 1].edubackground, guide1[j - 1].sex_num, guide1[j - 1].sex, guide1[j - 1].age,
//		guide1[j - 1].ps, guide1[j - 1].tel);
//	fclose(tal);
//	printf("已上线的人才数%d\n", readfiletal(guide1) - 1);//输出上线的人才数据的个数
//	return 0;
//}
//int readfilecom(companies guide2[])//读取公司信息函数
//{
//	int i = 0;
//	int fileend = 0;
//	if ((com = fopen("c://companies.txt", "r")) == null)
//	{
//		printf("can not open the file");
//	}
//	while (fileend == feof(com))
//	{
//		i = i + 1;
//		fscanf(com, "%ld%ld%s%d%s%s%d%s%d%s%s%s%s%s%s", &guide2[i].num, &guide2[i].passw, guide2[i].company,
//			&guide2[i].adress_num, guide2[i].adress, guide2[i].adress2, &guide2[i].property_num, guide2[i].property,
//			&guide2[i].background_num,
//			guide2[i].background, guide2[i].sex, guide2[i].age_limit, guide2[i].ps, guide2[i].person, guide2[i].tel);
//	}
//	return i;
//}
//int writefilecom(companies guide2[], int j)//将注册的公司信息写入数据库
//{
//	com = fopen("c:\\companies.txt", "a");
//	fprintf(com, "%ld %ld %s %d %s %s %d %s %d %s %s %s %s %s %s\n", guide2[j - 1].num, guide2[j - 1].passw, guide2[j - 1].company,
//		guide2[j - 1].adress_num, guide2[j - 1].adress, guide2[j - 1].adress2, guide2[j - 1].property_num, guide2[j - 1].property,
//		guide2[j - 1].background_num, guide2[j - 1].background, guide2[j - 1].sex, guide2[j - 1].age_limit, guide2[j - 1].ps, guide2[j - 1].person, guide2[j - 1].tel);
//	fclose(com);
//	printf("当前上线的公司数%d\n", readfilecom(guide2) - 1);
//	return 0;
//}
//int uploadtal()//上传人才数据
//{
//	int m, i, k;
//	long mima1, mima2;
//	i = readfiletal(guide1);
//	printf("已有人才%d个\n", i - 1);
//	k = 0;
//	printf("要上传，首先先创建账号吧!\n输入账号:");
//	scanf("%ld", &guide1[i - 1].num);
//	printf("输入密码:");
//	while (k == 0)
//	{
//		scanf("%ld", &mima1);
//		printf("请核对你的密码:");
//		scanf("%ld", &mima2);
//		if (mima1 == mima2)
//		{
//			guide1[i - 1].passw = mima1;
//			k = 1;
//		}
//		else
//			printf("请重新输入密码");
//	}
//	printf("输入姓名:");
//	scanf("%s", guide1[i - 1].name);
//	printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州\n");
//	printf("输入区域代号:");
//	scanf("%d", &guide1[i - 1].adress_num);
//	if (guide1[i - 1].adress_num > 5 || guide1[i - 1].adress_num < 1)
//	{
//		printf("输入错误，请输入1~5之间的数字:");
//		scanf("%d", &guide1[i - 1].adress_num);
//	}
//	switch (guide1[i - 1].adress_num)
//	{
//	case 1:strcpy(guide1[i - 1].adress, "镇江"); break;
//	case 2:strcpy(guide1[i - 1].adress, "南京"); break;
//	case 3:strcpy(guide1[i - 1].adress, "常州"); break;
//	case 4:strcpy(guide1[i - 1].adress, "无锡"); break;
//	case 5:strcpy(guide1[i - 1].adress, "苏州"); break;
//	}
//	printf("输入家庭住址:");
//	scanf("%s", guide1[i - 1].adress2);
//	printf("1.金融 2.管理 3.计算机 4.工程 5.其他\n");
//	printf("输入特长代号:");
//	scanf("%d", &guide1[i - 1].speciality_num);
//	if (guide1[i - 1].speciality_num > 5 || guide1[i - 1].speciality_num < 1)
//	{
//		printf("输入错误，请输入1~5之间的数字:");
//		scanf("%d", &guide1[i - 1].speciality_num);
//	}
//	switch (guide1[i - 1].speciality_num)
//	{
//	case 1:strcpy(guide1[i - 1].speciality, "金融"); break;
//	case 2:strcpy(guide1[i - 1].speciality, "管理"); break;
//	case 3:strcpy(guide1[i - 1].speciality, "计算机"); break;
//	case 4:strcpy(guide1[i - 1].speciality, "工程"); break;
//	case 5:strcpy(guide1[i - 1].speciality, "其他"); break;
//	}
//	printf("1.中专 2.大专 3.本科 4.硕士 5.博士\n");
//	printf("输入学历代号:");
//	scanf("%d", &guide1[i - 1].edubackground_num);
//	if (guide1[i - 1].edubackground_num > 5 || guide1[i - 1].edubackground_num < 1)
//	{
//		printf("输入错误，请输入1~5之间的数字:");
//		scanf("%d", &guide1[i - 1].edubackground_num);
//	}
//	switch (guide1[i - 1].edubackground_num)
//	{
//	case 1:strcpy(guide1[i - 1].edubackground, "中专"); break;
//	case 2:strcpy(guide1[i - 1].edubackground, "大专"); break;
//	case 3:strcpy(guide1[i - 1].edubackground, "本科"); break;
//	case 4:strcpy(guide1[i - 1].edubackground, "硕士"); break;
//	case 5:strcpy(guide1[i - 1].edubackground, "博士"); break;
//	}
//	printf("1.男 2.女 3.其他\n");
//	printf("请输入性别代号:");
//	scanf("%d", &guide1[i - 1].sex_num);
//	if (guide1[i - 1].sex_num > 3 || guide1[i - 1].sex_num < 1)
//	{
//		printf("输入错误，请输入1~3之间的数字:");
//		scanf("%d", &guide1[i - 1].sex_num);
//	}
//	switch (guide1[i - 1].sex_num)
//	{
//	case 1:strcpy(guide1[i - 1].sex, "男"); break;
//	case 2:strcpy(guide1[i - 1].sex, "女"); break;
//	case 3:strcpy(guide1[i - 1].sex, "其他"); break;
//	}
//	printf("请输入年龄:");
//	scanf("%d", &guide1[i - 1].age);
//	printf("请输入其他备注信息:");
//	scanf("%s", guide1[i - 1].ps);
//	printf("请输入联系方式:");
//	scanf("%s", guide1[i - 1].tel);
//	writefiletal(guide1, i);
//	printf("上传成功！\n");
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int uploadcom()//上传公司数据
//{
//	int m, i, j, k, s, t;
//	long mima1, mima2;
//	i = readfilecom(guide2);
//	printf("%d", i);
//	k = 0;
//	printf("要上传，首先先创建账号吧!\n输入账号:");
//	scanf("%ld", &guide2[i - 1].num);
//	printf("输入密码:");
//	while (k == 0)
//	{
//		scanf("%ld", &mima1);
//		printf("请核对你的密码:");
//		scanf("%ld", &mima2);
//		if (mima1 == mima2)
//		{
//			guide2[i - 1].passw = mima1;
//			k = 1;
//		}
//		else
//			printf("请重新输入密码");
//	}
//	printf("输入公司名称:");
//	scanf("%s", guide2[i - 1].company);
//	printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州\n");
//	printf("输入公司区域代号:");
//	scanf("%d", &guide2[i - 1].adress_num);
//	if (guide2[i - 1].adress_num > 5 || guide2[i - 1].adress_num < 1)
//	{
//		printf("输入错误，请输入1~5之间的数字:");
//		scanf("%d", &guide2[i - 1].adress_num);
//	}
//	switch (guide2[i - 1].adress_num)
//	{
//	case 1:strcpy(guide2[i - 1].adress, "镇江"); break;
//	case 2:strcpy(guide2[i - 1].adress, "南京"); break;
//	case 3:strcpy(guide2[i - 1].adress, "常州"); break;
//	case 4:strcpy(guide2[i - 1].adress, "无锡"); break;
//	case 5:strcpy(guide2[i - 1].adress, "苏州"); break;
//	}
//	printf("输入公司地址:");
//	scanf("%s", guide2[i - 1].adress2);
//	printf("1.金融证券 2.风险投资 3.互联网 4.软件外包 5.其他\n");
//	printf("输入公司性质代号:");
//	scanf("%d", &guide2[i - 1].property_num);
//	if (guide2[i - 1].property_num > 5 || guide2[i - 1].property_num < 1)
//	{
//		printf("输入错误，请输入1~5之间的数字:");
//		scanf("%d", &guide2[i - 1].property_num);
//	}
//	switch (guide2[i - 1].property_num)
//	{
//	case 1:strcpy(guide2[i - 1].property, "金融证券"); break;
//	case 2:strcpy(guide2[i - 1].property, "风险投资"); break;
//	case 3:strcpy(guide2[i - 1].property, "互联网"); break;
//	case 4:strcpy(guide2[i - 1].property, "软件外包"); break;
//	case 5:strcpy(guide2[i - 1].property, "其他"); break;
//	}
//	printf("1.中专 2.大专 3.本科 4.硕士 5.博士\n");
//	printf("请输入对于学历的要求(输入代号):");
//	scanf("%d", &guide2[i - 1].background_num);
//	if (guide2[i - 1].property_num > 5 || guide2[i - 1].property_num < 1)
//	{
//		printf("输入错误，请输入1~5之间的数字:");
//		scanf("%d", &guide2[i - 1].background_num);
//	}
//	switch (guide2[i - 1].background_num)
//	{
//	case 1:strcpy(guide2[i - 1].background, "中专"); break;
//	case 2:strcpy(guide2[i - 1].background, "大专"); break;
//	case 3:strcpy(guide2[i - 1].background, "本科"); break;
//	case 4:strcpy(guide2[i - 1].background, "硕士"); break;
//	case 5:strcpy(guide2[i - 1].background, "博士"); break;
//	}
//	printf("请输入对于性别的要求:");
//	scanf("%s", guide2[i - 1].sex);
//	printf("请输入对于年龄的要求:");
//	scanf("%s", guide2[i - 1].age_limit);
//	printf("请输入其他备注信息:");
//	scanf("%s", guide2[i - 1].ps);
//	printf("请输入联系人:");
//	scanf("%s", guide2[i - 1].person);
//	printf("请输入联系方式:");
//	scanf("%s", guide2[i - 1].tel);
//	writefilecom(guide2, i);
//	printf("上传成功！\n");
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int checktalnum(long num)//验证账号的正确性函数
//{
//	int i;
//	i = readfiletal(guide1);
//	for (n = 1; n < i; n++)
//	{
//		if (num == guide1[n].num)
//			return 1;
//	}
//	return 0;
//}
//int checktalpassw(long passw)//验证密码的正确性函数
//{
//	if (passw == guide1[n].passw)
//		return 1;
//	return 0;
//}
//int checkcomnum(long num)//验证企业账号
//{
//	int i;
//	i = readfilecom(guide2);
//	for (n = 1; n < i; n++)
//	{
//		if (num == guide2[n].num)
//			return 1;
//	}
//	return 0;
//}
//int checkcompassw(long passw)//验证企业账号密码
//{
//	if (passw == guide2[n].passw)
//		return 1;
//	return 0;
//}
//int printtal(int i)//打印出搜索结果的函数（人才）
//{
//	printf("++++++++++++++++++++++++<-京口瓜洲一水间->++++++++++++++++++++++++++++++\n");
//	printf("账号:%ld    姓名:%s    性别:%s    年龄:%d\n", guide1[i].num, guide1[i].name, guide1[i].sex, guide1[i].age);
//	printf("特长:%s    学历:%s    所在地:%s\n", guide1[i].speciality, guide1[i].edubackground, guide1[i].adress);
//	printf("家庭地址:%s    联系方式:%s\n", guide1[i].adress2, guide1[i].tel);
//	printf("ps:%s\n", guide1[i].ps);
//	printf("++++++++++++++++++++++++<-钟山只隔数重山->++++++++++++++++++++++++++++++\n");
//	return 0;
//}
//int printcom(int i)//打印出搜索结果的函数（公司）
//{
//	printf("++++++++++++++++++++++++++<-何处望神州->++++++++++++++++++++++++++++++\n");
//	printf("账号:%ld    公司:%s    属性:%s    所在地:%s\n", guide2[i].num, guide2[i].company, guide2[i].property, guide2[i].adress);
//	printf("性别要求:%s    学历要求:%s    年龄要求:%s\n", guide2[i].sex, guide2[i].background, guide2[i].age_limit);
//	printf("联系人:%s    联系方式:%s\n", guide2[i].person, guide2[i].tel);
//	printf("地址:%s    ps:%s\n", guide2[i].adress2, guide2[i].ps);
//	printf("++++++++++++++++++++++++<-满眼风光北固楼->++++++++++++++++++++++++++++++\n");
//	return 0;
//}
//int changetaldata()//更改人才数据函数
//{
//	long num, passw;
//	int i, k = 0, j = 0, t;
//	printf("请输入个人账号:");
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%ld", &num);
//		if (checktalnum(num) == 1)
//		{
//			break;
//			k++;
//		}
//		else
//		{
//			if (i != 2)
//				printf("您输入的的账号不存在，请重新输入,您还有%d次机会输入\n", 2 - i);
//			else
//				printf("看来你是忘记了你的账号了，重新相互侧一个吧!\n");
//		}
//	}
//	printf("请输入密码（您有三次输入机会）:");
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%ld", &passw);
//		if (checktalpassw(passw) == 1)
//		{
//			break;
//			k++;
//		}
//		else
//		{
//			if (i != 2)
//				printf("密码输入错误，请再次输入，您还有%d次输入机会", 2 - i);
//			else if (i == 2)
//				printf("您的账号存在问题，请一个小时之后在重新登录\n");
//		}
//	}
//	t = readfiletal(guide1);
//	if (k == 2)
//		printf("登录成功!\n");
//	printtal(n);
//	printf("1.姓名 2.性别 3.年龄 4.特长 5.学历 6.所在地 7.家庭地址 8.联系方式 9.ps 10.修改完毕\n");
//	while (j != 10)
//	{
//		scanf("%d", &j);
//		if (j > 10 || j < 1)
//			printf("%d", &j);
//		switch (j)
//		{
//		case 1:scanf("%s", guide1[n].name); break;
//		case 2:scanf("%s", guide1[n].sex); break;
//		case 3:scanf("%d", &guide1[n].age); break;
//		case 4:scanf("%s", guide1[n].speciality); break;
//		case 5:scanf("%s", guide1[n].edubackground); break;
//		case 6:scanf("%s", guide1[n].adress); break;
//		case 7:scanf("%s", guide1[n].adress2); break;
//		case 8:scanf("%s", guide1[n].tel); break;
//		case 9:scanf("%s", guide1[n].ps); break;
//		}
//	}
//	tal = fopen("c:\\talents.txt", "w");
//	for (i = 1; i <t; i++)
//	{
//		fprintf(tal, "%ld %ld %s %d %s %s %d %s %d %s %d %s %d %s %s\n", guide1[i].num, guide1[i].passw, guide1[i].name,
//			guide1[i].adress_num, guide1[i].adress, guide1[i].adress2, guide1[i].speciality_num, guide1[i].speciality,
//			guide1[i].edubackground_num, guide1[i].edubackground, guide1[i].sex_num, guide1[i].sex, guide1[i].age,
//			guide1[i].ps, guide1[i].tel);
//	}
//	fclose(tal);
//	printf("修改成功!\n");
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int changecomdata()//更改公司数据的函数
//{
//	long num, passw;
//	int i, k = 0, j = 0, t;
//	printf("请输入企业账号:");
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%ld", &num);
//		if (checkcomnum(num) == 1)
//		{
//			break;
//			k++;
//		}
//		else
//		{
//			if (i != 2)
//				printf("您输入的的账号不存在，请重新输入,您还有%d次机会输入\n", 2 - i);
//			else
//				printf("看来你是忘记了你的账号了，重新相互侧一个吧!\n");
//		}
//	}
//	printf("请输入密码（您有三次输入机会）:");
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%ld", &passw);
//		if (checkcompassw(passw) == 1)
//		{
//			break;
//			k++;
//		}
//		else
//		{
//			if (i != 2)
//				printf("密码输入错误，请再次输入，您还有%d次输入机会", 2 - i);
//			else if (i == 2)
//				printf("您的账号存在问题，请一个小时之后在重新登录\n");
//		}
//	}
//	t = readfilecom(guide2);
//	if (k == 2)
//		printf("登录成功!\n");
//	printcom(n);
//	printf("1.公司名称 2.性别限制 3.年龄限制 4.公司性质 5.学历要求 6.所在地 7.公司地址 8.联系方式 9.ps 10.联系人 11.修改完毕\n");
//	while (j != 11)
//	{
//		scanf("%d", &j);
//		if (j > 11 || j < 1)
//			printf("%d", &j);
//		switch (j)
//		{
//		case 1:scanf("%s", guide2[n].company); break;
//		case 2:scanf("%s", guide2[n].sex); break;
//		case 3:scanf("%d", &guide2[n].age_limit); break;
//		case 4:scanf("%s", guide2[n].property); break;
//		case 5:scanf("%s", guide2[n].background); break;
//		case 6:scanf("%s", guide2[n].adress); break;
//		case 7:scanf("%s", guide2[n].adress2); break;
//		case 8:scanf("%s", guide2[n].tel); break;
//		case 9:scanf("%s", guide2[n].ps); break;
//		case 10:scanf("%s", guide2[n].person); break;
//		}
//	}
//	com = fopen("c:\\companies.txt", "w");
//	for (i = 1; i <t; i++)
//	{
//		fprintf(com, "%ld %ld %s %d %s %s %d %s %d %s %s %s %s %s %s\n", guide2[i].num, guide2[i].passw, guide2[i].company,
//			guide2[i].adress_num, guide2[i].adress, guide2[i].adress2, guide2[i].property_num, guide2[i].property,
//			guide2[i].background_num, guide2[i].background, guide2[i].sex, guide2[i].age_limit, guide2[i].ps,
//			guide2[i].person, guide2[i].tel);
//	}
//	fclose(com);
//	printf("修改成功!\n");
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int searchtal()//搜索人才的函数
//{
//	int i, j, t, k, count;
//	char place[10];
//	k = readfiletal(guide1);
//	count = 0;
//	j = 0;
//	i = 0;
//	printf("1.地区 2.特长 3.学历 4.离开\n");
//	printf("需要那种类型的人才:");
//	while (i != 4)
//	{
//		scanf("%d", &i);
//		if (i > 4 || i < 1)
//		{
//			printf("请输入1~4:");
//			scanf("%d", &i);
//		}
//		switch (i)
//		{
//		case 1:
//			printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州 6.离开\n");
//			printf("输入区域代号:");
//			j = 0;
//			while (j != 6)
//			{
//				count = 0;
//				j = 0;
//				scanf("%d", &j);
//				if (j > 6 || j < 1)
//				{
//					printf("请输入1~6:");
//					scanf("%d", &j);
//				}
//				switch (j)
//				{
//				case 1:
//					strcpy(place, "镇江");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].adress) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 2:
//					strcpy(place, "南京");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].adress) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 3:
//					strcpy(place, "常州");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].adress) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 4:
//					strcpy(place, "无锡");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].adress) == 0)
//						{
//							printtal(t);
//							count++;
//						};
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 5:
//					strcpy(place, "苏州");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].adress) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 6:
//					break;
//				}
//			}
//			system("pause");
//			system("cls");
//			printf("1.地区 2.特长 3.学历 4.离开\n");
//			printf("需要那种类型的人才:");
//			break;
//		case 2:
//			printf("1.金融 2.管理 3.计算机 4.工程 5.其他 6.离开\n");
//			printf("请输入特长代号:");
//			j = 0;
//			while (j != 6)
//			{
//				j = 0;
//				count = 0;
//				scanf("%d", &j);
//				if (j > 6 || j < 1)
//				{
//					printf("请输入1~6:");
//					scanf("%d", &j);
//				}
//				switch (j)
//				{
//				case 1:
//					strcpy(place, "金融");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].speciality) == 0)
//						{
//							printtal(t);
//							count++;
//						};
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 2:
//					strcpy(place, "管理");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].speciality) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 3:
//					strcpy(place, "计算机");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].speciality) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 4:
//					strcpy(place, "工程");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].speciality) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 5:
//					strcpy(place, "其他");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].speciality) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 6:
//					break;
//				}
//			}
//			system("pause");
//			system("cls");
//			printf("1.地区 2.特长 3.学历 4.离开\n");
//			printf("需要那种类型的人才:");
//			break;
//		case 3:
//			printf("1.中专 2.大专 3.本科 4.硕士 5.博士 6.离开\n");
//			printf("请输入学历代号:");
//			j = 0;
//			while (j != 6)
//			{
//				j = 0;
//				count = 0;
//				scanf("%d", &j);
//				if (j > 6 || j < 1)
//				{
//					printf("请输入1~6:");
//					scanf("%d", &j);
//				}
//				switch (j)
//				{
//				case 1:
//					strcpy(place, "中专");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].edubackground) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 2:
//					strcpy(place, "大专");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].edubackground) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 3:
//					strcpy(place, "本科");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].edubackground) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 4:
//					strcpy(place, "硕士");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide1[t].edubackground) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				case 5:
//					strcpy(place, "博士");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide1[t].edubackground) == 0)
//						{
//							printtal(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的人才->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个人才~_~\n", count);
//					break;
//				}
//			}
//			system("pause");
//			system("cls");
//			printf("1.地区 2.特长 3.学历 4.离开\n");
//			printf("需要那种类型的人才:");
//			break;
//		case 4:
//			break;
//		}
//	}
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int searchcom()//搜索公司的函数
//{
//	int i, j, t, k, count;
//	char place[10];
//	k = readfilecom(guide2);
//	count = 0;
//	j = 0;
//	i = 0;
//	printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
//	printf("输入需要检索的公司的第一关键词代号:");
//	while (i != 4)
//	{
//		scanf("%d", &i);
//		if (i > 4 || i < 1)
//		{
//			printf("请输入1~4:");
//			scanf("%d", &i);
//		}
//		switch (i)
//		{
//		case 1:
//			printf("1.镇江 2.南京 3.常州 4.无锡 5.苏州 6.离开\n");
//			printf("输入公司区域代号:");
//			j = 0;
//			while (j != 6)
//			{
//				count = 0;
//				j = 0;
//				scanf("%d", &j);
//				if (j > 6 || j < 1)
//				{
//					printf("请输入1~6:");
//					scanf("%d", &j);
//				}
//				switch (j)
//				{
//				case 1:
//					strcpy(place, "镇江");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].adress) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 2:
//					strcpy(place, "南京");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].adress) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 3:
//					strcpy(place, "常州");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].adress) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 4:
//					strcpy(place, "无锡");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].adress) == 0)
//						{
//							printcom(t);
//							count++;
//						};
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 5:
//					strcpy(place, "苏州");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].adress) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 6:
//					break;
//				}
//			}
//			system("pause");
//			system("cls");
//			printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
//			printf("输入需要检索的公司的第一关键词代号:");
//			break;
//		case 2:
//			printf("1.金融证券 2.风险投资 3.互联网 4.软件外包 5.其他 6.离开\n");
//			printf("请输入公司性质代号:");
//			j = 0;
//			while (j != 6)
//			{
//				j = 0;
//				count = 0;
//				scanf("%d", &j);
//				if (j > 6 || j < 1)
//				{
//					printf("请输入1~6:");
//					scanf("%d", &j);
//				}
//				switch (j)
//				{
//				case 1:
//					strcpy(place, "金融证券");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].property) == 0)
//						{
//							printcom(t);
//							count++;
//						};
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 2:
//					strcpy(place, "风险投资");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].property) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 3:
//					strcpy(place, "互联网");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].property) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 4:
//					strcpy(place, "软件外包");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].property) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 5:
//					strcpy(place, "其他");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].property) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 6:
//					break;
//				}
//			}
//			system("pause");
//			system("cls");
//			printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
//			printf("输入需要检索的公司的第一关键词代号:");
//			break;
//		case 3:
//			printf("1.中专 2.大专 3.本科 4.硕士 5.博士 6.离开\n");
//			printf("请输入学历代号:");
//			j = 0;
//			while (j != 6)
//			{
//				j = 0;
//				count = 0;
//				scanf("%d", &j);
//				if (j > 6 || j < 1)
//				{
//					printf("请输入1~6:");
//					scanf("%d", &j);
//				}
//				switch (j)
//				{
//				case 1:
//					strcpy(place, "中专");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].background) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 2:
//					strcpy(place, "大专");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].background) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 3:
//					strcpy(place, "本科");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].background) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 4:
//					strcpy(place, "硕士");
//					for (t = 1; t <k; t++)
//					{
//						if (strcmp(place, guide2[t].background) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				case 5:
//					strcpy(place, "博士");
//					for (t = 1; t < k; t++)
//					{
//						if (strcmp(place, guide2[t].background) == 0)
//						{
//							printcom(t);
//							count++;
//						}
//					}
//					if (count == 0)
//						printf("没有检索到您需要的公司->_->\n");
//					else
//						printf("\n=====================================共检索到以上%d个公司~_~\n", count);
//					break;
//				}
//			}
//			system("pause");
//			system("cls");
//			printf("1.地区 2.公司性质 3.学历要求 4.离开\n");
//			printf("输入需要检索的公司的第一关键词代号:");
//			break;
//		case 4:
//			break;
//		}
//	}
//	system("pause");
//	system("cls");
//	title();
//	return 0;
//}
//int main()
//{
//	int m = 0;
//	title();
//	while (m != 8)
//	{
//		scanf("%d", &m);
//		switch (m)
//		{
//		case 1:uploadtal(); break;
//		case 2:uploadcom(); break;
//		case 3:changetaldata(); break;
//		case 4:changecomdata(); break;
//		case 6:searchcom(); break;
//		case 5:searchtal(); break;
//		case 7:contactus(); break;
//		case 8:break;
//		}
//	}
//	system("pause");
//	return 0;
//}
//人才管理
//数组的循环左移
//#include<iostream>
//#include<windows.h>
//using namespace std;
//int main()
//{
//	int n, i, j, temp;;
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	cout << "请输入数组循环左移的位数:";
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		temp = a[0];
//		for (j = 0; j < 10; j++)
//		{
//			if (j == 9)
//				a[j] = temp;
//			else
//			    a[j] = a[j + 1];
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		cout << a[i]<<" ";
//	}
//	cout << endl;
//	system("pause");
//}
//数组的循环左移
//无限的路
//#include<iostream>
//#include<windows.h>
//#include<iomanip>
//#include<math.h>
//using namespace std;
//int main()
//{
//	int n, x1, x2, y1, y2, i ,t1, t2, n;
//	double d, d0;
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		cin >> x1 >> y1 >> x2 >> y2;
//		t1 = x1 + y1;
//		t2 = x2 + y2;//t代表坐标点所在的层数
//		if (t1 == t2)
//		{
//			d = (double)sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
//			cout << fixed << setprecision(3) << d << endl;
//		}
//		else if (t1 > t2)
//		{
//			d = (double)sqrt(x1*x1 + (y1 - t1)*(y1 - t1))+(double)sqrt((x2-t2)*(x2-t2)+y2*y2);
//			d0 = 0;
//			while (t1 != t2)
//			{
//				d0 = d0+(double)sqrt(t2*t2 + (t2 + 1)*(t2 + 1));
//				t2++;
//				if (t2!=t1)
//				d0 = d0 + (double)sqrt(t2*t2 + t2*t2);
//			}
//			cout << fixed << setprecision(3) << d + d0 << endl;
//		}
//		else
//		{
//			d = (double)sqrt(x2*x2 + (y2 - t2)*(y2 - t2)) + (double)sqrt((x1 - t1)*(x1 - t1) + y1*y1);
//			d0 = 0;
//			while (t1 != t2)
//			{
//				d0 = d0 + (double)sqrt(t1*t1 + (t1 + 1)*(t1 + 1));
//				t1++;
//				if (t2 != t1)
//					d0 = d0 + (double)sqrt(t1*t1 + t1*t1);
//			}
//			cout << fixed << setprecision(3) << d + d0 << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
//无限的路
//反转单项链表
//#include<iostream>
//#include<malloc.h>
//#include<windows.h>
//#define null 0
//using namespace std;
//struct node
//{
//	int data;
//	struct node *next;
//};
//node *head;
//node *creat()
//{
//	int n = 1,n;
//	cout << "请输入数据的个数:";
//	cin >> n;
//	node *p1, *p2;
//	p1 = p2 = (node *)malloc(sizeof(node));
//	cin >> p1->data;
//	while (n-1 != 0)
//	{
//		if (n == 1)
//			head = p1;
//		else
//			p2->next = p1;
//		p2 = p1;
//		p1 = (node*)malloc(sizeof(node));
//		cin >> p1->data;
//		n--;
//		n++;
//	}
//	p2->next = p1;
//	p1->next = null;
//	return head;
//}
//node *rollback(node *head)//反转单链表函数
//{
//	node *q, *p, *t ;
//	p = head;
//	q = null;//q是我们最后要得到的反转链表的开头
//	while (p != null)
//	{
// 		t = p->next;//
//		p->next = q;//单链表的头节点指向反转链表表头
//		q = p;//将p复制给q，q重新变成反转链表的表头；
//		p = t;//将t赋值给p，p重新变成单向链表的表头;
//	}
//	return q;
//}
//void print(node *p)//打印链表函数
//{
//	while (p != null)
//	{
//		cout << p->data<< " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//int main()
//{
//	node *p1,*p2,*p3;
//	p1 = p2 = creat();
//	print(p1);
//	p3 = rollback(p2);
//	print(p3);
//	system("pause");
//	return 0;
//}
//反转单项链表
//哈夫曼树
//#include<iostream>
//#include<stdlib.h>
//#include<windows.h>
//#include<malloc.h>
//#define null 0
//using namespace std;
//const int maxvalue = 1000;//权值最大1000
//const int maxbit = 20;//编码位数不超过20，也就是哈夫曼树不高于20层
//const int maxnode = 100;//哈夫曼树携带的最多节点数
//struct store//存储字符以及其权值的结构体，为哈夫曼树做准备
//{
//	char ch;
//	int weight;
//	struct store *next;
//};
//struct haffnode
//{
//	int flag;
//	int parent;
//	int weight;
//	int leftchild;
//	int rightchild;
//};
//struct haffcode
//{
//	int start;
//	int weight;
//	int codebit[maxbit];//最大编码位数20位，也就是此哈夫曼树最高可以有20层
//};
//void transhafftree(haffnode node[], int n, store weight[])//构造哈夫曼树
//{
//	int i, j, m1, m2, x1, x2;;
//	int child, parent;
//	for (i = 0; i < 2 * n - 1; i++)//初始化所有结点
//	{
//		if (i < n)
//			node[i].weight = weight[i].weight;
//		else
//			node[i].weight = 0;
//		node[i].parent = 0;
//		node[i].flag = 0;
//		node[i].leftchild = -1;
//		node[i].rightchild = -1;
//	}
//	for (i = 0; i < n - 1; i++)//构建哈夫曼树
//	{
//
//		m1 = m2 = maxvalue;//m1,m2,x1,x2需要放在循环里面，每次一个循环都要重新赋值
//		x1 = x2 = 0;
//		for (j = i; j < n + i; j++)//在所有所有已知权重的节点中找到两个最小的
//		{
//			if (node[j].weight < m1&&node[j].flag == 0)
//			{
//				m2 = m1;
//				x2 = x1;
//				m1 = node[j].weight;
//				x1 = j;
//			}
//			else if (node[j].weight < m2&&node[j].flag == 0)
//			{
//				m2 = node[j].weight;
//				x2 = j;
//			}
//		}
//		node[x1].parent = n + i;
//		node[x2].parent = n + i;
//		node[x1].flag = 1;
//		node[x2].flag = 1;
//		node[n + i].leftchild = x1;
//		node[n + i].rightchild = x2;
//		node[n + i].weight = node[x1].weight + node[x2].weight;
//	}
//}
//void transhaffcode(haffnode node[], int n, haffcode code[])//求出每个字符的哈夫曼码
//{
//	haffcode code;//用来暂时存放某个叶节点的编码
//	int i, j, child, parent;
//	for (i = 0; i < n; i++)
//	{
//		child = i;
//		parent = node[child].parent;
//		code.start = 0;
//		code.weight = node[i].weight;
//		while (parent != 0)
//		{
//			if (node[parent].leftchild == child)
//				code.codebit[code.start] = 0;
//			else if (node[parent].rightchild == child)
//				code.codebit[code.start] = 1;
//			code.start++;
//			child = parent;
//			parent = node[child].parent;
//		}
//		code[i].weight = code.weight;
//		code[i].start = code.start;
//		for (j = 0; j < code.start; j++)
//		{
//			code[i].codebit[code.start - j - 1] = code.codebit[j];//code.start-j-1在这里是有说法的，因为是start个parent，所以下标最大为s-1
//			/*test cout << code[i].codebit[code.start-j-1];*/
//		}
//		/*test for (j = 0; j < code[i].start; j++)
//		cout << code[i].codebit[j];*/
//	}
//}
//store *head;
//store *returntr(char str[])//统计字符串中各个字符的个数
//{
//	int i, j = 0, k, flag;//j:链表节点的个数;flag:标记是否在节点的数据中找到相同的字符
//	store *p1, *p2, *p3;
//	head = p1 = p2 = p3 = (struct store*)malloc(sizeof(struct store));
//	for (i = 0; i < strlen(str); i++)
//	{
//		if (i == 0)//i=0时，将字符串的首字符复制给链表头节点的ch
//		{
//			head->ch = str[0];
//			head->weight = 0;//权值先初始化，这里既然出现了一次这个字符，权值为何是0？是由于下面i=0时权值还是会自加一次
//			p1 = p2 = head;//head刚刚得到了数据赋值，将其数据给p1，p2
//		}
//		flag = 0;//由于字符串中每个字符都要进行链表的遍历比对，所以这个flag每次作用结束都要重新归零，方便下一个字符的标记
//		p3 = head;//由于是链表遍历，每一次遍历结束后p3的数据都会发生变化，所以每次遍历开始重置p3数据
//		for (k = 0; k <= j; k++)//j在这里是动态变化的，j+1是节点数量，遍历就是要访问每个节点
//		{
//			if (str[i] == p3->ch)//如果字符串中的字符和链表当中的ch有一致的话，该节点的权值自加
//			{
//				p3->weight++;
//				flag = 1;//标记在链表节点的ch中找到一样的
//				break;
//			}
//			p3 = p3->next;
//		}
//		if (flag == 0)
//		{
//			j++;//执行此语句说明这个字符是链表中没有的数据，所以需要将其加入
//			p1 = (store*)malloc(sizeof(store));
//			p1->ch = str[i];
//			p1->weight = 1;
//			p2->next = p1;
//			p2 = p1;
//		}
//	}
//	p1->next = null;
//	return head;
//}
//void bottomcode(char str[], haffcode code[], int n, store weight[])//展示字符串被压缩后的机内码
//{
//	int i, j, k;
//	cout << "该字符串经过压缩后的补码如下" << endl;
//	for (i = 0; i < strlen(str); i++)
//	{
//		for (j = 0; j < n; j++)
//			if (str[i] == weight[j].ch)
//			{
//			for (k = 0; k < code[j].start; k++)
//				cout << code[j].codebit[k];
//			}
//	}
//	cout << endl;
//}
//int main()
//{
//	store *p1, *p2;
//	int i, k, j, count = 0;
//	store *node, temp;
//	char str[100];
//	haffnode hnode[100];
//	haffcode hcode[100];
//	cout << "请输入字符串" << endl;
//	cin >> str;
//	p1 = p2 = returntr(str);
//	while (p1 != null)
//	{
//		count++;//计算出节点数量，为了数组的大小
//		p1 = p1->next;
//	}
//	if (count > maxnode)
//	{
//		cout << "节点数越界，请重新设定！" << endl;
//		system("pause");
//		exit(0);
//	}
//	node = (store*)malloc(sizeof(store)*count);//节省内存
//	i = 0;
//	while (p2 != null)//将链表的数据传给数组
//	{
//		node[i].weight = p2->weight;
//		node[i].ch = p2->ch;
//		i++;
//		p2 = p2->next;
//	}
//	/*test for (i = 0; i < count; i++)
//	{
//	cout << node[i].ch << ":"<<node[i].weight<<endl;
//	}*/
//	for (i = 0; i < count - 1; i++)//将得到的数组权值从小到大冒泡排序
//		for (j = 0; j < count - i - 1; j++)
//		{
//		if (node[j].weight > node[j + 1].weight)
//		{
//			temp = node[j];
//			node[j] = node[j + 1];
//			node[j + 1] = temp;
//		}
//		}
//	/*以上是利用returntr函数返回的链表头所携带的链表信息转化为数组形式*/
//	transhafftree(hnode, count, node);//构建哈夫曼树
//	transhaffcode(hnode, count, hcode);//计算哈夫曼编码
//	cout << "ch  wieght  code" << endl;
//	for (i = 0; i < count; i++)
//	{
//		cout << " " << node[i].ch << "    " << node[i].weight << "     ";
//		for (j = 0; j < hcode[i].start; j++)
//			cout << hcode[i].codebit[j];
//		cout << endl;
//	}
//	bottomcode(str, hcode, count, node);
//	system("pause");
//	return 0;
//}
//哈夫曼树
//约瑟夫环非链表
//#include<iostream>
//#include<windows.h>
//#include<malloc.h>
//using namespace std;
//int main()
//{
//	int i=0, m, n,num,*a,j,k,count=1;
//	cout << "请输入人数:";
//	cin >> n;
//	num = n;
//	a = (int *)malloc(sizeof(int)*n);
//	for (j = 0; j < n; j++)
//	{
//		a[j] = 0;
//	}
//	cout<<"请输入终止序号:";
//	cin >> m;
//	while (n != 1)
//	{
//		for (j = 0; j < num; j++)
//		{
//			if (a[j] == 1)
//				continue;
//			if (count == m)
//			{
//				a[j] = 1;
//				count = 0;
//				n--;//此处的n不能把它替换for里面的num，绝对不可以，因为n是动态的，动态的东西不要用在for里面
//			}
//			count++;
//		}
//	}
//	for (j = 0; j < num; j++)
//		if (a[j] == 0)
//			cout << "最后一个是"<<j+1 << endl;
//	system("pause");
//	return 0;
//}
//约瑟夫环非链表
//双向链表
//#include<stdio.h>
//#include<malloc.h>
//#include<windows.h>
//#define null 0
//struct node
//{
//	int data;
//	struct node *next;
//	struct node *previous;
//};
//struct node *head;
//node *creat(int i)
//{
//	int n=1;
//	struct node *p1, *p2;
//	while (i != 1)
//	{
//			if (n == 1)
//			{
//				p1 = p2 = (struct node*)malloc(sizeof(struct node));
//				scanf("%d", &p1->data);
//				p1->previous = null;
//				head = p1;
//			}
//			else
//			{
//				p2->next = p1;
//				p1->previous = p2;
//			}
//			p2 = p1;
//			p1 = (struct node*)malloc(sizeof(struct node));
//			scanf("%d", &p1->data);
//			if (i == 2)
//			{
//				p2->next = p1;
//				p1->previous = p2;
//				p1->next = null;
//			}
//			i--;
//			n++;
//	}
//	return head;
//}
//int ergodic()
//{
//	node *p1,*p2;
//	p1 = head;
//	while (p1!=null)//按照next的顺序遍历链表
//	{
//		printf("%d ", p1->data);
//		p2 = p1;
//		p1 = p1->next;
//	}
//	while (p2!=null)//按照previous的顺序遍历链表
//	{
//		printf("%d ", p2->data);
//		p2 = p2->previous;
//	}
//	printf("\n");
//	return 0;
//}
//node *delete()
//{
//	node *p1;
//	int data;
//	p1 = head;
//	printf("请输入要删除的节点数据:");
//	scanf("%d", &data); 
//	while (1)
//	{
//		if (data == p1->data)
//		{
//			if (p1 == head)
//			{
//				p1->next->previous = null;
//				head = p1->next;
//			}
//			else if (p1->next == null)
//			{
//				p1->previous->next = null;
//			}
//			else
//			{
//				p1->previous->next = p1->next;
//				p1->next->previous = p1->previous;
//			}
//			printf("delete data%d\n", data);
//			free(p1);//释放p1内存
//			break;
//		}
//		else if (p1->next==null)
//		{
//			printf("找不到你要删除的节点！\n");
//			break;
//		}
//		p1 = p1->next;
//	}
//	return head;
//}
//node *insert()
//{
//	node *p1, *p;
//	int data;
//	p1 = head;
//	p = (struct node*)malloc(sizeof(struct node));
//	printf("请输入需要插入的新节点的数据:");
//	scanf("%d", &p->data);
//	printf("请输入那个需要插入到它之后的节点数据:");
//	scanf("%d", &data);
//	while (1)
//	{
//		if (data == p1->data)
//		{
//			if (p1->next == null)
//			{
//				p1->next = p;
//				p->previous = p1;
//				p->next = null;
//			}
//			else
//			{
//				p->next = p1->next;
//				p->previous = p1;
//				p1->next->previous = p;
//				p1->next = p;
//
//			}
//			printf("insert data%d\n", p->data);
//			break;
//		}
//		else if (p1->next==null)
//		{
//			printf("找不到你要指定的节点！\n");
//			break;
//		}
//		p1 = p1->next;
//	}
//	return head;
//}
//int main()
//{
//	int i;
//	printf("请输入数据的个数:");
//	scanf("%d", &i);
//	creat(i);
//	ergodic();
//	insert();
//	ergodic();
//	delete();
//	ergodic();
//	system("pause");
//	return 0;
//}
//双向链表