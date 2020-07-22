// 面试题 03.05. 栈排序

// 栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

// 示例1:

//  输入：
// ["SortedStack", "push", "push", "peek", "pop", "peek"]
// [[], [1], [2], [], [], []]
//  输出：
// [null,null,null,1,null,2]
// 示例2:

//  输入： 
// ["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
// [[], [], [], [1], [], []]
//  输出：
// [null,null,null,null,null,true]
// 说明:

// 栈中的元素数目在[0, 5000]范围内。



class SortedStack {
public:
    stack<int> s1;
    stack<int> s2;
    SortedStack() {

    }
    
    void push(int val) {
        while(!s2.empty() && s2.top() > val) {
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty() && s1.top() < val) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }
    
    void pop() {
        if(peek() != -1) {
            s1.pop();
        }
        return;
    }
    
    int peek() {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) {
            return s1.top();
        }
        return -1;
    }
    
    bool isEmpty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */