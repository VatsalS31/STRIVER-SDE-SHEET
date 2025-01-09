class LRUCache {
public:
class node{
    public:
    int val;
    int key;
    node*next;
    node*prev;

    node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
};

    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    unordered_map<int,node*>mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void add(node* newnode)
    {
        node*temp=head->next;
        newnode->next=temp;
        temp->prev=newnode;
        head->next=newnode;
        newnode->prev=head;

    }
    void deletenode(node * delnode){
        node*prevp=delnode->prev;
        node* nextp=delnode->next;

        prevp->next=nextp;
        nextp->prev=prevp;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node*resnode=mp[key];
            int ans=resnode->val;
            mp.erase(key);
            deletenode(resnode);
            add(resnode);
            mp[key]=head->next;
            return ans;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node *exsist=mp[key];
            deletenode(exsist);
            mp.erase(key);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        add(new node(key,value));
        mp[key]=head->next;
        
    }
};

/*
PEHLE DLL BANALI AND EK MAP BANALIYA JISME KEY OR CORRESPONDING ADDRESS STORE KR LIYA ANF THEN FUNCTION BANALIYE ADD IN DLL AND DELETE IN DLL
WALE THEN IN GET FUNCTION HAME KEY DALTE HE VALUE CHAOYE TOH HUM PEHELE MAP ME DHUNDEGE AND AGR MILGYA TOH US KEY KA ADDRESS NODE ME STORE KR
LENGE OR MAP IS ERASE KRDENGE AND DLL ME SE BHI DELETE KRKE AAGE ADD KRDENGE KYUKI LEAST RECENTLY KA TRACK RKHNA HAI AND THEN MAP SE VALUE LAKE
LL ME ADD KRDENGE OR AGR NAI MILA TOH -1 RETURN KRDEGE

PHIR PUT FUNCTION ME CHECK KRENGE KEY CORRESPONDING KEY HAI KYA AGAR ALREADY HAI TOH NEW VALUE SE REPLACE KRDENGE TOH PEHLE NODE ME STORE KIYA 
MAP SE LAKE THEN DELETE KRDIYA OR MAP SE ERASE BHI OR AGAR CAPACITY OR CURRNT LENGTH SAME HAI MTLB BHARGYA NAI ADD KRSKTE TO LAST USE DLETE KRO
NEW ADD KRO TOH MAP SE LAO OR DELETE KRO BAKI PHIR ADD KARO SIMPLY HEAD KE NEXT ME OR MAP ME UPDATE KRO

TC O(1) GET AND PUT ASSUMING DELETE O(1) ME KR RRA HAI 
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
