#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Display queue element. 
void display(queue<int>q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Q. Print all numbers in every window of size k. 
void PrintAllNumberEveryWindowSizeK(int k){
    /**
    arr = [3, 6, 2, 7, 8, 11]
    Ans:-
        FirstWindowAns = [3, 6, 2]
        SecondWindowAns = [6, 2, 7]
        ThirdWindowAns = [2, 7, 8]
        4thWindowAns = [7, 8, 11]
        and Like that. 
     */
    queue<int> q;
    for(int i = 0; i < k-1; i++){
        q.push(arr[i]); // pushing element up to k-1. 
    }
    // Now, Push the k-1 element and start displaying the element from the front. 
    for(int i = k - 1; i < n; i++){
        q.push(arr[i]);
        display(q);
        q.pop(); // removing the element of queue from the front. 
    }
}

// 
long long display1(queue<long long> q){
    // return first negative integers. 
    while(!q.empty()){
        if(q.front() < 0){
            return q.front();

            q.pop();
        }
    }
    return 0;
}

// Q. Find the First negative number in every window of size.
vector<long long> FirstNegativeNumberEveryWindowSize(long long int A[], long long int N, long long int K){
    /**
    arr = [2, -3, -4, -2, 7, 8, 9, -10]
    Approachs:
    1. Push the elment into a new queue. 
    2. Print first negative element from in queue. 
    3. Pop first element. 
    4. Again Push the another element. 
     */
    vector<long long>ans;
    queue<long long>q;
    
    // push k-1 elements into q. 
    for(long long int i = 0; i < K; i++){
        q.push(A[i]);
    }

    for(long long int i = K; i < N; i++){
        q.push(A[i]);
        ans.push_back(display(a));
        q.pop();
    }
    return ans;
}

// More optimized code. 
/**
Approachs. 
Ask a question like this. 
1. Is this negative element is a part of window of size k ?
2. 
*/
vector<long long> FirstNegativeNumberEveryWindowSize(long long int A[], long long int N, long long int K){
    
    vector<long long> ans;
    queue<long long> q;

    // k-1 element hai, push kar do only negative elements.
    for(long long int i = 0; i < K -1; i++){
        if(A[i] < 0){
            q.push(i); // Pushing index of negative element. 
        }
    }

    for(long long int i = K - 1; i < N; i++){
        
        // Push negative element. 
        if(A[i] < 0){
            q.push(i);
        }

        if(q.empty()){
            ans.push_back(0);
        }else{
            // Check if first index of queue lies inside the window. 
            if(q.front() <= i - K){
                q.pop();
            }

            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(A[q.front()]);
            }
        }
    }

    return ans;
}

// Q. Find the non repeating character of stream of characters. 
string firstNonRepeatingCharacterOfStreamCharacters(string A){
    string B = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for(int i = 0; i < A.size(); i++){
        // repeated. 
        if(repeated[A[i]-'a'] >= 1){
            repeated[A[i]-'a']++:
            while(!q.empty() && repeated[q.front()-'a']>1){
                if(q.empty()){
                    B+= '#';
                }else{
                    B+= q.front();
                }
            }
        }
        // Non repeated. 
        else{
            repeated[A[i]-'a']++:
            q.push(A[i]);
            while(repeated[q.front()-'a']>1){
                q.pop();
            }
            B+= q.front();
        }
    }
}

int main(){
    // 
}

