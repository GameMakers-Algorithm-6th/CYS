#include <iostream>
#include <queue>

using namespace std;

int main()
{
	pair<bool, int> map[100001] = {};
	int N, K, result = 100001, way = 0;

	cin >> N >> K;

	queue<pair<int, int>> q;

	q.push(make_pair(0, N));

	while (!q.empty())
	{
		const auto [time, pos] = q.front();
		q.pop();

		auto& [bPassed, passTime] = map[pos];

		// ���� ���� ������ ���̸鼭 �� �����ð��� �������ٸ� �ǳ� �ٰ�, �����ð����� ���� �ɸ� �ð��鵵 �ǳ� �ڴ�.
		if ((bPassed && passTime < time) || time > result)
			continue;

		// ã������ �ּҰ� ���� �� ��� �� ����
		if (pos == K)
		{
			result = time;
			++way;
			continue;
		}

		// �� ����
		bPassed = true;
		passTime = time;


		// ���� ������ �� �ִ� ���� Ž��
		q.push(make_pair(time + 1, pos + 1));
		if (pos != 0)
		{
			q.push(make_pair(time + 1, pos - 1));
			if (pos <= 50000)
				q.push(make_pair(time + 1, pos * 2));
		}
	}

	cout << result << endl << way << endl;

	return 0;
}