#include<stdio.h>
#define max 100
//cau truc mat hang
typedef struct mathang{
	int mamh;
	char tenmh[12];
};
struct queue{
	int n;
	int front, rear;
	mathang list[max];
};
//tao queue rong
void Init(queue &q){
	q.front=0;
	q.rear=max-1;
	q.n=0;
}
int isEmpty(queue q){
	return q.n==0 ? 1:0;
}
int isFull(queue q){
	return q.n=max ? 1:0;
}
//them phan tu vao queue
int EnQueue(queue &q, mathang x){
	if(isFull(q))
		return 0;
	q.rear=(q.rear+1)%max;
	q.list[q.rear]=x;
	q.n++;
	return 1;
}
mathang DeQueue(queue &q)
{
 if (!isEmpty(q))
{
	mathang x = q.list[q.front];
	q.front = (q.front + 1) % max;
	q.n--;
	return x;
}
}
//nhap mot mat hang
int NhapMatHang(mathang &x){
	printf("Nhap mot mat hang:");
	scanf("%d",&x.mamh);
	if(x.mamh==0)
		return 0;
	printf("\nNhap ten hang:");
	fflush(stdin);
	gets(x.tenmh);
}
//Nhap danh sach vao queue
void NhapDSMatHang(queue &q){
	mathang x;
	printf("Nhap mat hang = 0 de dung: ");
	int flag=NhapMatHang(x);
	while(flag){
		EnQueue(q,x);
		flag=NhapMatHang(x);
	}
	printf("\nKet thuc nhap DS mat hang.");
}
//xuat thong tin mat hang
void XuatMatHang(mathang x){
	printf("\nMa hang:%d ",x.mamh);
	printf("\nTen hang:%c",x.tenmh);
}
//xuat queue
void XuatQueue(queue q){
	mathang x;
	int i=q.n;
	if(isEmpty(q)){
		printf("\nKho khong con hang!");
		return;
	}
	while(i!=0){
		x=q.list[q.front];
		XuatMatHang(x);
		q.front=(q.front+1)%max;
		i--;
	}
}
//xuat thong tin mat hang chuan bi xuat
void Output_front(queue q){
	if(!isEmpty(q)){
		mathang x=q.list[q.front];
		XuatMatHang(x);
	}
}
//xuat thong tin hang moi nhap
void Output_rear(queue q){
	if(!isEmpty(q)){
		mathang x=q.list[q.rear];
		XuatMatHang(x);
	}
	
}
int main(){
	queue q;
	mathang x;
	Init(q);
	int choice;
	
	
	do{
		printf("1. Nhap mot mat hang\n");
		printf("2. Xuat mot mat hang\n");
		printf("3. Xem mot hang chuan bi xuat\n");
		printf("4. Xem mot hang moi nhap\n");
		printf("5. Xem cac mat hang co trong kho\n");
		printf("6. Xuat toan bo kho hang\n");
		printf("7. Ket thuc chuong trinh\n");
		printf("Chon:");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			NhapDSMatHang(q);
			break;
		case 2:
			XuatMatHang(x);
			break;
		case 3:
			printf("Mat hang sap xuat:");
			Output_front(q);
			break;
		case 4:
			printf("Mat hang moi nhap:");
			Output_rear(q);
			break;
		case 5:
			printf("Cac mat hang co trong kho:");
			XuatQueue(q);
			break;
			
		case 6:
			printf("Xuat toan bo kho hang:");
			XuatQueue(q);
			break;
		case 7:
			printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
			
	}
			
			
	}while(choice!=7);
	return 0;
	
	
	
}












