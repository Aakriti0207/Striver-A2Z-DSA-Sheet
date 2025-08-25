class MyStack {
    int size;
    int *arr;
    int top;
  public:
  MyStack(){
      size = 100;
      arr = new int[size];
      top = -1;
  }
    void push(int x) {
        if(top == size-1) return;
        top++;
        arr[top] = x;
    }

    int pop() {
        if(top == -1) return -1;
        int x = arr[top];
        top--;
        return x;
    }
};