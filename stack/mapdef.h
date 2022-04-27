#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = 
{
	{0, -1},		// �������� �̵�.
	{1, 0},			// ���������� �̵�.
	{0, 1},			// �Ʒ������� �̵�.
	{-1, 0}			// �������� �̵�.
};

// 시작 위치가 (n, m); -> 이동 할 때 더할수있게??
// 4, 4 4, 3 4, 2

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

typedef struct MapPositionType
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// ���� ��ġ�� �̵� ����.
} MapPosition;

typedef struct StackNodeType
{
	MapPosition pos;
	struct StackNodeType* pLink;
} LinkedMapNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	LinkedMapNode* pTopElement;		// Top ����� ������
} LinkedMapStack;

int pushLS(LinkedMapStack* pStack, LinkedMapNode element);


#endif