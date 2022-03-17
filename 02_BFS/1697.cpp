#include <iostream>
#include <queue>

using namespace std;

int main()
{
	bool map[100001] = {};

	int N, K, result = 0;
	int temp;

	cin >> N >> K;

	queue<pair<int, int>> q;

	q.push(make_pair(0, N));

	while (true)
	{
		const auto [time, pos] = q.front();
		q.pop();

		// �̹� �ѹ� �������� ����
		if (map[pos])
			continue;

		map[pos] = true;

		// ã������ ��� �� ����
		if (pos == K)
		{
			cout << time << endl;
			break;
		}

		// ���� ������ �� �ִ� ���� Ž��
		q.push(make_pair(time + 1, pos + 1));
		if (pos != 0)
		{
			q.push(make_pair(time + 1, pos - 1));
			if (pos <= 50000)
				q.push(make_pair(time + 1, pos * 2));
		}
	}

	return 0;
}