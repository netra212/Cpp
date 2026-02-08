#include <iostream>
#include <queue>
using namespace std;

// Q. Printing the element in queues. 
void printElement(queue<int> q){
    // print all the elements while not removing any elements. 
    while(n--){
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
}

// Q. Given a queue reverse it. 
queue<int> queueReversal(){
    // Empty the queue.
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    // Empty the stack. 
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}

// Reverse First K element of Queue. 
queue<int> reverseKElement(queue<int> q, int k){
    // Approaches. 
    // 1. Pusk first k element of queue in stack. 
    // 2. store the size of queue. 
    // 3. push all element of stack in queue. 
    // 4. Push first n element of queue at last. 
    stack<int> st;
    for(int i = 0; i < k; i++){
        st.push(q.front()); // queue ko front ko element laii stack ma haldiyako.
        q.pop(); // queue laii agadii batww khalii gardaii gako.
    }
    int n = q.size();
    // add elements into the queue. 
    while(!st.empty()){ // jaba samma stack empty hudaina, queue ma stack ko top dekhii element laii haldaii garne.
        q.push(st.top());
        st.pop(); // stack laii khalii gardaii gayako.
    }
    while(n--){
        q.push(q.front()); // aba queue ko first side ma element laii push gareko. 
        q.pop(); 
    }
    return q;
}

// Time needed to buy tickets. 
int timeRequiredToBuyTicket(queue<int> &tickets, int n){
    // arr = [1, 5, 2, 3, 7]
    // k = 2, means total time takenby the 2nd index to ticket. 
    int n = tickets.size();
    for(int i = 0; i < n; i++){
        q.push(i);
    }
    int time = 0;

    while(tickets[k]!=0){
        tickets[q.front()]--;
        if(tickets[q.front()]){
            q.push(q.front());
            q.pop();
            time++;
        // }else{
        //     q.pop();
        // }
        }
    }
    return time;
}

// Implement queue using stack. 
class Queue{
    stack<int> st1; // push
    stack<int> st2; // pop
public:
    bool empty(){
        return st1.empty() && st2.empty();
    }

    void push(int x){
        st1.push(x);
    }

    void pop(){
        if(empty){
            return 0;
        }
        else if(!st2.empty()){
            int element = st2.top();
            st2.pop();
            return element;
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int element = st2.pop();
            st2.pop();
            return element;
        }
    }

    int peek(){
        if(empty()){
            return 0;
        }
        if(!st2.empty()){
            return st2.top();
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
};

// Implement stack using Queue. 
class StackViaQueue{
public:
    queue<int> q1;
    queue<int> q2;

    StackViaQueue(){

    }

    bool empty(){
        return q1.empty() && q2.empty();
    }

    void push(int x){
        // Base Condition
        if(empty()){
            q1.push(x);
            // Jun queue ma element huncha, tesma push huncha. 
        }else if(q1.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }

    int pop(){
        if(empty()){
            return 0;
        }
        else if(q1.empty()){
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }

            int element = q2.front();
            q2.pop();
            return element;
        }else{
            if(q2.empty()){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }

            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int top(){
        if(empty()){
            return 0;
        }else if(q1.empty()){
            return q2.back();
        }else{
            return q1.back();
        }
    }
};


int main(){

}




