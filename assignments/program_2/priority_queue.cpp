///////////////////////////////////////////////////////////////////////////////
//Name: Colton Boyd                                                          //
//                                                                           //
//Project Name: Priority Queue                                               //
//                                                                           //
//Description: This program will read in "push" and "pop" commands           //
//in the input_data.txt file and will add various animal names according     //
//to data file. This will create a priority list to push these names onto    //
//a queue and read the length of the word. The shorter the word the higher   //
//the priority. The program will print out all popped off animals off of     //
//queue. And then after that will print out all the names remaining in the   //
//queue in alphabetical order.                                               //
//               							     //								 //														 //
//Files: input_data.txt, priority_queue.txt				     //
//Email: coltonboyd14@yahoo.com 					     //
//Semester: Spring 2018 						     //						 
//Course Name: 1063 Data Structures                                          //
//                                                                           //
//Date: April 2nd 2018                                                       // 
//                                                                           //
//Intructor: Griffin                                                         //
///////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Struct that contains our Node elements for our 
//linked list.
struct Node
{
	string val;
	Node* next;
	Node() // initializes node to empty and next pointer to null
	{
		val = " ";
		next = NULL;
	}
	Node(string v)
	{
		val = v;
		next = NULL;
	}
};



/**
* class Queue:
* This class is designed to use Nodes in a LL to
* push and pop strings in a queue in an instance of
* the class called Q.
* Methods:
*  - Queue()       : constructor intilizing front/rear = NULL.
*  - lengthBasedPQueue: will exchange words with eachother and swap based on
* word length. The shorter the length, higher the priority.
*  - string pop()  : will return name of animal at the front of list.
*  - bool pop(string&v) : will pop name of animal off of queue.
*  - void push (string v) : pushes a new animals name onto non-empty queue.
*  - bool empty() : will return whether or not the current list is empty
* or non empty.
*/

class Queue
{
private:
	Node* Front;
	Node* Rear;
public:
	/**
	* Queue
	* constructor
	* params:
	*     - none
	*/
	Queue()
	{
		Front = Rear = NULL;
	}

	/**
	* Function pop:
	*      Pops an item off the queue.
	* Params:
	*      none
	* Returns
	*      string
	*/
	string pop()
	{
		if (!empty())
		{
			Node* temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return v;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return " ";
		}
	}



	/**
	* Function pop:
	*      Popss an item off the queue.
	* Params:
	*      [string] v - value of item being pushed
	* Returns
	*      void
	*/
	bool pop(string &v)
	{
		if (!empty())
		{
			Node* temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			v = t;
			return true;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}

	/**
	* Function push:
	*      Pushes an item onto the queue.
	* Params:
	*      [string] val - value of item being pushed
	* Returns
	*      void
	*/
	void push(string v)
	{
		Node* n = new Node(v);
		// handle the empty case
		if (empty())
		{
			Front = n;
			Rear = n;
		}
		else
		{	// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
	}

	/**
	* Function empty:
	*      Checks if the list is empty.
	* Params:
	*      none
	* Returns
	*      bool
	*/
	bool empty()
	{
		return (Front == NULL);
	}

	/**
	* Function print:
	*      Prints every item still on the queue.
	* Params:
	*      none
	* Returns
	*      void
	*/
	void print()
	{
		Node* temp = Front;
		while (temp)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << '\n';
	}

	/**
	* Function lengthBasedPQueue:
	*      Sorts the items in the queue based on length.
	* Params:
	*      none
	* Returns
	*      void
	*/
	void lengthBasedPQueue()
	{
		Node *temp = Front;

		if (empty())
		{
			return;
		}

		while (temp->next != NULL)
		{
			string word1 = temp->val;
			string word2 = temp->next->val;

			if (word1.length() > word2.length())
			{	//swaps the nodes' values 
				temp->val = word2;
				temp->next->val = word1;
			}

			// if TIE - handles words of same length by placing them
			// alphabetically
			else if (word1.length() == word2.length())
			{
				if (word1 > word2)
				{
					temp->val = word2;
					temp->next->val = word1;
				}
			}
			temp = temp->next;
		}
	}

	/**
	* Function word:
	*      Returns the front value of the list for easy access before popping item off list.
	* Params:
	*      none
	* Returns
	*      string
	*/
	string word()
	{
		while (!empty())
		{
			return Front->val;
		}
		return "";
	}

	/**
	* Function outfileList:
	*      Prints list node value and number on list to output file.
	* Params:
	*      outfile
	* Returns
	*      void
	*/
	void outfileList(ofstream &outfile)
	{
		int itemsoutfiled = 1;
		Node *temp = Front;
		while (temp)
		{
			outfile << itemsoutfiled++ << " " << temp->val << '\n';
			temp = temp->next;
		}
	}
//Main Function 
};

int main()
{
	int number = 1;// for counting the number of items
						// popped off the list.
	Queue Q;
	string animal, command; // command is either push or pop
	int nodecount = 0;      // keeps track of the number of nodes
							// in the list

	fstream infile;
	infile.open("input_data.txt");
	ofstream outfile;
	outfile.open("priority_out.txt");// items still on Queue when
									 // program ends
	outfile << "Animals Popped off the Queue:" << '\n' << '\n';

	while (infile >> command)
	{
		if (command == "push")
		{
			infile >> animal;
			Q.push(animal);
			nodecount++;
		} // end of if

		else if (command == "pop")
		{
			if (Q.word() != "") // only prints and
										  // increments number
										  // it the list is not empty
			{
				outfile << number++ << " " << Q.word() << '\n';
			}
			Q.pop(animal);
			nodecount--;
			if (nodecount < 0)  // avoids making nodecount negative
			{
				nodecount = 0;   // in for loop
			} // end of if
		} // end of else if

		if (nodecount > 1)    // only sorts list when there is more
		{                     // than one item
			for (int i = 0; i < nodecount - i; i++) // loops the sort
													// function
													// enough times
													// for the
													// shortest items
													// in list to
													// move to the
													// front
			{
				Q.lengthBasedPQueue();
			} // end for loop
		} // end of if
	} // end of while

	outfile << '\n' << "Animals Remaining on the Queue (in order of priority):" << '\n' << '\n';

	Q.outfileList(outfile);

	infile.close();
	outfile.close();
	return 0;
}
