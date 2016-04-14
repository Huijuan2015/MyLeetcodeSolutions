// Class Node - DO NOT MODIFY
// NOTE: you can compare nodes using the == operator
// DO NOT worry about a .equals() method
public class Node  {
	public :
		Node* next;
		Node* previous;
			
};
// Class LinkedList - IMPLEMENT the 4 methods
// DO NOT USE any java container classes
// Your list should be consistent at the return of every call.
// Add any member variables or methods you need
// NOTE: any method defined can call any other method defined
public class LinkedList {
	private:
		Node *head;
	// addNodeToList() - add the inputted node to the end of the list
	//  - if the node is already in the list, move it to the end
	// use == to compare node,
	// - HINT moving a node to the end is the same as removing and adding to the end
	public:
		Linkedlist(){
		  	head = NULL;
			head->next = NULL;
			head->previous = NULL;
		}

//add node function
		void addNodeToList( Node *toAdd ) {

			//if tooAdd is NUll, the function will be ended
			
			if(toAdd){
				// 1. remove if the node is in the list
				removeNode(toAdd);

				//2.1. after remove, if head is NULL
				if(head == NULL){
					head = toAdd;	
					head->next = NULL;
					head->previous = NULL;
				}else { 
				//2.2. after remove, if head is not NULL
				//add the node to the end of the list
				Node * p = head;
				while(p->next){
					p = p->next;
				}
				p->next = toAdd;
				toAdd->next = NULL;
				toAdd->previous = p;
			}
		}
	}

	// removeNode() - remove the inputted node
	// - if the node is not in the list do nothing
		void removeNode( Node *toRemove ) {
			//to continue only if toRemove and head are not NULL. 
			//or it will do nothing and end the function
			//this also handle the head is null in addNodeToList function
			if(toRemove != NULL && head != NULL){
				Node *p = head;
				
				while(p && p != toRemove){
					p = p->next;
				}
				if(p && p == toRemove){
					if(p->previous && p->next){//normal case
						p->previous->next = p->next;
						p->next->previous = p->previous;
						
					}else if(p->previous){//node is end
						p->previous->next = p->next;
						
					}else if(p->next){//node is head
						p->next->previous = p->previous;
						head = p->next;
					}
					delete p;
		
				}
			}
		}


		// popNodeFromStart() - remove the node at the start of the list and return it
	    Node popNodeFromStart()  {
		 	Node *front = head;
		 	removeNode(head);
		 	return front;//if head is NULL, it will return null
		}

		// popNodeFromEnd() - remove the node at the end of the list and return it
	    Node popNodeFromEnd() {
		 	Node * p = head;
		 	while(p->next){
		 		p = p->next;
		 	}
		 	Node *tail = p;
		 	removeNode(p);
		 	return tail;//if head is NULL, it will return null
		}

	}

