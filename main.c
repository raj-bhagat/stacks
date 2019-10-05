#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "stack.h"
#include "queue.h"


void constant_memory()
{
Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

Stack stk = stack_new(10);
Stack *s=&stk;
Stack_Result Sres;

q=queue_add(q,10,&Qres);
q=queue_add(q,20,&Qres);
q=queue_add(q,30,&Qres);
q=queue_add(q,40,&Qres);

assert(q->count==4);
int d2count=1;
int d3count=q->count;

while(d2count<=d3count)
{
int dcount=1;
while(dcount<q->count)
{
	q = queue_delete(q,&Qres);
	q = queue_add(q,Qres.data,&Qres);
	dcount++;
}
	q = queue_delete(q,&Qres);
	s = stack_push(s,Qres.data,&Sres);

d2count++;
}
s = stack_peek(s,&Sres);
assert(Sres.data==10);
}

void stackTOqueue()
{
	Stack stk = stack_new(10);
Stack *s=&stk;
Stack_Result Sres;

Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

s = stack_push(s,93,&Sres);
s = stack_push(s,53,&Sres);
s = stack_push(s,73,&Sres);
s = stack_push(s,83,&Sres);

int element = 53;
int count = 0;
int i=0;
while(i<=s->top+1)
{
s = stack_peek(s,&Sres);
if(Sres.data==element)
{
	break;
}
else
{
	s = stack_pop(s,&Sres);
	q = queue_add(q,Sres.data,&Qres);
	count++;
}
i++;
}

int dcount=count;
int d1count=count;
while(count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	count--;
}
s = stack_peek(s,&Sres);
assert(Sres.data==73);

while(dcount!=0)
{
	s=stack_pop(s,&Sres);
	q=queue_add(q,Sres.data,&Qres);
	dcount--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==53);


while(d1count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	d1count--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==83);

}

/*Stack* addQueue(Stack *s1,int32_t element,Stack_Result Sres1)
{
	
	s1=stack_push(s1,element,&Sres1);
	return s1;
}
*/
Stack* deleteQueue(Stack *s1,Stack *s2,Stack_Result Sres1,Stack_Result Sres2)
{
	while(s1->top>-1)
	{
	s1 = stack_pop(s1,&Sres1);
	int32_t popelement = Sres1.data;
	s2 = stack_push(s2,popelement,&Sres2);
	}
	s2 = stack_pop(s2,&Sres2);
	return s2;
}


void queueUsingStacks()
{
	Stack stk1 = stack_new(10);
	Stack *s1=&stk1;
	Stack_Result Sres1;
	
	s1 = stack_push(s1,10,&Sres1); //it takes only one time to push the values
	s1 = stack_push(s1,20,&Sres1);
	s1 = stack_push(s1,50,&Sres1);	

	Stack stk2 = stack_new(10);
	Stack *s2=&stk2;
	Stack_Result Sres2;
	
	
	s2 = deleteQueue(s1,s2,Sres1,Sres2);
	s1 = stack_peek(s1,&Sres1);
	assert(s1->top==-1);
	
	s2 = stack_peek(s2,&Sres2);
	assert(Sres2.data==20); //10 is deleted using queue.
	
}

void transfer(Stack *S,Stack *T)
{
		Stack_Result Sres;
		Stack_Result Tres;
		
		S = stack_push(S,69,&Sres);
		S = stack_push(S,79,&Sres);
		S = stack_push(S,89,&Sres);
		S = stack_push(S,99,&Sres);

		S = stack_peek(S,&Sres);
		assert(Sres.data == 99);
		
		while(S->top>-1)
		{
		S = stack_pop(S,&Sres);
		int32_t element = Sres.data;
		T = stack_push(T,element,&Tres);
		}
		
		T = stack_peek(T,&Tres);
		assert(Tres.data==69);// bottom element of S is top element of T

}


void reverseElement(Stack *S,Stack *T)
{
	Stack_Result Sres;
		Stack_Result Tres;
		
		S = stack_push(S,69,&Sres);
		S = stack_push(S,79,&Sres);
		S = stack_push(S,89,&Sres);
		S = stack_push(S,99,&Sres);

		S = stack_peek(S,&Sres);
		assert(Sres.data == 99);
		
		while(S->top>-1)
		{
		S = stack_pop(S,&Sres);
		int32_t element = Sres.data;
		T = stack_push(T,element,&Tres);
		}
		
		T = stack_peek(T,&Tres);
		assert(Tres.data==69);
		
		while(T->top>-1)
		{
		T = stack_pop(T,&Tres);
		int32_t revElement = Tres.data;
		S = stack_push(S,revElement,&Sres);
		}
		
		S = stack_peek(S,&Sres);
		assert(Sres.data == 99);
}

void CheckStackFull()
{
		Stack stk = stack_new(3);
		Stack *S=&stk;
		Stack_Result res;
		
		S = stack_push(S,20,&res);
		S = stack_push(S,30,&res);
		S = stack_push(S,40,&res);
		
		S = stack_push(S,50,&res);
		assert(res.status==2); // stack is full hence res.status is 2 i.e stack_full
		S = stack_push(S,80,&res);
		
		assert(res.status==2); // stack is full hence res.status is 2 i.e stack_full

}

void TwoTemporaryStacks()
{
	Stack stk = stack_new(10);
	Stack *S=&stk;
	Stack_Result res;
	
	S = stack_push(S,33,&res);
	S = stack_push(S,22,&res);
	S = stack_push(S,11,&res);
	S = stack_push(S,55,&res);
	
	Stack stk1 = stack_new(10);
	Stack *temp1=&stk1;
	Stack_Result Tres1;
	
	Stack stk2 = stack_new(10);
	Stack *temp2=&stk2;
	Stack_Result Tres2;
	
	while(S->top>-1)
	{
	S = stack_pop(S,&res);
	int32_t element = res.data;
	temp1 = stack_push(temp1,element,&Tres1);
	temp2 = stack_push(temp2,element,&Tres2);
	}
	
	temp1 = stack_peek(temp1,&Tres1);
	assert(Tres1.data==33);
	temp2 = stack_peek(temp2,&Tres2);
	assert(Tres2.data==33);
}

void StacksConfiguration()
{
	Stack stk = stack_new(10);
	Stack *R=&stk;
	Stack_Result Rres;
	
	Stack stk1 = stack_new(10);
	Stack *S=&stk1;
	Stack_Result Sres;
	
	Stack stk2 = stack_new(10);
	Stack *T=&stk2;
	Stack_Result Tres;
	
	R = stack_push(R,1,&Rres);
	R = stack_push(R,2,&Rres);
	R = stack_push(R,3,&Rres);
	S = stack_push(S,4,&Sres);
	S = stack_push(S,5,&Sres);
	T = stack_push(T,6,&Tres);
	T = stack_push(T,7,&Tres);
	T = stack_push(T,8,&Tres);
	T = stack_push(T,9,&Tres);
	
	int count=0;
	while(S->top>-1)
	{
	S = stack_pop(S,&Sres);
	int32_t ele = Sres.data;
	R = stack_push(R,ele,&Rres);
	count++;
	}
	R = stack_peek(R,&Rres);
	//printf("%d",Rres.data);

	while(count!=0)
	{
	R = stack_pop(R,&Rres);
	int32_t element = Rres.data;
	T = stack_push(T,element,&Tres);
	count--;
	}
	
	T = stack_peek(T,&Tres);
	assert(Tres.data == 5);
	//printf("%d",Tres.data);
	
	
	}

int32_t dequeue(Queue *q, Queue_Result Qres)
{
q = queue_delete(q,&Qres);
int32_t ele=Qres.data;
//printf("%d",ele);
return ele;
}
	
void QueueRotate()
{
Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

q=queue_add(q,10,&Qres);
q=queue_add(q,20,&Qres);
q=queue_add(q,30,&Qres);
q=queue_add(q,40,&Qres);

q = queue_add(q,dequeue(q,Qres),&Qres);
assert(q->data[q->head-1]==10);

q = queue_add(q,dequeue(q,Qres),&Qres);
assert(q->data[q->head-1]==20);
}
	
void leakyStack()
{
	Stack stk1 = stack_new(5);
	Stack *S1=&stk1;
	Stack_Result Sres1;
	
	Stack stk2 = stack_new(5);
	Stack *S2=&stk2;
	Stack_Result Sres2;

	S1 = stack_push(S1,7,&Sres1);
	S1 = stack_push(S1,13,&Sres1);
	S1 = stack_push(S1,1,&Sres1);
	S1 = stack_push(S1,18,&Sres1);
	S1 = stack_push(S1,20,&Sres1);
	
	if(S1->top+1 == S1->size)
	{
		while(S1->top>-1)
		{
		S1 = stack_pop(S1,&Sres1);
		int32_t ele = Sres1.data;
		S2 = stack_push(S2,ele,&Sres2);
		}
		S2=stack_pop(S2,&Sres2);
		
		while(S2->top>-1)
		{
		S2 = stack_pop(S2,&Sres2);
		int32_t element = Sres2.data;
		S1 = stack_push(S1,element,&Sres1);
		}
		S1 = stack_peek(S1,&Sres1);
		assert(Sres1.data==20); // 7 is deleted and ready to add next element		
		S1 = stack_push(S1,50,&Sres1);
		
	}
	
	
	}
	
int main()

{
/*1. Design a stack using a single queue as an instance variable, 
and only constant additional local memory within the method bodies.*/
constant_memory();

/*2.Suppose you have a stack S containing n elements and a queue Q that is initially empty. 
Write function that use Q to scan S to see if it contains a certain element x, with the additional
constraint that your algorithm must return the elements back to S in their original order. You
may use S, Q and a constant number of other variables.*/
stackTOqueue();

//3.Design a queue using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.	
queueUsingStacks();

/*4. Implement a function with signature transfer(S,T) that transfers all elements from Stack S onto
Stack T, so that that elements that starts at the top of S is the first to be inserted into T, and
element at the bottom of S ends up at the top of T. */
Stack stk1 = stack_new(10);
Stack *S=&stk1;

Stack stk2 = stack_new(10);
Stack *T=&stk2;

transfer(S,T);

/*5.Implement a function that reverses a list of elements by pushing them onto a stack in one order,
and write them back to the list in reversed order.*/
reverseElement(S,T);

/*6. Modify ArrayStack implementation so that the stack’s capacity is limited to maxlen elements. If
push is called when the stack is at full capacity, throw a Full exception. */	
CheckStackFull();

/*7. Implement a transfer function and two temporary stacks, to replace the contents 
of a given stack S with those same elements, but in reverse order.*/	
TwoTemporaryStacks();

/*8. Suppose you have three nonempty stacks R, S and T. Describe a sequence of operations that
results in S storing all elements originally in T below of S’s original elements, with both sets of
those elements in their original configuration. For example, if R = [1,2,3], S = [4, 5] and T = [6, 7,
8, 9], the final configuration should have R = [1, 2, 3] and S = [6, 7, 8,  9, 4, 5].*/
StacksConfiguration();

/*9. In certain applications of the queue, it is common to repeatedly dequeue an element, process it
in some way, and then immediately enqueuer the same element. Modify ArrayQueue
implementation to include a rotate( ) method that has semantics identical to the combination,
Q.enqueue (Q.dequeue()). However, your implementation should be more efficient than making
two separate calls.*/
QueueRotate();

/*10. Implement LeakyStack. This stack should be of fixed size. When push is invoked with the stack at
full capacity, rather than throwing a Full exception, accept the pushed element at the top while
“leaking” the oldest element from the bottom of the stack to make a room.*/
leakyStack();

return 0;
}