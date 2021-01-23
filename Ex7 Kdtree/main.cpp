#include<iostream>
#include<stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include "kdtree.h"
#include "ball.h"
#include <crtdbg.h>//add this header file to detect memory leaks
using namespace std;

#define WINDOWWITH 600
#define WINDOWHEIGHT 600
#define DEF_NUM_PTS 10

COLORREF ballColorTable[] = { BLUE, GREEN, RED, YELLOW, MAGENTA, BROWN };


//������ײ��
void drawColBall(DataType* b, float x, float y)
{
	b->x = x;
	b->y = y;
	setcolor(ballColorTable[b->c]);
	setfillcolor(ballColorTable[b->c]);
	solidcircle(b->x, b->y, BALLRADIUS);
}



//�������kdtree
static void InOrderTraverse(kdnode* T)
{
	if (T)
	{
		InOrderTraverse(T->left);
		setcolor(ballColorTable[T->data.c]);
		setfillcolor(ballColorTable[T->data.c]);
		solidcircle(T->data.x, T->data.y, BALLRADIUS);
		InOrderTraverse(T->right);
	}
}

static float rd(void) {
	return (float)(BALLRADIUS + rand() % (WINDOWHEIGHT - 2 * BALLRADIUS));
}


int main()
{
	//��ʼ����ͼ����
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();
	//��ĸ���
	int num_pts = DEF_NUM_PTS;
	//ָ��kdtree
	struct kdnode* root = NULL;
	//��������С����
	DataType NearestBall;
	float dis;
	//������
	DataType Ball;

	srand(time(0));

	//���򻭳�����kdtree��(����������ֵ�Բ�ص�)
	for (int i = 0; i < num_pts; ++i) {
		Ball.x = rd(), Ball.y = rd(), Ball.c = rand() % 6;
		while (i > 0)
		{
			searchNearest(root, Ball, NearestBall, dis);
			if (dis >= 2 * BALLRADIUS)break;
			Ball.x = rd(), Ball.y = rd();
		}
		root = kdnode_insert(root, Ball);
		setcolor(ballColorTable[Ball.c]);
		setfillcolor(ballColorTable[Ball.c]);
		solidcircle(Ball.x, Ball.y, BALLRADIUS);
	}
	
	//����ײ��
	DataType cball;
	cball.c = rand() % 6;
	drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
	float ballDirction = -1;
	float speed = 3;



	//�¼�ѭ����������ꡢʱ���¼�
	MOUSEMSG m;
	bool ballMoving = FALSE;

	while (root)
	{
		BeginBatchDraw();
		// ��ȡһ�������Ϣ
		if (MouseHit())
		{
			m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_MOUSEMOVE:
				break;

			case WM_LBUTTONDOWN:
				//��������˶�������ʼ�˶�
				if (!ballMoving)
				{
					ballDirction = float(m.x - WINDOWWITH / 2) / float(WINDOWHEIGHT - m.y);
					ballMoving = TRUE;
				}
				break;

			case WM_RBUTTONUP:
				closegraph();
				kdtree_destroy(root);
				if (!_CrtDumpMemoryLeaks())
				{
					cout << "�Ѿ�������Ϸ" << endl;
				}
				system("PAUSE");
				return 0;	// ������Ҽ��˳�����
			}
		}

		//�����ײ���Ƿ񳬳���Χ
		if (cball.x > WINDOWWITH + BALLRADIUS || cball.x <-BALLRADIUS || cball.y > WINDOWHEIGHT + BALLRADIUS || cball.y < -BALLRADIUS)
		{
			cball.c = rand() % 6;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
			continue;
		}

	//	//�ƶ���������ײ��
		if (ballMoving == TRUE)
		{
			cleardevice();
			drawColBall(&cball, cball.x + (speed * ballDirction), cball.y - speed);

			//�����������̾���
			searchNearest(root,cball,NearestBall,dis);
			if (dis <= 2* BALLRADIUS )
			{
				if (cball.c == NearestBall.c)
				{
					root = kdnode_delete(root, NearestBall);
				}
				else
				{
					root = kdnode_insert(root, cball);
				}
				ballMoving = false;
				cball.c = rand() % 6;
				continue;
			}
			InOrderTraverse(root);
		}
		else
		{
			cleardevice();
			InOrderTraverse(root);
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
		}
		Sleep(10);
		EndBatchDraw();
	}
	closegraph();
	kdtree_destroy(root);
	if (!_CrtDumpMemoryLeaks())
	{
		cout << "�Ѿ�������Ϸ" << endl;
	}
	system("PAUSE");

	return 0;
}
