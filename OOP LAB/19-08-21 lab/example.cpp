#include <iostream>using namespace std;class list{    private:        int data;        list *next;    public:    	list *insert(int num, list *head)	{	    	if(head == NULL)	    	{	    	   head = new list();	    	   head->data = num;	    	}    	}};int main(){    list *head;    head = head->insert(5,head);        return 0;}