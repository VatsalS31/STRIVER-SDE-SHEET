class MinStack {
public:
     stack<pair<int,int>>st;
    MinStack() {
       
        
    }
    
    void push(int val) {
        if(st.empty())st.push({val,val});
        else st.push({val,min(val,st.top().second)});
        
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        
        return st.top().second;
    }
};

/*
  SIMPLE BRUTE FORCE APPROACH WHERE WE ARE USING PAIR AND STORING THAT INTO STACK WITH ELEMENT,MIN VALUE SO DIRECTLY WE CAN ACCESS IN LINEAR 
  TIME 
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


//OPTIMAL SOLUTION

class MinStack {
public:

    stack<long long>st;
    long long mini = INT_MAX,el;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
           st.push(val); 
           mini = val;

        } 
        else {
            if(val>mini) st.push(val);
            else{
                          
                st.push( (val - mini+val));
                 mini = val;
            }
         }
    }
    
    void pop() {
       
        if(st.empty()) return ;
        long long el = st.top();
        st.pop();
        if(el<mini){
            mini = (2*mini) - el;
        }
        
    }
    
    int top() {
         if(st.empty()) return INT_MAX;
         long long el = st.top();
        if(el>mini){
           return el;
        }
         return mini;
    }
    
    int getMin() {
       return mini;
    }
};

/*
  APPLYING ONE FORMULA THAT IS 2*MINI-VAL BASED ON THAT WE WILL MODIFY THE VALUE IN STACK AND BASED ON THAT I WILL GET THE PREVIOUS MINI VALUE
  ACCORDING TO FORMULA..
*/
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
