#include <iostream>
#include <stdint.h>
#include <math.h>  
using namespace std;
#define u64 uint64_t
#define u32 uint32_t
#define s32 int32_t

#define PARENT(i) ((i-1)/2)
#define LEFT_CHILD(i) ((2*i) + 1)
#define RIGHT_CHILD(i) ((2*i) + 2)
#define MAX_PRODUCT 1000000007

struct Data
{
  s32 index;
  u64 product;
  double logCost;
};

struct PriorityQueue
{
    Data data[100000];
    u32 queueSize;
};

PriorityQueue queue;

void heapUp(s32 index, PriorityQueue *q)
{
    s32 parent = PARENT(index);
    while(parent >= 0 && (q->data[parent].logCost > q->data[index].logCost))
    {
        Data temp = q->data[index];
        q->data[index] = q->data[parent];
        q->data[parent] = temp;
        
        index = parent;
        parent = PARENT(index);
    }
}

void heapDown(s32 index, PriorityQueue *q)
{
    s32 left_child = LEFT_CHILD(index);
    s32 right_child = RIGHT_CHILD(index);
    while(right_child < q->queueSize || left_child < q->queueSize)
    {
        s32 min_child;
        if(right_child >= q->queueSize || q->data[left_child].logCost < q->data[right_child].logCost) 
        {
            min_child = left_child;
        }
        else
        {
            min_child = right_child;
        }
        
        
        if(q->data[index].logCost > q->data[min_child].logCost)
        {
            Data temp = q->data[index];
            q->data[index] = q->data[min_child];
            q->data[min_child] = temp;
        
            index = min_child;
            left_child = LEFT_CHILD(index);
            right_child = RIGHT_CHILD(index);
        }
        else
        {
            break;
        }
    }
}

void enqueue(s32 index, u64 product, double logCost, PriorityQueue *q)
{
    Data *d = q->data + q->queueSize;
    d->index = index;
    d->product = product;
    d->logCost = logCost; 
    
    heapUp(q->queueSize++, q);
}



Data dequeue(PriorityQueue *q)
{
    Data result = q->data[0];

    q->data[0] = q->data[--(q->queueSize)];
    heapDown(0, q);
    
    return result;
}




int main()
{
    s32 N, K, A, i = 0;
    cin >> N >> K;
    Data empty = {};
    empty.product = 1;
    while(i < N)
    {
        cin >> A;
        s32 lastIndexInWindow = i - K;
        while(queue.queueSize > 0 && queue.data[0].index < lastIndexInWindow)
        {
            dequeue(&queue);
        }
        
        Data *min_predecessor = &empty;
        if(queue.queueSize > 0) min_predecessor = queue.data;
        
        if(i == N-1)
        {
            cout << ((min_predecessor->product * A) % MAX_PRODUCT);
            return 0;
        }
        
        enqueue(i, ((min_predecessor->product * A) % MAX_PRODUCT), min_predecessor->logCost + log(A), &queue);
        i++;
    }
    
    return -1;
}