/*This is c++ solution of this question
https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620
/1?page=2&sortBy=submissions in O(n) time complexity */
class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) 
    {
        stack<long long> st; // create an empty stack of type long long
        // iterate the input array from right to left
        for(int i=n-1;i>=0;i--) 
        {
            long long curr=arr[i]; // current element in the array
            if(st.empty()) // if the stack is empty
            { 
                arr[i]=-1; // there is no greater element to the right of current element
                st.push(curr); // push current element onto the stack
            } 
            else// if the stack is not empty
            { 
                while(curr>=st.top())// keep popping elements from stack until greater element is found or stack is empty
                { 
                    st.pop();
                    if(st.empty())// if the stack is empty, there is no greater element to the right of current element
                    { 
                        arr[i] = -1;
                        st.push(curr); // push current element onto the stack
                        break;
                    }
                }
                if(arr[i] != -1) // if greater element is found
                { 
                    arr[i] = st.top(); // assign the top of the stack to current element
                    st.push(curr); // push current element onto the stack
                }
            }
        }
        return arr; // return the modified array with next greater element for each element
    }
};