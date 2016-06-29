// Reverse with three pointers
void reverse1() {

	if (head != NULL || head->next != NULL) {
		return;
	}

	Node* previous = NULL;
	Node* next = NULL;
	Node* current = head;

	while (current != NULL)
	{
		next = current->next; 		// Save where we are going to go next
		current->next = previous; 	// Do the reversal! Set this node to point back, instead of forward
		previous = current; 		// Properly set where we "were" next round
		current = next;				// Proceed to the next node
	}

	head = previous;
}


// Reverse with node to start from
void reverse2(Node* start) {
	Node* previous = NULL;
	Node* next = NULL;
	Node* current = start;

	while (current != NULL)
	{
		next = current->next; 		// Save where we are going to go next
		current->next = previous; 	// Do the reversal! Set this node to point back, instead of forward
		previous = current; 		// Properly set where we "were" next round
		current = next;				// Proceed to the next node
	}

	start = previous;
}



// Reverse from node recursively
// http://stackoverflow.com/questions/14080758/reversing-a-linkedlist-recursively-in-c
void publicFacingReverse() {
	head = reverse(head);
}

Node* reverse3(Node* current) {

	// Base conditions
	if(current == NULL) { // list does not exist
		return NULL;
	}
	if(current->next == NULL) { // list with only one node
		return current; 
	}

	// Recursive step otherwise
   	Node* rest = reverse(current->next); // Recursive reverse call on rest
	Node* immediateNext = current->next; // Temporary pointer to the node after the current node (technically the last node of what was just reversed!)

	immediateNext->next= current; 		// Link the last node of the reversed list (aka, immediate next) to the current node
	current->next = NULL; 				// Since the current node is the new last node, make its 'next' link NULL.

	return rest; // rest now points to the head of the reversed list.
}



