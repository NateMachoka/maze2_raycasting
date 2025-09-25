#include <stdio.h>
#include <stdlib.h>

/* struct to represent position in the maze */
typedef struct {
	int x;
	int y;
} Position;

/* dynamic array to stre the path */
typedef struct {
	Position *data;
	int used;
	int capacity;
} Path;

/**
 * initPath - Create a path with a given capacity
 * @size: The initial capacity of the path
 *
 * Return: Pointer to the newly allocated Path struct.
 *         Exits with status 1 if memory allocation fails.
 */
Path *initPath(int size)
{
	Path *path = malloc(sizeof(Path));
	if (path == NULL)
	{
		printf("Memory allocation for struct path failed\n");
		exit(1);
	}
	path->data = malloc(size * sizeof(Position));
	if (path->data == NULL)
	{
		printf("Mem allocation failed for data\n");
		free(path);
		exit(1);
	}
	path->used = 0;
	path->capacity = size;

	Position start = {0, 0};
	path->data[path->used] = start;
	path->used = path->used + 1;

	return(path);
}

/**
 * resizePath - Double the capacity of a given path
 * @path: Pointer to the Path to be resized
 *
 * Return: Nothing. Exits with status 1 if reallocation fails.
 */
void resizePath(Path *path)
{
	path->capacity *= 2;
	path->data = realloc(path->data, path->capacity * sizeof(Position));
	if (path->data == NULL)
	{
		printf("Reallocationn failed\n");
		exit(1);
	}
}
void move(Path *path, int dx, int dy)
{
	Position last, newPos;

	last = path->data[path->used - 1];
	newPos.x = last.x + dx;
	newPos.y = last.y + dy;

	if (path->used == path->capacity)
	{
		resizePath(path);
	}

	path->data[path->used] = newPos;
	path->used = path->used + 1;
}
void delete_lastPosition(Path *path)
{
	if (path->used > 0)
	{
		path->used--;
	}
}
Position undoDelete(Path *path)
{
	Position invalid = {-1, -1};

	if (path->used == 0)
		return(invalid);

	return(path->data[--path->used]);
}
void delete_atIndex(Path *path, int index)
{
	int i;

	if (index < 0 || index >= path->used)
	{
		return;
	}
	for (i = index; i < path->used - 1; i++)
	{
		path->data[i] = path->data[i + 1];
	}
	path->used--;
}

void keepLastN(Path *path, int N)
{
	int i, excess;

	if (path->used <= N)
		return;

	excess = path->used - N;

	for(i = 0; i < N; i++)
	{
		path->data[i] = path->data[i + excess];
	}
	path->used = N;
}
void removeLastN(Path *path, int N)
{
	if (N <= 0)
		return;

	if (N >= path->used)
	{
		path->used = 1;
	}
	path->used -= N;
}
void printPath(Path *path)
{
	int i;

	printf("path history: \n");
	for (i = 0; i < path->used; i++)
	{
		printf("Step %d -> (%d , %d)\n", i, path->data[i].x, path->data[i].y);
	}
}

void freePath(Path *path)
{
	free(path->data);
	free(path);
}

/* ----------------- MAIN TEST ----------------- */
int main()
{
	Path *myPath = initPath(2);

	move(myPath, 1, 0);  // right
	move(myPath, 0, 1);  // up
	move(myPath, -1, 0); // left
	move(myPath, 0, -1); // down
	printPath(myPath);

	printf("\n-- Undo last move --\n");
	delete_lastPosition(myPath);
	printPath(myPath);

	printf("\n-- Delete at index 1 --\n");
	delete_atIndex(myPath, 1);
	printPath(myPath);

	printf("\n-- Add more moves --\n");
	move(myPath, 2, 0);
	move(myPath, 2, 2);
	move(myPath, 3, 2);
	move(myPath, 4, 2);
	printPath(myPath);

	printf("\n-- Keep only last 3 moves --\n");
	keepLastN(myPath, 3);
	printPath(myPath);

	printf("\n-- Remove last 2 moves --\n");
	removeLastN(myPath, 2);
	printPath(myPath);

	freePath(myPath);
	return 0;
}
