#include<iostream>
using namespace std;

typedef struct Node{
  struct Node* next;
  int data;
}Node;
class Slist{
public:
  Slist()
    :head(nullptr){}
  Node* BuySlistNode(const int data){
    Node* pNewNode = new Node;
    pNewNode->data = data;
    pNewNode->next = nullptr;
    return pNewNode;
  }
  void SlistPushBack(Slist* s,int data){
    Node* pNewNode = BuySlistNode(data);
    if(s->head == nullptr){
      s->head = pNewNode;
    }else{
      Node* pCur = s->head;
      while(pCur->next){
        pCur = pCur->next;
      }
      pCur->next = pNewNode;
    }
  }
  void SlistPopBack(Slist* s){
    if(s->head == nullptr)
      return;
    else{
      Node* pPre = nullptr;
      Node* pCur = s->head;
      while(pCur->next){
        pPre = pCur;
        pCur = pCur->next;
      }
      pPre->next = pCur->next;
      delete pCur;
      pCur = nullptr;
    }
  }
  void SlistPushFront(Slist* s,int data){
    Node* pNewNode = BuySlistNode(data);
    if(s->head == nullptr)
      s->head = pNewNode;
    else{
      pNewNode->next = s->head;
      s->head = pNewNode;
    }
  }
  void SlistPopFront(Slist* s){
    if(s->head == nullptr)
      return;
    else{
      Node* pDelNode = s->head;
      s->head = pDelNode->next;
      delete pDelNode;
      pDelNode = nullptr;
    }
  }
  void SlistInsert(Node* pos,int data){
    if(pos == nullptr)
      return;
    Node* pNewNode = BuySlistNode(data);
    pNewNode->next = pos->next;
    pos->next = pNewNode;
  }
  void SlistErase(Slist* s,Node* pos){
    if(pos == nullptr||s->head == nullptr){
      return;
    }
    if(s->head == pos){
      s->head = pos->next;
    }else{
      Node* pPrePos = s->head;
      while(pPrePos&&pPrePos->next!=pos){
        pPrePos = pPrePos->next;
      }
      if(pPrePos){
        pPrePos->next = pos->next;
      }
    }
    delete pos;
    pos = pos->next;
  }
  Node* SlistFind(Slist* s,int data){
    if(s->head == nullptr)
      return nullptr;
    Node* pCur = s->head;
    while(pCur){
      if(pCur->data == data){
        return pCur;
      }
      pCur = pCur->next;
    }
    return nullptr;
  }
  void SlistPrint(Slist* s){
    Node* pCur = s->head;
    while(pCur){
      cout<<pCur->data<<"->";
      pCur = pCur->next;
    }
    cout<<"nullptr"<<endl;
  }
  ~Slist(){
    if(head){
      head = nullptr;
    }
  }
private:
  Node* head;
};
void Test(){
  Slist s;
  s.SlistPushBack(&s,1);
  s.SlistPushBack(&s,2);
  s.SlistPushBack(&s,3);
  s.SlistPushBack(&s,4);
  s.SlistPushBack(&s,5);
  s.SlistPrint(&s);
  s.SlistPopBack(&s);
  s.SlistPrint(&s);
  s.SlistPushFront(&s,0);
  s.SlistPushFront(&s,-1);
  s.SlistPrint(&s);
  s.SlistPopFront(&s);
  s.SlistPrint(&s);
  s.SlistInsert((s.SlistFind(&s,2)),10);
  s.SlistPrint(&s);
  s.SlistErase(&s,(s.SlistFind(&s,10)));
  s.SlistPrint(&s);

}
