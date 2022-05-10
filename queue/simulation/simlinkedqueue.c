#include "simdef.h"

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue) // customer 초기화
{
    QueueNode   buf;

    buf.customer.arrivalTime = arrivalTime; // 도착시간
    buf.customer.serviceTime = processTime; // 서비스시간
    insertLQ(pQueue, buf);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue) // 프로세스가 도착했을 때
{
    QueueNode   *temp;

    if (isLinkedQueueEmpty(pArrivalQueue)) // 만약 arrival queue가 비어있다면 진행할 수 없다.
        return ;
    temp = peekLQ(pArrivalQueue);
    if (currentTime == temp->customer.arrivalTime) // 현재 시간이 arrival time과 같다면 wait queue로 이동한다.
    {
        temp = deleteLQ(pArrivalQueue);
        temp->customer.status = arrival;
        insertLQ(pWaitQueue, *temp);
        free(temp);
        temp = NULL;
    }
}

QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue) // 진행
{
    QueueNode   *temp;

    if (isLinkedQueueEmpty(pWaitQueue)) // 만약 wait queue가 비어있다면 진행할 수 없다.
        return (NULL);
    temp = peekLQ(pWaitQueue);
    if(temp->customer.status == arrival) // status, startTime을 start 상태에 맞게 고쳐준다.
    {
        temp->customer.status = start;
        temp->customer.startTime = currentTime;
        return (NULL);
    }
    else if(temp->customer.startTime + temp->customer.serviceTime == currentTime) // 시작시간 + 서비스시간 이 currentTime과 같다면 종료조건에 부합한다.
        return temp;
    else
        return (NULL);
}

QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    if (!pServiceNode)
        return (NULL);
    *pServiceUserCount += 1; // 완료한 process
    *pTotalWaitTime += pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime; // 대기시간은 도착이후로 시작한 시간이다.
    pServiceNode->customer.endTime = currentTime;
    pServiceNode->customer.status = end;
    return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("the customers arrival, service time : %d %d \n", customer.arrivalTime, customer.serviceTime);
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode   *temp;

    printf("current time %d, waiting users %d \n", currentTime, pWaitQueue->currentElementCount);
    printf("====================================================================\n");
    temp = pWaitQueue->pFrontNode;
    for(int i = pWaitQueue->currentElementCount; i > 0; i--)
    {
        printSimCustomer(currentTime, temp->customer);
        temp = temp->pRLink;
    }
    printf("====================================================================\n");
}

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
    printf("remaining : %d, user count : %d, wait Time : %d\n", pWaitQueue->currentElementCount, serviceUserCount, totalWaitTime);
}

int main()
{
    LinkedQueue *ArrivalQueue = createLinkedQueue();
    LinkedQueue *WaitQueue = createLinkedQueue();
    QueueNode   *temp;
    int t = 0;
    int serviceUserCount = 0;
    int totalWaitTime = 0;

    insertCustomer(0, 3, ArrivalQueue);
    insertCustomer(2, 2, ArrivalQueue);
    insertCustomer(4, 1, ArrivalQueue);
    insertCustomer(6, 1, ArrivalQueue);
    insertCustomer(8, 3, ArrivalQueue);
    while(t < 10)
    {
        processArrival(t, ArrivalQueue, WaitQueue);
        printWaitQueueStatus(t, WaitQueue);
        temp = processServiceNodeStart(t, WaitQueue);
        if (temp) // 만약 반환받았다면, 종료한 것으로 간주한다.
        {
            processServiceNodeEnd(t, temp, &serviceUserCount, &totalWaitTime);
            deleteLQ(WaitQueue);
            free(temp);
            temp = NULL;
        }
        else
            t++;
    }
    printReport(WaitQueue, serviceUserCount, totalWaitTime);
    // system("leaks a.out");
    return 0;
}