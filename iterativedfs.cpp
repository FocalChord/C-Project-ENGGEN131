#include <cstdio>
#include <stack>

#define MAX_MAP_SIZE 100

 void countTotalPureGold(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int *i, int *j, int rows, int cols, int *pureGold)
{
    if (*i != 0 && *i != rows - 1 && *j != 0 && *j != cols - 1) {
        if (map[*i + 1][*j] == 9 && map[*i - 1][*j] == 9 && map[*i][*j + 1] == 9 && map[*i][*j - 1] == 9 && map[*i + 1][*j + 1] == 9 && map[*i - 1][*j - 1] == 9 && map[*i + 1][*j - 1] == 9 && map[*i - 1][*j + 1] == 9)
            (*pureGold)++;
    }
} 

struct cell {
	int x;
	int y;
};

void dfs(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int visited[MAX_MAP_SIZE][MAX_MAP_SIZE], int r, int c, int *nGold, int *nPureGold) {
	cell stack[MAX_MAP_SIZE * MAX_MAP_SIZE + 5];	
	cell *endOfStack = stack+0;

	cell curCell = {r, c};
	*endOfStack = curCell;
	endOfStack++;

	while(endOfStack != stack+0) {
		curCell = *(endOfStack - 1);
		endOfStack--;

		if(map[curCell.x][curCell.y] == 9) (*nGold)++;
		countTotalPureGold(map, &curCell.x, &curCell.y, 15, 15, nPureGold);

		//adds adjacent valid cells to the stack
		for(int i=-1; i<=1; i++) {
			for(int j=-1; j<=1; j++) {
				cell adjCell = {curCell.x + i, curCell.y + j};
				if(map[adjCell.x][adjCell.y] == 9 && visited[adjCell.x][adjCell.y] == 0) {
					*endOfStack = adjCell;
					endOfStack++;
					visited[adjCell.x][adjCell.y] = 1;
				}
			}
		}
	} 

	/*
		push cell:
			*endOfStack = cell{r,c};
			endOfStock++;

		pop cell
			poppedCell = *endOfStack
			endOfStack--;
	*/
}

int main() {
	int map1[MAX_MAP_SIZE][MAX_MAP_SIZE] = {
		{1,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,4,3,0,0,0,0,9,9,8,0,0,0,0,0},
		{0,2,0,3,3,0,0,9,9,0,0,0,0,0,0},
		{0,0,0,0,0,4,6,9,9,6,0,0,0,0,0},
		{0,0,0,0,0,0,9,0,8,0,0,6,0,0,0},
		{0,0,9,9,9,9,0,0,0,0,7,7,8,8,0},
		{0,0,9,9,9,9,0,0,0,0,0,7,0,0,0},
		{0,0,9,9,9,9,0,1,1,1,2,2,2,2,2},
		{0,0,0,9,9,0,0,0,0,0,0,0,0,3,0},
		{0,0,0,4,4,0,0,0,0,0,0,0,5,6,0},
		{0,0,0,0,9,9,9,0,0,9,0,0,0,5,0},
		{0,0,1,2,9,9,9,0,0,0,9,0,0,4,2},
		{0,0,0,0,9,9,9,0,0,0,9,9,9,0,0},
		{9,9,0,0,0,0,1,0,0,0,0,9,0,0,0},
		{9,0,0,0,0,0,2,2,0,0,0,0,0,0,0}
	};

	int visited[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};

	for(int i=0; i<15; i++) {
		for(int j=0; j<15; j++) {
			if(map1[i][j] == 9 && visited[i][j] == 0) {
				visited[i][j] = 1;
				int nGold = 0, nPureGold = 0;
				dfs(map1, visited, i, j, &nGold, &nPureGold);
				printf("Gold Cells: %d   Pure Gold Cells: %d\n", nGold, nPureGold);
			}
			visited[i][j] = 1;
		}
	}
}