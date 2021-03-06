#include<iostream>

#include<cstdlib>

using namespace std;

struct node{

    int info;

    struct node *next;

};

class Queue{

    private:

        node *rear;

        node *front;

    public:

        Queue();

        void push();

        void pop();

        void display();//front

};

Queue::Queue(){

    rear = NULL;

    front = NULL;

}

void Queue::push(){

    int data;

    node *temp = new node;

    cout<<"Enter the data to push: ";

    cin>>data;

    temp->info = data;

    temp->next = NULL;

    if(front == NULL){

        front = temp;

    }else{

        rear->next = temp;

    }

    rear = temp;

}

void Queue::pop(){

    node *temp = new node;

    if(front == NULL){

        cout<<"\nQueue is Emtpty\n";

    }else{

        temp = front;

        front = front->next;

        cout<<"The data poped is "<<temp->info;

        delete temp;

    }

}

void Queue::display(){

    node *p = new node;

    p = front;

    if(front == NULL){

        cout<<"\nNothing to Display\n";

    }else{

        while(p!=NULL){

            cout<<endl<<p->info;

            p = p->next;

        }

    }

}

int main(){

    Queue queue;

    int choice;

    while(true){

        cout<<"\n1.push\n2. pop\n3. Display\n 4.Quit";

        cout<<"\nEnter your choice: ";

        cin>>choice;

        switch(choice){

            case 1:

                queue.push();

                break;

            case 2:

                queue.pop();

                break;

            case 3:

                queue.display();

                break;

            case 4:

                exit(0);

                break;

            default:

                cout<<"\nInvalid Input. Try again! \n";

                break;

        }

    }

    return 0;

}