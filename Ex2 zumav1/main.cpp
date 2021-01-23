#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "LinkList.h"
#include "ball.h"

#define WINDOWWITH 600
#define WINDOWHEIGHT 600

COLORREF ballColorTable[] = {
BLUE, GREEN, RED, YELLOW, MAGENTA, BROWN
};

//��ͼ����ʾ��
void drawExample(void)
{
	// ���û�ͼɫΪ��ɫ
	setcolor(RED);
	setfillcolor(RED);

	// ������
	rectangle(100, 100, 300, 300);
	solidcircle(200, 200, 100);

}

//������ײ��
void drawColBall(ball* b, int x, int y)
{
	b->x = x;
	b->y = y;

	setcolor(ballColorTable[b->c]);
	setfillcolor(ballColorTable[b->c]);
	solidcircle(b->x, b->y, BALLRADIUS);
}

//�������������벹ȫ�ú���
void drawBallList(Node* head)
{
	Node* p = head->next;
	for(int i=1;i<=10;i++)
	{
		setcolor(ballColorTable[p->data.c]);
		setfillcolor(ballColorTable[p->data.c]);
		solidcircle(p->data.x, p->data.y, BALLRADIUS);
		p = p ->next;
	}
}

//��ʼ���������������������������һЩ���벹ȫ�ú���
void initBallList(Node* head)
{
	Node* p, * s;
	int i,x=BALLRADIUS;
	p = head;
	for (i = 1; i <= 10; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data.c = rand()%6;
		s->data.y = WINDOWHEIGHT / 2;
		s->data.x = x;
		x += BALLRADIUS * 2;
		p->next = s;
		s->next = NULL;
		p = s;
	}
}

int main()
{
	// ��ʼ����ͼ����
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();

	//����һ���յ�������
	Node* head = NULL;
	head = CreateEmptyList();
	srand(time(0));
	
	//��ʼ����������
	initBallList(head);

	//�ڴ����л���������
	drawBallList(head);
	//��ͼʾ����������ȫdrawBallList������������ɾ��
	//drawExample();


	//����ײ��
	ball cball;
	cball.c = rand() % 6;
	drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);

	//�ȴ�������˳�
	_getch();
	//������������ͻ�ͼ����
	DestroyList(head);
	closegraph();
	
	return 0;
}
	
