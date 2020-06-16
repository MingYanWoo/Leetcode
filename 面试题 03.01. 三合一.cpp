// 面试题 03.01. 三合一

// 三合一。描述如何只用一个数组来实现三个栈。

// 你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

// 构造函数会传入一个stackSize参数，代表每个栈的大小。

// 示例1:

//  输入：
// ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
// [[1], [0, 1], [0, 2], [0], [0], [0], [0]]
//  输出：
// [null, null, null, 1, -1, -1, true]
// 说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
// 示例2:

//  输入：
// ["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
// [[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
//  输出：
// [null, null, null, null, 2, 1, -1, -1]



class TripleInOne {
public:
    int *stack;
    int cap[3];
    int Ssize;
    TripleInOne(int stackSize) {
        stack = new int[stackSize*3];
        cap[0] = cap[1] = cap[2] = 0;
        Ssize = stackSize;
    }
    
    void push(int stackNum, int value) {
        if(cap[stackNum] >= Ssize) {
            return;
        }else {
            stack[stackNum*Ssize+cap[stackNum]] = value;
            cap[stackNum]++;
        }
        return;
    }
    
    int pop(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        int res = stack[stackNum*Ssize+cap[stackNum]-1];
        cap[stackNum]--;
        return res;
    }
    
    int peek(int stackNum) {
        if(!isEmpty(stackNum)) {
            return stack[stackNum*Ssize+cap[stackNum]-1];
        }
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        return cap[stackNum] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */