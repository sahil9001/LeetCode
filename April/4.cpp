class MyCircularQueue
{
private:
    deque<int> dq;
    int capacity;

public:
    MyCircularQueue(int k)
    {
        capacity = k;
    }

    bool enQueue(int value)
    {
        if (dq.size() < capacity)
        {
            dq.push_back(value);
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (dq.size() != 0)
        {
            dq.pop_front();
            return true;
        }
        return false;
    }

    int Front()
    {
        if (dq.size() == 0)
            return -1;

        return dq.front();
    }

    int Rear()
    {
        if (dq.size() == 0)
            return -1;
        return dq.back();
    }

    bool isEmpty()
    {
        return dq.size() == 0 ? true : false;
    }

    bool isFull()
    {
        return dq.size() == capacity ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */