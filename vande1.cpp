#include<stdio.h>

struct Node{
	int data;
	Node *link;
};
struct queue{
	Node *front,*rear;
};
//tao queue rong
void Init(queue &q){
	q.front==NULL;
}
//kiem tra queue rong
int isEmpty(queue q){
	return q.front==NULL ? 1:0; // queue rong tra ve 1
}
//them phan tu vao queue
void EnQueue(queue &q, int x){
	Node *p=new Node;
	p->data=x;
	p->link=NULL;
	if(isEmpty(q)){
		q.front=p;
		q.rear=p;
	}else{
		q.rear->link=p;
		q.rear=p;
	}
}
//trich thong tin o dinh Q
int DeQueue(queue &q){
	if(isEmpty(q)){
		printf("Queue rong!\n");
		return 1;
	}
	Node *p=q.front;
	q.front=q.front->link;
	if(isEmpty(q)){
		q.rear=NULL;
	}
	int x=p->data;
	p->link=NULL;
	delete(p);
	return x;
	
}
//xem thong tin phan tu dau Q
int Front(queue q){
	if(isEmpty(q))
		return 1;
	return q.front->data;
}
int main(){
	int k;
	queue q;
	Init(q);
	printf("Nhap cac phan tu vao Queue(nhap -1 de ket thuc):\n");
	scanf("%d",&k);
	while(k!=-1){
		EnQueue(q,k);
		scanf("%d",&k);
	}
	printf("Lay cac phan tu ra khoi Queue: ");
	while(!isEmpty(q)){
		k=DeQueue(q);
		printf("%d ",k);
	}
}
















