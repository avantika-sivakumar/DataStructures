struct node{
 int n;
 struct node*next;
};
 
struct node*front=NULL;
struct node*rear=NULL;
 
void enqueue(int);
int dequeue();
void display();
 
void enqueue(int no){
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 if(!temp){
   printf("error");
   return;
 }
 temp->n=no;
 temp->next=NULL;
 if(front==NULL){
   front=temp;
   rear=temp;
   return;
 }
 rear->next=temp;
 rear=temp;
}
 
int dequeue(){
 struct node*ptr=front;
 int n;
 if(front==NULL){
   printf("Queue is empty!\n");
   return -1;
 }
 n=ptr->n;
 if(ptr==rear){
   front=NULL;
   rear=NULL;
   free(ptr);
   return n;
 }
 front=ptr->next;
 free(ptr);
 return n;
}
 
void display(){
 struct node*ptr=front;
 if(front==NULL){
   printf("Queue is empty!\n");
   return;
 }
 printf("Printing the queue: ");
 while(ptr!=rear->next){
   printf("%d ",ptr->n);
   ptr=ptr->next;
 }
 printf("\n\n");
}

