
//here i will use doubly linked list for my implemenation 

struct Node{
    int key,value,cnt;
    Node* prev;
    Node* next;
    Node(int _key,int _value){
        key=_key;
        value=_value;
        cnt=1;
    }
    //each query get will give us a key jske corresponding we need to return its value 
    //har access due to get or put uski frequency bad jaegi
    //jaise hi koi new element aega then the least frequency is automatically set to 1

};
struct List{
    int size;
    Node* head;
    Node* tail;
    //so that we can get rid of corner cases we can directly  insert and delete from 2 dummy nodes
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
        //dummy nodes will not contribute to the  size of the node 
    }
    void addfront(Node* node){
        //for adding or removing from a dll we simply do noe pointer rearrangemen
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        head->next=node;
        size++;
        //understand  the node   pointer rearrangement here 


    }
    void removenode(Node* delnode){
        //jabhi node delete hogi lfu walin list nme se hogi 
        //if  there occurs a tie then thge lru once is used 
        //you should not forgot these corner test cases
        //fist understand the logic then code it  well
        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};







class LFUCache {
public:
//now here we will mention what all data struture we required to implement thre lru catch operation class
map<int,Node*>keynode;
map<int,List*>freqlistmap;
int maxsizecache;
int minfreq;
int currsize;//this will keep track of the node jo abhi tak black box ie lfu cache me jachuke h 
// cause there is a limit n on this according  to the questions

    LFUCache(int capacity) {
        //this is the construtor of this class this will intialise all the things 
        maxsizecache=capacity;
        minfreq=0;
        currsize=0;

        
    }
    void updatefreqlistmap(Node* node){
        
        keynode.erase(node->key);
        freqlistmap[node->cnt]->removenode(node);
        if(node->cnt==minfreq && freqlistmap[node->cnt]->size==0){
            minfreq++;
        }
        List* nexthigherfreqlist=new List();
        if(freqlistmap.find(node->cnt+1)!=freqlistmap.end()){
            nexthigherfreqlist=freqlistmap[node->cnt+1];
        }
        node->cnt++;
        nexthigherfreqlist->addfront(node);
        freqlistmap[node->cnt]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {


        if(keynode.find(key)!=keynode.end()){
            //then this is present already just find the value of it
            Node* node=keynode[key];
            int val=node->value;
            //since i have called get function on this kye 
            //uski access frequency bad jaegi 
            //to hi update karni padegi inside the data strutres accordinglyu 
            updatefreqlistmap(node);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {

        //deal the corner cases and the base cases first 
        if(maxsizecache==0){
            //ek test case bhi daal denge chech karne  ke liye 
            return ;
        }

        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            node->value=value;
            updatefreqlistmap(node);//whenever this function is called access frequency is increaesd by 
            //dry run karke flow samjha karo dosto

        }else{
            //the given entry will be going inside the lru cache for first time
            //kya kya possib
            if(currsize==maxsizecache){
                //then we need to delete the lfu and create space for the incoming
                List* list=freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                //use node ko dono hashmap me sse delte karna hoga
                freqlistmap[minfreq]->removenode(list->tail->prev);
                currsize--;
            }
            currsize++;
            //new value has to be added which is not there previously 
            //whenever a new element comes the min freq inside the lfu data struture is automatically set to 1
            minfreq=1;
            List* list=new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                list=freqlistmap[minfreq];

            }
            Node* node=new Node(key,value);
            list->addfront(node);
            keynode[key]=node;
            freqlistmap[minfreq]=list;
        }

        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
