#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Node
{
    list<int> linkedNodesIndex;
    bool bVisit;
};

Node nodes[2000];

bool FindABCDE(int n, int linkCount)
{
    if (nodes[n].bVisit)
        return false;

    if (++linkCount == 5)
        return true;

    nodes[n].bVisit = true;

    for (auto linkedNode : nodes[n].linkedNodesIndex)
    {
        if (FindABCDE(linkedNode, linkCount))
            return true;
    }
    nodes[n].bVisit = false;

    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    // �׷��� ����
    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        nodes[s].linkedNodesIndex.push_back(e);
        nodes[e].linkedNodesIndex.push_back(s);
    }

    for (int i = 0; i < N; ++i)
    {
        // ��� ��忡�� ã�ƺ��� ��ã���� ABCDE�� �������� �ʴ°�
        if (FindABCDE(i, 0))
        {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}