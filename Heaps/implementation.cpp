#include <iostream>
#include <vector>
using namespace std;
class heap
{
public:
    int size;
    int arr[100];

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {

        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
                return;
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (i < leftIndex and arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (i < rightIndex and arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else return;
        }
    }
};
int main()
{
    heap h;
    // 80 43 70 5 29 54 65
    h.insert(5);
    h.insert(70);
    h.insert(65);
    h.insert(43);
    h.insert(80);
    h.insert(54);
    h.insert(29);

    h.printHeap();
    h.deleteHeap();
    h.printHeap();
}

// #include <iostream>
// using namespace std;
// class heap
// {
//     public:
//         int arr[100];
//         int size;
//         heap()
//         {
//             arr[0] = -1;
//             size = 0;
//         }
//     void insert(int val)
//     {
//         size = size + 1;
//         int index = size;
//         arr[index] = val;

//         while(index > 1)
//         {
//             int parent = index/2;
//             if(arr[parent] < arr[index])
//             {
//                 swap(arr[parent],arr[index]);
//                 index = parent;
//             }
//             else return;
//         }
//     }
//     void print()
//     {
//         for(int i = 1; i <= size; i++) cout << arr[i] << " ";
//         cout << endl;
//     }
//     void deleteFromHeap()
//     {
//         if(size == 0)
//         {
//             cout << "Empty Heap" << endl;
//             return;
//         }
//         //put the last element in first index
//         arr[1] = arr[size];
//         //remove the last element
//         size--;

//         //take root node to it's correct position
//         int i = 1;
//         while(i < size)
//         {
//             int leftIndex = 2*i;
//             int rightIndex = 2*i+1;
//             if(leftIndex < size && arr[i] < arr[leftIndex])
//             {
//                 swap(arr[i],arr[leftIndex]);
//                 i = leftIndex;
//             }
//             else if(rightIndex < size && arr[i] < arr[rightIndex])
//             {
//                 swap(arr[i],arr[rightIndex]);
//                 i = rightIndex;
//             }
//             else return;
//         }
//     }
// };
// int main()
// {
//     heap h;
//     h.insert(20);
//     h.insert(12);
//     h.insert(30);
//     h.insert(14);
//     h.insert(21);
//     h.insert(18);
//     h.print();
//     h.deleteFromHeap();
//     h.print();
// }