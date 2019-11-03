#include<iostream>
using namespace std;
typedef struct QueueNode{
  QueueNode()
    :next(nullptr)
  {}
  struct QueueNode* next;
  int data;
}Node;
class Queue{
public:
  Queue()
    :_front(nullptr)
    ,_rear(nullptr)
  {}
  Node* BuyQueueNode(const int data){
    Node* pNewNode = new Node;
    pNewNode->next = nullptr;
    pNewNode->data = data;
    return pNewNode;
  }
  int QueueEmpty(){
    return _front == nullptr;
  }
  void QueuePush(const int data){
    Node* pNewNode = BuyQueueNode(data);
    if(QueueEmpty())
      _rear = _front = pNewNode;
    else{
      _rear->next = pNewNode;
      _rear = pNewNode;
    }
  }
  void QueuePop(){
    if(QueueEmpty())
      return;
    Node* pDelNode = _front;
    _front = pDelNode->next;
    delete pDelNode;
    pDelNode = nullptr;
  }
  int QueueSize(){
    int count = 0;
    Node* pCur = _front;
    while(pCur){
      count++;
      pCur = pCur->next;
    }
    return count;
  }
  int QueueFrontData(){
    return _front->data;
  }
  int QueueRearData(){
    return _rear->data;
  }
  void QueuePrint(){
    Node* pCur = _front;
    while(pCur){
      cout<<pCur->data<<" ";
      pCur = pCur->next;
    }
    cout<<endl;
  }
  ~Queue(){
    Node* pCur = _front;
    while(pCur){
      if(_front){
        _front = pCur->next;
        delete pCur;
        pCur = _front;
      }
    }
    _front = _rear = nullptr;
  }
private:
  Node* _front;
  Node* _rear;

};
void Test(){
  Queue q;
  q.QueuePush(1);
  q.QueuePush(2);
  q.QueuePush(3);
  q.QueuePush(4);
  q.QueuePush(5);
  q.QueuePush(6);
  q.QueuePush(7);
  q.QueuePrint();
  q.QueuePop();
  q.QueuePrint();
  cout<<q.QueueSize()<<endl;
  cout<<q.QueueFrontData()<<endl;
  cout<<q.QueueRearData()<<endl;
}
