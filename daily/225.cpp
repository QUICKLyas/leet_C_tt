//
// Created by Administrator on 2024/3/3.
// 两个队列实现后入先出的栈，并且简单支持push pop top empty
# include <queue>

using namespace std;

class MyStack {
public:
    queue<int> queAnswer;
    queue<int> queTemp;
    MyStack () {
    }
    void push(int x) {
        // 入栈操作需要反复将数据元素进行移动
        int size = queAnswer.size();
        queAnswer.push(x);
        for (int i = 0;i<size;i++) {
            queAnswer.push(queAnswer.front());
            queAnswer.pop();
        }
//        queAnswer.push(x);
//        int i;
//        for (i = 0;i < queAnswer.size(); i++) {
//            queTemp.push(queAnswer.front());
//            // 获得队列中队头的数据，并压入队列的队尾，保证队头是逻辑栈的栈顶
//            queTemp.pop(); // 弹出队头元素
//        }
//        swap(queAnswer,queTemp);
    }
    int pop () {
        int headItem = queAnswer.front();
        queAnswer.pop();
        return headItem;

    }
    int top() {
        return queAnswer.front();
    }
    bool empty() {
        return queAnswer.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.pop();
    myStack.pop();
    return 0;
}