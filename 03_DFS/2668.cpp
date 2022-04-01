#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, chart[100];

    cin >> N;

    // �������� ���ϱ� ���� ����
    set<int> temp;
    set<int> result;

    for (int i = 0; i < N; ++i)
    {
        cin >> chart[i];
        result.insert(chart[i]);
    }

    // result�� ũ�Ⱑ N�� ���ٸ� �ߺ��� �����Ƿ� ����� result��
    if (result.size() != N)
    {
        while (temp.size() != result.size())
        {
            temp = result;
            result.clear();

            // ���Ӱ� ���� ����� �ٽ� ���� ���ϴ� ���� ����
            for (auto i : temp)
                result.insert(chart[i - 1]);
        }
    }

    cout << result.size() << endl;
    for (auto i : result)
        cout << i << endl;

    return 0;
}