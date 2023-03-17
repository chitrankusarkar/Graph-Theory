#include <iostream>
#define SIZE 50
using namespace std;

class BFS
{
private:
    int size, rear, front, sVertex, queue[SIZE], statusArr[SIZE], adjMat[SIZE][SIZE];
    void initStatusArr()
    {
        for (int i = 0; i < size; i++)
        {
            statusArr[i] = 0;
        }
    }
    void initAdjMat()
    {
        cout << "Enter the Adjacency Matrix : " << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> adjMat[i][j];
            }
        }
    }
    void enQueue(int data)
    {
        if (front == -1)
        {
            front++;
        }
        queue[++rear] = data;
    }
    int deQueue()
    {
        int val = queue[front--];
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }

public:
    BFS(int vertex)
    {
        size = vertex;
        rear = -1;
        front = -1;
    }
    void breadthFirstSearch()
    {
        initAdjMat();
        initStatusArr();
        cout << "Enter the starting vertex : ";
        cin >> sVertex;

        statusArr[--sVertex] = 1;
        enQueue(sVertex);

        cout << "The Output is : " << endl;
        while (front != 1)
        {
            int deQueuedVal = deQueue();
            for (int i = 0; i < size; i++)
            {
                if (statusArr[i] == 0 && adjMat[deQueuedVal][i] == 1)
                {
                    statusArr[i] = 1;
                    cout << deQueuedVal + 1 << " --> " << i + 1 << endl;
                    enQueue(i);
                }
            }
            statusArr[deQueuedVal] = 2;
        }
    }
};
int main()
{
    int vertices;
    cout << "Enter the vertices : ";
    cin >> vertices;
    BFS obj(vertices);
    obj.breadthFirstSearch();
    return 0;
}