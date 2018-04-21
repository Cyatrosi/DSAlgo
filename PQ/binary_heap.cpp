#include<bits/stdc++.h>
using namespace std;
class minheap
{
    int capacity,size;
    vector<int> data;
    int leftchildindex(int i) {return 2*i +1;}
    int rightchildindex(int i) {return 2*i +2;}
    int parentindex(int i) {return (i-1)/2;}

    bool has_leftchild(int i) {return (2*i +1 < size);}
    bool has_rightchild(int i) {return (2*i +2 < size);}
    bool has_parent(int i) {return ((i-1)/2 >= 0);}

    int leftchild(int i) {return data[2*i +1];}
    int rightchild(int i) {return data[2*i +2];}
    int parent(int i) {return data[(i-1)/2];}

    void swap(int i , int j)
    {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    void ensurecapacity()
    {
        if(size == capacity)
            data.resize(2*capacity);
    }
    public:
        minheap(){
            capacity = 2;
            size = 0;
            data.resize(capacity);
        }
    int peak()
    {
        if(size == 0) return -1;
        else return data[0];
    }
    int pop()
    {
        int item;
        if(size >= 0)
        {
            item = data[0];
            data[0] = data[size-1];
            --size;
        }
        else
            item = -1;
        heapifydown();
        return item;
    }
    void add(int item)
    {
        ensurecapacity();
            data[size++] = item;
            heapifyup();
    }
    void heapifyup()
    {
        int index = size-1;
        while(has_parent(index) && parent(index)>data[index])
        {
            swap(index,parentindex(index));
            index = parentindex(index);
        }
    }
    void heapifyup(int startindex)
    {
        int index = startindex;
        while(has_parent(index) && parent(index)>data[index])
        {
            swap(index,parentindex(index));
            index = parentindex(index);
        }
    }
    void heapifydown()
    {
        int index = 0;
        while(has_leftchild(index))
        {
            int small_child = leftchildindex(index);
            if(has_rightchild(index))
                if(rightchild(index)<data[small_child])
                    small_child = rightchildindex(index);
            if(data[index]>data[small_child])
                {swap(index,small_child);index = small_child;}
            else
                break;
        }
    }
    void heapifydown(int startindex)
    {
        int index = startindex;
        while(has_leftchild(index))
        {
            int small_child = leftchildindex(index);
            if(has_rightchild(index))
                if(rightchild(index)<data[small_child])
                    small_child = rightchildindex(index);
            if(data[index]>data[small_child])
                {swap(index,small_child);index = small_child;}
            else
                break;
        }
    }
    void display()
    {
        for(int i=0;i<size;++i)
            if(has_leftchild(i)) cout<<data[i]<<" ";
            else cout<<data[i]<<"# ";
        cout<<endl;
    }
    int search(int key)
    {
        for(int i=0;i<size;++i)
            if(data[i] == key)
                return i;
        return -1;
    }
    void decrease_key(int index,int key)
    {
        if(index>=0 && index <size)
            data[index] = key;
        heapifyup(index);
    }
    int lessthan_k(int k)
    {
        queue<int> q;
        int index = 0;
        int ans = 0;
        if(data[index]<k)
            q.push(index);
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            ++ans;
            if(has_leftchild(index))
                if(leftchild(index)<k)
                    q.push(leftchildindex(index));
            if(has_rightchild(index))
                if(rightchild(index)<k)
                    q.push(rightchildindex(index));
        }
        return ans;
    }
};
int main()
{
minheap heap;
heap.add(8);
heap.add(7);
heap.add(4);
heap.add(1);
heap.add(9);
heap.display();
cout<<heap.lessthan_k(1);
return 0;
}
