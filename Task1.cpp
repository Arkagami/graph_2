#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vstub.h"
#define RAZ 220
int D = 100;
int U = 300;
int L = 100;
int R = 300;
namespace std
{
	void sposob1(int x1, int y1, int x2, int y2);
	int CODE(int x, int y)
	{
		int m = 0;
		if (x<L) m += 1;
		if (x>R) m += 2;
		if (y<D) m += 8;
		if (y>U) m += 4;
		return m;
	}
	void peresech(int x1, int y1, int x2, int y2)
	{
		double dy = y1 - y2, dx = x1 - x2;
		if (dy != 0)
		{
			if (x1 < x2)
			{
				swap(x1, x2);
				swap(y1, y2);
			}
			dy = y1 - y2;
			dx = x1 - x2;
			if ((x1 > R) && (x2 < R))
			{
				sposob1(x1, y1, R + 1, y1 - (x1 - R - 1)*dy / dx);
				sposob1(x2, y2, R - 1, y1 - (x1 - R + 1)*dy / dx);
				return;
			}
			if ((x1 > L) && (x2 < L))
			{
				sposob1(x1, y1, L + 1, y1 - (x1 - L - 1)*dy / dx);
				sposob1(x2, y2, L - 1, y1 - (x1 - L + 1)*dy / dx);
				return;
			}
		}
		if (dx != 0)
		{
			if (y1 < y2)
			{
				swap(x1, x2);
				swap(y1, y2);
			}
			dy = y1 - y2, dx = x1 - x2;
			if ((y1 > U) && (y2 < U))
			{
				sposob1(x1, y1, x1 - (y1 - U - 1)*dx / dy, U + 1);
				sposob1(x2, y2, x1 - (y1 - U + 1)*dx / dy, U - 1);
				return;
			}
			if ((y1 > D) && (y2 < D))
			{
				sposob1(x1, y1, x1 - (y1 - D - 1)*dx / dy, D + 1);
				sposob1(x2, y2, x1 - (y1 - D + 1)*dx / dy, D - 1);
				return;
			}
		}
	}
	void sposob1(int x1, int y1, int x2, int y2)
	{
		int c1, c2;
		c1 = CODE(x1, y1);
		c2 = CODE(x2, y2);
		if (c1 == c2 &&c1 == 0)
		{
			setcolor(0, 255, 0);
			putline(x1, y1, x2, y2);
			return;
		}
		else if ((c1&c2) != 0)
		{
			setcolor(255, 255, 255);
			putline(x1, y1, x2, y2);
			return;
		}
		else
			peresech(x1, y1, x2, y2);
	}
	void sposob2(int x1, int y1, int x2, int y2)
	{
		int c1, c2, x, y;
		c1 = CODE(x1, y1);
		c2 = CODE(x2, y2);
		if (c1 == c2 && c1 == 0)
		{
			setcolor(255, 0, 0);
			putline(x1, y1, x2, y2);
			return;
		}
		else if (c1&c2)
		{
			setcolor(255, 255, 255);
			putline(x1, y1, x2, y2);
			return;
		}
		else
		{
			x = (x1 + x2) / 2;
			y = (y1 + y2) / 2;
			if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1)
				return;
			if (x == L || x == R)
			{
				if (x1 < x2)
				{
					sposob2(x1, y1, x, y);
					sposob2(x2, y2, x, y);
					return;
				}
				else
				{
					sposob2(x1, y1, x, y);
					sposob2(x2, y2, x, y);
					return;
				}
			}
			if (y == D || y == U)
			{
				if (y1 < y2)
				{
					sposob2(x1, y1, x, y);
					sposob2(x2, y2, x, y);
					return;
				}
				else {
					sposob2(x1, y1, x, y);
					sposob2(x2, y2, x, y);
					return;
				}
			}
			sposob2(x1, y1, x, y);
			sposob2(x2, y2, x, y);


		}
	}
	int main()
	{
		srand(time(NULL));
		int x1, x2, y1, y2;
		int t, t1, t2;
		setcolor(80, 80, 0);
		putline(L, D, R, D);
		putline(L, U, R, U);
		putline(L, D, L, U);
		putline(R, D, R, U);
		t = clock();
		for (int i = 0; i < RAZ; i++)
		{
			x1 = rand() % 400;
			y1 = rand() % 400;
			x2 = rand() % 400;
			y2 = rand() % 400;
			setcolor(0, 0, 255);
			sposob1(x1, y1, x2, y2);
		}
		t1 = clock() - t;
		vc << "\nd(Time) - " << t1 / 1000 << "." << t1 % 1000 << " seconds";
		t = clock();
		for (int i = 0; i < RAZ; i++)
		{
			x1 = rand() % 400;
			y1 = rand() % 400;
			x2 = rand() % 400;
			y2 = rand() % 400;
			setcolor(0, 0, 50);
			sposob2(x1, y1, x2, y2);
		}
		t2 = clock() - t;
		vc << "\nd(Time) - " << t2 / 1000 << "." << t2 % 1000 << " seconds";
		TFlush();
		GFlush();
		vgetchar();
		return 0;
	}
}
