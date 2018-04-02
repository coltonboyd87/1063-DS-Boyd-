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
//               							     //
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
    Node *next;
    Node()
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
    Node *Front;
    Node *Rear;
    string word_1;
    string word_2;

  public:
    /**
   * Queue
   * constructor
   * 
   * params:
   *     - none
   */
    Queue()
    {
        Front = Rear = NULL;
    }

  /** Method name: void lengthBasedPQueue
   * 
   * Description: Will sort the words in the queue based the 
   * length of the word. 
   * 
   * Params: None 
   * 
   * Returns: void 
   * 
   * 
   */

  void lengthBasedPQueue()
  {
    Node *temp = Front; 
    if(empty())
		{             // handles the empty case, doesnt have to return a value 
		  return;     // because it is a void type. 
		}
		
		while (temp->next != NULL)
		{	                                // This puts words in an order to be swapped. 
		  string word_1 = temp->val;
			string word_2 = temp->next->val;
    }
    
    if (word_1.length()>word_2.length())
			{	                                // Case in which word 1 is longer than
				temp->val = word_2;             // word 2. 
				temp->next->val = word_1;
			}
			
			else if (word_1.length() == word_2.length())
			{	
			  if (word_1>word_2)
				{	
				  temp->val = word_2;        // Case in which word 1 is in equal length 
					temp->next->val = word_1;  // of word 2. 
				}
			}
			temp = temp->next;
		}
	}
	
  /** Method name: string pop 
   * 
   * Description: will return name of animal at the front of list. Will display error 
   * message if queue is somehow empty. 
   * 
   * Params: None 
   * 
   * Returns: string 
   * 
   */
    string pop()
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
            string v = temp->val; // grab value out of node
            Front = Front->next;  // move pointer to next node
            delete temp;          // give mem back to system
            return v;
        }
        else
        {
            cout << "error: cannot pop off empty queue." << endl;
            return " ";
        }               // Error message indicating an empty queue. 
    }

/** Method name: void push  
   * 
   * Description: pushes a new animals name onto non-empty queue.
   * 
   * Params: string 
   * 
   * Returns: None because it is a void type. 
   * 
   */
    void push(string v)
    {
        Node *n = new Node(v);

        // handle the empty case
        if (empty())
        {
            Front = n;
            Rear = n;
        }
        else
        {
            // not empty add to rear
            Rear->next = n;
            Rear = n;
        }
    }
    
/** Method name: bool empty   
   * 
   * Description: will return whether or not the current list is empty 
* or non empty. 
   * 
   * Params: None 
   * 
   * Returns: boolean, T or F. 
   * 
   */
    bool empty()
    {
        return (Front == NULL && Rear == NULL);
    }
    

/** Method name: bool pop  
   * 
   * Description: will pop name of animal off of queue.
   * 
   * Params: string 
   * 
   * Returns: boolean, T or F. 
   * 
   */
    bool pop(string &v)
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
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
    ////////////////////////////////////////////
    //                                        //
    //Functions to be used in main function:  //
    //                                        //
    //string word                             //
    //oFile                                   //
    //                                        //
    //                                        //
    ////////////////////////////////////////////
    
    /** Fuction name: string word  
   * 
   * Description: Will return the first item in the queue
   * 
   * Params: None 
   * 
   * Returns: string
   * 
   */
  string word()
  {
      while (!empty())  //This is a check for the first item in queue 
    {                 // and will ultimately return for its use. 
      return Front->val;
    }
      return "";
  }
    
     /** Fuction name: oFile   
   * 
   * Description: Will print remaining to an outfile, based on the word 
   * length priority within the queue.
   * 
   * Params: oFile ofstream 
   * 
   * Returns: void
   * 
   */
   
   void oFile(ofstream &ofile)
  { 
    int num = 1;
    Node *temp = Front;
		while (temp)
		{	
		  ofile << num++ << " " << temp->val << '\n';
			temp = temp->next;
		}
  }
};


//////////////////////
//                  //
//Main Function     //
//                  //
//////////////////////

int main()
{
  //Variable intilizing
  Queue Q;
	string animal, command;
  int num_popped = 1;
 	int node_Count = 0;      
	                        
	//Data Type to create an instance of a text file to be able to access
	//strings in the input_data.txt file. 
	//Also creates an output file called priority_out.txt to output 
	//animals names. 
  ifstream ifile;
	ifile.open("input_data.txt");
  
  
  
	ofstream ofile;
	ofile.open("priority_out.txt"); //defining our ofile 
	ofile << "Animals Popped off the Queue:" << '\n' << '\n';
	
	//Loop to go through and process input_data.txt file. 
	while (ifile >> command)
	{	
	  //If statement to handle the case of the push function being commanded in 
	  //input text file. This will run the push method defined earlier in our 
	  //Class Q. 
	  if (command == "push")
		{	
		  ifile >> animal;
			Q.push(animal); //Push animal onto queue
			node_Count++;
		} 
		
    //Else if statement to handle the case of the pop function being commanded 
    //in input text file. This will run the pop method defined earlier in our 
    //class Q. 
		else if (command == "pop")
		{ 
		  if (Q.word() != "") 
		  { 
		    ofile<<num_popped++<< " " <<Q.word()<< '\n';
		  }
		  Q.pop(animal);
    	node_Count--;
			if (node_Count < 0)  
			{ 
			  node_Count = 0;   
			} 
		} 

    if (node_Count > 1)    
    { 
      for(int i = 0; i < node_Count - i ; i++) 
      { 
        Q.lengthBasedPQueue();  //This is where we implement our method to 
      }                         //sort our animal names based on priority. 
    } 
	} 
	//ofile 
	ofile << '\n' << "Animals Remaining on the Queue (In Order of priority):" << '\n' << '\n'; 
	
	Q.oFile(ofile);
	ifile.close(); //commands to close ifile and ofile files. 
	ofile.close();
	return 0;
}
