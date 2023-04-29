#include<stdio.h>
#include<iostream>
#include <stdlib.h>
int Matrix[500][500] = {0}, num = 0; //tr,dr---->row,tc,dc---->column

//（1） 棋盘：可以用一个二维数组board[size][size]表示一个棋盘，其中
//		size=2^k。为了在递归处理的过程中使用同一个棋盘，将数组board
//		设为全局变量；

//（2） 子棋盘：整个棋盘用二维数组board[size][size]表示。其中的子棋
//		盘由棋盘左上角的下标tr、tc和棋盘大小s表示；

//（3） 特殊方格：用board[dr][dc]表示特殊方格，dr和dc是该特殊方格在
//		二维数组board中的下标;

//（4） L型骨牌：一个2^k×2^k的棋盘中有一个特殊方格。所以，用到L型骨
//		牌的个数为(4^k-1)/3，将所有L型骨牌从1开始连续编号，用一个全
//		局变量t表示。

void chessBoard(int tr, int tc, int dr, int dc, int size) {
	if (size == 1)
		return;
	int s = size / 2;   //分割棋盘
	int t = ++num;      //L型骨牌号

	//覆盖左上角子棋盘
	if (dr < tr + s && dc < tc + s) {
		//特殊方格在此棋盘中
		chessBoard(tr, tc, dr, dc, s);
	} else {        //此棋盘中无特殊方格
		//用t号L型骨牌覆盖右下角
		Matrix[tr + s - 1][tc + s - 1] = t;
		//覆盖其余方格
		chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}

	//覆盖右上角子棋盘
	if (dr < tr + s && dc >= tc + s ) {
		//特殊方格在此棋盘中
		chessBoard(tr, tc + s, dr, dc, s);
	} else {        //此棋盘中无特殊方格
		//用t号L型骨牌覆盖左下角
		Matrix[tr + s - 1][tc + s] = t;
		//覆盖其余方格
		chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}

	//覆盖左下角子棋盘
	if (dr >= tr + s && dc < tc + s) {
		//特殊方格在此棋盘中
		chessBoard(tr + s, tc, dr, dc, s);
	} else {
		//用t号L型骨牌覆盖右上角
		Matrix[tr + s][tc + s - 1] = t;
		//覆盖其余方格
		chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}

	//覆盖右下角子棋盘
	if (dr >= tr + s && dc >= tc + s) {
		//特殊方格在此棋盘中
		chessBoard(tr + s, tc + s, dr, dc, s);
	} else {
		//用t号L型骨牌覆盖左上角
		Matrix[tr + s][tc + s] = t;
		//覆盖其余方格
		chessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}

}
int main() {
	int size, r, c, row, col;
	printf("请输入棋盘的行列号");
	scanf("%d", &size);
	printf("请输入特殊方格的行列号");
	scanf("%d %d", &row, &col);
	chessBoard(0, 0, row, col, size);
	for (r = 0; r < size; r++) {
		for (c = 0; c < size; c++) {
			printf("%2d ", Matrix[r][c]);
		}
		printf("\n");
	}
	return 0;
}
